#include "PosixTestClient.h"
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <string>

#include <curl/curl.h>
#include <curl/easy.h>

#include "MetaData.h"
#include "Pairs.h"
#include "Buy_Sell.h"
#include "Download.h"
#include "DateAscPrint.h"
#include "DateDescRewrite.h"
#include "FileInfo.h"
#include "FetchData.h"

using namespace std;

#define READLINES 2465
#define UPDATE_TIMES 200
#define TEST_LINE 800
#define INITIAL_CASH 100000000

#define MAX_ATTEMPTS 50
#define SLEEP_TIME 1


int main(int argc, char* argv[])
{
	Pairs * pair;
	int choice = 0;
	string a,b;
	int c=0;

	cout<<"please choose the stocks 1 for a pair"<<endl;
	cin>>a;
	cout<<"please choose the stocks b for a pair"<<endl;
	cin>>b;
	cout<<"show data after downloading? 0-->no 1-->yes"<<endl;
	cin>>c;
	cout<<"downloading date..."<<endl;

	downloadCSV(a,c); 	//MCD
	downloadCSV(b,c);   //XLY
	string s1,s2;
	s1 = a;
	s1.append(".csv");
	s2 = b;
	s2.append(".csv");
	cout<<"download finish"<<endl;

	cout<<"checking files"<<endl;
	int l1 = 0,l2 = 0;
	try{
		FileInfo stock1_csv(s1);
		l1 = stock1_csv.get_line();
		cout<<s1<<" has lines"<<l1<<endl;
	}
	catch(MyException& e){
			e.print();
	}
	try{
		FileInfo stock2_csv(s2);
		l2 = stock2_csv.get_line();
		cout<<s2<<" has lines"<<l2<<endl;
	}
	catch(MyException& e){
			e.print();
	}

	cout<<"data obtained, please input control data"<<endl;
	int initial_line, update_line, testing_line;

	cout<<"how many lines to initial the pairs?"<<endl;
	cin>>initial_line;
	cout<<"how many lines to update the pairs?"<<endl;
	cin>>update_line;
	cout<<"how many lines to do the testing?"<<endl;
	cin>>testing_line;

	while ((initial_line + update_line + testing_line )>l1 || (initial_line + update_line + testing_line )>l2 )
	{
		cout<<" invalid input"<<endl;
		cout<<"how many lines to initial the pairs?"<<endl;
		cin>>initial_line;
		cout<<"how many lines to update the pairs?"<<endl;
		cin>>update_line;
		cout<<"how many lines to do the testing?"<<endl;
		cin>>testing_line;
	}

	try{
		pair = new Pairs(b,a,initial_line+1); //READLINE+1 for skip the first line
		cout<<"SIGNAL after initial: "<< pair->get_signal()<<endl;
	}
	catch(MyException& e){
		e.print();
	}

	pair->from_csv_update(update_line);

	int i = 0, d=0;

	cout<<"initial finished, practice-->1 or mock-->2?"<<endl;
	cin>> choice;
	if (choice ==2 ) {
		cout<<"how many cash for mock?"<<endl;
		cin>>d;
		Buy_Sell decision(d); // initial the decision with 10000 dollar

		for ( i=0; i<testing_line;i++) {
			pair->from_csv_update(1);
			decision.decide(pair->get_date(),pair->get_signal(),pair->get_one_new_sigs(),pair->s2_close(),pair->s1_close(),pair->Beta);
		}
		cout<<"Initial:"<< d<<endl;
		cout<<"Now cash:"<<decision.get_cash()<<endl;
		cout<<"Profit:"<< decision.get_cash()-d <<endl;
	}
	else if (choice == 1) {
		cout<<"not implemented"<<endl;
	}
	/*
	const char* host = argc > 1 ? argv[1] : "";
	unsigned int port = 7496;
	int clientId = 0;
	int connected_flag = 0;

	unsigned attempt = 0;
	printf( "Start of POSIX Socket Client Test %u\n", attempt);

	for (;;) {
		++attempt;
		printf( "Attempt %u of %u\n", attempt, MAX_ATTEMPTS);

		IB::PosixTestClient client;

		client.connect( host, port, clientId);

		while( client.isConnected()) {
			client.processMessages();

		}

		if( attempt >= MAX_ATTEMPTS) {
			break;
		}

		printf( "Sleeping %u seconds before next attempt\n", SLEEP_TIME);
		sleep( SLEEP_TIME);
	}

*/
	printf ( "End of POSIX Socket Client Test\n");
}
