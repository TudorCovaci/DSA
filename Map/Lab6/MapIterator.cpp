#include "MapIterator.h"
MapIterator::MapIterator(const Map* map)
{
	map_ = map;
	for (int i = 0; i <= map->m; i++)
	{
		currentPosition_ = i;
		if (currentPosition_ == map->m)
			break;
		if (map_->elements[i].first != INT_MIN && map_->elements[i].first != DELETED)
		{
			break;
		}
	}
}
bool MapIterator::valid()
{
	return currentPosition_ < map_->m;
}
void MapIterator::first()
{
	for (int i = 0; i < map_->m; i++)
	{
		currentPosition_ = i;
		if (map_->elements[i].first != INT_MIN && map_->elements[i].first != DELETED)
		{
			
			break;
		}
	}
}
void MapIterator::next()
{
	if (!valid())
		throw std::exception("Invalid iterator!");
	currentPosition_++;
	while (currentPosition_ <= map_->m - 1 && (map_->elements[currentPosition_].first == INT_MIN || map_->elements[currentPosition_].first == DELETED))
	{
		currentPosition_++;
	}
}
TElem MapIterator::getCurrent()
{
	if(valid() == false)
		throw std::exception("Iterator not valid!");
	
	return map_->elements[currentPosition_];
}