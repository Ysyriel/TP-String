CFLAGS=-std=c++11 -Wall -Wextra

all: main

main: main.o string.o
	g++ $(CFLAGS) main.o string.o -o main

main.o: main.cpp string.h
	g++ $(CFLAGS) -c main.cpp -o main.o

string.o: string.cpp string.h
	g++ $(CFLAGS) -c string.cpp -o string.o

clean:
rm -f *.o
