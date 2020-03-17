#include "ListIterator.h"
#include <exception>
ListIterator::ListIterator(const IndexedList* List)
{
    list_ = List;
    currentPosition_ = 0;
}
void ListIterator::first()
{
    currentPosition_ = 0;
}
bool ListIterator::valid()
{
    return currentPosition_ < list_->size();
}
void ListIterator::next()
{
    if (!valid())
        throw std::exception();
    currentPosition_++;
}
int ListIterator::getCurrent()
{
    if (!valid())
        throw std::exception();
    return list_->getElement(currentPosition_);
}