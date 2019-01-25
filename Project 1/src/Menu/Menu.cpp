#include "Menu.h"
using namespace std;

Menu::Menu(){

}

Menu::Menu(Database dataPar){
        data = dataPar;
}

bool Menu::printMenu(){
        uint8_t select;
        cout << "\nPlease select one of the following:" << endl;
        cout << "[1] Print all records" << endl;
        cout << "[2] Print the record for a single student" << endl;
        cout << "[3] Add a student" << endl;
        cout << "[4] Delete a student" << endl;
        cout << "[5] Add a course to a student" << endl;
        cout << "[6] Delete a course from a student" << endl;
        cout << "[7] Exit" << endl;
        cout << "Enter your selection: ";
        cin >> select;

        switch(select) {
        case '1':
                printRecords();
                break;
        case '2':
                printSingleRecord();
                break;
        case '3':
                addStudent();
                break;
        case '4':
                deleteStudent();
                break;
        case '5':
                addCourse();
                break;
        case '6':
                deleteCourse();
                break;
        case '7':
                return false;
                break;
        default:
                cout << select << " is not an option" << endl;
        }
        return true;
}

void Menu::printRecords(){
        cout << data.getRecords() << endl;
}

void Menu::printSingleRecord(){
        cout << "Enter the student UID: ";
        uint32_t uid = 0;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin >> uid;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        Student* selected = data.getRecords().getStudent(uid);
        if(selected != NULL) cout << *data.getRecords().getStudent(uid);
        else cout << "Invalid ID" << endl;
}

void Menu::addStudent(){
        //TODO: Implement Add Student
        cout << "Add a student" << endl;
}

void Menu::deleteStudent(){
        //TODO: Implement Delete Student
        cout << "Delete a student" << endl;
}

void Menu::addCourse(){
        //TODO: Implement Add Course
        cout << "Add a course" << endl;
}

void Menu::deleteCourse(){
        //TODO: Implement Delete Course
        cout << "Delete a course" << endl;
}
