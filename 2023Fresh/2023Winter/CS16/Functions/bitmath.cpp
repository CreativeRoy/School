#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int add(unsigned int first_num, unsigned int second_num) {
	while (second_num != 0) {
		unsigned int carry = first_num & second_num;
		first_num = first_num ^ second_num;
		second_num = carry << 1;
	}
	return first_num;
}

int sub(unsigned int first_num, unsigned int second_num) {
	unsigned int inverse_second = ~second_num;
	unsigned int diff = add(first_num, add(1, inverse_second));
	return diff;
}

int mul(unsigned int first_num, unsigned int second_num) {
	unsigned int sum = 0;
	while (second_num != 0) {
		if (second_num & 1) {
			sum = add(sum, first_num);
		}
		first_num <<= 1;
		second_num >>= 1;   	
	}
	return sum;
}


int get_operand(string txt) {
	cout << txt << " operand:" << endl;
	unsigned int num;
	cin >> num;
	return num;   	
}

string binary_rep(unsigned int num) {
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


void display(unsigned int num) {
	cout << "0b" << setfill('0') << setw(32) << binary_rep(num) << "  ";
	cout << "0x" << hex << setfill('0') << setw(8) << num << "  ";
	cout << dec << num << endl;
}

int main() {
	string opp;
	cout << "Operation:" << endl;
	cin >> opp;
	if (opp == "see") {
		unsigned int first_num = get_operand("First");
		display(first_num);
	} else if (opp == "add") {
		unsigned int first_num = get_operand("First");
		unsigned int second_num = get_operand("Second");
		unsigned int sum = add(first_num, second_num);
		display(first_num);
		display(second_num);
		display(sum);
	} else if (opp == "sub") {
		unsigned int first_num = get_operand("First");
		unsigned int second_num = get_operand("Second");
		unsigned int diff = sub(first_num, second_num);
		display(first_num);
		display(second_num);
		display(diff);
	} else if (opp == "mul") {
		unsigned int first_num = get_operand("First");
		unsigned int second_num = get_operand("Second");
		unsigned int prod = mul(first_num, second_num);
		display(first_num);
		display(second_num);
		display(prod);
	}
	return 0;	
}
