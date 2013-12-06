/*
 * StockInfo.h
 *
 *  Created on: Nov 25, 2013
 *      Author: minhuigu
 */

#ifndef STOCKINFO_H_
#define STOCKINFO_H_

#include <string>
#include <iostream>
#include "MetaData.h"

using namespace std;

#define ROLLBACK 60

class StockInfo
{
public:
	StockInfo( string name, int lines);
	~StockInfo();
	void new_day_update(double price, int volume,string date);
	MetaData get_data(int index);
	void  from_csv_update(int lines);
	int Counter;
	double get_price();
	int get_volume();
	string get_date();

protected:
	string Name;
	int Controller;
	MetaData Days[ROLLBACK];

};

class MyException
{
private:
	string  msg;
public:
	MyException(string str){
		msg = str;
	};
	void print(){
		cout<<msg.c_str()<<endl;
	};

};


#endif /* STOCKINFO_H_ */
