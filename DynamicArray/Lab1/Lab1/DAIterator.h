#pragma once
#ifndef ITERATOR
#define ITERATOR
#include "DynamicArray.h"
class DAIterator
{
private:

    int Current;
    const DynamicArray* DynArr;
public:
    //Constructor
    //Receives a dynamic array as parameter
    //Complexity: O(1)
    DAIterator(const DynamicArray*);

    //Returns the current element
    //Raises an exception if there are no more elements
    //Complexity: O(1)
    TElem getCurrent();

    //Goes to the next element
    //Complexity: O(1)
    void next();

    //Checks if the current element is valid
    //Raises an exception if not
    //Complexity: O(1)
    bool valid();

    //Goes to the first element
    //Complexity: O(1)
    void first();

    //Destructor
    //Complexity: O(1)
    ~DAIterator();


};
#endif