CC = g++
FLAGS = -g -c

all:
	$(CC) -c -o Student.o Student.cpp
	mv Student.o ../../build/

test:
	$(CC) -o StudentTest Student.cpp StudentTest.cpp ../Person/Person.cpp ../Course/Course.cpp

clean:
	rm -f Student.o StudentTest
