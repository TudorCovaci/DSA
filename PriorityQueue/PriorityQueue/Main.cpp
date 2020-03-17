#include "ShortTest.h"
#include "ExtendedTest.h"
#include "PriorityQueue.h"
#include <assert.h>

void testSearch()
{
    
    PriorityQueue pq(rel2);
    for (int i = 0;i < 10;i++)
        pq.push(i,i);
    assert(pq.search(0) == true);
    assert(pq.search(10) == false);

}
int main()
{
    //testAll();
    testAllExtended();
    testSearch();
    return 0;
}