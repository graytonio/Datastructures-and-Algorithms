#include "Maze/Maze.h"

int main(){

        return 0;
}

bool move(Maze* p, MazeCell* currPos){
        p->printBoard();
        if(currPos->value == 3) { //Found the gate
                return true;
        }else if(currPos->value == 1) { //Found obstacle
                return false;
        }else{ //Open Space
                for(uint8_t i=0; i<4; i++) {
                        switch(i) {
                        case 0:
                                if(move(p, currPos->up)) return true;
                                break;
                        case 1:
                                if(move(p, currPos->right)) return true;
                                break;
                        case 2:
                                if(move(p, currPos->down)) return true;
                                break;
                        case 3:
                                if(move(p, currPos->left)) return true;
                                break;
                        }
                }
                return false;
        }
}
