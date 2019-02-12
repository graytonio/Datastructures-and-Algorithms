CC = g++
FLAGS = -g -c
MODULE = $(abspath $(dir $(lastword $(MAKEFILE_LIST))

all:
	$(CC) -c -o Course.o Course.cpp
	mv Course.o ../../build/

test:
	$(CC) -o CourseTest Course.cpp CourseTest.cpp
	mv CourseTest ../../tests/

clean:
	rm -f Course.o CourseTest

echo $(MODULE)
