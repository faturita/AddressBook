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

// Starting time 00:32 -> 02:20
// 08:50


int main(int argc, char *argv[])
{

    AddressBook addressBook;

    addressBook.load();

    // # Code each one of the CRUD methods here.

    if (isPresentCommandLineParameter(argc,argv,"-add"))
    {
        std::string name(getCommandLineParameter(argc,argv,"-name"));
        std::string lastname(getCommandLineParameter(argc,argv,"-last"));
        std::string phone(getCommandLineParameter(argc,argv,"-phone"));

        AddressBookEntry ad(name, lastname, phone);

        addressBook.add(ad);

    }

    if (isPresentCommandLineParameter(argc,argv, "-remove"))
    {
        char *val = getCommandLineParameter(argc,argv,"-remove");
        int entry = atoi( val );

        addressBook.remove(entry);
    }

    if (isPresentCommandLineParameter(argc,argv,"-namesort"))
    {
        addressBook.sort(1);
    }
    if (isPresentCommandLineParameter(argc,argv,"-lastsort"))
    {
        addressBook.sort(2);
    }


    if (isPresentCommandLineParameter(argc,argv,"-search"))
    {
        std::string searchkey(getCommandLineParameter(argc,argv,"-search"));

        std::vector<AddressBookEntry>::iterator it = addressBook.search(searchkey);

        if (it != addressBook.end())
        {
            AddressBookEntry ad = *it;

            std::cout << "Found:" << ad.toString() << std::endl;
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
