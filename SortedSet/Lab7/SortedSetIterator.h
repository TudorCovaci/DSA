#pragma once
#include "SortedSet.h"

#include <stack>
class SortedSetIterator
{
	friend class SortedSet;
private:
	std::stack<int> stack_;
	const SortedSet& set_;
	int currentPosition_;
public:
	SortedSetIterator(const SortedSet& set);
	void first();
	TElem getCurrent();
	void next();
	bool valid();

};