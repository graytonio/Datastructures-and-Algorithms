CC = g++
FLAGS = -g -c

all:
	$(CC) -c -o Person.o Person.cpp
	mv Person.o ../../build/

test:
	$(CC) -o PersonTest Person.cpp PersonTest.cpp
	mv PersonTest ../../tests/

clean:
	rm -f Person.o PersonTest
