#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>

using namespace std;

void print_input_error() {
	cout << "USAGE: substitution [-ed] [key]" << endl;
}

bool detect_input_error(int arg, char** argv) {
	//cout << "Starting!" << argv[1] << endl;
	if (arg != 3) return false;
	if (strlen(argv[1]) != 2) return false;
	if (strcmp(argv[1],"-e") != 0 && strcmp(argv[1],"-d") != 0) return false;
	if (strlen(argv[2]) != 26) return false;
	//cout << "PASSED ARGS" << endl;
	int alpha[26] = {0};
	for (char c : string(argv[2])) {
		if (isalpha(c) == 0) return false;
		char d = tolower(c);
		//cout << d << endl;
		int ind = d - 'a';
		//cout << ind << endl;
		alpha[ind]++;
	}
	//cout << "PASSED ALPHA" << endl;
	for (int i : alpha) {
		//cout << (i) << endl;
		if (i != 1) return false;
	}	
	return true;	
}

int main(int argc, char** argv) { 
	if (!detect_input_error(argc, argv)) {
		print_input_error();
		return 1; 
	}
	bool enc = false;
	if (strcmp(argv[1],"-e") == 0) {
		enc = true;
	}
	char enc_lib[26];
	char dec_lib[26];

	int id = 0;
	for (char c : string(argv[2])) {
		char d = tolower(c);
		enc_lib[id++] = d;
	}
	id = 0;
	for (char c : string(argv[2])) {
		char d = tolower(c);
		int ind =  d-'a';
		dec_lib[ind] = static_cast<char>(id+'a');
		id++;
	}

	string line;
	while (getline(cin, line)) { 
		if (enc) {
			for (char c : line) {
				if (isalpha(c) == 0) {
					cout << c;
					continue;
				}
				bool cap = false;
				char d = tolower(c);
				if (d != c) cap = true;
				int ind = d - 'a';
				char e = enc_lib[ind];
				if (cap) e = toupper(e);
			   	cout << e;	
			}
			cout << endl;
		} else {
			for (char c : line) {
				if (isalpha(c) == 0) {
					cout << c;
					continue;
				}
				bool cap = false;
				char d = tolower(c);
				if (d != c) cap = true;
				int ind = d - 'a';
				char e = dec_lib[ind];
				if (cap) e = toupper(e);
			   	cout << e;	
			}
			cout << endl;
		}
	}
	return 0;
}
