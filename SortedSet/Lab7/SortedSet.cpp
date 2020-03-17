#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <climits>
SortedSet::SortedSet(Relation r)
{
	r_ = r;
	cap_ = 10;
	size_ = 0;
	elements_ = new Node[cap_];
	firstEmpty_ = 0;
	root_ = -1;
	for (int i = 0; i < cap_ - 1; i++)
	{
		elements_[i].setLeftChild(i + 1);
	}
	elements_[cap_ - 1].setLeftChild(-1);



}
void SortedSet::resize()
{
	firstEmpty_ = cap_;
	cap_ *= 2;
	Node* auxElements = new Node[cap_];
	for (int i = 0; i < cap_ / 2; i++)
	{
		auxElements[i] = elements_[i];
	}
	for (int i = cap_ / 2; i < cap_ - 1; i++)
	{
		auxElements[i].setLeftChild(i + 1);
	}
	auxElements[cap_ - 1].setLeftChild(-1);
	delete[] elements_;
	elements_ = auxElements;
}
bool SortedSet::add(TComp e)
{
	int currentNode = root_;
	int prev = -1;
	if (size_ == cap_)
		resize();
	if (currentNode == -1)
	{
		Node newNode;
		newNode.setInfo(e);
		newNode.setLeftChild(-1);
		newNode.setRightChild(-1);
		int insertPosition = firstEmpty_;
		firstEmpty_ = elements_[firstEmpty_].getLeftChild();
		elements_[insertPosition] = newNode;
		root_ = insertPosition;
		size_++;
		return true;
	}
	while (currentNode != -1)
	{
		prev = currentNode;
		if (elements_[currentNode].getInfo() == e)
		{
			return false;
		}
		if (r_(e, elements_[currentNode].getInfo()))
		{
			currentNode = elements_[currentNode].getLeftChild();
		}
		else
		{
			currentNode = elements_[currentNode].getRightChild();
		}
	}
	
	Node newNode;
	newNode.setInfo(e);
	newNode.setLeftChild(-1);
	newNode.setRightChild(-1);
	int insertPosition = firstEmpty_;
	firstEmpty_ = elements_[firstEmpty_].getLeftChild();
	elements_[insertPosition] = newNode;
	if (r_(e, elements_[prev].getInfo()))
	{
		elements_[prev].setLeftChild(insertPosition);
	}
	else
	{
		elements_[prev].setRightChild(insertPosition);
	}
	size_++;
	
	return true;
}\
bool SortedSet::remove(TComp e)
{
	if (size_ == 0)
		return false;
	int currentNode = root_;
	int parent = -1;
	while (currentNode != -1 && elements_[currentNode].getInfo() != e)
	{
		parent = currentNode;
		if (r_(e, elements_[currentNode].getInfo()))
		{
			currentNode = elements_[currentNode].getLeftChild();
		}
		else
		{
			currentNode = elements_[currentNode].getRightChild();
		}
	}
	if (currentNode == -1)
	{
		return false;
	}
	if (elements_[currentNode].getLeftChild() == -1)
	{
		if (elements_[currentNode].getRightChild() == -1)
		{
			if (currentNode == root_)
			{
				root_ = -1;
			}
			else
			{
				if (r_(e, elements_[parent].getInfo()))
				{
					elements_[parent].setLeftChild(-1);
				}
				else
				{
					elements_[parent].setRightChild(-1);
				}
			}
		}

		else
		{
			if (currentNode == root_)
			{
				root_ = elements_[currentNode].getRightChild();
			}
			else
			{
				if (elements_[parent].getLeftChild() == currentNode)
				{
					elements_[parent].setLeftChild(elements_[currentNode].getRightChild());
				}
				else
				{
					elements_[parent].setRightChild(elements_[currentNode].getRightChild());
				}
			}
		}
		int firstEmpty = firstEmpty_;
		firstEmpty_ = currentNode;
		elements_[firstEmpty_].setLeftChild(firstEmpty);
		size_--;
		return true;
	}
	else
	{
		if (elements_[currentNode].getRightChild() == -1)
		{
			if (currentNode == root_)
			{
				root_ = elements_[currentNode].getLeftChild();
			}
			else
			{
				if (elements_[parent].getLeftChild() == currentNode)
				{
					elements_[parent].setLeftChild(elements_[currentNode].getLeftChild());
				}
				else
				{
					elements_[parent].setRightChild(elements_[currentNode].getLeftChild());
				}
			}
			int firstEmpty = firstEmpty_;
			firstEmpty_ = currentNode;
			elements_[firstEmpty_].setLeftChild(firstEmpty);
			size_--;
			return true;
		}
		else
		{
			int currentParent = currentNode;
			int position = elements_[currentNode].getRightChild();
			while (elements_[position].getLeftChild() != -1)
			{
				currentParent = position;
				position = elements_[position].getLeftChild();
			}
			elements_[currentNode].setInfo(elements_[position].getInfo());
			if (elements_[position].getRightChild() != -1)
			{
				elements_[currentParent].setLeftChild(elements_[position].getRightChild());
			}
			else
			{
				elements_[currentParent].setLeftChild(-1);
			}
			int firstEmpty = firstEmpty_;
			firstEmpty_ = position;
			elements_[firstEmpty_].setLeftChild(firstEmpty);
			size_--;
			return true;
		}
	}
	return false;
	
}
bool SortedSet::search(TElem elem) const
{
	int currentNode = root_;
	while (currentNode != -1 && elements_[currentNode].getInfo() != elem)
	{
		if (r_(elem, elements_[currentNode].getInfo()))
			currentNode = elements_[currentNode].getLeftChild();
		else currentNode = elements_[currentNode].getRightChild();
	}
	if (currentNode != -1)
		return true;
	return false;
}
SortedSetIterator SortedSet::iterator() const
{
	SortedSetIterator newIterator = SortedSetIterator(*this);
	return newIterator;
}
int SortedSet::getRange() const
{
	if (size_ == 0)
		return -1;
	if (size_ == 1)
		return root_;
	int min = INT_MAX, max = INT_MIN;
	int currentNode = root_;
	while (elements_[currentNode].getLeftChild() != -1)
	{
		currentNode = elements_[currentNode].getLeftChild();
	}
	min = elements_[currentNode].getInfo();
	currentNode = root_;
	while (elements_[currentNode].getRightChild() != -1)
	{
		currentNode = elements_[currentNode].getRightChild();
	}
	max = elements_[currentNode].getInfo();
	return max - min;
}