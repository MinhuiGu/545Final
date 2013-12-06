/*
 * Buy_Sell.h
 *
 *  Created on: Nov 30, 2013
 *      Author: minhuigu
 */

#ifndef BUY_SELL_H_
#define BUY_SELL_H_
#define FEE 0.005
#define YES 1
#define NO 0
#include "pairs.h"

class Buy_Sell
{
public:
	Buy_Sell(int money){ fee=FEE; cash=money; BUY=NO; SELL=NO; share1=0; share2=0;}

	void decide(string date,long double score, signals scores,double p1,double p2,double beta[2]);
	void buy(){}
	void sell(){}
	double get_cash(){return cash;}

private:
	int BUY;
	int SELL;
	int share1;
	int share2;
	double cash;
	double fee;
};

#endif /* BUY_SELL_H_ */
