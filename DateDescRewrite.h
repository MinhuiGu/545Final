/*
 * DateDescRewrite.h
 *
 *  Created on: Dec 5, 2013
 *      Author: senyang
 */

#ifndef DATEDESCREWRITE_H_
#define DATEDESCREWRITE_H_

#include "IStrategy.h"

class DateDescRewrite: public IStrategy {
public:
	void process(string file);
};

#endif /* DATEDESCREWRITE_H_ */
