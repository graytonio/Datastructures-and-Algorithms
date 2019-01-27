CC = g++
FLAGS = -g -c

all:
	$(CC) -c -o Records.o Records.cpp
	mv Records.o ../../build/

test:
	$(CC) -o RecordsTest Records.cpp RecordsTest.cpp ../Student/Student.cpp ../Person/Person.cpp ../Course/Course.cpp
	mv RecordsTest ../../tests/

clean:
	rm -f Records.o RecordsTest
