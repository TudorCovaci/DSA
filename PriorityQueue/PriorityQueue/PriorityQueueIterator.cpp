#include "PriorityQueueIterator.h"
PriorityQueueIterator::PriorityQueueIterator(PriorityQueue& queue) :
    priorityQueue_(queue)
{
    
    currentPosition_ = queue.head_;
}
bool PriorityQueueIterator::valid()
{
    return currentPosition_ != -1;
}
void PriorityQueueIterator::next()
{
    if (currentPosition_ != -1)
        throw std::exception();
    currentPosition_ = priorityQueue_.next_[currentPosition_];
}
void PriorityQueueIterator::first()
{
    currentPosition_ = priorityQueue_.head_;
}
Element PriorityQueueIterator::getCurrent()
{
    return priorityQueue_.elements_[currentPosition_];
}