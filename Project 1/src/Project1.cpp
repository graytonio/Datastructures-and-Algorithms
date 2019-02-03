#include <iostream>
#include "Database/Database.h"
#include "Menu/Menu.h"

using namespace std;

int main(){

        Menu m("res/default.csv", "res/coursesDefaults.csv"); //Initialize the Menu Object with a Database using the required paths
        while(m.printMenu()); //While the user has not requested to exit, print the menu and process the selection

        return 0;
}
