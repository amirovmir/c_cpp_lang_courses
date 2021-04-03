#include <iostream>

using namespace std;

void CocktailSort(int a[], int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped)
    {
        swapped = false;
        for (int i = start; i < end; ++i)
        {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i)
        {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}

int main() {
	int a;
	cin >> a;
	int *num = new int[a];
	for (int i = 0; i < a; i++) {
		num[i] = rand() % 100;
	}
	for (int i = 0; i < a; i++) {
		cout << num[i] << " ";
	}
	cout << "\n";

    CocktailSort(num, a);

    for (int i = 0; i < a; i++) {
        cout << num[i] << " ";
    }
    cout << "\n";
	return 0;
}