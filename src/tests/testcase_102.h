#ifndef TESTCASE_102_H
#define TESTCASE_102_H

#include "../addressbookclass.h"
#include "testcase.h"


class TestCase_102 : public TestCase
{
private:
    AddressBook addressbook;
public:
    TestCase_102();
    void init();
    int check(unsigned long timertick);
    std::string title();
    int number();
};

#endif // TESTCASE_102_H
