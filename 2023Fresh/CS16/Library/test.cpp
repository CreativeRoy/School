#include "xps.h"
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	/*
	cout << "----------------------TESTING xps_getchar(...)----------------------" << endl;
	cout << xps_getchar(xps,0) << endl;
	cout << xps_getchar(xps,15) << endl;
	cout << xps_getchar(xps,16) << endl;
	cout << xps_getchar(xps,20) << endl;
	cout << xps_getchar(xps,28) << endl;
	cout << xps_getchar(xps,29) << endl;
	cout << "----------------------TESTING xps_setchar(...)----------------------" << endl;
	xps_setchar(xps, 1, 'Z');
	xps_debug(xps);	
	cout << endl;
	xps_setchar(xps, 1, 'Z');
	xps_debug(xps);	
	cout << endl;
	xps_setchar(xps, 0, 'Z');
	xps_debug(xps);
	cout << endl;
	xps_setchar(xps, 29, 'Z');
	xps_debug(xps);
	cout << endl;
	xps_setchar(xps, 28, 'Z');
	xps_debug(xps);
	cout << "----------------------TESTING xps_from_cstr(...)--------------------" << endl;
	char cstr[] = "hellomynameistaquavionjohnson!";
	char* xps2 = xps_from_cstr(cstr);
	char cstr2[] = "hellomynamei";
	char* xps3 = xps_from_cstr(cstr2);
	xps_debug(xps2);	
	xps_debug(xps3);	
	cout << "----------------------TESTING xps_slice(...)--------------------" << endl;
	xps = xps_readline();
	char* xps4 = xps_slice(xps, 5);
	char* xps5 = xps_slice(xps, 100);	
	xps = xps_readline();
	char* xps6 = xps_slice(xps, 5, 23);
	char* xps7 = xps_slice(xps, 12, 34);
	
	xps_debug(xps4);	
	xps_debug(xps5);	
	xps_debug(xps6);	
	xps_debug(xps7);	
	cout << "----------------------TESTING xps_compare(...)--------------------" << endl;
	char* xps2 = xps_readline();
	cout << xps_compare(xps, xps2) << endl;
	cout << "----------------------TESTING xps_length(...)-----------------------" << endl;
	cout << xps_length(xps) << endl;
	cout << "FINISHED TESTING" << endl;	

	cout << "---------------------TESTING xps_concat(...)------------------------" << endl;
	char* xps2 = xps_readline();
	char* newstr = xps_concat(xps, xps2);
	xps_debug(newstr);
	
	char* xps = xps_readline();
	char* xps4 = xps_slice(xps, 5);
	char* xps5 = xps_slice(xps, 100);	
	xps = xps_readline();
	char* xps6 = xps_slice(xps, 5, 23);
	char* xps7 = xps_slice(xps, 12, 34);
	cout << "4" << endl;
	xps_debug(xps4);

	cout << "5" << endl;
	xps_debug(xps5);

	cout << "6" << endl;
	xps_debug(xps6);

	cout << "7" << endl;
	xps_debug(xps7);	
	char cstr[] = "hellomynameistaquavionjohnson!";
	char* xps2 = xps_from_cstr(cstr);
	char cstr2[] = "hellomynamei";
	char* xps3 = xps_from_cstr(cstr2);
	xps_debug(xps2);	
	xps_debug(xps3);	
	*/
	char* xps = xps_readline();
	char* xps4 = xps_slice(xps, 5);
	char* xps5 = xps_slice(xps, 100);	
	xps = xps_readline();
	char* xps6 = xps_slice(xps, 5, 23);
	char* xps7 = xps_slice(xps, 12, 34);
	cout << "4" << endl;
	xps_debug(xps4);

	cout << "5" << endl;
	xps_debug(xps5);

	cout << "6" << endl;
	xps_debug(xps6);

	cout << "7" << endl;
	xps_debug(xps7);	
}
