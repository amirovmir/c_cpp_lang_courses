#include <iostream>

using namespace std;

/*�������� ���������, �������:
-����� ������ ��������� ����, ������� ����� ���� ������ �� � �������� ��������� ��������� ������ � �������� �������� ��������(���� �� ������)
������ ����� :
	wolf
	dog
	tiger
- ��������� ������ Animal, Dog, Tiger, Wolf
- ������ Dog, Tiger, Wolf �������� ������������ Animal
- ����� Animal ���������� ����������� ����� void voice()
- ������ Dog, Tiger, Wolf �������������� ����������� ����� void voice(), ����� Dog ������� �� ����� gav, Tiger - rrr, Wolf - WoU
������������� :
������� 1.
- ������� ������������ ������ ����������(������ ����� ����� �������� � �����) �� ����� Animal � �������
��� ���������� ���� �������, ��������������� ��������, ��������� �� �����
- �������� ������� ��� ������ ���� �������� void showAll(Animal * p, int number_of_animal)
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