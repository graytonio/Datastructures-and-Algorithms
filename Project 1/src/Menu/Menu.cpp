#include "Menu.h"
using namespace std;

//Default Constructor
Menu::Menu(){

}

//Base Constructor
Menu::Menu(Database dataPar){
        data = dataPar;
}

//Print all the Menu Options and process the selection
bool Menu::printMenu(){
        clearConsole(); //Clear the Console
        uint8_t select;

        //Print all the Options
        cout << "Please select one of the following:" << endl;
        cout << "[1] Print all records" << endl;
        cout << "[2] Print the record for a single student" << endl;
        cout << "[3] Add a student" << endl;
        cout << "[4] Delete a student" << endl;
        cout << "[5] Add a course to a student" << endl;
        cout << "[6] Delete a course from a student" << endl;
        cout << "[7] Exit" << endl;
        cout << "Enter your selection: ";
        cin >> select; //Read the input from the user

        //Send the user to the proper function based on the input
        switch(select) {
        case '1':
                printRecords(); //Print all records
                break;
        case '2':
                printSingleRecord(); //Print a single Record
                break;
        case '3':
                addStudent(); //Add a student
                break;
        case '4':
                deleteStudent(); //Delete a student
                break;
        case '5':
                addCourse(); //Add a course to a student
                break;
        case '6':
                deleteCourse(); //Delete a course from a student
                break;
        case '7':
                return false; //Exit the program
                break;
        default:
                cout << select << " is not an option" << endl; //Unrecognized Option
        }

        cout << "Press Enter to Continue"; //Wait for User to continue program
        cin.ignore();
        return true;
}

//Print all the Student Records
void Menu::printRecords(){
        cout << endl << *data.getRecords(); //Get the Records from the database and print it
        cin.ignore();
}

//Ask the user for a UID and print the matching Student
void Menu::printSingleRecord(){
        string uid;
        cout << "Enter the student UID: "; //Ask user for UID of student to print
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Fixed issue with multiple cins in a row
        cin >> uid;

        if(isNumber(uid)) { //Validate that the input was a number
                Student* selected = data.getRecords()->getStudent((uint32_t) stoi(uid)); //Get the student from the records object

                if(selected != NULL) cout << endl << *selected; //If the student was found print it
                else cout << "Invalid ID" << endl; //If the student was not found print the error
        }else cout << "Invalid ID" << endl; //If the input was not a number print the error
        cin.ignore();
}

//Add a student to the records
void Menu::addStudent(){
        Student s; //Temp Student Object to build the new record
        string input;
        cout << "\nEnter the User ID: "; //Ask user for UID of new Student
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Fixed issue with multiple cins in a row
        cin >> input;
        s.setUID((uint32_t) stoi(input)); //Set temp Student Obect UID

        cout << "Enter Name: "; //Ask user for Name of new Student
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Fixed issue with multiple cins in a row
        getline(cin, input);
        s.setName(input); //Set temp Student Object Name

        cout << "Enter Age: "; //Ask user for Age of new Student
        cin >> input;
        s.setAge((uint32_t) stoi(input)); //Set temp Student Object Age
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Fixed issue with multiple cins in a row

        data.getRecords()->addStudent(s); //Add copy of temp Student Object to records
        cout << "\nStudent Added" << endl;
}

//Remove student from the records
void Menu::deleteStudent(){
        string input;
        cout << "\nEnter the User ID: "; //Ask the user for the UID of the student to remove
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Fixed issue with multiple cins in a row
        cin >> input;

        Student s = data.getRecords()->deleteStudent((uint32_t) stoi(input)); //Send UID to records to remove if student exists
        if(s.getName() != "NA") cout << "\n" << s.getName() << " Deleted" << endl; //If student was found say it was removed
        else cout << "\nStudent not found" << endl; //Else print the error
        cin.ignore();
}

//Add a course to a student
void Menu::addCourse(){
        string input;
        cout << "\nEnter the User ID: "; //Ask the user for the UID of the student to add the course to
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Fixed issue with multiple cins in a row
        cin >> input;
        Student* s = data.getRecords()->getStudent((uint32_t) stoi(input)); //Find the student based on the UID provided by the user

        if(s != NULL) { //If the student was found
                Course c; //Temp Course Object for building the new Course

                cout << "Enter Course Code: "; //Ask the user for the Course Code
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Fixed issue with multiple cins in a row
                cin >> input;
                c.setCode(input); //Set the temp Course Code to the input value

                cout << "Enter Course Title: "; //Ask the user for the Course Title
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Fixed issue with multiple cins in a row
                cin >> input;
                c.setTitle(input); //Set the temp Course Title to the input value

                cout << "Enter Course Credit Hours: "; //Ask the user for the Course Credit Hours
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Fixed issue with multiple cins in a row
                cin >> input;
                if (isNumber(input)) c.setCreditHour((uint8_t) stoi(input)); //Set the temp Course Credir Hours to the input value if input is number
                else {
                        cout << "Invalid Credit Hours Input" << endl;
                        return;
                }

                cout << "Enter Grade: "; //Ask the user for the Course Grade
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Fixed issue with multiple cins in a row
                cin >> input;
                if(isNumber(input)) c.setGrade(stod(input));
                else{
                        cout << "Invalid Grade Input" << endl;
                        return;
                }

                s->addCourse(c);  //Add Course to the Student

                cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Fixed issue with multiple cins in a row
                cout << "Add a course" << endl;
        }else cout << "Student not found" << endl;
}

//Remove a course from a Student
void Menu::deleteCourse(){
        string input;
        cout << "Enter User ID: "; //Ask the user for the UID of the Student
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Fixed issue with multiple cins in a row
        cin >> input;
        Student* s = NULL;
        if(isNumber(input)) s = data.getRecords()->getStudent((uint32_t) stoi(input)); //Get the Student by UID input
        if(s != NULL) {
                cout << "Enter Course Code: "; //Ask the user for the Course Code to delete
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Fixed issue with multiple cins in a row
                cin >> input;
                if(s->deleteCourse(input)) { //If the course was found and deleted
                        cout << input << " removed from " << s->getName() << endl;
                }else{ //Else print the error
                        cout << input << " is not a valid Course Code" << endl;
                }
        }
        else cout << "Invalid UID" << endl;
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Fixed issue with multiple cins in a row
}

//Function to "Clear" the terminal window
void Menu::clearConsole(){
        for(uint8_t i=0; i<200; i++) {
                cout << endl;
        }
}

//Validate that a string is a number
bool Menu::isNumber(string s) {
        for (int i = 0; i < s.length(); i++) //For every character in the string
                if (isdigit(s[i]) == false) //If the character is not a digit
                        return false; //return false

        return true; //All characters are digits therefore the string is a number
}
