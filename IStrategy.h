/*
 * IStrategy.h
 *
 *  Created on: Dec 5, 2013
 *      Author: senyang
 */
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stack>

using namespace std;
#ifndef ISTRATEGY_H_
#define ISTRATEGY_H_

class IStrategy {

public:
	virtual void process(string symbol)=0;
};

#endif /* ISTRATEGY_H_ */
