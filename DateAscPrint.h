/*
 * DateAscPrint.h
 *
 *  Created on: Dec 5, 2013
 *      Author: senyang
 */

#ifndef DATEASCPRINT_H_
#define DATEASCPRINT_H_

#include "IStrategy.h"

class DateAscPrint: public IStrategy {
public:
	void process(string file);
};

#endif /* DATEASCPRINT_H_ */
