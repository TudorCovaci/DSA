#pragma once
#include <iostream>
#include "DynamicVector.h"
#include <queue>
typedef int TElem;
typedef int TPriority;
typedef std::pair<TElem, TPriority> Element;

class DLLANode
{
private:
	Element info_;
	int next_;
	int prev_;
public:
    DLLANode() { next_ = prev_ = -1; }
	Element& getInfo() { return info_; }
	int getNext() { return next_; }
	int getPrev() { return prev_; }
	void setNext(int newNext) { next_ = newNext; }
	void setPrev(int newPrev) { prev_ = newPrev; }
	void setInfo(Element newInfo) { info_ = newInfo; }
	
};
class DLLA
{
private:
    Element* elements_;
    int* next_;
    int *prev_;
	int cap_;
	int head_;
	int tail_;
    int size_;
	int firstEmpty_;
    
public:
	DLLA();
    ~DLLA();
	int allocate();
    void free(int position);
    void insertPosition(Element elem, int position);
    Element getElement(int position) { return nodes_[position].getInfo(); }
private:
    void resize();
};