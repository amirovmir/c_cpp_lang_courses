#include <iostream>

using namespace std;

int calcVar(const char fam[8]) {
	return fam[0] % 2 + 1;
}

int main() {
	cout << calcVar("Амиров");
	//Output = 1;
	return 0;
}
