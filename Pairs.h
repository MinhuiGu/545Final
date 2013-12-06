/*
 * pairs.h
 *
 *  Created on: Nov 25, 2013
 *      Author: minhuigu
 */

#ifndef PAIRS_H_
#define PAIRS_H_

#include <string>
#include <map>
using namespace std;
#include "Stock_Concrete.h"
#include "Signal_Collection.h"


class signals
{
public:
	signals( double s1,double s2, double s3, double s4){s_bo=s1; s_sc=s2; s_so=s3; s_bc=s4;}
	void display() {cout<<s_bo<<" "<<s_sc<<" "<<s_so<<" "<<s_bc<<endl;}

	double s_bo;
	double s_sc;
	double s_so;
	double s_bc;
};

class Pairs
{
public:
	Pairs(string name1, string name2,int lines);
	~Pairs();
	void set_betas();
	void set_E();
	void liner_e();
	long double get_signal();

	void from_csv_update(int lines);
	void set_sigs();
	signals get_one_new_sigs();
	double s1_close();
	double s2_close();
	string get_date();

	double Beta[2];
	double Beta0[2];

private:
	StockInfo * S1;
	StockInfo * S2;

	double E[60];
	double E_e[59];
	long double signal;
	Signal_Pool Signals;
	int counter;
	map<int, signals> Signal_set_map;

};



#endif /* PAIRS_H_ */
