#include <iostream>
#include <stdlib.h>

using namespace std;

void bubbleSort(int* arr, int size)
{
    int tmp, m, n;
    int g = 0;

    for (m = 0; m < size; m++)
    {
        for (n = 0; n < size - m - 1; n++)
        {
            if (arr[n + 1] < arr[n])
            {
                tmp = arr[n + 1];
                arr[n + 1] = arr[n];
                arr[n] = tmp;
            }
            else
                g++;
        }
    }
    cout << g << "\n";
}

int main() {
    const unsigned int DIM = 10;
    int num[DIM] = {0};

    for (int i = 0; i < DIM; i++) {
        num[i] = rand() % 10;
    }

    bubbleSort(num, DIM);
    for (int i = 0; i < DIM; i++) {
        cout << num[i] << " ";
    }
	return 0;
}