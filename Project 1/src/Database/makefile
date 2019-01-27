CC = g++
FLAGS = -g -c

all:
	$(CC) -c -o Database.o Database.cpp
	mv Database.o ../../build/

test:
	$(CC) -o DatabaseTest Database.cpp DatabaseTest.cpp ../Student/Student.cpp ../Person/Person.cpp ../Course/Course.cpp ../Records/Records.cpp
	mv DatabaseTest ../../tests/

clean:
	rm -f Records.o RecordsTest
