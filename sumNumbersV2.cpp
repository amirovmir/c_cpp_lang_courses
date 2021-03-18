#include <iostream>
#include <cctype>

using namespace std;

int main() {
	int amt;
	char numbers;
	int sum = 0;

	cin >> amt;
	for (int i = 0; i < amt; ++i) {
		cin >> numbers;
		if (numbers - '0' >= 0 && numbers - '0' <= 9) {
			sum += numbers - '0';
		}
	}

	cout << sum;
	return 0;
}