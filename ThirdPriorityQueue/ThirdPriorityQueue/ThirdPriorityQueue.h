//
// Created by Tudor on 5/7/2019.
//
#pragma once

#include <iostream>

typedef int TElem;
typedef int TPriority;
typedef std::pair<TElem, TPriority> Element;
typedef bool (*Relation)(TPriority p1, TPriority p2);

class ThirdPriorityQueue {
private:
  //representation of the ThirdPriorityQueue
  int cap_;
  int size_;
  Element *elem_;
  Relation relation_;

public:
  //implicit constructor
  ThirdPriorityQueue(Relation relation);

  //adds an element with a priority to the queue
  //Complexity: O(log(n))
  void push(TElem e, TPriority p);

  //return the element with the third highest priority with respect to the relation
  //throws exception if the queue has less than 3 elements
  //Complexity: Theta(1)
  Element top() const;

  //removes and returns the element with the third highest priority
  // throws exception if the queue has less than 3 elements
  //Complexity: O(log(n))
  Element pop();

  //checks if the queue has at most two elements
  //Complexity: Theta(1)
  bool atMostTwo() const;

  //destructor
  ~ThirdPriorityQueue();

  friend std::ostream &operator<<(std::ostream &, const ThirdPriorityQueue &);

private:
    //Complexity: Theta(n)
  void resize();

    //Complexity: O(log(n))
  void bubbleUp();

  //Complexity: O(log(n))
  void bubbleDown(int);

  //Complexity: Theta(1)
  int getTopPosition() const;
};
