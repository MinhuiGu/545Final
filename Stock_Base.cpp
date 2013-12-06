/*
 * StockInfo.cpp
 *
 *  Created on: Nov 25, 2013
 *      Author: minhuigu
 */

#include <exception>
#include <fstream>
#include <math.h>
#include <sstream>

#include "Stock_Base.h"
using namespace std;

StockInfo :: StockInfo(string name, int line_number) {

	string tmp = name;
	Controller = line_number;
	Counter = 1;
	name.append(".csv");
	ifstream infile(name);

	if (!infile.good())
		throw MyException(name + " :file cannot open");

	string line,token;

	int i,j;
	long double Return,AReturn;
	string csv_array[7];

	while( getline(infile, line) && Counter <= Controller)
	{
		stringstream input_stringstream(line);
		i=0;

		/* get a line's data, save it to csv_array */
		while( getline(input_stringstream, token, ',')) {
			csv_array[i++] = token;
		}
		//cout<<"save line "<<Counter<<" in Day: "<<((Counter-1)%ROLLBACK)<<endl;

		if (Counter > 1) {
			Days[(Counter-1)%ROLLBACK].set_price(atof(csv_array[4].c_str()));
			Days[(Counter-1)%ROLLBACK].set_volume(atoi(csv_array[5].c_str()));
			Days[(Counter-1)%ROLLBACK].set_date(csv_array[0]);

			//cout<<csv_array[4]<<" "<<csv_array[5]<<endl;
		}

		Return = AReturn = 0;
		if (Counter > 2) {
			Return = log( Days[(Counter-1)%60].get_price()/Days[(Counter-2)%60].get_price() );
			Days[(Counter-1)%60].set_return(Return);
			//cout<<"setting line "<<Counter<<" Return:"<<Return<<" in Day: "<<((Counter-1)%ROLLBACK)<<endl;
		}

		if (Counter > 11) {
			for (j=10; j>0; j--) {
				AReturn += Days[(Counter-1-j)%60].get_volume();
			}
			AReturn = (AReturn/10/Days[(Counter-1)%60].get_volume())*Days[(Counter-1)%60].get_return();
			Days[(Counter-1)%60].set_AdjReturn(AReturn);
			//cout<<"setting line "<<Counter<<" AReturn:"<<AReturn<<" in Day: "<<((Counter-1)%60)<<endl;
		}
		Counter ++ ;
	}
	infile.close();
	Name = tmp;
	if (Counter <= 60+11) {
		throw MyException(name + " :insufficient data");
	}

}
StockInfo :: ~StockInfo() {

}

void StockInfo :: new_day_update(double price, int volume,string date)
{
	int j;
	long double Return, AReturn=0;

	//cout<<"update line "<<Counter<<" in Day: "<<((Counter-1)%ROLLBACK)<<endl;
	Days[(Counter-1)%60].set_price(price);
	Days[(Counter-1)%60].set_volume(volume);
	Days[(Counter-1)%60].set_date(date);

	Return = log( Days[(Counter-1)%60].get_price()/Days[(Counter-2)%60].get_price() );
	Days[(Counter-1)%60].set_return(Return);

	for (j=10; j>0; j--) {
		AReturn += Days[(Counter-1-j)%60].get_volume();
	}

	AReturn = (AReturn/10/Days[(Counter-1)%60].get_volume())*Days[(Counter-1)%60].get_return();
	Days[(Counter-1)%60].set_AdjReturn(AReturn);
	Counter++;

}

void StockInfo :: from_csv_update(int lines)
{
	string name = Name;
	name.append(".csv");
	ifstream infile(name);
	Controller = Counter+lines;

	if (!infile.good())
		throw MyException(name + " :file cannot open");

	string line,token;
	int i;
	int start = Counter,end = Counter+lines;
	string csv_array[7];
	int line_n = 0;
	while( getline(infile, line))
	{
		line_n++;
		if (line_n == 1)
			continue;
		else if (line_n >= start && line_n < end) {
			stringstream input_stringstream(line);

			/* get a line's data, save it to csv_array */
			i=0;
			while( getline(input_stringstream, token, ',')) {
				csv_array[i++] = token;
			}

			new_day_update(atof(csv_array[4].c_str()),atoi(csv_array[5].c_str()),csv_array[0]);
		}
	}

	infile.close();

	if (Counter < end-1) {
		throw MyException(name + " :insufficient data lines for updating");
	}

}
double StockInfo :: get_price()
{
	return get_data(((Counter-2)%60)).get_price();
}

int StockInfo :: get_volume()
{
	return get_data(((Counter-2)%60)).get_volume();
}

MetaData StockInfo :: get_data(int index)
{
	return Days[index];
}

string StockInfo :: get_date()
{
	return get_data(((Counter-2)%60)).get_date();
}

