/*
 * Buy_Sell.cpp
 *
 *  Created on: Nov 30, 2013
 *      Author: minhuigu
 */
#include "Buy_Sell.h"
#include <iostream>
#include <math.h>
using namespace std;

#define _DEBUG 1


void Buy_Sell:: decide(string date,long double score, signals scores,double p1,double p2,double beta[2])
{

#ifdef _DEBUG
	if (beta[1]>0.8 || beta[1] < 0) cout<<beta[1]<<endl;
#endif

	if (SELL || BUY){
		if (SELL) {
			if (score < scores.s_bc) {
				cash = share1*p1 +share2*p2 + cash - fee*(-share1+share2);
				share1 = 0;
				share2 = 0;
				SELL = NO;
			}
			else {
				if (beta[1] > beta[0]) {
					cash += floor ( (share1 * beta[1] +share2)/100 )*100*(p2+fee);
					share2 = floor( -share1*beta[1]/100)*100;
				}
				else {
					cash += floor( (share2/beta[1]+share1)/100)*100*(p1-fee);
					share1 = -floor(share2/beta[1]/100)*100;
				}
			}
		}
		if (BUY) {
			if (score > scores.s_sc) {
				cash = share1*p1 +share2*p2+cash-fee*(share1-share2);
				share1=0;
				share2=0;
				BUY = NO;
			}
			else {
				if (beta[1] > beta[0]) {
					cash += floor ( (share1 * beta[1] +share2)/100 )*100*(p2-fee);
					share2 = floor( -share1*beta[1]/100)*100;
				}
				else {
					cash += floor( (share2/beta[1]+share1)/100)*100*(p1+fee);
					share1 = -floor(share2/beta[1]/100)*100;
				}
			}
		}
	}

	else {
		if (score < scores.s_bo) {
			share1 = floor(0.7*cash/p1/100)*100;
			share2 = -floor(share1*beta[1]/100)*100;
			cash = -share1*p1-share2*p2+cash - fee*(share1-share2);
			BUY = YES;
		}
		else if (score > scores.s_so) {
			share2 = floor(0.7*cash/p2/100)*100;
			share1 = -floor(share2/beta[1]/100)*100;
			cash = -share1*p1-share2*p2+cash - fee*(-share1+share2);
			SELL = YES;
		}
	}
#ifdef _DEBUG
	cout<<date<<" wealth:"<<cash+share1*p1+share2*p2<<" share1: "<<share1<<" share2:"<<share2<<" cash:"<<cash<<endl;

#endif
}
