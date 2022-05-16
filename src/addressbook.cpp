//
//  addressbook.cpp
//  AddressBook
//
//  Basic commandline addressbook.   Nice as testbed to quickly test code or to check performance issues (or even for STEM education).
//
//
//  Time to completion: 4 hours and 20 minutes.
//
//
//  The main provides the access to the functionalities provided by the AddressBook class, based on command line parameters.  It can add new
//  records, list them, remove one by one, find a particular one based on partial matching for name or lastname.
//
//  The AddressBook class is based on vector<> template class from std14+.  At the end is just that and relies heavily on what the vector template
//  can do or not.  It is quite straightforward.
//
//  The idea is to load everything into memory, operate on a standard vector structure, and stores everything back to a file.
//  This way is not very efficient for a large number of records.  However, as it is like an in-memory database, it is very quick.
//  For large files, we start to move into the realm of databases so we need to use new approaches to deal with large registers.  We can start
//  by fixing each record to a fixed-length approach, create an index of the file, and move around based on the index.

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
#include "addressbookclass.h"


// The main read the default addressbook (the file is created if it does not exists) perform any operation on memory and store back the result.
int main(int argc, char *argv[])
{

    AddressBook addressBook;

    addressBook.load();

    // # Code each one of the CRUD methods here.

    if (isPresentCommandLineParameter(argc,argv,"-add") &&
            isPresentCommandLineParameter(argc,argv,"-name") &&
            isPresentCommandLineParameter(argc,argv,"-last") &&
            isPresentCommandLineParameter(argc,argv,"-phone"))
    {
        std::string name(getDefaultedCommandLineParameter(argc,argv,"-name",""));
        std::string lastname(getDefaultedCommandLineParameter(argc,argv,"-last",""));
        std::string phone(getDefaultedCommandLineParameter(argc,argv,"-phone",""));

        AddressBookEntry ad(name, lastname, phone);

        addressBook.add(ad);

        std::cout << "New entry added:" << ad.toString() << std::endl;

    }

    if (isPresentCommandLineParameter(argc,argv, "-remove"))
    {
        char *val = getCommandLineParameter(argc,argv,"-remove");
        int entry = atoi( val );

        addressBook.remove(entry);

        std::cout << "Entry Removed: " << entry << std::endl;
    }

    if (isPresentCommandLineParameter(argc,argv,"-namesort"))
    {
        addressBook.sort(NAMESORT);
        std::cout << "Sorted by Name." << std::endl;
    }
    if (isPresentCommandLineParameter(argc,argv,"-lastsort"))
    {
        addressBook.sort(LASTNAMESORT);
        std::cout << "Sored by Lastname." << std::endl;
    }


    if (isPresentCommandLineParameter(argc,argv,"-search"))
    {
        std::string searchkey(getCommandLineParameter(argc,argv,"-search"));

        std::vector<AddressBookEntry>::iterator it = addressBook.search(searchkey);

        if (it != addressBook.end())
        {
            for(; it != addressBook.end();it++ )
            {
                AddressBookEntry ad = *it;

                int entryNumber = addressBook.findEntry(ad);

                std::cout << "Found:" << ad.toString() << " at #" << entryNumber << std::endl;
            }

        }
        else
        {
            std::cout << "Element not found." << std::endl;
        }
    }


    addressBook.show();
    addressBook.save();


    return 0;

}
