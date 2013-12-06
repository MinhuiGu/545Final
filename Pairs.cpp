/*
 * Pairs.cpp
 *
 *  Created on: Nov 25, 2013
 *      Author: minhuigu
 */

#include "Pairs.h"
#include "Logger.h"
#include "Stock_Factory.h"
#include <math.h>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

#define XLY 1
#define MCD 2
#define OTHERS 3


Pairs :: Pairs(string name1, string name2,int lines)
{
	counter = 0;
	int error = 0;
	StockFactory fac;
	try{
		if (name1 == "XLY")
			S1 = fac.create_stock(XLY,lines,name1);
		else
			S1 = fac.create_stock(OTHERS,lines,name1);
	}
	catch(MyException& e){
		error = 1;
		e.print();
	}

	try{
		if (name2 == "MCD")
			S2 = fac.create_stock(MCD,lines,name2);
		else
			S1 = fac.create_stock(OTHERS,lines,name2);
	}
	catch(MyException& e){
		error = 1;
		e.print();
	}

	if (error == 1)
		throw MyException("pairs initial fail");

	set_betas();

	set_E();
	liner_e();
	Logger::Instance()->print("Pair initialed");

};


void Pairs :: from_csv_update(int lines)
{
	int i = 0;
	for(i =0 ; i<lines; i++) {
		try{
			S1->from_csv_update(1);
		}
		catch(MyException& e){
			e.print();
		}

		try{
			S2->from_csv_update(1);
		}
		catch(MyException& e){
			e.print();
		}

		set_betas();

		set_E();
		liner_e();
		set_sigs();
//		ostringstream convert;
//		convert << lines;
//		Logger::Instance()->print("file updated " + convert.str() + " lines");
	}
}

Pairs :: ~Pairs()
{
	delete S1;
	delete S2;
}

void Pairs :: set_betas()
{
	Beta[0] = Beta[1];
	Beta0[0] = Beta0[1];

	long double A=0,B=0,C=0,D=0,x,y;
	int i,n = 60;

	for(i=0;i<n;i++)
	{
		x = S1->get_data((S1->Counter-1-(60-i))%60).get_AdjReturn();
		y = S2->get_data((S2->Counter-1-(60-i))%60).get_AdjReturn();
		A += x;
		B += y;
		C += x*x;
		D += x*y;
	}

	Beta[1]=(n*D-A*B)/(n*C-A*A);
	Beta0[1]=(B-Beta[1]*A)/n;

}

void Pairs :: set_E()
{
	int i = 0;
	for (i=0; i<60; i++) {
		E[i] = S2->get_data((S2->Counter-1-(60-i))%60).get_AdjReturn() - Beta0[1] - Beta[1]*(S1->get_data((S1->Counter-1-(60-i))%60).get_AdjReturn());
	}
}

void Pairs :: liner_e()
{
	counter++;
	long double A=0,B=0,C=0,D=0,x,y;
	long double a,b,k,m;
	int i,n;
	n = 60;

	for(i=1;i<n;i++)
	{
		x = E[i-1];
		y = E[i];
		A += x;
		B += y;
		C += x*x;
		D += x*y;
	}
	b=((n-1)*D-A*B)/((n-1)*C-A*A);
	a=(B-b*A)/(n-1);

	k = -log(b) * 252;
	m = a/(1-b);

	A=0,B=0;
	for (i=1; i<60; i++) {
		E_e[i-1] = E[i] - a - b*E[i-1] ;
		A += E_e[i-1] * E_e[i-1];
		B += E_e[i-1];
	}

	double sigma,var;
	var = A/(n-1) - (B/(n-1))*(B/(n-1));
	sigma = sqrt(var/(1-b*b));
	signal = (E[59]-m)/sigma;

	Signals.addSignal( std::pair<int,long double>(counter,signal));

	if (Signals.size() > 120) {
		Signals.get_iter()->delete_index(counter-120);
	}
	//cout<<"counter:"<<counter<<" sig pool size:"<<Signals.size()<<endl;
}

long double Pairs :: get_signal()
{
	return signal;
}

void Pairs :: set_sigs()
{
	signals new_one= get_one_new_sigs();

	Signal_set_map.insert(std::pair<int,signals>(Signal_set_map.size()+1,new_one));
	//new_one.display();
}
double Pairs ::s1_close()
{
	return S1->get_price();
}

double Pairs ::s2_close()
{
	return S2->get_price();
}

string Pairs ::get_date()
{
	return S1->get_date();
}

signals Pairs :: get_one_new_sigs(){

	vector<long double> signal_pvec( Signals.get_iter()->get_positive_value_vector() );
	vector<long double> signal_nvec( Signals.get_iter()->get_negative_value_vector() );

	int i = 0,size1,size2;
	if (signal_pvec.size() < 5)
		size1 = 1;
	else
		size1 = signal_pvec.size()*0.2;
	if (signal_nvec.size() < 5)
		size2 = 1;
	else
		size2 = signal_nvec.size()*0.2;

	long double A=0,B=0,C=0,D=0;

	for (vector<long double>::iterator it=signal_pvec.begin(); it!=signal_pvec.end(); ++it) {
		i++;
		if (i<= size1) {
			A += *it;
		}
		if ( i>signal_pvec.size()-size1 ) {
			B += *it;
		}
	}

	A /=size1; // smaller positive
	B /=size1; // biger positive

	i = 0;
	for (vector<long double>::iterator it=signal_nvec.begin(); it!=signal_nvec.end(); ++it) {
		i++;
		if (i<= size2) {
			C += *it;
		}
		if ( i>signal_nvec.size()-size2 ) {
			D += *it;
		}
	}

	C /=size2; // smaller negative
	D /=size2; // larger negative

	signals sig(C,D,B,A);
	return sig;

}

