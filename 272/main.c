#include <stdio.h>
#include <string.h>

#define MAX_LINE 10000
#define OPEN_QUOTE '`'
#define CLOSE_QUOTE '\''
#define DOUBLE_QUOTE '"'

void subs (char *s, int i, char ch) {
	int len = strlen (s);
	int pos = len - 1;
	while (pos >= i) {
		s[pos+1] = s[pos];
		pos--;
	}

	s[i] = s[i+1] = ch;
	s[len+1]='\0';
}

int main () {
	char line[MAX_LINE];
	int is_open = 0;
	do {
		if (fgets (line, MAX_LINE-1, stdin) != NULL) { 
			int i;
			for (i = 0; i < strlen (line) - 1; i++) {
				if (line[i] == DOUBLE_QUOTE) {
					subs (line, i,
							is_open ? CLOSE_QUOTE : OPEN_QUOTE);
					is_open = !is_open;
				}
			}

			printf ("%s", line);
		}
	} while (!feof (stdin));
	return 0;
}
