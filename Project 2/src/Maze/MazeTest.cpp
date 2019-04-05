#include "Maze.h"
#include "Stack.h"
using namespace std;

bool move(Maze* p, MazeCell* currPos, Stack* stack){
        if(currPos == NULL) return false;
        if(currPos->searched) return false;
        else currPos->searched = true;
        if(currPos->free == 3) { //Found the gate
                return true;
        }else if(currPos->free == 1) { //Found obstacle
                return false;
        }else{ //Open Space
                for(uint8_t i=0; i<4; i++) {
                        if(i == 0) {
                                if(move(p, currPos->up, stack)) {
                                        stack->push(currPos->up);
                                        return true;
                                }
                        }else if(i == 1) {
                                if(move(p, currPos->right, stack)) {
                                        stack->push(currPos->right);
                                        return true;
                                }
                        }else if(i == 2) {
                                if(move(p, currPos->down, stack)) {
                                        stack->push(currPos->down);
                                        return true;
                                }
                        }else if(i == 3) {
                                if(move(p, currPos->left, stack)) {
                                        stack->push(currPos->left);
                                        return true;
                                }
                        }
                }
                return false;
        }
}


int main(){
        Maze p(10, 70);
        Stack* stack = new Stack();
        p.setDeadalusCurrentLocation(1, 1);
        p.setGateLocation(4, 4);
        p.printBoard();
        if(move(&p, p.getDeadalusCurrentCell(), stack)) {
                cout << "Found" << endl;
                MazeCell* c = stack->pop();
                while(c != NULL) {
                        if(c->free != 3) {
                                c->free = 2;
                                p.printBoard();
                                c->free = 0;
                        }else{
                                p.printBoard();
                        }
                        c = stack->pop();
                }
        }else{
                cout << "No Path" << endl;
        }


        return 0;
}
