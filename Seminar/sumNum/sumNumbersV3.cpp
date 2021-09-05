#include <iostream>
#include <cctype>

int main() {

	using namespace std;

	int amt;
	char numbers;
	int sum = 0;
	cin >> amt;
	for (int i = 0; i < amt; ++i) {
		cin >> numbers;
		if (numbers - '0' >= 0 && numbers - '0' <= 9) {
			sum += numbers - '0';
		}
		else {
			cout << (char)tolower(numbers);
		}
	}
	cout << "\n" << sum;
	return 0;
}
