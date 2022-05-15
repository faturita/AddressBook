#include <stdio.h>
#include <string.h>

#include <vector>
#include <mutex>
#include <unordered_map>

#include <iostream>



// Starting time 00:32


class AddressBookEntry
{
    std::string Name;
    std::string LastName;
    std::string phoneNumber;

public:
    AddressBookEntry(std::string name, std::string lastname, std::string phone)
    {
        AddressBookEntry::Name = name;
        AddressBookEntry::LastName = lastname;
        AddressBookEntry::phoneNumber = phone;
    }

    std::string toString()
    {
        std::string str;
        str.append("Name:").append(Name).append("/").append(LastName);
        str.append("(").append(phoneNumber).append(")");
        return str;
    }


};


std::vector<AddressBookEntry> addressbook;

int main(int argc, char *argv[])
{

    AddressBookEntry ad("Peter","Karl","074454332");

    addressbook.push_back( ad );

    for(std::vector<AddressBookEntry>::iterator   it = addressbook.begin(); it != addressbook.end();it++ )
    {
        AddressBookEntry entry = *it;

        std::cout << entry.toString() << std::endl;
    }



    return 0;

}
