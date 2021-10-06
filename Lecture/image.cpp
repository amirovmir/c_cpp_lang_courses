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
    }
    virtual ~Image() {
        delete[] img;
    };
    int get(int x, int y) {
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
    
    int set(int x, int y, int color) {
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
    Image operator=(const Image& v) {
        mx = v.mx; 
        my = v.my;
        return *this;
    }
};

int main() {
    try {
        Image img1(5, 5);
        img1.set(4, 0, 1);
        img1.set(1, 2, 1);

        Image img2(5, 5);
        img2.set(1, 3, 2);
        img2.set(1, 0, 1);

        if (img1 == img2) {
            cout << "Error, same format" << endl;
        }

        cout << img1.get(5, 1) << endl;
        cout << img2.get(2, 4) << endl;
    }
    catch (int) {
        cout << "Out of range\n";
    }
}