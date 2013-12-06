/*
 * FileInfo.h
 *
 *  Created on: Dec 5, 2013
 *      Author: minhuigu
 */

#ifndef FILEINFO_H_
#define FILEINFO_H_
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class FileInfo
{
public:
	FileInfo(string name){
		file_name = name;
		ifstream infile(name);
		if (!infile.good())
			throw MyException(name + " :file cannot open");
		infile.close();
	}

	~FileInfo(){}
	int get_line() {
		ifstream infile(file_name);
		int counter = 0;
		string line;
		while( getline(infile, line) )
			counter++;
		infile.close();
		return counter;

	}
private:
	string file_name;

};


#endif /* FILEINFO_H_ */
