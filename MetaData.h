/*
 * MetaData.h
 *
 *  Created on: Nov 25, 2013
 *      Author: minhuigu
 */

#ifndef METADATA_H_
#define METADATA_H_
#include <string>
using namespace std;

class MetaData
{
public:
		MetaData(double close, int volume);
		MetaData();
		~MetaData();
		void set_return(double Return);
		long double get_return();
		void set_price(double price);
		double get_price();
		void set_volume(int volume);
		int get_volume();
		void set_AdjReturn( double AReturn);
		long double get_AdjReturn();
		void set_date(string date) {Date = date; }
		string get_date(){return Date;}

private:
		int Volume;
		double Close_price;
		long double Daily_return;
		long double AjReturn;
		string Date;

};


#endif /* METADATA_H_ */
