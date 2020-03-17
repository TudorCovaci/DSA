#include "IndexedList.h"
#include <stdlib.h>
#include <exception>

IndexedList::IndexedList()
{
    size_ = 0;
    head_ = new Node(size_);
}
Node* IndexedList::head()
{
    return head_;
}
bool IndexedList::isEmpty() const
{
    return size_ == 0;
}
int IndexedList::size() const
{
    return size_;
}
TElem IndexedList::getElement(int index) const
{
    if (index >= size_)
        throw std::exception("Invalid index");
    Node* currentNode = head_;
    int i;
    for (i = 0; i < size_ && index != i; i++)
    {
        currentNode = currentNode->next();
    }
    if (index == i)
        return currentNode->value();
}
void IndexedList::addToPosition(int position, TElem value)
{
    if (position > size_)
        throw std::exception("Invalid position");
    Node* nodeToAdd = new Node(position,value);
    Node* auxNode = head_;
    Node* currentNode = head_;
    if (position == 0)
    {
        nodeToAdd->setNext(head_);
        nodeToAdd->setIndex(0);
        head_->setIndex(1);
        head_ = nodeToAdd;
        size_++;
        return;
    }
    for (int i = 0; i < size_ && i != position; i++)
    {
        auxNode = currentNode;
        currentNode = currentNode->next();
    }
    auxNode->setNext(nodeToAdd);
    if (position == size_)
        nodeToAdd->setNext(NULL);
    else nodeToAdd->setNext(currentNode);
    for (int i = position; i < size_; i++)
    {
        currentNode->setIndex(position + 1);
        currentNode = currentNode->next();
    }
    size_++;
    return;

}
void IndexedList::addToEnd(TElem value)
{
    addToPosition(size_, value);
}
Node* IndexedList::findNodeByIndex(int index)
{
    if (index >= size_ || index < 0)
        return nullptr;
    Node* currentNode = head_;
    for (int i = 0; i < size_ && i != index; i++)
        currentNode = currentNode->next();
    return currentNode;
}
TElem IndexedList::setElement(int index, TElem value)
{
    if (index >= size_ || index < 0)
        throw std::exception("Invalid index");
    Node* foundNode = findNodeByIndex(index);
    int oldValue = foundNode->value();
    foundNode->setValue(value);
    return oldValue;
}
int IndexedList::search(TElem value) const
{

    for (int i = 0; i < size_; i++)
    {
        if (getElement(i) == value)
            return i;
    }
    return -1;
}
TElem IndexedList::remove(int index)
{
    if (index >= size_ || index < 0)
        throw std::exception("Invalid index");
    Node* currentNode = head_;
    Node* prevNode = head_;
    int deletedValue = -1;
    if (index == 0)
    {
        head_ = head_->next();
        deletedValue = currentNode->value();
        delete currentNode;
        size_--;
        return deletedValue;
    }
    
    for (int i = 0; i < size_ && i != index; i++)
    {
        prevNode = currentNode;
        currentNode = currentNode->next();
    }
    prevNode->setNext(currentNode->next());
    deletedValue = currentNode->value();
    delete currentNode;
    currentNode = prevNode->next();
    
    size_--;
    return deletedValue;
}
ListIterator IndexedList::iterator() const
{
   return ListIterator(this); 
}