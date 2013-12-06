/*
 * Logger.cpp
 *
 *  Created on: Nov 30, 2013
 *      Author: minhuigu
 */
#include <stdio.h>
#include "Logger.h"
#include <time.h>


Logger* Logger::m_pInstance = NULL;

Logger::Logger(void)
{
	outfile.open("log.txt", ios_base::app);
}
 
Logger::~Logger(void)
{
	outfile.close();

}

Logger* Logger::Instance()
{
   if (!m_pInstance)
        m_pInstance = new Logger;

   return m_pInstance;
}

void Logger::print(string content)
{
	time_t rawtime;
	struct tm * timeinfo;
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	cout<< asctime(timeinfo) <<"---->"<<content<<endl<<endl;
	outfile << asctime(timeinfo) <<"---->"<<content<<endl<<endl;
}
