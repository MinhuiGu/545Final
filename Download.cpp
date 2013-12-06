/*
 * Download.cpp
 *
 *  Created on: Dec 5, 2013
 *      Author: senyang
 */
#include "Download.h"
#include "IStrategy.h"
#include "DateAscPrint.h"
#include "DateDescRewrite.h"

Download::Download(): strategy(0){
}

void Download::setStrategy(IStrategy* strategy){
	this->strategy = strategy;
}
void Download::execute(string file){
	strategy->process(file);
}

