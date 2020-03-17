#include "DLLA.h"
DLLA::DLLA()
{
	firstEmpty_ = 0;
    cap_ = 10;
	head_ = tail_ = 0;
    size_ = 0;
    elements_ = new Element[cap_];
    next_ = new int[cap_];
    prev_ = new int[cap_];
    for (int i = 0;i < cap_;i++)
        next_[i] = i + 1;
    next_[cap_ - 1] = -1;

 
}

DLLA::~DLLA()
{
    delete[] elements_;
}
void DLLA::resize()
{
    auto tempNodes = new DLLANode[2 * cap_ +1];
    cap_ *= 2;
    for (int i = 0;i < size_;i++)
    {
        tempNodes[i] = nodes_[i];
    }
    delete[] nodes_;
    nodes_ = tempNodes;
    firstEmpty_ = cap_;
    for (int i = cap_ / 2;i < cap_;i++)
    {
        emptyQueue.push(i);
    }
}
int DLLA::allocate()
{
    if (size_ == cap_)
    {
        return -1;
    }
    firstEmpty_ = emptyQueue.front();
    emptyQueue.pop();
	int newElem = firstEmpty_;
	if (newElem != -1)
	{
        firstEmpty_ = nodes_[firstEmpty_].getNext();
        if (firstEmpty_ != -1)
        {
            nodes_[firstEmpty_].setPrev(-1);
        }
        nodes_[newElem].setNext(-1);
        nodes_[newElem].setPrev(-1);
	}
    return newElem;
}
void DLLA::free(int position)
{
    nodes_[position].setNext(firstEmpty_);
    nodes_[position].setPrev(-1);
    if (firstEmpty_ != -1)
    {
        nodes_[firstEmpty_].setPrev(position);
    }
    emptyQueue.push(position);
    firstEmpty_ = position;
}
void DLLA::insertPosition(Element elem, int position)
{
    int newElem = allocate();
    if (newElem == -1)
    {
        resize();
        newElem = allocate();
    }
    nodes_[newElem].setInfo(elem);
    if (position == 1)
    {
        if (head_ == -1)
        {
            head_ = newElem;
            tail_ = newElem;
        }
        else
        {
            nodes_[newElem].setNext(head_);
            nodes_[head_].setPrev(newElem);
            head_ = newElem;

        }
    }
    else
    {
        int auxNode = head_;
        int auxPosition = 1;
        while (auxNode != -1 && auxPosition < position-1)
        {
            auxNode = nodes_[auxNode].getNext();
            auxPosition++;
        }
        if (auxNode != -1)
        {
            int nextNode = nodes_[auxNode].getNext();
            nodes_[newElem].setNext(nextNode);
            nodes_[newElem].setPrev(auxNode);
            nodes_[auxNode].setNext(newElem);
            if (nextNode != -1)
            {
                nodes_[nextNode].setPrev(newElem);
            }
            else
            {
                tail_ = newElem;
            }
        }
    }
    
    size_++;
}