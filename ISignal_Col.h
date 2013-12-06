/*
 * ISignal_Col.h
 *
 *  Created on: Dec 5, 2013
 *      Author: minhuigu
 */

#ifndef ISIGNAL_COL_H_
#define ISIGNAL_COL_H_
#include <map>

class ISignal_Col
{

public:
	ISignal_Col(){};
	~ISignal_Col(){};
	void addSignal( std::pair<int,long double> pair) { signal_pool.insert(pair); }
	int size(){ return signal_pool.size();}


	std:: map<int, long double> signal_pool;
};



#endif /* ISIGNAL_COL_H_ */
