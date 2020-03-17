#include "Map.h"
#include <climits>
Map::Map()
{
	m = 16;
	n = 0;
	c1 = 0.5;
	c2 = 0.5;
	loadFactor = 0;
	elements = new TElem[m];
	for (int i = 0; i < m; i++)
	{
		std::pair<int, int> pair(INT_MIN, INT_MIN);
		elements[i] = pair;
	}

}
int Map::hashKey(TKey key) const
{
	int h = key % m;
	if (h < 0)
		return -h;
	return h;
}
int Map::hash(TKey key, int i) const
{
	int h = int((hashKey(key) + c1 * i + c2 * i * i)) % m;
	
	return h;
}
void Map::resize()
{
	m *= 2;
	TElem* auxArray = new TElem[m];
	for (int i = 0; i < m; i++)
	{
		std::pair<int, int> pair(INT_MIN, INT_MIN);
		auxArray[i] = pair;
	}
	for (int i = 0; i < m/2; i++)
	{
		if (elements[i].first == INT_MIN)
		{
			auxArray[i] = elements[i];
		}
		else
		{
			int j = 0;
			bool added = false;
			while (!added && j<m)
			{
				int h = hash(elements[i].first, j);
				if (auxArray[h].first == INT_MIN)
				{
					auxArray[h] = elements[i];
					added = true;
				}
				j++;
			}
		}
	}
	delete[] elements;
	elements = auxArray;
}
int Map::size() const
{
	return n;
}
bool Map::isEmpty() const
{
	return n == 0;
}
TValue Map::add(TKey c, TValue v)
{
	if (loadFactor >= 0.7)
		resize();
	int j = 0;
	
	bool added = false;
	while (!added)
	{
		int h = hash(c, j);
		if (elements[h].first == DELETED || elements[h].first == INT_MIN)
		{
			//std::cout << "Position: " << h << " Value: " << v << "\n";
			elements[h].first = c;
			elements[h].second = v;
			n++;
			loadFactor = n / m;
			added = true;
			return NULL_TVALUE;
		}
		
		else if (elements[h].first == c)
		{
			TValue oldVal = elements[h].second;
			//std::cout << "Position: " << h << " Value: " << v << "\n";
			elements[h].second = v;
			added = true;
			loadFactor = n / m;
			return oldVal;
		}
		j++;
	}
}
TValue Map::search(TKey c) const
{
	int j = 0;
	int startingPos = hash(c,j);
	if (elements[startingPos].first == c)
	{
		return elements[startingPos].second;
	}
	if (elements[startingPos].first == INT_MIN)
		return NULL_TVALUE;
	j++;
	int currentPos = hash(c, j);
	while (true)
	{
		if (elements[currentPos].first == c)
		{
			return elements[currentPos].second;
		}
		if (elements[currentPos].first == INT_MIN)
			return NULL_TVALUE;
		j++;
		currentPos = hash(c, j);
	}
	return NULL_TVALUE;

}
TValue Map::remove(TKey c)
{
	int j = 0;
	int startingPos = hash(c, j);
	if (elements[startingPos].first == c)
	{
		TValue val = elements[startingPos].second;
		elements[startingPos].first = DELETED;
		elements[startingPos].second = DELETED;
		n--;
		loadFactor = n / m;
		
		return val;
	}
	if (elements[startingPos].first == INT_MIN)
	{
		
		return NULL_TVALUE;
	}
	j++;
	int currentPos = hash(c, j);
	while (true)
	{
		if (elements[currentPos].first == c)
		{
			TValue val = elements[currentPos].second;
			elements[currentPos].first = DELETED;
			elements[currentPos].second = DELETED;
			n--;
			loadFactor = n / m;
			return val;
		}
		if (elements[currentPos].first == INT_MIN)
			return NULL_TVALUE;
		j++;
		currentPos = hash(c, j);
	}
	return NULL_TVALUE;
}
int Map::addIfNotPresent(Map& map)
{
	MapIterator iterator(&map);
	if (!iterator.valid())
		throw std::exception("Invalid map!\n");
	int pairsAdded = 0;
	while(iterator.valid())
	{
		if (loadFactor >= 0.7)
			resize();
		TKey key = iterator.getCurrent().first;
		TValue value = iterator.getCurrent().second;
		
			int j = 0;
			
			bool added = false;
			while (!added)
			{
				int h = hash(key, j);
				if (elements[h].first == key)
					break;
				if (elements[h].first == DELETED || elements[h].first == INT_MIN)
				{
					//std::cout << "Position: " << h << " Value: " << v << "\n";
					elements[h].first = key;
					elements[h].second = value;
					n++;
					loadFactor = n / m;
					added = true;
					pairsAdded++;
				}
				j++;
			}
			iterator.next();
			
	}
	return pairsAdded;
}
MapIterator Map::iterator() const
{
	
	return MapIterator(this);
}
Map::~Map()
{
	delete[] elements;
}