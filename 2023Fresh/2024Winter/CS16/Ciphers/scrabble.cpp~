#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>

using namespace std;

void print_input_error() {
	cout << "USAGE: scrabble [letters]" << endl;
}

bool detect_input_error(int arg, char** argv) {
	//cout << "Starting!" << argv[1] << endl;
	if (arg != 2) return false;
	//cout << "PASSED ARGS" << endl;
	for (char c : (string)argv[1]) {
		if (isalpha(c) == 0) {return false;}
	}
	//cout << "PASSED ARGV" << endl;
	return true;	
}

int main(int argc, char** argv) {
	if (!detect_input_error(argc, argv)) {
		print_input_error();
		return 1; 
	}
	int array[26] = {0};
	for (char c: (string)argv[1]) {
		int id = tolower(c)-'a';
		array[id]++;
	}
	string line;
	while (getline(cin, line)) {
		bool invalid = false;
		int clone[26];
	   	string yn = "Yes";
		copy(begin(array), end(array), begin(clone));	
		for (char c : line) {
			if (!isalpha(c)) {
				invalid = true;
				break;
			}
			int ind = tolower(c) - 'a';
			clone[ind]--;
			if (clone[ind] < 0) {
				yn = "No";
			}
		}
		if (invalid) {
			cout << "Invalid word." << endl ;
			continue;
		}
		cout << line << ": " << yn << endl; 
	}
	return 0;
}
