#include "addressbookentry.h"

#include <stdio.h>
#include <string.h>

#include <vector>
#include <mutex>
#include <unordered_map>

#include <iostream>
#include <fstream>
#include <regex>

#include "commandline.h"


AddressBookEntry::AddressBookEntry()
{
    // We allow empty entries.
}

AddressBookEntry::AddressBookEntry(std::string name, std::string lastname, std::string phone)
{
    AddressBookEntry::Name = name;
    AddressBookEntry::LastName = lastname;
    AddressBookEntry::phoneNumber = phone;
}

std::string AddressBookEntry::toString() const
{
    std::string str;
    str.append("Name:").append(Name).append(DELIMITER).append(LastName);

    //@FIXME: phonenumber should be optional
    str.append("(").append(phoneNumber).append(")");
    return str;
}

std::string AddressBookEntry::serialize() const
{
    std::string str;
    str.append(Name).append(DELIMITER).append(LastName).append(DELIMITER).append(phoneNumber).append(DELIMITER);
    return str;
}

void AddressBookEntry::deserialize(std::string code)
{
    // @FIXME: Verify that name, lastname and phoneNumber do not contain any DELIMITER !!!
    std::string del(DELIMITER);
    std::vector<std::string> tokens;

    auto pos = code.find(del);
    while (pos != std::string::npos)
    {
        std::string str = code.substr(0, pos);
        code = code.substr(pos + del.length());
        pos = code.find(del);

        tokens.push_back(str);


    }

    Name = tokens[0];
    LastName = tokens[1];
    phoneNumber = tokens[2];

    // @NOTE: use me for debugging
    //for (const auto &e : tokens) std::cout << e  << std::endl;
}

std::string AddressBookEntry::comp(int sorttype)
{
    if (sorttype==NAMESORT)     return Name;
    else                        return LastName;

}


std::string AddressBookEntry::GetName()
{
    return Name;
}

std::string AddressBookEntry::GetLastName()
{
    return LastName;
}

bool AddressBookEntry::operator==(AddressBookEntry ad)
{
    // The phone number from two entries could be different but I am assumming the entry will be the same anyway.
    return (Name == ad.Name && LastName == ad.LastName);
}



