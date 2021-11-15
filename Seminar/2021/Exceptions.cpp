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
		if (size <= 0)
			throw std::invalid_argument("Size error. Out of range\n");
		
		this->size = size;
		p = new T[size];

		for (int i = 0; i < size; i++)
			p[i] = rand() % 100;
	}

	Array(const Array<T>& mas) {
		size = mas.size;
		p = new T[size];

		if (size <= 0)
			throw std::invalid_argument();

		for (int i = 0; i < size; i++)
			p[i] = mas.p[i];
	}

	~Array() {
		delete[] p;
	}

	void set(int ind, T val) {
		if (std::is_same<T, int>::value) {
			if (val < -100 || val > 100)
				throw std::invalid_argument("Setter error. Invalid argument\n");
		}
		if (ind < 0 || ind >= size)
			throw std::invalid_argument("Setter error. Out of range\n");
		else
			p[ind] = val;
	}

	void get(int ind) {
		if (ind < 0 || ind >= size)	{
			throw std::out_of_range("Getter error. Out of range\n");
		}
		else 
			return p[ind];
	}

	void push_back(T val) {
		if (std::is_same<T, int>::value) {
			if (val > 100 || val < -100)
				throw std::invalid_argument("Push_back error. Invalid argument\n");
		}
		else {
			T* mass = new T[size + 1];
			memcpy(mass, p, size * sizeof(T));
			mass[size] = val;

			size++;
			p = mass;
		}
	}

	void dist(Array<T>& arr) {
		if (std::is_same<T, int>::value) {
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
		else
			throw std::logic_error("Lofic failure\n");
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

int main() {
	try {
		Array<char> a(7);
		a.print();
		Array<char> b(7);
		b.print();
		a.dist(b);
		Array<char> c(7);
		c.print();
	}
	catch (exception& e) {
		cerr << "Caught: " << e.what() << endl;
		cerr << "Type: " << typeid(e).name() << endl;
	};
}
