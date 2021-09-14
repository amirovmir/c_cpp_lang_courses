#include <iostream>

/*
Вариант 1.
Номер варианта – остаток от деления суммы всех букв фамилии на число вариантов.
*/

int variant(int length, int options) {
	return length % options + 1;
}

int main() {
	char c;
	int sum = 0;
	const int varMax = 2; //number of options

	while (true) {
		std::cin >> c;
		if (c != '\n')
			sum++;
		else
			break;
	}

	std::cout << variant(sum, varMax);

	return 0;
}
