# Project 2

This project is designed to generate and solve mazes using a backtracking algorithm
Built on Ubuntu 18.04.1 using g++ v7.3.0

The input of the maze is done by passing command line arguments to the program with the first argument being the size of the maze and the second being the percent free and the third indicating weather the path should be drawn with individual step markers (2) or drawing a path (1)

```
./Project2 10 70 2

+----------+
|   *      |
|*   *  *@*|
|*      *  |
|  *  *  *#|
|   *  *   |
|     *   *|
| *   **  *|
|* * ** *  |
|  *  *+* *|
|  *     * |
+----------+
```

```
./Project2 10 70 1

+----------+
|*  *@@@@@*|
|** @@ **@*|
|  *@  * @@|
|* @@*   *@|
|* @  **  @|
| *+*  *  @|
|*  @@* * @|
| * #@@@@@@|
|     *@@@@|
|****  @@**|
+----------+
```
(Both methods of drawing draw each step through the maze to reach the goal)

The maze will then be printed and it will begin to search for a path

If a path is found it will begin printing the steps of the path by placing a @ on the next cell in the path from the start indicated by a + to the end indicated by a #

### Building

To build the main executable

```
mkdir build
make
```
The executable will be available in the root directory

To build the tests

```
mkdir tests
make test
```

The test executables are stored in the test folder and should be executed from there

To clean all the compiled code

```
make clean
```

## Running the tests

Move into the test/ directory and execute the nesessary test

## File Descriptions

### Maze.cpp/Maze.h
```
Handles the generation and controlling locations in the maze
```

### MazeCell.cpp/MazeCell.h
```
Stores the position and status of each cell in the maze cell
```

### Stack.cpp/Stack.h
```
Contains the stack information for printing the found path if it was found
```
