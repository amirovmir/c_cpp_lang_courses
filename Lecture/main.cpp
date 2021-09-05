#include <iostream>
#include "strutil.h"

/*
Задание 2
Написать функцию для определения наличия строки a в строке str
int strConteins(char *a, char* str)
Возвращает -1, если не содержит
Позицию начала, если содержит
Примечание:
1. Функция ищет только первое вхождение
2. Программа должна включать следующие файлы:
main.cpp – функции для тестирование strConteins
strutil.cpp – реализация функции strConteins
strutil.h - объявление функции strConteins
*/

int main() {
	char ch1[50], ch2[100];
	std::cin >> ch1 >> ch2;

	std::cout << strConteins(ch1, ch2);
	return 0;
}