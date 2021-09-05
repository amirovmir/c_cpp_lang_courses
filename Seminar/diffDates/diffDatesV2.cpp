#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int year, month1, day1, month2, day2;
    int bis = 0; //bis - булевая переменная для отслеживания високосного года
    int days_betw = 0;
    int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    cout << "Enter year, month1 (number), month2 (number), day1, day2" << endl;
    cin >> year >> month1 >> month2 >> day1 >> day2;
    //проверка введенных месяцев
    while (month1 > 12 || month1 < 1) {
        cout << "Enter the correct moths1(number)" << endl;
        cin >> month1;
    }
    while (month2 > 12 || month2 < 1) {
        cout << "Enter the correct moths2(number)" << endl;
        cin >> month2;
    }
    //проверка високосности года
    if ((year % 4) == 0) {
        if ((year % 100) == 0) {
            if ((year % 400) == 0) {
                bis = 1;
            }
            else {
                bis = 0;
            }
        }
        else {
            bis = 1;
        }
    }
    else {
        bis = 0;
    }
    //проверка введенных дней
    while (day1 < 1 || day1 > 31 || (bis == 0 && month1 == 2 && day1 > 28) || (bis == 1 && month1 == 2 && day1 > 29)) {
        cout << "Enter the correct day1(number)" << endl;
        cin >> day1;
    }
    while (day2 < 1 || day2 > 31 || (bis == 0 && month2 == 2 && day2 > 28) || (bis == 1 && month2 == 2 && day2 > 29)) {
        cout << "Enter the correct day2(number)" << endl;
        cin >> day2;
    }
    // в зависимости от того, какой месяц больше (month1 и month2), считаем количество месяцев и дней между ними
    if (month1 < month2) {
        //высчитываем кол-во оставшихся дней в первом месяце со дня, введенного пользователем
        if (months[month1 - 1] == 31) {
            days_betw += (31 - day1);
        }
        else {
            if (months[month1 - 1] == 30) {
                days_betw += (30 - day1);
            }
        }
        if (month1 == 2) {
            if (bis == 0) {
                days_betw += (28 - day1);
            }
            else {
                days_betw += (29 - day1);
            }
        }
        //вычисление кол-ва дней в полных месяцах между month1 и month2
        for (int i = month1; i < month2 - 1; ++i) {
            if (bis == 0) {
                days_betw += months[i];
            }
            else {
                months[1] = 29;
                days_betw += months[i];
            }
        }
        days_betw += day2; //прибавляем кол-во дней в последнем большем введенном месяце
        cout << "Number of days between day1 and day2 is " << days_betw;
        return 0;
    }
    else if (month2 < month1) {
        //высчитываем кол-во оставшихся дней в первом месяце со дня, введенного пользователем
        if (months[month2 - 1] == 31) {
            days_betw += 31 - day2;
        }
        else {
            if (months[month2 - 1] == 30) {
                days_betw += 30 - day2;
            }
        }
        if (month2 == 2) {
            if (bis == 0) {
                days_betw += 28 - day2;
            }
            else if (bis == 1) {
                days_betw += 29 - day2;
            }
        }
        //вычисление кол-ва дней в полных месяцах между month1 и month2
        for (int i = month2; i < month1 - 1; ++i) {
            if (bis == 0) {
                days_betw += months[i];
            }
            else if (bis == 1) {
                months[1] = 29;
                days_betw += months[i];
            }
        }
        days_betw += day1; //прибавляем кол-во дней в последнем большем введенном месяце
        cout << "Number of days between day1 and day2 is " << days_betw;
        return 0;
    }
    else if (month1 == month2)
        days_betw = abs(day1 - day2);
    cout << "Number of days between day1 and day2 is " << days_betw;
    return 0;
}
