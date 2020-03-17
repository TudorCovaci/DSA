#pragma once

#include "Node.h"

typedef int TElem;

typedef TElem TComp;

class SortedSetIterator;


typedef bool(*Relation)(TComp, TComp);



class SortedSet {
	friend class SortedSetIterator;
private:

	Node* elements_;
	int firstEmpty_;
	int root_;
	int size_;
	int cap_;
	Relation r_;

	/*Representation of the SortedSet*/
	
public:

	//constructor
	//Theta(cap)
	SortedSet(Relation r);



	//adds an element to the sorted set

	//if the element was added, the operation returns true, otherwise (if the element was already in the set) 

	//it returns false
	//O(n)
	bool add(TComp e);

	//Theta(1)
	int getRoot() const { return root_; }
	//Theta(1)
	Node* getElements() const { return elements_; }
	//removes an element from the sorted set

	//if the element was removed, it returns true, otherwise false
	//O(n)
	bool remove(TComp e);



	//checks if an element is in the sorted set
	//
	bool search(TElem elem) const;





	//returns the number of elements from the sorted set

	int size() const { return size_; }



	//checks if the sorted set is empty

	bool isEmpty() const { return size_ == 0; }



	//returns an iterator for the sorted set

	SortedSetIterator iterator() const;

	//returns the difference between the maximum and the minimum element(assume integer values)
	//if the SortedSet is empty the range is -1
	int getRange() const;

	// destructor

	~SortedSet() { delete[] elements_; }



private:
	void resize();

};
