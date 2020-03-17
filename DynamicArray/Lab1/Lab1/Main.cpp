#define _CRTDBG_MAP_ALLOC
#include "ExtendedTest.h"
#include <iostream>
#include <crtdbg.h>

#include <stdlib.h>

using namespace std;
int main()
{

    testAllExtended();
    cout << "Success\n";
    _CrtDumpMemoryLeaks();
    return 0;
}