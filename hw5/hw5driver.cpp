#include "hw5.h"
#include <iostream>
#include <list>
#include <vector>

int main(int argc, const char *argv[])
{
    hw5 a = hw5();
    a.read();
    a.findCycle();

    return 0;
}
