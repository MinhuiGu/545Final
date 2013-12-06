/*
 * Signal_Collection.h
 *
 *  Created on: Dec 4, 2013
 *      Author: minhuigu
 */

#ifndef SIGNAL_COLLECTION_H_
#define SIGNAL_COLLECTION_H_

#include "ISignal_Col.h"
#include "Signal_Iterator.h"

class Signal_Pool: public ISignal_Col
{

public:
	Signal_Pool():ISignal_Col(){};
	~Signal_Pool(){};
	Signal_Iterator * get_iter() {
		Signal_Iterator *iter = new Signal_Iterator(this);
		return iter;
	}
};


#endif /* SIGNAL_COLLECTION_H_ */
