#pragma once
template <typename T>
class DynamicVector
{
private:
    T* elements_;
    int size_;
    int capacity_;
	friend class DLLA;
public:

    //default constructor
    DynamicVector(int capacity = 100);

    //copy constructor
    DynamicVector(const DynamicVector& OriginalVector);
    ~DynamicVector();

    int add(const T& elementToAdd);
    int remove(int position);
    int find(T& elementToFind);
    int getSize() { return size_; }
    //T& getElement(int position) { return elements_[position]; }
    T& operator[](int position) { return elements_[position]; }
private:
    void resize();
};

template <typename T>
DynamicVector<T>::DynamicVector(int capacity)
{
    size_ = 0;
    capacity_ = capacity;
    elements_ = new T[capacity];
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector& OriginalVector)
{
    capacity_ = OriginalVector.getCapacity();
    size_ = OriginalVector.getSize();
    for (int index = 0; index < size_; index++)
        elements_[index] = OriginalVector[index];
}

template <typename T>
DynamicVector<T>::~DynamicVector()
{
    delete[] elements_;
}
template <typename T>
void DynamicVector<T>::resize()
{
    T* temporaryArray = new T[capacity_ * 2];
    for (int index = 0; index < size_; index++)
        temporaryArray[index] = elements_[index];
    delete[] elements_;
    capacity_ = capacity_ * 2;
    elements_ = temporaryArray;
}
template <typename T>
int DynamicVector<T>::add(const T& ElementToAdd)
{
    if (size_ == capacity_)
        resize();
    elements_[size_] = ElementToAdd;
    size_++;
    return 0;
}

template <typename T>
int DynamicVector<T>::remove(int position)
{
    elements_[position].~T();
    for (int index = position; index < size_ - 1 ; index++)
    {
        elements_[index] = elements_[index + 1];
    }
    size_ -= 1;
    return 0;
}
template <typename T>
int DynamicVector<T>::find(T& elementToFind)
{
    for (int index = 0; index < size_; index++)
        if (elements_[index] == elementToFind)
            return index;
    return -1;
}
