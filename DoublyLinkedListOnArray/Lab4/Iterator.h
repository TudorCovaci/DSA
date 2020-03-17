#pragma once
#include "DynamicVector.h"
template <typename T>
class Iterator
{
private:
    DynamicVector<T>* DynamicArray_;
    int currentPosition_;
public:
    Iterator(DynamicVector<T>*);
    Iterator() {}
    ~Iterator() {}
    bool valid();
    void first();
    T& operator++(int);
    T& operator*();
    
};

template <typename T>
Iterator<T>::Iterator(DynamicVector<T>* DynVector)
{
    DynamicArray_ = DynVector;
    currentPosition_ = 0;
}


template <typename T>
bool Iterator<T>::valid()
{
    return currentPosition_ < DynamicArray_->getSize();
}

template <typename T>
void Iterator<T>::first()
{
    currentPosition_ = 0;
}

template <typename T>
T& Iterator<T>::operator++(int Argument)
{
    T& temporaryElement = DynamicArray_->getElement(currentPosition_);
    currentPosition_++;
    return temporaryElement;
}

template <typename T>
T& Iterator<T>::operator*()
{
    if(valid())
        return DynamicArray_->getElement(currentPosition_);
}