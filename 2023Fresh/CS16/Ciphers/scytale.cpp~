#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>

using namespace std;


void print_input_error() {
	cout << "USAGE: scytale [-ed] [key]" << endl;
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
	if (stoi(argv[2]) == 0) {
		print_input_error();
		return 1;
	}	
	//cout << "PASSED DIGIT" << endl;
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
	int key = stoi(argv[2]);
	string line;
	if (enc) {
		while (getline(cin, line)) {
			int line_len = (line).length();
			int grid_len = ceil((0.0 + line_len)/key);
			char grid[key][grid_len] = {'\0'};
			int x = 0;
		   	int y = 0;	
			for (char c : line) {
				if (y == grid_len) {
					y = 0;
					x++;
				}
				grid[x][y++] = c;
			}
			for (int i = 0; i < grid_len; i++) {
				for (int j = 0; j < key; j++) {
					if (grid[j][i] == '\0') {
						cout << " "; 
					} else {
						cout << grid[j][i];
					}
				}
			}
			cout << endl;
		}
	} else {
		while (getline(cin, line)) {
			int line_len = (line).length();
			int grid_len = ceil((0.0 + line_len)/key);
			int cnt = 0;
			for (int i = 0; i < key; i++) {
				for (int j = i; j < line_len; j+=key) {
					cout << line.at(j);
					cnt++;
				}
			}	
			for (int i = cnt; i < key*grid_len; i++) {
				cout << " ";
			}
			cout << endl;
		}
	}
}
