#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	string c;
	float temp;
	float ref;
   	float C, F, K, R;	
	cout << "Enter a temperature:" << endl;
	cin >> temp >> c;	
	//make everything in terms of Celcius
	if (c == "C") {
		ref = temp;
	} else if (c == "F") {
		ref = (temp - 32) * (5.0/9.0);
	} else if (c == "K") {
		ref = temp - 273.15;
	} else if (c == "R") {
		ref = (temp - 491.67) * (5.0/9.0);
	}
	C = ref;
	F = ref*(9.0/5.0) + 32;
	K = ref+273.15;
	R = ref*(9.0/5.0) + 491.67;
	cout << fixed << setprecision(2);
	cout << "= " << C << " C" << endl;
	cout << "= " << F << " F" << endl;
	cout << "= " << K << " K" << endl;
	cout << "= " << R << " R" << endl;
}
