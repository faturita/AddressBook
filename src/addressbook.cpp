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

// Starting time 00:32

std::vector<AddressBookEntry> addressbook;

void show()
{
    int number = 1;
    for(std::vector<AddressBookEntry>::iterator   it = addressbook.begin(); it != addressbook.end();it++ )
    {
        AddressBookEntry entry = *it;

        std::cout << "Entry #" << number++ << ":" << entry.toString() << std::endl;
    }
}

int main(int argc, char *argv[])
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

   std::ifstream ifs("addressbook.w", std::ios_base::binary);

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

    show();

    // # Code each one of the CRUD methods here.

    if (isPresentCommandLineParameter(argc,argv,"-add"))
    {
        std::string name(getCommandLineParameter(argc,argv,"-name"));
        std::string lastname(getCommandLineParameter(argc,argv,"-last"));
        std::string phone(getCommandLineParameter(argc,argv,"-phone"));

        AddressBookEntry ad(name, lastname, phone);
        addressbook.push_back(ad);

    }

    show();


    std::ofstream so("addressbook.w", std::ios_base::binary);

    for (const auto &e : addressbook) so << e.serialize() << std::endl;

    so.close();


    return 0;

}
