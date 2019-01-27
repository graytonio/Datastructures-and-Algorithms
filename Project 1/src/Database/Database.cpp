#include "Database.h"
using namespace std;

//Default Constructor
Database::Database(){
}

//Base Constructor
Database::Database(string pathStudentsPar, string pathCoursesPar){
        pathStudents = pathStudentsPar;
        pathCourses = pathCoursesPar;
        records = loadData(); //Load the Data from the file paths passed into the constructor
}

//Student File Path Getter
string Database::getPathStudents(){
        return pathStudents;
}

//Student File Path Setter
void Database::setPathStudents(string path){
        Database::pathStudents = path;
}

//Courses File Path Getter
string Database::getPathCourses(){
        return pathCourses;
}

//Courses File Path Setter
void Database::setPathCourses(string path){
        Database::pathCourses = path;
}

//Records Object Getter
Records* Database::getRecords(){
        return &records;
}

//Records Object Setter
void Database::setRecords(Records records){
        Database::records = records;
}

//Function for reading and parsing the data into memory
Records Database::loadData(){
        vector<Student> students; //Vector for holding Student Records
        vector<Course> courses; //Vector for holding Course REcords
        Student tempStudent; //Temporary holding container for each record in csv file
        string cell; //Temporary holding variable for each value in the csv record

        ifstream inputFile(pathStudents); //Read in student csv file

        while(getline(inputFile, cell, ',')) { //Read the line up to a comma and store it into the holding variable
                tempStudent.setUID((uint32_t) stoi(cell)); //Set the temp student UID to the read value

                getline(inputFile, cell, ','); //Read the line from the previous place up to a comma and store it into the holding variable
                tempStudent.setName(cell); //Set the temp student Name to the read value

                getline(inputFile, cell, ','); //Read the line from the previous place up to a comma and store it into the holding variable
                tempStudent.setAge((uint32_t) stoi(cell)); //Set the temp student age to the read value

                getline(inputFile, cell, ','); //Read the line from the previous place up to a comma and store it into the holding variable
                tempStudent.setTotalCreditHours((uint32_t) stoi(cell)); //Set the temp student credit hours to the read value

                getline(inputFile, cell, ','); //Read the line from the previous place up to a comma and store it into the holding variable
                tempStudent.setNumberOfCourses((uint32_t) stoi(cell)); //Set the temp student number of courses to the read value

                getline(inputFile, cell); //Read the rest of the line up to carriage return
                tempStudent.setGPA((double) stod(cell)); //Set the temp student gpa to the read value

                students.push_back(tempStudent); //Push a copy of the temp student object to the vector
        }

        Course tempCourse; //Temp Course object to build each course record
        Student *currentStudent = NULL; //Student pointer to update the student records already in the student vector

        ifstream inputCourse(pathCourses); //Read the courses information
        while(getline(inputCourse, cell, ',')) { //Read the line up to a comma

                for(vector<Student>::iterator i = students.begin(); i != students.end(); i++) { //Iterate through the vector
                        if((*i).getUID() == (uint32_t) stoi(cell)) { //If the read value for the UID matches a record in the students vector
                                currentStudent = &(*i); //Set the student pointer to point at the student in the vector
                                break; //Break the loop
                        }
                }

                getline(inputCourse, cell, ','); //Read the line up to a comma from the previous position
                tempCourse.setCode(cell); //Set the temp Course code to the read value

                getline(inputCourse, cell, ','); //Read the line up to a comma from the previous position
                tempCourse.setTitle(cell); //Set the temp Course title to the read value

                getline(inputCourse, cell, ','); //Read the line up to a comma from the previous position
                tempCourse.setCreditHour((uint8_t) stoi(cell)); //Set the temp Course credit hour to the read value

                getline(inputCourse, cell); //Read the rest of the line
                tempCourse.setGrade(stod(cell)); //Set the temp course to the read value

                currentStudent->addCourse(tempCourse); //Push the temp course to the student in the vector
        }

        Records r(students); //Create a Records object with the resulting students vector
        return r; //Return the Records Object
}

//Write the current student and course data to the record files
void Database::saveData(){
        ofstream file;

        file.open(pathStudents); //Erase Student CSV
        file.close();
        file.open(pathCourses); //Erase Course CSV
        file.close();

        for(Student s : records.getStudents()) { //For every student
                file.open(pathStudents, std::ios_base::app); //Append the student data to the student file
                file << s.getUID() << "," << s.getName() << "," << unsigned(s.getAge()) << "," << s.getTotalCreditHours() << "," << s.getNumberOfCourses() << "," << s.getGPA() << "\n";
                file.close();

                file.open(pathCourses, std::ios_base::app);
                for(Course c : s.getCourses()) { //Write a record for every course record in the student object
                        file << s.getUID() << "," << c.getCode() << "," << c.getTitle() << "," << unsigned(c.getCreditHour()) << "," << c.getGrade() << "\n";
                }
                file.close();
        }
}
