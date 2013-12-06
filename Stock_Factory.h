/*
 * StockFactory.h
 *
 *  Created on: Nov 30, 2013
 *      Author: minhuigu
 */

#ifndef STOCKFACTORY_H_
#define STOCKFACTORY_H_
#include <string>
#include <iostream>
#include "MetaData.h"
#include "Stock_Concrete.h"

using namespace std;


class StockFactory
{
public:
	StockFactory(void){};
	~StockFactory(void){};
	StockFactory(StockFactory const&){};
	static StockFactory* Instance();
	StockInfo *create_stock(int choice, int lines,string name);


};


#endif /* STOCKFACTORY_H_ */
