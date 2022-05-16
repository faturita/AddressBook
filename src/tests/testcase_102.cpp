#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../addressbookclass.h"

#include "testcase_102.h"

TestCase_102::TestCase_102()
{
    // Use me to setup any extra initialization for the test itself.
    addressbook = AddressBook(std::string("testcase102.w"));
}

void TestCase_102::init()
{
    AddressBookEntry ad;
    ad.deserialize(std::string("Clark/Gable/0777636"));
    addressbook.add(ad);
}

int TestCase_102::check(unsigned long timertick)
{

    if (timertick > 400)
    {
        addressbook.show();


        for(std::vector<AddressBookEntry>::iterator   it = addressbook.begin(); it != addressbook.end();it++ )
        {
            AddressBookEntry entry = *it;

            if (entry.GetLastName() == std::string("Gable") && entry.GetName() == std::string("Clark"))
                haspassed = true;

        }
        isdone = true;
        message = std::string("No data is stored in the addressbook.");
    }


    if (timertick > 1000)
    {
        isdone = true;
        haspassed = false;
        message = std::string("The timeout has occurred and nothing happened.");
    }


    return 0;
}

int TestCase_102::number()
{
    return 102;

}

std::string TestCase_102::title()
{
    return std::string("Add data and check if it is there.");
}


// -----------
TestCase *pickTestCase(int testcase)
{
    return new TestCase_102();
}

