#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>

using namespace std;

int getRandomNum(int min, int max) {
	int num = min + rand() % (max - min + 1);
	return num;
}

int main() {
	int size1, size2;

	cin >> size1 >> size2;

	map<int, int> sameElements;
	vector<int> vec1(size1), vec2(size2);

	float sum1 = 0.0, sum2 = 0.0;

	for (int i = 0; i < size1; i++) {
		vec1[i] = getRandomNum(-100, 100);
		sum1 += vec1[i];

		cout << vec1[i] << ' ';
	}
	cout << endl;

	for (int i = 0; i < size2; i++) {
		vec2[i] = getRandomNum(-100, 100);
		sum2 += vec2[i];

		cout << vec2[i] << ' ';

		if (find(vec1.begin(), vec1.end(), vec2[i]) != vec1.end())
			sameElements[i]++;
	}

	cout << endl;

	cout << static_cast<float>(sum1 / size1) << endl;
	cout << static_cast<float>(sum2 / size2) << endl;

	if (!sameElements.empty()) {
		for (pair<int, int> tmp : sameElements)
			cout << tmp.first << " ";
		cout << endl;
	}
	else {
		cout << "No identical elements\n";
	}

	return 0;
}
