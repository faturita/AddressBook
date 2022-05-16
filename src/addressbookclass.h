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

#define DEFAULTFILENAME "addressbook.w"

class AddressBook {
    std::string filename;
    std::vector<AddressBookEntry> addressbook;

public:
    AddressBook();
    AddressBook(std::string filename);

    // Show all the entries in the addressbook.
    void show();

    // Load the addressbook from file.
    void load();

    // Save the addressbook in memory to a file.
    void save();

    // Add a new record.
    void add(AddressBookEntry ad);

    // Remove one particular entry based on the EntryId.
    void remove(size_t entry);

    // Sort the addressbook, either by name (NAMESORT) or lastname (LASTNAMESORT)
    void sort(int sorttype);

    // Search for all the entries that matches the key 'searchkey' which is in this format NAME/LASTNAME/
    std::vector<AddressBookEntry>::iterator search(std::string searchkey);

    // Iterators
    std::vector<AddressBookEntry>::iterator end();
    std::vector<AddressBookEntry>::iterator begin();

    // Indexed access
    AddressBookEntry operator[](size_t pos);

    // Given an addressbook element, return the entryId.
    size_t findEntry(AddressBookEntry ad);

};


#endif // ADDRESSBOOKCLASS_H
