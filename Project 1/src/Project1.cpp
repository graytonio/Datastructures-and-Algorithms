#include <iostream>
#include "Database/Database.h"
#include "Records/Records.h"

using namespace std;

int main(){
        Database d("default.csv", "coursesDefaults.csv");
        Records r = d.getRecords();
        cout << r;

        return 0;
}
