//
// This is a base class to create unit tests.
//
// It is called from tester.cpp.
//
//
//
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "testcase.h"

TestCase::TestCase()
{

}

TestCase::~TestCase()
{

}

int TestCase::number()
{
    return 0;
}

void TestCase::init()
{

}

int TestCase::check(unsigned long timertick)
{
    return 0;
}
std::string TestCase::title()
{
    return std::string("Generic Test Case");

}

bool TestCase::done()
{
    return isdone;
}
bool TestCase::passed()
{
    return haspassed;
}
std::string TestCase::failedMessage()
{
    return message;
}
