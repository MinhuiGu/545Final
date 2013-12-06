/*
 * Signal_Iterator.cpp
 *
 *  Created on: Dec 4, 2013
 *      Author: minhuigu
 */

#include "Signal_Collection.h"
#include <iostream>

bool mycmp (long double i,long double j) { return (i<j); }

Signal_Iterator :: Signal_Iterator( ISignal_Col * pool)
{
	target = pool;
	size = pool->size();
	current = pool->signal_pool.begin();
}

bool Signal_Iterator :: at_end()
{
	if (current == target->signal_pool.end()){
		return true;
	}
	else
		return false;
}

void Signal_Iterator :: next()
{
	current++;
}

bool Signal_Iterator :: find_index( int index )
{
	while (!at_end()) {
		if ( current->first == index )
			break;
		else
			next();
	}
	if (at_end())
		return false;
	return true;
}

bool Signal_Iterator :: delete_index( int index )
{
	if (find_index( index )) {
		target->signal_pool.erase(current);
		return true;
	}
	return false;
}
vector<long double> Signal_Iterator :: get_positive_value_vector() {
	vector<long double> pos;

	while(!at_end()) {
		if ((*current).second > 0)
			pos.push_back((*current).second);
		next();
	}

	sort(pos.begin(), pos.end(), mycmp);
	return pos;
}
vector<long double> Signal_Iterator :: get_negative_value_vector() {
	vector<long double> neg;
	while(!at_end()) {
		if ((*current).second < 0)
			neg.push_back((*current).second);
		next();
	}
	sort (neg.begin(), neg.end(), mycmp);
	return neg;
}


