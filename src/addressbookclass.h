#include <stdio.h>
#include <string.h>

#include <vector>
#include <mutex>
#include <unordered_map>

#include <iostream>
#include <fstream>
#include <regex>

#include "commandline.h"
#include "addressbookentry.h"

#ifndef ADDRESSBOOKCLASS_H
#define ADDRESSBOOKCLASS_H

class AddressBook {
    const std::string filename = std::string("addressbook.w");
    std::vector<AddressBookEntry> addressbook;

public:
    void show();

    void load();

    void save();

    void add(AddressBookEntry ad);

    void remove(int entry);

    void sort(int sorttype);


    std::vector<AddressBookEntry>::iterator search(std::string searchkey);


    std::vector<AddressBookEntry>::iterator end();

};


#endif // ADDRESSBOOKCLASS_H
