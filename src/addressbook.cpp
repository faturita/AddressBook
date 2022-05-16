#include <stdio.h>
#include <string.h>

#include <vector>
#include <mutex>
#include <unordered_map>

#include <iostream>
#include <fstream>
#include <regex>

#include "commandline.h"



// Starting time 00:32


class AddressBookEntry
{
    std::string Name;
    std::string LastName;
    std::string phoneNumber;

public:
    AddressBookEntry()
    {

    }

    AddressBookEntry(std::string name, std::string lastname, std::string phone)
    {
        AddressBookEntry::Name = name;
        AddressBookEntry::LastName = lastname;
        AddressBookEntry::phoneNumber = phone;
    }

    std::string toString() const
    {
        std::string str;
        str.append("Name:").append(Name).append("/").append(LastName);
        str.append("(").append(phoneNumber).append(")");
        return str;
    }

    std::string serialize() const
    {
        std::string str;
        str.append(Name).append("/").append(LastName).append("/").append(phoneNumber).append("/");
        return str;
    }

    void deserialize(std::string code)
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

        for (const auto &e : tokens) std::cout << e  << std::endl;
    }


};


std::vector<AddressBookEntry> addressbook;

int main(int argc, char *argv[])
{
    char *param;

    // # Code each one of the CRUD methods here.

    if (isPresentCommandLineParameter(argc,argv,"-add"))
    {
        std::string name(getCommandLineParameter(argc,argv,"-name"));
        std::string lastname(getCommandLineParameter(argc,argv,"-last"));
        std::string phone(getCommandLineParameter(argc,argv,"-phone"));

        AddressBookEntry ad(name, lastname, phone);
        addressbook.push_back(ad);

    }


    std::ifstream ss("addressbook.w", std::ios_base::binary);

    AddressBookEntry ad;
    std::string code;
    ss >> code;

    std::cout << code << std::endl;

    ad.deserialize(code);


    AddressBookEntry ad2("Peter","Karl","074454332");

    addressbook.push_back( ad2 );

    for(std::vector<AddressBookEntry>::iterator   it = addressbook.begin(); it != addressbook.end();it++ )
    {
        AddressBookEntry entry = *it;

        std::cout << entry.toString() << std::endl;
    }


    std::ofstream so("addressbook.w", std::ios_base::binary);

    for (const auto &e : addressbook) so << e.serialize() << std::endl;


    return 0;

}
