#include <iostream>
#include <exception>
#include <cmath>

using namespace std;

template<typename T>
class Array {
	T* p;
	int size;
public:
	Array(int size) {
		this->size = size;
		p = new T[size];

		if (size == 0)
			throw std::bad_alloc();

		for (int i = 0; i < size; i++)
			p[i] = rand() % 100;
	}

	Array(const Array<T>& mas) {
		size = mas.size;
		p = new T[size];

		if (size == 0)
			throw std::bad_alloc();
		if (size > 1000)
			throw std::out_of_range();

		for (int i = 0; i < size; i++)
			p[i] = mas.p[i];
	}

	~Array() {
		delete[] p;
	}

	void set(int ind, T val) {
		if (ind < 0 || ind >= size)
			throw std::bad_alloc("Setter error. Out of range\n");
		if (val > 100 || val < -100)
			throw std::invalid_argument("Setter error. Invalid argument\n");
		else p[ind] = val;
	}

	void get(int ind) {
		if (ind < 0 || ind >= size)	{
			throw std::out_of_range("Getter error. Out of range\n");
		}
		else 
			return p[ind];
	}

	void push_back(T val) {
		if (val > 100 || val < -100)
			throw std::invalid_argument("Push_back error. Invalid argument\n");
		T* mass = new T[size + 1];
		memcpy(mass, p, size * sizeof(T));
		mass[size] = val;

		size++;
		p = mass;
	}

	void dist(Array<T>& arr) {
		double r = 0.0;
		for (int i = 0; i < arr.size - 1; i++) {
			int diff = (p[i] - arr.p[i]);
			r += diff * diff;
		}
		if (r > 0)
			r = sqrt(r);
		else
			r = 0;

		cout << "Distance between two massives is: " << r << endl;
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
		if (val < -100 || val > 100)
			throw std::invalid_argument("setArr error. Invalid value\n");		
		if	(ind < 0 || ind >= size)
			throw std::out_of_range("setArr error. Out of range\n");
		else
			arr[ind] = val;
	}

	int getArr(int ind) {
		if (ind >= 0 && ind < size)
			return arr[ind];
		else
			throw std::out_of_range("getArr error. Out of range\n");
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
			throw std::invalid_argument("setArr error. Invalid value\n");
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
		b.print();

		DArr c(9);
		c.print();

		DArr d = a - b;
		d.print();

		Array<int> f(7);
		f.print();
		Array<int> h(7);
		h.print();
		f.dist(h);
		Array<char> g(7);
		g.print();
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
