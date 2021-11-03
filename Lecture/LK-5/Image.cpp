#include <iostream>

using namespace std;

template<typename DataType, std::size_t mx, std::size_t my>
class Image {
    DataType* img;
    size_t tmx = mx;
    size_t tmy = my;

public:
    Image() {
        img = new int[mx * my]();
    };

    virtual ~Image() {
        delete[] img;
    }

    int get(int x, int y);
    int set(int x, int y, int color);
    Image operator=(const Image& v) { 
        mx = v.mx;
        my = v.my;
        return *this;
    }
};

template<typename DataType, std::size_t mx, std::size_t my>
int Image<DataType, mx, my>::get(int x, int y) {
    try {
        if (x > mx || y > my || x < 0 || y < 0)
            throw 404;
    }
    catch (int error) {
        cout << "Eror " << error << endl;
        exit(1);
    }

    return img[y * my + x];
}

template<typename DataType, std::size_t mx, std::size_t my>
int Image<DataType, mx, my>::set(int x, int y, int color) {
    try {
        if (x >= mx || y >= my || x < 0 || y < 0)
            throw 404;
    }
    catch (int error) {
        cout << "Eror " << error << endl;
        exit(1);
    }
    img[y * my + x] = color;
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
    }
    catch (int f) {
        if(f == '404')
            cout << "Out of range. Element not found\n";
    }
}
