#include <iostream>
#include <exception>

using namespace std;

template<typename T, std::size_t tmx, std::size_t tmy>
class Image {
    T* img;
    size_t mx;
    size_t my;

public:
    Image() {
        mx = tmx;
        my = tmy;
        img = new T[mx * my];

        for (int i = 0; i < tmy; ++i) {
            for (int j = 0; j < tmx; ++j) {
                img[i * tmy + j] = rand() % 10;
            }
        }
    };
    Image(const Image& v) {
        img = new T[tmx * tmy];

        int buf = tmx * tmy;
        for (int i = 0; i < buf; i++) {
            img[i] = v.img[i];
        }
    }

    ~Image() {
        delete[] img;
    }

    int get(int x, int y);
    int set(int x, int y, int color);
    void print();
    Image operator=(const Image& v) {
        this->mx = v.mx;
        this->my = v.my;
        return *this;
    }
};

template<typename T, std::size_t tmx, std::size_t tmy>
int Image<T, tmx, tmy>::get(int x, int y) {
    if (x >= 0 && x < tmx && y >= 0 && y < tmy)
        return img[y * tmy + x];
    else
        throw std::out_of_range("Getter error! Out of range\n");
}

template<typename T, std::size_t tmx, std::size_t tmy>
int Image<T, tmx, tmy>::set(int x, int y, int color) {
    if (x >= 0 && x < tmx && y >= 0 && y < tmy)
        img[y * tmy + x] = color;
    else
        throw std::out_of_range("Setter error! Out of range\n");
}

template<typename T, std::size_t tmx, std::size_t tmy>
void Image<T, tmx, tmy>::print() {
    for (int i = 0; i < tmy; ++i) {
        for (int j = 0; j < tmx; ++j) {
            cout << img[i * tmy + j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    try {
        Image<int, 5, 5> img1;
        img1.set(4, 0, 1);
        img1.set(1, 2, 1);

        Image<int, 5, 5> img2;
        img2.set(1, 3, 2);
        img2.set(1, 0, 1);

        cout << img1.get(1, 2) << endl;
        cout << img2.get(1, 3) << endl;

        img1.print();
    }

    catch (exception& e) {
        cerr << "Caught: " << e.what() << endl;
        cerr << "Type: " << typeid(e).name() << endl;
    };
}
