#include <iostream>
using namespace std;
int main() {
	bool z = 1, y = 1, x = 1;
	for (int i = 0; i <= z; i++) {
		for (int j = 0; j <= y; j++) {
			for (int k = 0; k <= x; k++) {
				cout << i << " " << j << " " << k << " " << endl;
			}
		}
	}
	return 0;
}