/*
 * Logger.h
 *
 *  Created on: Nov 30, 2013
 *      Author: minhuigu
 */

#ifndef LOGGER_H_
#define LOGGER_H_
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Logger
{
public:
	static Logger* Instance();     // get Instance
	void print(string content);  // print into file

private:
	Logger(void);				// cannot intantiate an object
	Logger(Logger const&){};    // cannot copy
	~Logger(void);

	ofstream outfile;
	static Logger* m_pInstance;
};


#endif /* LOGGER_H_ */
