#include <algorithm>    // std::sort
#include <cctype>
#include <string>

#include "addressbookclass.h"

AddressBook::AddressBook()
{
    AddressBook::filename = std::string(DEFAULTFILENAME);
}

AddressBook::AddressBook(std::string filename)
{
    AddressBook::filename = filename;
}

void AddressBook::show()
{
    int number = 1;

    if (addressbook.size()==0)
    {
        std::cout << "Empty !" << std::endl;
    }

    for(std::vector<AddressBookEntry>::iterator   it = addressbook.begin(); it != addressbook.end();it++ )
    {
        AddressBookEntry entry = *it;

        std::cout << "Entry #" << number++ << ":" << entry.toString() << std::endl;
    }
}

size_t AddressBook::findEntry(AddressBookEntry ad)
{
    size_t number = 1;
    for(std::vector<AddressBookEntry>::iterator   it = addressbook.begin(); it != addressbook.end();it++ )
    {
        AddressBookEntry entry = *it;

        // == is overleaded for AddressBookEntry
        if (entry == ad)
        {
            return number;
        }

        number++;
    }
}

void AddressBook::load()
{
    // It could be more easily implemented using SO based functions.  It maybe a parameter to create it if it does not exist.
    std::ifstream ifpeek(filename, std::ios_base::binary);

    // Check if file exists and create it if it does not.
    if (!ifpeek.is_open())
    {
        ifpeek.close();
        std::ofstream so(filename, std::ios_base::binary);
        so.close();
    } else {
        ifpeek.close();
    }

   std::ifstream ifs(filename, std::ios_base::binary);

   AddressBookEntry ad;
   std::string code;
   ifs >> code;

    while (!ifs.eof())
    {
        ad.deserialize(code);

        addressbook.push_back(ad);

        AddressBookEntry ad;
        ifs >> code;

    }

    ifs.close();
}

void AddressBook::save()
{
    std::ofstream so(filename, std::ios_base::binary);

    for (const auto &e : addressbook) so << e.serialize() << std::endl;

    so.close();
}

void AddressBook::add(AddressBookEntry ad)
{
    addressbook.push_back(ad);
}

void AddressBook::remove(size_t entry)
{
    // @FIXME Check boundaries.

    if (entry>addressbook.size())
        addressbook.erase(addressbook.begin()+entry-1);
}

void AddressBook::sort(int sorttype)
{
    //This is the function signature: bool myfunction (int i,int j) { return (i<j); }

    auto lambda = [sorttype](AddressBookEntry a, AddressBookEntry b) ->bool {
        return (a.comp(sorttype)<b.comp(sorttype));
    };


    std::sort (addressbook.begin(), addressbook.end(), lambda);

}

std::string toLower(std::string input)
{
    std::transform(input.begin(), input.end(), input.begin(),
        [](unsigned char c){ return std::tolower(c); });

    return input;
}

std::vector<AddressBookEntry>::iterator  AddressBook::search(std::string searchkey)
{

    auto lambda = [](AddressBookEntry entry, AddressBookEntry searchkey) ->bool {

        std::string name = toLower(searchkey.GetName());

        std::string lastname = toLower(searchkey.GetLastName());


        std::string entryname = toLower(entry.GetName());
        std::string entrylastname = toLower(entry.GetLastName());

        // Force the comparision to only accept it if it is located at the beginning of the entry.
        return (    (name.length() > 0 && entryname.find(name)             != std::string::npos && entryname[0] == name[0])    ||
                    (lastname.length() > 0 && entrylastname.find(lastname)  != std::string::npos && entrylastname[0] == lastname[0])    );
    };

    AddressBookEntry ab;
    ab.deserialize(searchkey);

    AddressBookEntry a[] = {ab};

    std::vector<AddressBookEntry>::iterator it;
    it = std::search (addressbook.begin(), addressbook.end(), a,a+1,lambda);

    return it;
}

std::vector<AddressBookEntry>::iterator AddressBook::end()
{
    return addressbook.end();
}


std::vector<AddressBookEntry>::iterator AddressBook::begin()
{
    return addressbook.begin();
}


AddressBookEntry AddressBook::operator[](size_t pos) {
    if (pos>=addressbook.size()) return AddressBookEntry();

    return addressbook[pos];
}

