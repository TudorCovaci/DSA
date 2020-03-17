# -*- coding: utf-8 -*-
"""
Created on Tue Feb 19 15:48:58 2019

@author: Zsu
"""


class Bag:

    # creates a new, empty Bag
    def __init__(self):
        self.__elements = []
        self.__freq = []


    # adds a new element to the Bag
    def add(self, e):
        if e not in self.__elements:
            self.__elements.append(e)
            self.__freq.append(1)
        else:
            self.__freq[self.__elements.index(e)] +=1


    # removes one occurrence of an element from a Bag
    # returns True if an element was actually removed (the Bag contained the element e), or False if nothing was removed
    def remove(self, e):
        if e in self.__elements:
            self.__elements.remove(e)
            return True
        return False

    # searches for an element e in the Bag
    # returns True if the Bag contains the element, False otherwise
    def search(self, e):
        return e in self.__elements

    # counts and returns the number of times the element e appears in the bag
    def nrOccurrences(self, e):
        return self.__freq[self.__elements.index(e)]

    # returns the size of the Bag (the number of elements)
    def size(self):
        return len(self.__elements)

    # returns True if the Bag is empty, False otherwise
    def isEmpty(self):
        return self.size() == 0

    # returns a BagIterator for the Bag
    def iterator(self):
        return BagIterator(self)


class BagIterator:

    #creates an iterator for the Bag b, set to the first element of the bag, or invalid if the Bag is empty
    def __init__(self, b):
        if b.isEmpty():
            raise ValueError("Empty bag passed as parameter!")
        self.__bag = b
        self.__currentPosition = 0
        self.__currentFreqPosition = 0



    # returns True if the iterator is valid
    def valid(self):
        return self.__currentPosition < len(self.__bag.__elements)

    # returns the current element from the iterator.
    # throws ValueError if the iterator is not valid
    def getCurrent(self):
        if self.valid():
            return self.__bag.__elements[self.__currentPosition]
        raise ValueError("Iterator not valid!")

    # moves the iterator to the next element
    #throws ValueError if the iterator is not valid
    def next(self):
        if self.valid():
            self.__currentPosition+=1
        raise ValueError("Iterator not valid!")

    # sets the iterator to the first element from the Bag
    def first(self):
        self.__currentPosition = 0
