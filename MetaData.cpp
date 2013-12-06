/*
 * MetaData.cpp
 *
 *  Created on: Nov 24, 2013
 *      Author: minhuigu
 */

#include "MetaData.h"

MetaData :: MetaData(double close, int volume) {
	Volume = volume;
	Close_price = close;

}
MetaData :: MetaData() {

}

MetaData :: ~MetaData() {

}

long double MetaData :: get_return() {
	return Daily_return;
}

void MetaData :: set_return(double Return) {
	Daily_return = Return;
}

void MetaData :: set_price(double price) {
	Close_price = price;
}

double MetaData:: get_price() {
	return Close_price;
}

void MetaData :: set_volume(int volume) {
	Volume = volume;
}

int MetaData :: get_volume() {
	return Volume;
}

void MetaData :: set_AdjReturn( double AReturn) {
	AjReturn = AReturn;
}

long double MetaData :: get_AdjReturn() {
	return AjReturn;
}
