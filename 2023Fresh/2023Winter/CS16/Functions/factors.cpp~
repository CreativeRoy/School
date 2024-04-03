#include <iostream>
using namespace std;

int main() {
	int N;
	cout << "Enter a number:" << endl;
	cin >> N;
	int P = N;
	if (N < 0) {
		N = -1*N;
	}
	int K = N;
	if (N < 2) {
		cout << "This number has no prime factors." << endl;
	} else {
		cout << "The prime factors of " << P << " are:" << endl;
		for (int i = 2; i <= K; i++) {
			int cnt = 0;
			while (N % i == 0) {
				cnt++;
				N = N/i;
			}
			if (cnt == 0) continue;
			if (cnt == 1) {
				cout << i << endl;
			} else {
				cout << i << "^" << cnt << endl;
			}
		}
	}

}
