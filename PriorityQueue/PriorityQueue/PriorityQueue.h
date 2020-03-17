#pragma once
#include <iostream>
typedef int TElem;

typedef int TPriority;



typedef std::pair<TElem, TPriority> Element;



typedef bool(*Relation)(TPriority p1, TPriority p2);



class PriorityQueue {
    friend class PriorityQueueIterator;
private:

	//representation of PriorityQueue
    Element* elements_;
    int* next_;
    int* prev_;
    int head_;
    int tail_;
    int firstEmpty_;
    int cap_;
    int size_;
    Relation r_;


public:

	//implicit constructor

	PriorityQueue(Relation r);



	//adds an element with priority to the queue

	void push(TElem e, TPriority p);



	//returns the element with the highest priority with respect to the order relation

	//throws exception if the queue is empty

	Element top()  const;



	//removes and returns the element with the highest priority

	//throws exception if the queue is empty

	Element pop();



	//checks if the queue is empty

	bool isEmpty() const;

    //checks if elem is in the PriorityQueue or not
    bool search(TElem elem) const;

	//destructor

	~PriorityQueue();

private:
    void resize();

};