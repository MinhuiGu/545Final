/*
 * Stock_Concrete.h
 *
 *  Created on: Dec 4, 2013
 *      Author: minhuigu
 */

#ifndef STOCK_CONCRETE_H_
#define STOCK_CONCRETE_H_

#include "Stock_Base.h"

class MCD: public StockInfo
{

public:
	MCD(int lines) : StockInfo("MCD",lines) {
	}
	string getname() {
		return "MCD";
	}
};

class XLY: public StockInfo
{
public:
	XLY(int lines): StockInfo("XLY",lines) {

	}
	string getname() {
		return "XLY";
	}
};

class Normal_stock: public StockInfo
{
public:
	Normal_stock( string name,int lines) :StockInfo (name,lines){

	}
	string getname() {
			return Name;
	}

};





#endif /* STOCK_CONCRETE_H_ */
