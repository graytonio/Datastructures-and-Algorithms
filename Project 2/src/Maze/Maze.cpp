#include "Maze.h"
using namespace std;

Maze::Maze(uint8_t size, uint8_t percentFree, uint32_t seed){
        srand(seed); //Set Seed
        Maze::size = size;
        Maze::percentFree = percentFree;
        generateBoard(); //Generate Cells

}

Maze::Maze(uint8_t size, uint8_t percentFree){
        srand(time(0)); //Random Seed
        Maze::size = size;
        Maze::percentFree = percentFree;
        generateBoard(); //Generate Cells
}

void Maze::generateBoard(){
        origin = NULL;
        numberObst = (size*size) - ((size*size) * (percentFree/100.0));
        MazeCell *p, *row;
        for (uint8_t i = 0; i < size; i++) { //Rows
                row = origin; //Start at top
                if (row != NULL) { //Loop to the bottom row
                        while (row->down != NULL) row = row->down;
                }
                for (uint8_t j = 0; j < size; j++) { //Columns
                        if (i == 0) { //If the first row
                                if (origin == NULL) { //If the first cell in the maze
                                        origin = new MazeCell(); //Set origin to new cell
                                } else {
                                        p = origin; //Start at origin
                                        while (p->right != NULL) p = p->right; //Move as far right as you can
                                        p->right = new MazeCell(); //Create a new cell to the right
                                        p->right->left = p; //Set the left of the new cell to the previously most right cell
                                }
                        } else { //Every other row
                                p = row; //Start at row pointer
                                while (p->down != NULL) p = p->right; //Move as far right as you can on the row below
                                p->down = new MazeCell(); //Create a new cell below the current cell
                                p->down->up = p; //Create the reciprical relation
                                if (p->left != NULL) { //If it is not the edge of the maze
                                        p->left->down->right = p->down; //Set the right relation of the cell below and right
                                        p->down->left = p->left->down; //Set the left relation of the cell below
                                }
                        }
                }
        }
        generateCellStates(size); //Randomize maze configuration
        setDeadalusCurrentLocation(rand()%size, rand()%size); //Randomly place Deadalus
        setGateLocation(rand()%size, rand()%size); //Randomly place Gate
}


uint8_t Maze::generateCellStates(uint8_t size){
        while(numberObst>0) { //While there are obstacles to place
                uint8_t x = rand() % size; //Choose random x
                uint8_t y = rand() % size; //Choose random y
                MazeCell* p = origin; //Start at the origin

                for(uint8_t i = 0; i<x; i++) p = p->right; //Move along to correct x
                for(uint8_t i=0; i<y; i++) p = p->down; //Move along to correct y

                if(p->free == 0) { //If the selected cell is not already an obstacle
                        p->free = 1; //Set the state to an obstacle
                        numberObst--; //Increment the obstacle count
                }
        }
}

//0 = free
//1 = obstable
//2 = Deadalus
//3 = Gate
void Maze::printBoard() {
        MazeCell* p = origin; //Column Pointer
        MazeCell* q = p; //Row Pointer

        cout << "+"; //Corner
        for(uint8_t i =0; i<size; i++) cout << "-"; //Top
        cout << "+" << endl; //Corder

        while(p = q) { //Equivalent to while p != NULL but containing assignment
                q = p->down; //Move Row Down
                cout << "|"; //Side
                while(p != NULL) { //While cell is valid
                        //Print state of cell
                        if(p->free == 0) cout << " ";
                        else if(p->free == 1) cout << "*";
                        else if(p->free == 2) cout << "+";
                        else if(p->free == 3) cout << "#";
                        else if(p->free == 4) cout << "@";
                        p = p->right; //Move right
                }
                cout << "|" << endl; //Side
        }

        cout << "+"; //Corner
        for(uint8_t i =0; i<size; i++) cout << "-"; //Bottom
        cout << "+" << endl; //Corner
}

MazeCell* Maze::getDeadalusCurrentCell(){
        MazeCell* p = origin; //Start at origin
        for(uint8_t i=0; i<dx; i++) p = p->right; //Move along to correct x
        for(uint8_t i=0; i<dy; i++) p = p->down; //Move along to correct x
        return p; //Return cell
}

void Maze::setDeadalusCurrentLocation(uint8_t x, uint8_t y){
        dx = x; //Set Maze dx
        dy = y; //Set Maze dy
        MazeCell* p = origin; //Start at the origin
        for(uint8_t i = 0; i<x; i++) p = p->right; //Move along to correct x
        for(uint8_t i=0; i<y; i++) p = p->down; //Move along to correct y
        p->free = 2; //Set state of cell to Deadalus
}

void Maze::setGateLocation(uint8_t x, uint8_t y){
        gx = x; //Set Maze gx
        gy = y; //Set Maze gy
        MazeCell* p = origin; //Start at origin
        for(uint8_t i = 0; i<x; i++) p = p->right; //Move along to correct x
        for(uint8_t i=0; i<y; i++) p = p->down; //Move along to correct y
        p->free = 3; //Set state of cell to Gate
}
