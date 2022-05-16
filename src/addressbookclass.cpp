#include "addressbookclass.h"

void AddressBook::show()
{
    int number = 1;
    for(std::vector<AddressBookEntry>::iterator   it = addressbook.begin(); it != addressbook.end();it++ )
    {
        AddressBookEntry entry = *it;

        std::cout << "Entry #" << number++ << ":" << entry.toString() << std::endl;
    }
}

void AddressBook::load()
{
    std::ifstream ifpeek("addressbook.w", std::ios_base::binary);

    if (!ifpeek.is_open())
    {
        ifpeek.close();
        std::ofstream so("addressbook.w", std::ios_base::binary);
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

void AddressBook::remove(int entry)
{
    // @FIXME Check boundaries.
    addressbook.erase(addressbook.begin()+entry-1);
}
