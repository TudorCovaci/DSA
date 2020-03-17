//
// Created by Tudor on 5/7/2019.
//

#include "ThirdPriorityQueue.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
int ThirdPriorityQueue::getTopPosition() const {
  int minChild = relation_(elem_[2].second, elem_[3].second) ? 2 : 3;
  int minChildBrother = 5 - minChild;
  int minGrandson;
  if (minChild * 2 > size_)
    return minChildBrother;
  if (minChild * 2 == size_) {
    minGrandson =
        relation_(elem_[minChildBrother].second, elem_[minChild * 2].second)
            ? minChildBrother
            : minChild * 2;
    return minGrandson;
  }
  if (minChild * 2 + 1 <= size_) {
    minGrandson =
        relation_(elem_[minChild * 2].second, elem_[minChild * 2 + 1].second)
            ? minChild * 2
            : minChild * 2 + 1;
    minGrandson =
        relation_(elem_[minGrandson].second, elem_[minChildBrother].second)
            ? minGrandson
            : minChildBrother;
    return minGrandson;
  }
  return -1;
}
Element ThirdPriorityQueue::top() const {
  if (this->atMostTwo()) {
    throw std::exception();
  }

  int topPosition = getTopPosition();
  return elem_[topPosition];
}

Element ThirdPriorityQueue::pop() {
  if (this->atMostTwo()) {
    throw std::exception();
  }

  int minChild = getTopPosition();

  auto retVal = this->elem_[minChild];

  this->elem_[minChild] = this->elem_[this->size_];

  this->size_ = this->size_ - 1;

  this->bubbleDown(minChild);

  return retVal;
}

void ThirdPriorityQueue::bubbleDown(int pos) {

  auto elem = this->elem_[pos];
  while (pos < this->size_) {
    int maxChild = -1;
    if (pos * 2 <= this->size_) { // left child
      maxChild = pos * 2;
    }
    if (pos * 2 + 1 <= this->size_ &&
        this->relation_(this->elem_[pos * 2 + 1].second,
                        this->elem_[pos * 2].second)) { // right child
      maxChild = pos * 2 + 1;
    }
    if (maxChild != -1 &&
        this->relation_(this->elem_[maxChild].second,
                        elem.second)) { // has a child and it checks out
      // swap
      auto aux = this->elem_[pos];
      this->elem_[pos] = this->elem_[maxChild];
      this->elem_[maxChild] = aux;

      pos = maxChild;

    } else {
      pos = this->size_ + 1;
    }
  }
}

ThirdPriorityQueue::ThirdPriorityQueue(Relation relation) {
  relation_ = relation;
  size_ = 0;
  cap_ = 1;
  elem_ = new Element[cap_];
}

ThirdPriorityQueue::~ThirdPriorityQueue() {
  size_ = 0;
  cap_ = 1;
  delete[] elem_;
}

bool ThirdPriorityQueue::atMostTwo() const { return size_ < 3; }

void ThirdPriorityQueue::resize() {
  cap_ = cap_ * 2;
  auto auxArray = new Element[cap_];
  for (int i = 1; i <= size_; i++)
    auxArray[i] = elem_[i];
  delete[] elem_;
  elem_ = auxArray;
}

void ThirdPriorityQueue::bubbleUp() {
  int auxPos = size_;
  Element auxElement = elem_[size_];
  int parent = size_ / 2;
  while (auxPos > 1 && relation_(auxElement.second, elem_[parent].second)) {
    elem_[auxPos] = elem_[parent];
    auxPos = parent;
    parent = auxPos / 2;
  }
  elem_[auxPos] = auxElement;
}

void ThirdPriorityQueue::push(TElem e, TPriority p) {

  if (size_ == cap_ - 1) {
    resize();
  }
  Element newPair(e, p);
  elem_[size_ + 1] = newPair;
  size_++;
  bubbleUp();
}

std::ostream &operator<<(std::ostream &osObject,
                         const ThirdPriorityQueue &tpq) {
  int char_width = 0;
  auto max = tpq.elem_[1].second;
  for (int i = 2; i <= tpq.size_; i++) {
    if (tpq.elem_[i].second > max) {
      max = tpq.elem_[i].second;
    }
  }
  auto aux = static_cast<unsigned int>(max) - 1;
  while (aux > 0) {
    aux = aux / 10;
    char_width = char_width + 1;
  }

  unsigned int spaces = 0;
  unsigned int layers = 0;

  auto auxx = static_cast<unsigned int>(tpq.size_);
  while (auxx > 0) {
    auxx = auxx >> 1u;
    layers = layers + 1;
  }

  spaces = (1u << (layers - 1)) - 1;
  for (auto currentLayer = 1u; currentLayer <= layers; currentLayer++) {
    osObject << std::string(spaces * char_width, ' ');
    unsigned int index = 1u << (currentLayer - 1);
    osObject << std::setw(char_width)
             << std::to_string(tpq.elem_[index].second); // first elem
    index++;
    unsigned int limit = std::min((1u << currentLayer) - 1,
                                  static_cast<unsigned int>(tpq.size_));
    while (index <= limit) {
      osObject << std::string(spaces * char_width, ' '); // spaces
      osObject << std::string(char_width, ' ');          // fake
      osObject << std::string(spaces * char_width, ' '); // spaces
      osObject << std::setw(char_width)
               << std::to_string(tpq.elem_[index].second);
      index++;
    }
    osObject << std::endl;
    spaces = spaces / 2;
  }

  return osObject;
}
