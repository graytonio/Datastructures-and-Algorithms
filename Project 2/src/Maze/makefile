CC = g++
FLAGS = -g -c

all:
	$(CC) -c -o Maze.o Maze.cpp
	$(CC) -c -o MazeCell.o MazeCell.cpp
	$(CC) -c -o Stack.o Stack.cpp
	mv Maze.o ../../build/
	mv MazeCell.o ../../build/
	mv Stack.o ../../build/

test:
	$(CC) -o MazeTest Maze.cpp MazeTest.cpp MazeCell.cpp Stack.cpp
	mv MazeTest ../../tests/

clean:
	rm -f Maze.o MazeTest
