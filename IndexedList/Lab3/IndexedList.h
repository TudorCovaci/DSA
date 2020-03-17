#pragma once

#include "Node.h"

class ListIterator;
#include "ListIterator.h"

typedef int TElem;

class IndexedList
{
private:
    //representation of the IndexedList
    Node* head_;
    int size_;
    Node* findNodeByIndex(int index);

public:


    // returns the head of the list
    
    //Complexity: Theta(1);

    Node* head();
    

    // constructor
    
    //Complexity: Theta(1);

    IndexedList();


    // checks if the list is empty
    
    //Complexity: Theta(1);

    bool isEmpty() const;

    
    // returns the number of elements from the list
    
    //Complexity: Theta(1);

    int size() const;


    // adds an element to a given position

    //throws an exception if the position is not valid
    
    //Complexity: O(size_)

    void addToPosition(int pos, TElem e);


    // searches for an element and returns the first position where the element appears or -1 if the element is not in the list
    
    //Complexity: O(size_)

    int search(TElem e)  const;


    // modiifes an element from agiven position

    //returns the old value from the position

    //throws an exception if the position is not valid

    //Complexity: O(size_)

    TElem setElement(int pos, TElem e);


    // returns an element from a position

    //throws exception if the position is not valid

    //Complexity: O(size_)

    TElem getElement(int pos) const;


    // removes an element from a given position

    //returns the removed element

    //throws an exception if the position is not valid

    //Complexity: O(size_)

    TElem remove(int pos);


    // adds an element to the end of the list

    //Complexity: O(size_)

    void addToEnd(TElem e);


    // returns an iterator set to the first element of the list or invalid if the list is empty
    
    //Complexity: Theta(1);

    ListIterator iterator() const;

};
