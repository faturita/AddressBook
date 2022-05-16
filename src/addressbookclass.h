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
    std::string filename;
    std::vector<AddressBookEntry> addressbook;

public:
    AddressBook();
    AddressBook(std::string filename);

    void show();

    void load();

    void save();

    void add(AddressBookEntry ad);

    void remove(int entry);

    void sort(int sorttype);


    std::vector<AddressBookEntry>::iterator search(std::string searchkey);

    std::vector<AddressBookEntry>::iterator end();
    std::vector<AddressBookEntry>::iterator begin();

    AddressBookEntry operator[](size_t pos);

    int findEntry(AddressBookEntry ad);

};


#endif // ADDRESSBOOKCLASS_H
