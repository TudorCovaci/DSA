#include "Test.h"
#include <iostream>
#include "SortedSet.h"
#include <assert.h>
bool r3(TComp e1, TComp e2) {
	if (e1 <= e2) {
		return true;
	}
	else {
		return false;
	}
}


void testRange()
{
	SortedSet set(r3);
	set.add(12);
	set.add(15);
	set.add(-10);
	set.add(-100);
	set.add(100);
	assert(set.getRange() == 200);
}
