#include "Database.h"

using namespace std;

int main(){
        Database d("../res/default.csv", "../res/coursesDefaults.csv"); //Create the Database with the res files
        Records* r = d.getRecords(); //Get the records from the database object
        cout << *r; //Check that the records were loaded correctly
        return 0;
}
