#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const int SIZE = 30;

/*Написать программу, которая:
-умеет читать текстовый файл, который может быть указан ей в качестве аргумента командной строки и содержит названия животных(одно на строке)
Пример файла :
	wolf
	dog
	tiger
- Реализует классы Animal, Dog, Tiger, Wolf
- Классы Dog, Tiger, Wolf являются наследниками Animal
- Класс Animal определяет виртуальный метод void voice()
- Классы Dog, Tiger, Wolf переопределяют виртуальный метод void voice(), чтобы Dog выдавал на экран gav, Tiger - rrr, Wolf - WoU
Дополнительно :
Вариант 1.
- Создать динамический массив указателей(размер равен числу животных в файле) на класс Animal и функцию
для добавления туда классов, соответствующих животным, считанным из файла
- Написать функцию для печати всех животных void showAll(Animal * p, int number_of_animal)
*/

class Animal {
public:
	virtual void voice(char* buf) = 0;
};

class Dog : public Animal {
public:
	void voice() {
		cout << "gav\n";
	}
};

class Tiger : public Animal {
public:
	void voice() {
		cout << "rrr\n";
	}
};

class Wolf : public Animal {
public:
	void voice() {
		cout << "WoU\n";
	}
};

void showAll(Animal** p, int number_of_animal) {
	char fromconsole[SIZE];
	cin >> fromconsole;

	for (int i = 0; i < number_of_animal; i++) {
		p[i]->voice(fromconsole);
		cout << endl;
	}
}

void fileReader(string fDir, Animal** p) {
	string line;
	ifstream in(fDir);
	int calc = 0;
	
	if (in.is_open()) {
		while (getline(in, line)) {
			calc++;
		}

		in.seekg(0, ios::beg);
		p = new Animal * [calc];
		int i = 0;

		while (getline(in, line)) {
			if ((const char*) line[0] == 'w') {
				p[i] = new Wolf;
			}
			if ((const char*)line[0] == 'd') {
				p[i] = new Dog;
			}
			if ((const char*)line[0] == 't') {
				p[i] = new Tiger;
			}
			i++;
		}
		showAll(p, calc);
		delete[] p;
	}
	in.close();
}

int main(string txt) {
	Animal** anim = nullptr;
	fileReader(txt, anim);

	return 0;
}
