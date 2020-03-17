#pragma once

class IndexedList;
#include "IndexedList.h"
class ListIterator
{
private:
    const IndexedList* list_;
    int currentPosition_;
public:
    ListIterator(const IndexedList*);
    void first();
    bool valid();
    void next();
    int getCurrent();

};
