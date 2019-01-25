#include "Menu.h"
#include "../Database/Database.h"

using namespace std;

int main(){
        Database d("default.csv", "coursesDefaults.csv");
        Menu m(d);
        while(m.printMenu());
        return 0;
}
