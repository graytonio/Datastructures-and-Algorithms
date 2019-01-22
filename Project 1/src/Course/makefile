CC = g++
FLAGS = -g -c

all:
	$(CC) -c -o Course.o Course.cpp
	mv Course.o ../../build/

test:
	$(CC) -o CourseTest Course.cpp CourseTest.cpp

clean:
	rm -f Course.o CourseTest
