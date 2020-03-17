#include "Node.h"

Node::Node(int index)
{
    nextNode_ = nullptr;
    value_ = -1;
    index_ = index;
}
Node::Node(int index, int value)
{
    nextNode_ = nullptr;
    value_ = value;
    index_ = index;
}
int Node::setValue(int newValue)
{
    value_ = newValue;
    return value_;
}
int Node::setNext(Node* nextNode)
{
    nextNode_ = nextNode;
    return 0;
}
Node* Node::next()
{
    return nextNode_;
}
int Node::value() 
{
    return value_;
}
int Node::index()
{
    return index_;
}
int Node::setIndex(int newIndex)
{
    index_ = newIndex;
    return index_;
}