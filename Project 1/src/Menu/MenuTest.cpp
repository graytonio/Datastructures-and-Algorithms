#include "Menu.h"
#include "../Database/Database.h"

using namespace std;

int main(){
        Database d("../res/default.csv", "../res/coursesDefaults.csv");
        Menu m(d);
        while(m.printMenu());
        return 0;
}
