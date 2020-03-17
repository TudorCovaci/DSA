//#include "DynamicArray.h"
//#include "DAIterator.h"
//#include <stdlib.h>
//#include <exception>
//#include <assert.h>
//#include <stdio.h>
//
//int main()
//{
//    DynamicArray da(10);
//    DAIterator it = da.iterator();
//    for (int i = 0; i < 10; i++)
//    {
//        da.addToEnd(i);
//        assert(it.getCurrent() == i);
//        it.next();
//        assert(da.size() == i + 1);
//    }
//    da.removeBetween(0, 5);
//    assert(da.size() == 4);
//    it.first();
//    for (int i = 0; i < da.size(); i++)
//    {
//        printf("%d ", it.getCurrent());
//        it.next();
//    }
//
//
//}