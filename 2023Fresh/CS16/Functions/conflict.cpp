#include <iostream>
#include <string>
using namespace std;

bool valid(string time) {
	int pos_col = time.find(":");
	if (pos_col == (int)string::npos) return false;
	string hr = time.substr(0, pos_col);
	string min = time.substr(pos_col+1);
	//cout << "CHECK HR: " << hr << endl;
	//cout << "CHECK MIN: " << min << endl;
	for (char c : hr) if (!isdigit(c)) return false;
	for (char c : min) if (!isdigit(c)) return false;
   	int HR = stoi(hr);
	int MIN = stoi(min);
	return (0 <= HR) && (HR < 24) && (0 <= MIN) && (MIN < 60);	
}

int ask_start(int num) {
	string str;
	cout << "Class " << num << " start time:" << endl;
	cin >> str;
	while (!valid(str)) {
		cout << "Invalid time; try again." << endl;
		cout << "Class " << num << " start time:" << endl;
		cin >> str;
	}
	int pos_col = str.find(":");
	int hr = stoi(str.substr(0, pos_col));
	int min = stoi(str.substr(pos_col+1));
	return (60*hr + min);
}

int ask_end(int num) {
	string str;
	cout << "Class " << num << " end time:" << endl;
	cin >> str;
	while (!valid(str)) {
		cout << "Invalid time; try again." << endl;
		cout << "Class " << num << " end time:" << endl;
		cin >> str;
	}
	int pos_col = str.find(":");
	int hr = stoi(str.substr(0, pos_col));
	int min = stoi(str.substr(pos_col+1));
	return (60*hr + min);
}

string convert(int time) {
	int hr = (int)(time/60);
	int min = time%60;
	string h = to_string(hr);
	string m = to_string(min);
	if (hr < 10) {
		h = "0"+h;
	}
	if (min < 10) {
		m = "0"+m;
	}
	return (h + ":" + m);
}	
	


int main() {
	int c1_start = ask_start(1);
	int c1_end = ask_end(1);
	if (c1_end <= c1_start) {
		cout << "Start time must be later than end time; try again." << endl;
		c1_start = ask_start(1);
		c1_end = ask_end(1);
	} 
	int c2_start = ask_start(2);
	int c2_end = ask_end(2);
	if (c2_end <= c2_start) {
		cout << "Start time must be later than end time; try again." << endl;
		c2_start = ask_start(2);
		c2_end = ask_end(2);
	} 
	
	cout << "Class 1 runs from " << convert(c1_start) << " to " << 
		convert(c1_end) << "." << endl;
	cout << "Class 2 runs from " << convert(c2_start) << " to " << 
		convert(c2_end) << "." << endl;

	if (c1_end >= c2_end) {
		if (c1_start < c2_end) {
			cout << "Conflict!" << endl;
		} else {
			cout << "No conflict." << endl;
		}		
	} else if (c1_end < c2_end) {
		if (c2_start < c1_end) {
			cout << "Conflict!" << endl;
		} else {
			cout << "No conflict." << endl;
		}		
	}
}
