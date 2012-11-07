#include <stdio.h>

int main () {
	char str[10000];
	while ( fgets (str, 9999, stdin)) {
		int i = 0;
		while (str[i] != '\0') {
			if (str[i] != '\n') {
				str[i]-=7;
			}
			putchar (str[i++]);
		}
	}

	return 0;
}
