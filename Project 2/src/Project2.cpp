#include "Maze/Maze.h"
#include "Maze/Stack.h"
using namespace std;

bool move(Maze* p, MazeCell* currPos, Stack* stack){
        if(currPos == NULL) return false; //If we are at the wall
        if(currPos->searched) return false; //If the cell has already been searched
        else currPos->searched = true; //Set the searched flag
        if(currPos->free == 3) { //Found the gate
                return true;
        }else if(currPos->free == 1) { //Found obstacle
                return false;
        }else{ //Open Space
                for(uint8_t i=0; i<4; i++) { //Loop through possible routes
                        if(i == 0) { //Up
                                if(move(p, currPos->up, stack)) { //Search the cell above
                                        stack->push(currPos->up); //The cell is part of the solution, add it to the stack
                                        return true;
                                }
                        }else if(i == 1) { //Right
                                if(move(p, currPos->right, stack)) { //Search the cell to the right
                                        stack->push(currPos->right); //The cell is part of the solution, add it to the stack
                                        return true;
                                }
                        }else if(i == 2) { //Down
                                if(move(p, currPos->down, stack)) { //Search the cell below
                                        stack->push(currPos->down); //The cell is part of the solution, add it to the stack
                                        return true;
                                }
                        }else if(i == 3) { //Left
                                if(move(p, currPos->left, stack)) { //Search the cell to the left
                                        stack->push(currPos->left); //The cell is part of the solution, add it to the stack
                                        return true;
                                }
                        }
                }
                return false;
        }
}

//Arg 1 = size
//Arg 2 = fill %
int main(int argc, char *argv[]){
        //Command Line Input Validation
        bool line;
        if(!atoi(argv[1])) {
                cout << "Invalid Size" << endl;
                return 1;
        }
        if(!atoi(argv[2])) {
                cout << "Invalid Percent Free" << endl;
                return 1;
        }else if(atoi(argv[2]) > 100 || atoi(argv[2]) < 0) {
                cout << "Invalid Percent Value" << endl;
                return 1;
        }
        if(!atoi(argv[3]) == 1) {
                cout << "Invalid line argument" << endl;
                return 1;
        }else if(atoi(argv[3]) != 1 && atoi(argv[3]) != 2) {
                cout << "Invalid line value" << endl;
                return 1;
        }

        if(atoi(argv[3]) == 1) line = true;
        else line = false;
        Maze p(atoi(argv[1]), atoi(argv[2]));         //Generate Maze
        Stack* stack = new Stack(); //Create stack object
        p.printBoard(); //Print initial state of board
        if(move(&p, p.getDeadalusCurrentCell(), stack)) { //If Path is Found
                cout << "Found" << endl;
                MazeCell* c = stack->pop(); //Start at the top of stack
                while(c != NULL) {
                        if(c->free != 3) { //If cell is not the gate
                                //Mark the current cell with a @ and print the step
                                c->free = 4;
                                p.printBoard();
                                if(!line) c->free = 0;
                        }else{
                                //Print the board
                                p.printBoard();
                        }
                        //Move down the stack
                        c = stack->pop();
                }
        }else{
                //Path not found
                cout << "No Path" << endl;
        }

        return 0;
}
