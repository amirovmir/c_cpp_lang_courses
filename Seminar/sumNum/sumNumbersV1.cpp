#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int amt;
	char numbers;
	int count = 0;
	cin >> amt;
	for (int i = 0; i < amt; ++i) {
		cin >> numbers;
		cout << int(numbers) << endl;
		count += numbers - 48;
	}
	cout << count;
	return 0;
}
