/*
 * FetchData.h
 *
 *  Created on: Dec 5, 2013
 *      Author: minhuigu
 */

#ifndef FETCHDATA_H_
#define FETCHDATA_H_

//call back function to write data
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream);

//download csv file by symobl name
void downloadCSV(string symbol,int check_flag);

//reverse lines
void reverseLines(string file);


void downloadCSV(string symbol,int check_flag) {
	//Definition
	CURL *curl;
	CURLcode res;
	FILE *fp;
	string base = "http://ichart.finance.yahoo.com/table.csv?s=SYMBOL&a=00&b=3&c=2000&g=d";
	base.replace(44, 6, symbol);
	cout << base << endl;
	string out = symbol.append(".csv");

	//Make a request and download data to csv file
	curl = curl_easy_init();
	if (curl) {
		fp = fopen(out.c_str(), "wb");
		curl_easy_setopt(curl, CURLOPT_URL, base.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		fclose(fp);
		cout << "Download " << symbol << " successfully!" << endl;
	} else {
		cout << "Failed to download " << symbol << ".csv!" << endl;
	}

	Download* down = new Download();

	//Invoke Strategy Pattern
	//print the file 1st time
	if(check_flag) {
		down->setStrategy(new DateAscPrint());
		down->execute(out);
	}


	//reverse csv lines
	down->setStrategy(new DateDescRewrite());
	down->execute(out);
}

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
	size_t written;
	written = fwrite(ptr, size, nmemb, stream);
	return written;
}



#endif /* FETCHDATA_H_ */
