#include <iostream>

using namespace std;

class DArr {
    int size;
    int *arr;

  public:
    DArr(int a) {
        size = a;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = rand() % 10;
    }

    DArr(const DArr & src) {
        size = src.size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = src.arr[i];
    }

    ~DArr() {
        delete[] arr;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    void setArr(int ind, int val) {
        if ((val >= -100 && val <= 100) && (ind >= 0 && ind < size)) {
            arr[ind] = val;
        }
        else {
            cout << "Error\n";
        }
    }

    int getArr(int ind) {
        if (ind >= 0 && ind < size)
            return arr[ind];
        else
            cout << "Error\n";
    }

    void addArr(int val) {
        if (val >= -100 && val <= 100) {
            int* buf = new int[size];
            for (int i = 0; i < size; i++) {
                buf[i] = arr[i];
            }
            delete[] arr;

            size++;
            arr = new int[size];
            for (int i = 0; i < size - 1; i++) {
                arr[i] = buf[i];
            }
            arr[size - 1] = val;
            delete[] buf;
        }
    }
    friend DArr operator+(DArr, DArr);
    friend DArr operator-(DArr, DArr);
};

DArr operator+(DArr arr1, DArr arr2) {
    if (arr1.size >= arr2.size) {
        DArr buf(arr1.size);

        for (int i = 0; i < arr2.size; i++) {
            buf.setArr(i, arr1.getArr(i) + arr2.getArr(i));
        }

        for (int i = arr2.size; i < arr1.size; i++) {
            buf.setArr(i, arr1.getArr(i));
        }

        return buf;
    }
    else {
        DArr buf(arr2.size);

        for (int i = 0; i < arr1.size; i++) {
            buf.setArr(i, arr1.getArr(i) + arr2.getArr(i));
        }

        for (int i = arr1.size; i < arr2.size; i++) {
            buf.setArr(i, arr2.getArr(i));
        }

        return buf;
    }
}

DArr operator-(DArr arr1, DArr arr2) {
    if (arr1.size >= arr2.size) {
        DArr buf(arr1.size);

        for (int i = 0; i < arr2.size; i++) {
            buf.setArr(i, arr1.getArr(i) - arr2.getArr(i));
        }

        for (int i = arr2.size; i < arr1.size; i++) {
            buf.setArr(i, arr1.getArr(-i));
        }

        return buf;
    }
    else {
        DArr buf(arr2.size);

        for (int i = 0; i < arr1.size; i++) {
            buf.setArr(i, arr1.getArr(i) - arr2.getArr(i));
        }

        for (int i = arr1.size; i < arr2.size; i++) {
            buf.setArr(i, arr2.getArr(i));
        }

        return buf;
    }
}

int main() {
    DArr a(7);
    a.print();
    a.setArr(3, 88);
    a.print();
    a.addArr(9);
    a.print();
    cout << a.getArr(3) << endl;

    DArr b(a);
    b.print();
    b.setArr(2, 34);
    b.setArr(5, 3);

    DArr c(9);
    c.print();
    
    DArr d = a - b;
    d.print();

    DArr e = c - b;
    e.print();

    return 0;
}
