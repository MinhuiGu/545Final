/*
 * DateAscPrint.cpp
 *
 *  Created on: Dec 5, 2013
 *      Author: senyang
 */

#include "DateAscPrint.h"

//Default downloaded csv file begins from the newest date
//Print file lines from 1st line to last line
void DateAscPrint::process(string file){
	ifstream infile(file.c_str());
	string temp;
	while (getline(infile, temp)){
		cout << temp << endl;
	}
}
