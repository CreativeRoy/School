#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;


void print_input_error() {
	cout << "USAGE: caesar [-ed] [key]" << endl;
}

bool detect_input_error(int arg, char** argv) {
	//cout << "Starting!" << argv[1] << endl;
	if (arg != 3) return false;
	//cout << "PASSED ARGS" << endl;
	if (strlen(argv[1]) != 2) return false;
	//cout << "PASSED LEN 2" << endl;
	if (strcmp(argv[1],"-e") != 0 && strcmp(argv[1],"-d") != 0) return false;
	//cout << "PASSED LETTERS" << endl;
	for (char c : string(argv[2])) {   
		if (!isdigit(c)) return false;
	}
	//cout << "PASSED DIGIT" << endl;
	return true;	
}

int main(int argc, char** argv) {
	if (!detect_input_error(argc, argv)) {
		print_input_error();
		return 1; 
	}
	string line;
	bool enc = false;
	if (strcmp(argv[1],"-e") == 0) {
		//cout << argv[1] << endl;
		enc = true;
	}
	int key = stoi(argv[2]);
	while (getline(cin, line)) {
		if (enc) { 
			//cout << "ENCRYPTION" << endl;
			for (char c : line) {
				if (isalpha(c) == 0) {
					cout << c;
					continue;
				}
				int id;
				int new_id;
				if (c >= 97) {//lower case 
					id = c - 'a';
					new_id = (id + key) % 26;
					new_id += 'a'; 
				} else { // upper case 
					id = c - 'A';
					new_id = (id + key) % 26;
					new_id += 'A';
				}	
				char new_c = static_cast<char>(new_id);
				cout << new_c;
			}	
		} else {
			//cout << "DECRYPTION" << endl;
			for (char c : line) {
				if (isalpha(c) == 0) {
					cout << c;
					continue;
				}
				int id;
				int new_id;
				if (c >= 97) {//lower case 
					id = c - 'a';
					new_id = (id - key) % 26;
					if (new_id < 0) {
						new_id += 26;
					}
					new_id += 'a'; 
				} else { // upper case 
					id = c - 'A';
					new_id = (id - key) % 26;
					if (new_id < 0) {
						new_id += 26;
					}
					new_id += 'A';
				}	
				char new_c = static_cast<char>(new_id);
				cout << new_c;
			}		
		}	
		cout << endl;	
	}
}
