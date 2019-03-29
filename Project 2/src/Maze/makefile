CC = g++
FLAGS = -g -c

all:
	$(CC) -c -o Maze.o Maze.cpp
	mv Maze.o ../../build/

test:
	$(CC) -o MazeTest Maze.cpp MazeTest.cpp MazeCell.cpp
	mv MazeTest ../../tests/

clean:
	rm -f Maze.o MazeTest
