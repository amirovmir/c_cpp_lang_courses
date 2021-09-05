#include <string>

int strConteins(char *a, char* str) {
	int pos = -1;
	int i = 0, j = 0;
	while (i < strlen(str)) {
		if (str[i] == a[0])	{
			pos = i;
			for (j = 1; j < strlen(a); j++) {
				i++;
				if (a[j] != str[i]) {
					pos = -1;
					break;
				}
			}

		}
		i++;
		if (pos != -1)
			break;
	}
	pos++;
	return pos;
}