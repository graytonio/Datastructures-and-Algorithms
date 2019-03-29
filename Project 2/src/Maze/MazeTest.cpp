#include "Maze.h"
using namespace std;

bool move(Maze* p, MazeCell* currPos){
        if(currPos == NULL) return false;
        else cout << unsigned(currPos->free) << endl;
        p->printBoard();
        if(currPos->free == 3) { //Found the gate
                cout << "Found Gate" << endl;
                return true;
        }else if(currPos->free == 1) { //Found obstacle
                cout << "Found Obstacle" << endl;
                return false;
        }else{ //Open Space
                for(uint8_t i=0; i<4; i++) {
                        if(i == 0) {
                                cout << "Up" << endl;
                                if(move(p, currPos->up)) {
                                        cout << "Up" << endl;
                                        if(currPos->up->free != 3) {
                                                currPos->up->free = 2;
                                                p->printBoard();
                                                currPos->up->free = 0;
                                        }else{
                                                p->printBoard();
                                        }
                                        return true;
                                }
                        }else if(i == 1) {
                                cout << "Right" << endl;
                                if(move(p, currPos->right)) {
                                        cout << "Right" << endl;
                                        if(currPos->right->free != 3) {
                                                currPos->right->free = 2;
                                                p->printBoard();
                                                currPos->right->free = 0;
                                        }else{
                                                p->printBoard();
                                        }
                                        return true;
                                }
                        }else if(i == 2) {
                                cout << "Down" << endl;
                                if(move(p, currPos->down)) {
                                        cout << "Down" << endl;
                                        if(currPos->down->free != 3) {
                                                currPos->down->free = 2;
                                                p->printBoard();
                                                currPos->down->free = 0;
                                        }else{
                                                p->printBoard();
                                        }
                                        return true;
                                }
                        }else if(i == 3) {
                                cout << "Left" << endl;
                                if(move(p, currPos->left)) {
                                        cout << "Left" << endl;
                                        if(currPos->left->free != 3) {
                                                currPos->left->free = 2;
                                                p->printBoard();
                                                currPos->down->free = 0;
                                        }else{
                                                p->printBoard();
                                        }
                                        return true;
                                }
                        }
                }
                return false;
        }
}


int main(){
        Maze p(10, 70, 4234523);
        p.setDeadalusCurrentLocation(1, 1);
        p.setGateLocation(4, 4);
        p.printBoard();
        move(&p, p.getDeadalusCurrentCell());
        cout << "Done" << endl;

        return 0;
}
