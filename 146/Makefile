all: 
	gcc -g -Wall -lm -lcrypt -O2 -pipe -ansi -DONLINE_JUDGE main.c -o main

tests:
	gcc -g -Wall -lm -lcrypt -O2 -pipe -ansi -DONLINE_JUDGE -DTEST main.c -o tst-main && ./tst-main
