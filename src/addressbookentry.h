#include <stdio.h>
#include <string.h>

#include <vector>
#include <mutex>
#include <unordered_map>

#include <iostream>
#include <fstream>
#include <regex>

#include "commandline.h"

#ifndef ADDRESSBOOKENTRY_H
#define ADDRESSBOOKENTRY_H


class AddressBookEntry
{
    std::string Name;
    std::string LastName;
    std::string phoneNumber;

public:
    AddressBookEntry();


    AddressBookEntry(std::string name, std::string lastname, std::string phone);


    std::string toString() const;


    std::string serialize() const;


    void deserialize(std::string code);


};

#endif // ADDRESSBOOKENTRY_H
