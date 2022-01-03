#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	map<string, int> foomap;
	string line;

	while (cin >> line) {		
		if (line != "\.")
			foomap[line]++;
		else
			break;
	}

	for (pair<string, int> p : foomap)
		cout << p.first << ": " << p.second << " times" << endl;

	return 0;
}
