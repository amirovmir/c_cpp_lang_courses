#include <thread>
#include <mutex>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>

using namespace std;

/*
1. Разработать программу, которая включает два потока один поток моделирует полет шарика, второй отображает
в текстовом виде положение шарика на экране с заданной частотой.
Информация о траектории полета (координаты и метка времени) должны заносится в std::vector
Масса, начальная скорость и положение шарика должны задаваться в качестве параметров командной строки.
Вариант 1
Моделируем полет брошенного в вертикально вверх со скоростью v шарика массой m.
При соударении с землей шарик прилипает к поверхности.
Программа должна иметь функции:
- Вычисления положения (h) и параметров движения шарика (v, a) через заданный промежуток времени
- Печатать на экран информацию о траектории движения шарика за заданный промежуток времени
*/

const double g = 9.80665;
const double dt = 0.01;
const int print_delay = 100;
const int calc_delay = 50;

struct Ball {
	double t;
	double h;
	double v;
};
vector <Ball> states(0);

mutex vec_locker;

void modeling(double H, double V) {
	double h = H;
	double v = V;
	double t = 0;
	double t0 = (V + sqrt(V * V + 2 * g * H)) / g;

	do {
		if (t >= t0) t = t0;

		h = H + V * t - (g * t * t) / 2;
		v = V - g * t;
		t += dt;

		vec_locker.lock();
		states.push_back({ t, h, v });
		this_thread::sleep_for(chrono::milliseconds(10));
		vec_locker.unlock();

		this_thread::sleep_for(chrono::milliseconds(calc_delay - 10));
	} while(v > 0);
}

void print() {
	Ball buf;
	do {
		this_thread::sleep_for(chrono::milliseconds(print_delay - 10));

		vec_locker.lock();
		buf = states.back();
		this_thread::sleep_for(chrono::milliseconds(10));
		vec_locker.unlock();

		std::cout << fixed;
		std::cout << setprecision(2) << buf.t << '\t' << buf.h << '\t' << buf.v << endl;
	} while (buf.h > 0);
}

int main(int argc, char* argv[]) {
	double m, h, v;

	if (argc != 4) {
		std::cout << "Not enough arguments!" << endl;
		return 0;
	}
	else {
		stringstream convert(argv[1]);
		if (!(convert >> m)) {
			std::cout << "Mass convertation error!" << endl;
			return 0;
		}

		convert.clear();
		convert.str(argv[2]);
		if (!(convert >> h)) {
			std::cout << "Height convertation error!" << endl;
			return 0;
		}

		convert.clear();
		convert.str(argv[3]);
		if (!(convert >> v)) {
			std::cout << "Speed convertation error!" << endl;
			return 0;
		}
	}

	states.push_back({ 0.0, h, v });

	std::cout << endl << endl << "Time\tHeight\tSpeed" << endl;
	std::cout << fixed;
	std::cout << setprecision(2) << 0.00 << '\t' << h << '\t' << v << endl;

	thread thread_m(modeling, h, v);
	thread thread_p(print);

	thread_m.join();
	thread_p.join();

	return 1;
}
