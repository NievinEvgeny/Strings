all: main.c strings.c strings.h
		gcc -Wall -o str strings.c main.c
clean:
		rm str