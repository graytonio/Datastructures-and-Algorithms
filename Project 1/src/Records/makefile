CC = g++
FLAGS = -g -c

all:
	$(CC) -c -o Records.o Records.cpp
	mv Student.o ../../build/

test:
	$(CC) -o RecordsTest Records.cpp RecordsTest.cpp ../Student/Student.cpp ../Person/Person.cpp ../Course/Course.cpp

clean:
	rm -f Records.o RecordsTest
