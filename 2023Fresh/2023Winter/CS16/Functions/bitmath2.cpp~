#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int add(int first_num, int second_num) {
	while (second_num != 0) {
		int carry = first_num & second_num;
		first_num = first_num ^ second_num;
		second_num = carry << 1;
	}
	return first_num;
}

int get_operand(string txt) {
	cout << txt << " operand:" << endl;
	int num;
	cin >> num;
	return num;   	
}

string binary_rep(int num) {
	string str = "";
	while (num != 0) {
		if ((num & 1) == 1) {
			str.insert(0, "1");
		} else { 
			str.insert(0, "0");
		}
		num >>= 1;
	}
	return str;
}


void display(int num) {
	cout << "0b" << setfill('0') << setw(32) << binary_rep(num) << "  ";
	cout << "0x" << hex << setfill('0') << setw(8) << num << "  ";
	cout << dec << num << endl;

}

int main() {
	string opp;
	cout << "Operation:" << endl;
	cin >> opp;
	if (opp == "see") {
		int first_num = get_operand("First");
		display(first_num);
	} else if (opp == "add") {
		int first_num = get_operand("First");
		int second_num = get_operand("Second");
		int sum = add(first_num, second_num);
		display(first_num);
		display(second_num);
		display(sum);
	}
	return 0;	
}
