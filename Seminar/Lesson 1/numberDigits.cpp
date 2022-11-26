#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int a, d, count = 0;
    setlocale(LC_ALL, "RUS");
    cout << "Введите число: " << endl;
    cin >> a;

    if (a / 10 == 0) {
        cout << a;
        return 0;
    }

    d = a;
    while (d / 10 != 0) {
        d = d / 10;
        ++count;
    }
    
    cout << "a = ";
    cout << int (a / pow(10, count)) << "*10^" << count << " + ";
    --count;
    while (count != 0) {
        cout << int (a / pow(10, count)) % 10 << "*10^" << count << " + ";
        --count;
    }
    cout << a % 10;
    return 0;
}
