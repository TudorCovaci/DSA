#include "DynamicArray.h"
#include <stdlib.h>
#include <exception>
#include "DAIterator.h"
using namespace std;
DynamicArray :: DynamicArray(int capacity)
{
    if (capacity <= 0)
        throw exception("Invalid Position!");
    Capacity = capacity;
    Length = 0;
    Elements = (TElem*)::operator new(sizeof(TElem)*capacity);
}
int DynamicArray::size() const
{
    return Length;
}
TElem DynamicArray::getElement(int pos) const
{
    if (pos < 0 || pos > Length)
    {
        throw exception();
    }
    return Elements[pos];
}
TElem DynamicArray::setElement(int pos, TElem newElem)
{
    if (pos < 0 || pos > Length)
    {
        throw exception();
    }
    TElem oldElem = Elements[pos];
    Elements[pos] = newElem;
    return oldElem;
}
void DynamicArray::addToEnd(TElem newElem)
{   
    if (Capacity == Length)
    {
        Elements = (TElem*)realloc(Elements, 2 * Capacity * sizeof(TElem));
        Capacity *= 2;
    }
        
    Elements[Length++] = newElem;
}
void DynamicArray::addToPosition(int pos, TElem newElem)
{
    if (pos < 0 || pos > Length)
    {
        throw exception("Invalid position!");
    }
    if (Length == Capacity)
    {
        Elements = (TElem*)realloc(Elements, 2 * Capacity * sizeof(TElem));
        Capacity *= 2;
    }
    for (int i = Length-1; i >= pos; i--)
        Elements[i + 1] = Elements[i];
    Length++;
    Elements[pos] = newElem;
}
TElem DynamicArray::remove(int pos)
{
    if (pos < 0 || pos >= Length)
        throw exception("Invalid postion!");
    TElem remElem = Elements[pos];
    for (int i = pos; i < Length-1; i++)
        Elements[i] = Elements[i + 1];
    Length--;
    return remElem;
}
DAIterator DynamicArray::iterator() const
{
    
    return DAIterator(this);
}
DynamicArray::~DynamicArray()
{
    delete[] Elements;
}
void DynamicArray::removeBetween(int i, int j)
{
    if (i < 0 || i >= Length)
    {
        throw exception();
    }
    if (j < 0 || j >= Length || i > j)
    {
        throw exception();
    }
    int k = 0;
    for (int index = j+1; index < Length; index++)
    {
        Elements[i + k] = Elements[index];
        k++;
    }
    Length = Length - (j - i + 1);
}