//#include <assert.h>
//#include <exception>
//#include "Node.h"
//#include "IndexedList.h"
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
//void testNode()
//{
//    Node newNode1(0);
//    assert(newNode1.value() == -1);
//    assert(newNode1.next() == nullptr);
//    Node newNode2(1,10);
//    assert(newNode2.value() == 10);
//    assert(newNode2.next() == nullptr);
//    newNode2.setNext(&newNode1);
//    assert(newNode2.next() == &newNode1);
//}
//void testIndexedList()
//{
//    IndexedList list = IndexedList();
//    assert(list.isEmpty());
//    assert(list.head() != nullptr);
//    assert(list.size() == 0);
//    assert(list.addToPosition(0, 1) == 0);
//    assert(list.size() == 1);
//    assert(list.getElement(0) == 1);
//    assert(list.addToEnd(2) == 0);
//    assert(list.size() == 2);
//    assert(list.getElement(1) == 2);
//    assert(list.setElement(0, 3) == 0);
//    assert(list.getElement(0) == 3);
//    assert(list.search(2) == 1);
//    assert(list.search(1) == -1);
//    assert(list.remove(0) == 0);
//    assert(list.size() == 1);
//    assert(list.search(3) == -1);
//    assert(list.remove(0) == 0);
//    assert(list.size() == 0);
//    assert(list.search(2) == -1);
//
//    
//}
////int main()
////{
////    testNode();
////    testIndexedList();
////    _CrtDumpMemoryLeaks();
////    return 0;
////}