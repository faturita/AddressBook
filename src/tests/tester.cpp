#include <stdio.h>
#include "testcase.h"


// General code that executes the testcase.

TestCase *t = NULL;

long unsigned timer = 0;

void worldStep()
{
    timer++;

    long unsigned starttime = 200;

    if (timer == starttime)
    {
        std::cout << "Starting time:" << starttime << std::endl;
    }

    t->check(timer);

    if (t->done())
    {
        if (t->passed())
        {
            printf("Test Passed\n");
            exit(1);
        }
        else
        {
            std::cout << "Test Failed:" << t->failedMessage() << std::endl;

            exit(0);
        }
    }
}

int main(int argc, char *argv[])
{
    int testcase = 0;
    t = pickTestCase(testcase);

    t->init();

    while(true) {
        timer++;
        worldStep();
    }

}




