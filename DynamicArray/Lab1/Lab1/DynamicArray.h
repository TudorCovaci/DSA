#pragma once


typedef int TElem;

class DAIterator;

class DynamicArray {



private:

    /*representation of Dynamic Array*/
    int Length;
    int Capacity;
    TElem* Elements;




public:



    //constructor

    //throws exception if capacity is 0 or negative
    
    //Complexity: Theta(1)
    DynamicArray(int capacity);



    //returns the size (number of elements) from the DynamicArray

    //Complexity: Theta(1)
    int size() const;



    //returns the element from a given position (indexing starts from 0)

    //throws exception if pos is not a valid position
    //Complexity: Theta(1)
    TElem getElement(int pos) const;



    //changes the element from a pozition to a different value

    //returns the old element from pozition poz

    //throws exception if pos is not a valid position
    //Complexity: Theta(1)
    TElem setElement(int pos, TElem newElem);



    //adds a new element to the end of the DynamicArray
    //Complexity: Theta(1)
    void addToEnd(TElem newElem);



    //adds a new element to a given position in a DynamicArray

    //throws exception if pos is not a valid position
    //Complexity: O(n)
    void addToPosition(int pos, TElem newElem);



    //removes an element from a given position

    //returns the removed element

    //throws exception if pos is not a valid position
    //Complexity: O(n)
    TElem remove(int pos);



    //returns an iterator for the DynamicArray
    //Complexity: Theta(1)
    DAIterator iterator() const;

    //removes all elements between two positions i and j
    //throws an exception if i or j is not valid
    //Complexity: O(n);
    void removeBetween(int i, int j);

    //destructor
    //Complexity: Theta(1)
    ~DynamicArray();

}; 
