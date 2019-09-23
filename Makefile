word: main.c 
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra main.c -o word

launch: word
	./word