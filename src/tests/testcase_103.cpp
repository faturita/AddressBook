#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <thread>
#include <mutex>
#include <chrono>

#include "../addressbookclass.h"

#include "testcase_103.h"

int getRandomInteger(int min, int max)
{
    int val = (rand() % (max+1) + min);
    return val;
}

TestCase_103::TestCase_103()
{
    srand (time(NULL));
}


void TestCase_103::init()
{


}

std::mutex vector_mutex;

//
// This test, creates two threads and access a shared AddressBook.
// It guards the access to the the addressbox by using a mutex to avoid issues.
// The thread_safety of vector<> is tricky.  I have used it many times directly without problems
// (without any kind of semaphore) but sometimes for some particular applications you can have concurrency issues on
// race conditions.  The library itself provides basic thread-safety functionality, so extra care should be taken.
//
// This code creates two threads, access the same addressbook, creates an entry from one of them and delete it in the other.
//
// It should be extended to repeat this process many times to force more complex race conditions.
//

int TestCase_103::check(unsigned long timertick)
{

    AddressBook abook("testcase102.w");

    auto f1 = [](AddressBook* abook)  {

        std::this_thread::sleep_for(std::chrono::seconds(getRandomInteger(1,10)));

        std::lock_guard<std::mutex> guard(vector_mutex);

        AddressBookEntry ad;
        ad.deserialize(std::string("Jon/Doe/0778333"));
        abook->add(ad);

        std::cout << "Thread:" << ad.toString() << std::endl;


    };


    auto f2 = [](AddressBook* abook)  {


        std::this_thread::sleep_for(std::chrono::seconds(getRandomInteger(1,10)));
        std::lock_guard<std::mutex> guard(vector_mutex);

        AddressBookEntry ad;
        ad.deserialize(std::string("Charles/Dickens/000733"));
        abook->add(ad);

        std::cout << "Thread:" << ad.toString() << std::endl;

        std::vector<AddressBookEntry>::iterator it = abook->search("/Do/");

        ad = *it;

        std::cout << "Found entry:" << ad.toString() << std::endl;

        abook->remove(abook->findEntry(ad));

    };

    std::thread th1(f1, &abook);

    std::thread th2(f2, &abook);

    th1.join();
    th2.join();

    {
        abook.show();

        message = std::string("Couldn't find the data on the addressbook.");

        for(std::vector<AddressBookEntry>::iterator   it = abook.begin(); it != abook.end();it++ )
        {
            AddressBookEntry entry = *it;

            if (entry.GetLastName() == std::string("Doe") && entry.GetName() == std::string("Jon"))
            {
                haspassed = false;
            } else {
                haspassed = true;

            }

        }


    }

    isdone = true;


    return 0;
}

int TestCase_103::number()
{
    return 103;

}

std::string TestCase_103::title()
{
    return std::string("Add data concurrently, creating two threads and modifying what the other added.");
}


// -----------
TestCase *pickTestCase(int testcase)
{
    return new TestCase_103();
}

