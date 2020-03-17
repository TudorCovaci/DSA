#pragma once
#include <iostream>


#define NULL_TVALUE -1
#define DELETED INT_MAX
typedef int TKey;

typedef int TValue;



typedef std::pair<TKey, TValue> TElem;



class MapIterator;

class Map {
	friend class MapIterator;
private:

	// representation of Map
	TElem* elements;
	int n;
	int m; // should be power of 2
	double c1;
	double c2;
	double loadFactor;
	int hashKey(TKey key) const;
	int hash(TKey key, int i) const;
	void resize();


public:



	// implicit constructor
	//Theta(m)
	Map();



	// adds a pair (key,value) to the map

	//if the key already exists in the map, then the value associated to the key is replaced by the new value and the old value is returned

	//if the key does not exist, a new pair is added and the value null is returned
	//O(m)
	TValue add(TKey c, TValue v);



	//searches for the key and returns the value associated with the key if the map contains the key or null: NULL_TVALUE otherwise
	//O(m)
	TValue search(TKey c) const;



	//removes a key from the map and returns the value associated with the key if the key existed ot null: NULL_TVALUE otherwise
	//O(m)
	TValue remove(TKey c);



	//returns the number of pairs (key,value) from the map
	//Theta(1)
	int size() const;



	//checks whether the map is empty or not
	//Theta(1)
	bool isEmpty() const;



	//returns an iterator for the map
	//Theta(1)
	MapIterator iterator() const;

	//adds all pairs from the given Map, whose key is not in the Map already
	//returns the number of pairs that were added
	//O(m)
	int addIfNotPresent(Map& m);

	// destructor
	//Theta(1)
	~Map();


};


#include "MapIterator.h"



