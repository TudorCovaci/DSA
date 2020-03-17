#pragma once
#include "PriorityQueue.h"
class PriorityQueueIterator
{
private:
    int currentPosition_;
    PriorityQueue& priorityQueue_;
public:
    PriorityQueueIterator(PriorityQueue&);
    bool valid();
    void next();
    void first();
    Element getCurrent();
};