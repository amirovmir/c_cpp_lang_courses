#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
class Array {
	T* p;
	int size;
public:
	Array(int size) {
		this->size = size;
		p = new int[size];
	}

	Array(const Array& mas) {
		size = mas.size;
		p = new T[size];
		for (int i = 0; i < size; i++)
			p[i] = mas.p[i];
	}

	~Array() {
		delete[] p;
	}

	void set(int ind, T val) {
		if (ind < 0 || ind >= size)
			cout << "Setter error. Out of range" << endl;
		else p[ind] = val;
	}

	void get(int ind) {
		if (ind < 0 || ind >= size)	{
			cout << "Getter error. Out of range" << endl;
			return -1;
		}
		else 
			return p[ind];
	}

	void push_back(T val) {
		T* mass = new T[size + 1];
		memcpy(mass, p, size * sizeof(T));
		mass[size] = val;

		size++;
		p = mass;
	}

	double dist(const Array& arr) {
		int p = 0.0;
		for (int i = 0; i < size; i++) 
			p += (p[i] - arr.p[i]) * (p[i] - arr.p[i]);

		return sqrt(p);
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << p[i] << " ";
		}
		cout << endl;
	}

	friend ostream& operator<<(ostream& output, const Array& arr) {
		for (int i = 0; i < arr.size; i++) 
			output << arr.p[i] << ' ';
		output << endl;

		return output;
	}

	Array& operator=(const Array& arr) {
		if (this == &arr) 
			return *this;

		size = arr.size;
		p = new T[size];
		for (int i = 0; i < size; i++) 
			p[i] = arr.p[i];

		return *this;
	}
};

class DArr {
	int size;
	int* arr;

public:
	DArr(int a) {
		size = a;
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = rand() % 10;
	}

	DArr(const DArr& src) {
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
			cout << "Error! Invalid value or out of range\n";
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
			int* mass = new int[size + 1];
			memcpy(mass, arr, size * sizeof(int));
			mass[size] = val;

			size++;
			arr = mass;
		}
		else {
			cout << "Error! Invalid value\n";
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
	try {
		DArr a(7);
		cout << "a(7)\n";
		a.print();
		a.setArr(3, 88);
		a.print();
		a.addArr(9);
		a.print();
		cout << a.getArr(3) << endl;

		DArr b(a);
		cout << "b(a)\n";
		b.print();
		b.setArr(2, 34);
		b.setArr(5, 3);
		cout << "b\n";
		b.print();

		DArr c(9);
		cout << "c(9)\n";
		c.print();

		DArr d = a - b;
		cout << "d = a - b\n";
		d.print();

		DArr e = c - b;
		cout << "e = c - b\n";
		e.print();
	}
	catch (bad_alloc a) {
		cout << "Array initialization error!\n" << a.what() << endl;
	}
	catch (out_of_range b) {
		cout << "Accessing array elements error!\n" << b.what() << endl;
	}
	catch (invalid_argument c) {
		cout << "Setting array arguments error!\n" << c.what() << endl;
	}
}
