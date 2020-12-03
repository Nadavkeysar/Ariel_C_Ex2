CC=gcc
FLAGS= -Wall -g
AR =ar 


all: main	

main: main.o myBank.o
	$(CC) $(FLAGS) -o main main.o myBank.o  -lm

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c

main.o: main.c myBank.h 
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.so *.a main