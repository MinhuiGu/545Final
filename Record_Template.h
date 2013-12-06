/*
 * Record_Template.h
 *
 *  Created on: Dec 5, 2013
 *      Author: minhuigu
 */

#ifndef RECORD_TEMPLATE_H_
#define RECORD_TEMPLATE_H_


class Output_Template
{
	void share1(){cout<< "share1: ";}
	void share2(){cout<< "share2: ";}
	virtual void share1_do() = 0;
	virtual void share2_do() = 0;

public:
	void output()
	{
		share1();
		share1_do();
		share2();
		share2_do();
	}

};







#endif /* RECORD_TEMPLATE_H_ */
