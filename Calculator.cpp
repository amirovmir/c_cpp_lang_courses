#include <iostream>
#include <string>

using namespace std;

int main() {
	//setlocale(0, ""); //устанавливаем  ириллицу
	int year, m1, d1, m2, d2, diff;
	string month[12] = {"January ", "February ", "March ", "April ", "May ", "June ", "July ", "August ", "September ", "October ", "November ", "December "};
	int daysinmonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	cout << "Enter year, month1, day1, month2, day2" << endl;
	cin >> year >> m1 >> d1 >> m2 >> d2;

	//проверка мес€цев
	while (m1 > 12 || m2 > 12) {
		if (m1 > 12) {
			cout << "Enter correct month1:" << endl;
			cin >> m1;
		}
		else {
			cout << "Enter correct month2:" << endl;
			cin >> m2;
		}
	}

	//проверка високосного ‘еврал€
	while (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && (m1 == 2 || m2 == 2) && (d1 > 29 || d2 > 29)) {
		if (m1 == 2)
			cout << "It can't be more than 29 days in February in " << year << " year. Enter correct day in month1: ";
		else 
			cout << "It can't be more than 29 days in February in " << year << " year. Enter correct day in month2: ";
		if (m1 == 2 && d1 > 29)
			cin >> d1;
		if (m2 == 2 && d2 > 29) {
			cin >> d2;
		}
	}

	//проверку обычного ‘еврал€
	while ((year % 4 != 0 || (year % 4 == 0 && year % 100 == 0 && year % 400 != 0)) && (m1 == 2 || m2 == 2) && (d1 > 28 || d2 > 28)) {
		if (m1 == 2)
			cout << "It can't be more than 28 days in February in " << year << " year. Enter correct day in month1: ";
		else
			cout << "It can't be more than 28 days in February in " << year << " year. Enter correct day in month2: ";
		if (m1 == 2 && d1 > 28)
			cin >> d1;
		if (m2 == 2 && d2 > 28)
			cin >> d2;
	}

	//проверка 30 дневных мес€цев
	while ((daysinmonth[m1 - 1] % 2 == 0 || daysinmonth[m2 - 1] % 2 == 0) && (d1 > 30 || d2 > 30)) {
		if (d1 > 30) {
			cout << "Uncorrect day in month1. Enter correct day1: ";
			cin >> d1;
		}
		else {
			cout << "Uncorrect day in month2. Enter correct day2: ";
			cin >> d2;
		}
	}

	//проверка 31 дневных мес€цев
	while ((daysinmonth[m1 - 1] % 2 == 1 || daysinmonth[m2 - 1] % 2 == 1) && (d1 > 31 || d2 > 31)) {
		if (d1 > 31) {
			cout << "Uncorrect day in month1. Enter correct day1: ";
			cin >> d1;
		}
		else {
			cout << "Uncorrect day in month2. Enter correct day2: ";
			cin >> d2;
		}
	}

	//ќпредел€ем какой год и сколько дней в каждом мес€це
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {
		cout << "Leap year (366 days)" << endl;
		year = 366;
		daysinmonth[1] = 29;
		for (int i = 0; i <= 11; ++i) {
			cout << month[i] << daysinmonth[i] << endl;
		}
	} 
	else {		
		cout << "Common year (365 days)" << endl;
		year = 365;
		for (int i = 0; i <= 11; ++i) {
			cout << month[i] << daysinmonth[i] << endl;
		}
	}

	//определ€ем разницу в дн€х
	int x1 = 0;
	for (int i = 0; i < m1 - 1; ++i) {
		x1 += daysinmonth[i];
		}
	int x2 = 0;
	for (int i = 0; i < m2 - 1; ++i) {
		x2 += daysinmonth[i];
		}
	diff = abs(d1 + x1 - d2 - x2);
	cout << "Difference betwen dates: " << diff << " days" << endl;
	return 0;
}