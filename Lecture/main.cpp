#include <iostream>
#include "strutil.h"

/*
������� 2
�������� ������� ��� ����������� ������� ������ a � ������ str
int strConteins(char *a, char* str)
���������� -1, ���� �� ��������
������� ������, ���� ��������
����������:
1. ������� ���� ������ ������ ���������
2. ��������� ������ �������� ��������� �����:
main.cpp � ������� ��� ������������ strConteins
strutil.cpp � ���������� ������� strConteins
strutil.h - ���������� ������� strConteins
*/

int main() {
	char ch1[50], ch2[100];
	std::cin >> ch1 >> ch2;

	std::cout << strConteins(ch1, ch2);
	return 0;
}