#include "Map.h"
#include "Test.h"
void testOperation()
{
	Map m1;
	Map m2;
	for (int i = 1; i < 10; i++)
		m1.add(i, i);
	for (int i = 5; i < 15; i++)
		m2.add(i, i);
	int result = m1.addIfNotPresent(m2);
	std::cout << "Number of added pairs: " << result;
}