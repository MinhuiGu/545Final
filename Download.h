/*
 * Download.h
 *
 *  Created on: Dec 5, 2013
 *      Author: senyang
 */
#include <iostream>
#include <string>
using namespace std;

#ifndef DOWNLOAD_H_
#define DOWNLOAD_H_

class IStrategy;
class Download {
public:
	Download();
private:
	IStrategy* strategy;
public:
	void setStrategy(IStrategy*);
	void execute(string);
};

#endif /* DOWNLOAD_H_ */
