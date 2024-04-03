#include <iostream>

using namespace std;

int main() {
	int length;
	cout << "Side length:" << endl;
	cin >> length;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length-i-1; j++) {
			cout << " ";
		}
		cout << "/";
		for (int j = 0; j < 2*i; j++) {
			cout << " "; 
		}
		cout << "\\" << endl;
	}
	for (int i = length-1; i >= 0; i--) {
		for (int j = 0; j < length-i-1; j++) {
			cout << " ";
		}
		cout << "\\";
		for (int j = 0; j < 2*i; j++) {
			cout << " "; 
		}
		cout << "/" << endl;
	}
}
