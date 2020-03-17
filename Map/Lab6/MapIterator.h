#pragma once

#include "Map.h"
class MapIterator
{
private:
	const Map* map_;
	int currentPosition_;
	
public:
	MapIterator(const Map* map);
	bool valid();
	void next();
	TElem getCurrent();
	void first();
};