/*
 * StockFactory.cpp
 *
 *  Created on: Nov 30, 2013
 *      Author: minhuigu
 */

#include "Stock_Factory.h"

StockInfo * StockFactory::create_stock(int choice,int lines,string name)
{
  if (choice == 1)
    return new XLY(lines);
  else if (choice == 2)
    return new MCD(lines);
  /* other stock*/
  else
	  return new Normal_stock(name,lines);

};




