#include <iostream>

using namespace std;

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
	virtual void voice();
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

void showAll(Animal* p, int number_of_animal) {

}

void fileReader() {

}

int main() {

	return 0;
}