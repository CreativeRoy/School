#include <iostream>
using namespace std;

int main() {
	long a, b;
	cout << "Number one:" << endl;
	cin >> a;
	cout << "Number two:" << endl;
	cin >> b;
	long x = a;
	long y = b;
	while (x != 0 && y != 0) {
		if (x >= y) {
			x = x % y;
		} else {
			y = y % x;
		}	
	}
	int gcd = x;
	if (y > x) {
		gcd = y;
	} 
	long long lcm = (long long)(a * b)/(gcd);
	cout << "gcd(" << a << ", " << b << ") = " << gcd << endl;
	cout << "lcm(" << a << ", " << b << ") = " << lcm << endl;
	return 0;
}
