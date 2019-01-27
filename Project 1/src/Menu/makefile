CC = g++
FLAGS = -g -c

all:
	$(CC) -c -o Menu.o Menu.cpp
	mv Menu.o ../../build/

test:
	$(CC) -o MenuTest Menu.cpp MenuTest.cpp ../Student/Student.cpp ../Person/Person.cpp ../Course/Course.cpp ../Records/Records.cpp ../Database/Database.cpp
	mv MenuTest ../../tests/

clean:
	rm -f Menu.o MenuTest
