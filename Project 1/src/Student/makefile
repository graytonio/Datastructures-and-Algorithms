CC = g++
FLAGS = -g -c

all:
	$(CC) -c -o Student.o Student.cpp
	mv Student.o ../../build/

test:
	$(CC) -o StudentTest Student.cpp StudentTest.cpp ../Person/Person.cpp ../Course/Course.cpp
	mv StudentTest ../../tests/

clean:
	rm -f Student.o StudentTest
