#pragma once

typedef int TElem;
class Node
{
private:
    TElem value_;
    Node* nextNode_;
    int index_;
public:
    Node(int index);
    Node(int, int);
    int setValue(int newValue);
    int setNext(Node* nextNode);
    int setIndex(int newIndex);
    int index();
    Node* next();
    int value();
   
};