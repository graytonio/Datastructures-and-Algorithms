# Project 1

The first project is designed to display and modify student record data
The CSV files in the res/ directory were used during testing
Built on Ubuntu 18.04.1 using g++ v7.3.0

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

### Course - Contain an individual course record for an individual student
```
Course/Course.h - Course Class Interface
Course/Course.cpp - Course Class Implementation
Course/CourseTest.cpp - Course Class Test Program
Course/makefile - makefile for the Course Class and Test
```

### Database - Reads/Writes to the csv files to manage the current Records Object
```
Database/Database.h - Database Class Interface
Database/Database.cpp - Database Class Implementation
Database/DatabaseTest.cpp - Database Class Test Program
Database/makefile - makefile for the Database Class and Test
```

### Menu - Contains the options available to the user as well as processing all user input 
```
Menu/Menu.h - Menu Class Interface
Menu/Menu.cpp - Menu Class Implementation
Menu/MenuTest.cpp - Course Class Test Program
Menu/makefile - makefile for the Menu Class and Test
```

### Person - The base class containing basic person information
```
Person/Person.h - Person Class Interface
Person/Person.cpp - Person Class Implementation
Person/PersonTest.cpp - Person Class Test Program
Person/makefile - makefile for the Person Class and Test
```
### Records - Contains the current set of students in memory with tools to easily modify and add to the set
```
Records/Records.h - Records Class Interface
Records/Records.cpp - Records Class Implementation
Records/RecordsTest.cpp - Records Class Test Program
Records/makefile - makefile for the Records Class and Test
```
### Student - Contains the information relevant to a student including a list of current Courses
Student/Student.h - Student Class Interface
Student/Student.cpp - Student Class Implementation
Student/StudentTest.cpp - Student Class Test Program
Student/makefile - makefile for the Student Class and Test
