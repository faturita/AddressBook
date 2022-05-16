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
    str.append("Name:").append(Name).append("/").append(LastName);

    //@FIXME: phonenumber is optional
    str.append("(").append(phoneNumber).append(")");
    return str;
}

std::string AddressBookEntry::serialize() const
{
    std::string str;
    str.append(Name).append("/").append(LastName).append("/").append(phoneNumber).append("/");
    return str;
}

void AddressBookEntry::deserialize(std::string code)
{
    std::string del("/");
    std::vector<std::string> tokens;

    auto pos = code.find(del);
    while (pos != std::string::npos)
    {
        std::string str = code.substr(0, pos);
        code = code.substr(pos + del.length());
        pos = code.find("/");

        tokens.push_back(str);


    }

    Name = tokens[0];
    LastName = tokens[1];
    phoneNumber = tokens[2];

    //for (const auto &e : tokens) std::cout << e  << std::endl;
}
