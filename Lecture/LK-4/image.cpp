#include <iostream>

/*
Вариант 1
Реализовать перегрузку операции присваивания =
*/

using namespace std;

class Image {
	int* img;
	int mx, my;

public:
	Image(int tmx, int tmy) : mx(tmx), my(tmy) {
		img = new int[mx * my]();
	};

	virtual ~Image() {
		delete[] img;
	};

	int get(int x, int y);
	void set(int x, int y, int color);

	Image operator=(const Image& v) {
		this->mx = v.mx;
		this->my = v.my;
		return *this;
	};
	void show();
};

int Image::get(int x, int y) {
	if (x >= 0 && x < mx && y >= 0 && y < my)
		return img[y * my + x];
}

void Image::set(int x, int y, int color) {
	if (x >= 0 && x < mx && y >= 0 && y < my)
		img[y * my + x] = color;
}

void Image::show() {
	for (int i = 0; i < my; ++i) {
		for (int j = 0; j < mx; ++j) {
			cout << img[i * my + j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	Image img1(4, 5);
	img1.set(4, 0, 1);
	img1.set(1, 2, 1);

	Image img2 (3, 4);
	img2.set(1, 3, 2);
	img2.set(1, 0, 1);

	cout << img1.get(1, 2) << endl;
	cout << img2.get(1, 3) << endl;

	img1.show();

	return 0;
}
