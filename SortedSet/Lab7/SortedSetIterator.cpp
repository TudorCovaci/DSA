#include "SortedSetIterator.h"

SortedSetIterator::SortedSetIterator(const SortedSet& set): set_(set)
{
	currentPosition_ = set_.getRoot();
	while (currentPosition_ != -1)
	{
		stack_.push(currentPosition_);
		currentPosition_ = set_.getElements()[currentPosition_].getLeftChild();
	}
	if (stack_.empty())
	{
		currentPosition_ = -1;
	}
	else
	{
		currentPosition_ = stack_.top();
	}
}
void SortedSetIterator::next()
{
	if (!valid())
		throw std::exception("Invalid iterator!");
	int currentNode = stack_.top();
	stack_.pop();
	if (set_.getElements()[currentNode].getRightChild() != -1)
	{
		currentNode = set_.getElements()[currentNode].getRightChild();
		while (currentNode != -1)
		{
			stack_.push(currentNode);
			currentNode = set_.getElements()[currentNode].getLeftChild();
		}
		
	}
	if (!stack_.empty())
	{
		currentPosition_ = stack_.top();
	}
	else
	{
		currentPosition_ = -1;
	}
}
bool SortedSetIterator::valid()
{
	return currentPosition_ != -1;
}
TElem SortedSetIterator::getCurrent() 
{
	if (!valid())
		throw std::exception();
	return set_.getElements()[currentPosition_].getInfo();
}
void SortedSetIterator::first()
{
	while (stack_.size() != 0)
		stack_.pop();
	int currentNode = set_.getRoot();
	while (currentNode != -1)
	{
		stack_.push(currentNode);
		currentNode = set_.getElements()[currentNode].getLeftChild();
	}
	if (stack_.empty())
	{
		currentPosition_ = -1;
	}
	else
		currentPosition_ = stack_.top();
}