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

// Starting time 00:32 -> 02:20
// 08:50


class AddressBook {
    const std::string filename = std::string("addressbook.w");
    std::vector<AddressBookEntry> addressbook;

public:
    void show()
    {
        int number = 1;
        for(std::vector<AddressBookEntry>::iterator   it = addressbook.begin(); it != addressbook.end();it++ )
        {
            AddressBookEntry entry = *it;

            std::cout << "Entry #" << number++ << ":" << entry.toString() << std::endl;
        }
    }

    void load()
    {
        std::ifstream ifpeek("addressbook.w", std::ios_base::binary);

        if (!ifpeek.is_open())
        {
            ifpeek.close();
            std::ofstream so("addressbook.w", std::ios_base::binary);
            so.close();
        } else {
            ifpeek.close();
        }

       std::ifstream ifs(filename, std::ios_base::binary);

       AddressBookEntry ad;
       std::string code;
       ifs >> code;

        while (!ifs.eof())
        {
            ad.deserialize(code);

            addressbook.push_back(ad);

            AddressBookEntry ad;
            ifs >> code;

        }

        ifs.close();
    }

    void save()
    {
        std::ofstream so(filename, std::ios_base::binary);

        for (const auto &e : addressbook) so << e.serialize() << std::endl;

        so.close();
    }

    void add(AddressBookEntry ad)
    {
        addressbook.push_back(ad);
    }

    void remove(int entry)
    {
        // @FIXME Check boundaries.
        addressbook.erase(addressbook.begin()+entry-1);
    }

};





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

    addressBook.show();
    addressBook.save();


    return 0;

}
