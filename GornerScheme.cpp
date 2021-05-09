#include <iostream>
#include <ctype.h>
#include <cmath>

using namespace std;

int perevodDec(int base) {
	char chislo;
	int dec = 0;
	while (1) {
		cin.get(chislo);
		if (chislo == '\n') {
			break;
		}
		dec *= base;
		if (chislo - 'A' + 10 > 9) {
			dec += (chislo - 'A' + 10);
		}
		else if (chislo - '0' >= 0 && chislo - '0' <= 9) {
			dec += (chislo - '0');
		}
	}
	return dec;
}

void perevodAnother(int base, int chislo) {
	int i = 0;
	while (pow(base, i) < chislo) {
		i++;
	}
	i = i - 1;
	for (; i > -1; i--) {
		int c = chislo / int(pow(base, (i)));
		if (c > 9) {
			cout << char(c + 'A' - 10);
		}
		else {
			cout << c;
		}
		chislo -= c * pow(base, i);

	}
}

int main() {
	int b1, b2;
	int a;
	setlocale(LC_ALL, "RUS");
	cout << "Введите основание системы счисления числа и само число в виде: СС; ЧЧЧ..." << endl;
	cin >> b1;

	a = perevodDec(b1);
	cout << a << '\n';
	
	cout << "Введите основание системы счисления в которую нужно перевести: ";
	cin >> b2;
	perevodAnother(b2, a);
	return 0;
}
