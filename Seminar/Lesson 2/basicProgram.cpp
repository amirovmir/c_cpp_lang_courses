#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

int main() {
	string a; //число входное число
	string b; //входное числа в обратном порядке
	int base1; //основание системы счисления введенного числа
	int base2; //основание системы счисления, в которую нужно перевести
	int rest, save;
	int semiOtvet = 0; //число в 10 системе счисления
	string otvet; //ответ 

	setlocale(LC_ALL, "RUS"); //Кириллица
	cout << "Введите основание системы счисления: \n";
	cin >> base1;
	cout << "Введите число в этой системе счисления: \n";
	cin >> a;
	cout << "Введите основание системы счисления, в которую нужно перевести: \n";
	cin >> base2;

	//запись числа в обратном порядке
	for (int k = a.size() - 1; k >= 0; k--) {
		char ch = a[k];
		b += ch;
	}

	for (int i = 0; i < b.size(); i++) {
		//подсчёт основания системы счисления в степени разряда числа
		int st = 1;
		for (int j = i; j > 0; j--) {
			st *= base1;
		}
		//перевод в 10 систему счисления
		if (b[i] - '0' > 9) {
			semiOtvet += (b[i] - 'A' + 10) * st;
		}
		else {
			semiOtvet += (b[i] - '0') * st;
		}
	}
	cout << "Число в десятичной системе счисления: " << semiOtvet << endl;

	//перевод из 10 системы счисления в заданную
	while (semiOtvet >= base2) {
		save = semiOtvet;
		semiOtvet = save / base2;
 		rest = save - semiOtvet * base2;
		if (rest > 9) {
			otvet += rest - 10 + 'A';
		}
		else
			otvet += rest + '0';
	}
	if (semiOtvet > 9) {
		otvet += semiOtvet - 10 + 'A';
	}
	else
		otvet += semiOtvet + '0';
	//выписывание остатков в обратном порядке
	cout << "Число в системе счисления с основанием " << base2 << " : ";
	for (int i = otvet.size(); i >= 0; i--) {
		char digit = otvet[i];
		cout << digit;
	}
	return 0;
}
