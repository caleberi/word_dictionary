TNC= -I ./lib
CC=gcc
STD=-std=c11 
WARN=-Wall
ERRORMAX=-fmax-errors=10 -Wextra


executable: main.o word_tree.o
	$(CC) $(STD) $(WARN) $(ERRORMAX) $(INC) main.o word_tree.o  -o main

main.o: 
	$(CC) $(STD) $(WARN) $(ERRORMAX) -c main.c 

word_tree.o: 
	$(CC) $(STD) $(WARN) $(ERRORMAX) -c ./lib/word_tree.c

launch: 
	./main

clean: 
	rm word_tree.o main.o 
