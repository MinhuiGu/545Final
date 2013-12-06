/*
 * DateDescRewrite.cpp
 *
 *  Created on: Dec 5, 2013
 *      Author: senyang
 */
#include <iostream>
#include "DateDescRewrite.h"

//Reverse downloaded csv file's lines for other threads
void DateDescRewrite::process(string file){
	stack<string> stack;
	string temp;
	ifstream infile(file.c_str());
	ofstream reversedCSV;

	//Read file and put the lines to stack
	int i = 0;
	while (getline(infile, temp)){
		if(i!=0){//skip 1st line
		stack.push(temp);
		}
		i++;
	}
	infile.close();

	//Reverse lines and rewrite the file
	stringstream lines;
	lines << "Date,Open,High,Low,Close,Volume,Adj Close\n";
	reversedCSV.open(file.c_str());
	while (!stack.empty()){
		lines << stack.top()<< "\n";
		stack.pop();
	}
	reversedCSV << lines.str();
	reversedCSV.close();
}


