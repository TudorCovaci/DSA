#include "DAIterator.h"
#include <exception>
#include <stdlib.h>
using namespace std;
DAIterator::DAIterator(const DynamicArray* Array)
{
    DynArr = Array;
    Current = 0;
}
TElem DAIterator::getCurrent()
{
    if (Current >= DynArr->size())
    {
        throw exception("Index out of range!");
    }
    return DynArr->getElement(Current);
}
void DAIterator::next()
{
    if (Current >= DynArr->size())
    {
        throw exception("Index out of range!");
    }
    Current++;
}
bool DAIterator::valid()
{
    return Current < DynArr->size();
}
void DAIterator::first()
{
    Current = 0;
}
DAIterator::~DAIterator()
{
    DynArr = NULL;
    Current = 0;
}
