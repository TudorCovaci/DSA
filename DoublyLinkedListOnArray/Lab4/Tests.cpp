#include "Tests.h"
#include <assert.h>
#include <iostream>
void testDLLA()
{
    DLLA dlla;
    Element p1(1, 2);
    //assert(dlla.allocate() != -1);
    for (int i = 1;i < 101;i++)
    {

        dlla.insertPosition(Element(i, i+1), i);
        std::cout << dlla.getElement(i).first << " ";
        std::cout << dlla.getElement(i).second << "\n";
        assert(dlla.getElement(i).first == i);
        assert(dlla.getElement(i).second == i+1);
    }

    



}
int main()
{
    testDLLA();
	return 0;
}