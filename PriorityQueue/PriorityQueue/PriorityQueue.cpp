#include "PriorityQueue.h"
#include <exception>
PriorityQueue::PriorityQueue(Relation r)
{
    cap_ = 10;
    size_ = 0;
    head_ = 0;
    tail_ = 0;
    firstEmpty_ = 0;
    elements_ = new Element[cap_];
    next_ = new int[cap_];
    prev_ = new int[cap_];
    r_ = r;
    
    for (int i = 0;i < cap_;i++)
    {
        next_[i] = i + 1;
    }
    for (int i = 1;i < cap_;i++)
    {
        prev_[i] = i - 1;
    }
    next_[cap_ - 1] = -1;
    prev_[0] = -1;
}
PriorityQueue::~PriorityQueue()
{
    //delete[] elements_;
    //delete[] next_;
    //delete[] prev_;
}
void PriorityQueue::push(TElem e, TPriority p)
{
    
    if (size_ == cap_ || firstEmpty_ == -1)
    {
        resize();
    }
    int auxPosition = firstEmpty_;
    firstEmpty_ = next_[firstEmpty_];
    elements_[auxPosition].first = e;
    elements_[auxPosition].second = p;

    if (size_ == 0)
    {
        tail_ = head_ = auxPosition;
        size_++;
        return;
    }
    if (r_(p, elements_[tail_].second)) //after last
    {
        next_[tail_] = auxPosition;
        next_[auxPosition] = -1;
        prev_[auxPosition] = tail_;
        tail_ = auxPosition;
        size_++;
        return;
    }
    if (!r_(p, elements_[head_].second)) //before first
    {
        next_[auxPosition] = head_;
        prev_[auxPosition] = -1;
        prev_[head_] = auxPosition;
        head_ = auxPosition;
        size_++;
        return;
    }
    
    int currentPosition = head_;
    while (currentPosition != -1)
    {
        if (!r_(p, elements_[currentPosition].second))
        {
            next_[auxPosition] = currentPosition;
            prev_[auxPosition] = prev_[currentPosition];
            next_[prev_[currentPosition]] = auxPosition;
            prev_[currentPosition] = auxPosition;
            size_++;
            return;
        }
        currentPosition = next_[currentPosition];
    }
   
}
Element PriorityQueue::top() const
{
    if (size_ == 0)
        throw std::exception("Empty queue!");
    return elements_[tail_];
}
Element PriorityQueue::pop()
{
    if (size_ == 0)
        throw std::exception("Empty queue!");
    Element top = elements_[tail_];
    next_[prev_[tail_]] = -1;
    next_[tail_] = firstEmpty_;
    firstEmpty_ = tail_;
    tail_ = prev_[tail_];
    size_--;
    return top;
}
bool PriorityQueue::isEmpty() const
{
    return size_ == 0;
}
void PriorityQueue::resize()
{
    cap_ *= 2;
    auto tempElem = new Element[cap_];
    auto tempNext = new int[cap_];
    auto tempPrev = new int[cap_];
    for (int i = 0;i < size_;i++)
    {
        tempElem[i] = elements_[i];
        tempNext[i] = next_[i];
        tempPrev[i] = prev_[i];
    }
    for (int i = cap_/2;i < cap_;i++)
        tempNext[i] = i + 1;
    tempNext[cap_ - 1] = -1;
    delete[] elements_;
    delete[] next_;
    delete[] prev_;
    elements_ = tempElem;
    next_ = tempNext;
    prev_ = tempPrev;
    firstEmpty_ = cap_ / 2;
}
bool PriorityQueue::search(TElem elem) const
{
    int currentPosition = head_;
    while (currentPosition != -1)
    {
        if (elements_[currentPosition].first == elem)
        {
            return true;
        }
        currentPosition = next_[currentPosition];

    }
    return false;
}