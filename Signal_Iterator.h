/*
 * Signal_Iterator.h
 *
 *  Created on: Dec 5, 2013
 *      Author: minhuigu
 */

#ifndef SIGNAL_ITERATOR_H_
#define SIGNAL_ITERATOR_H_

#include "ISignal_Col.h"
#include <vector>
using namespace std;

class Signal_Iterator
{
public:
	Signal_Iterator(ISignal_Col * pool);

	bool delete_index( int index );
	vector<long double> get_positive_value_vector();
	vector<long double> get_negative_value_vector();
private:
	bool at_end();
	bool find_index(int index);
	void next();
	ISignal_Col * target;
	std::map<int,long double>::iterator current;
	int size;
};

#endif /* SIGNAL_ITERATOR_H_ */
