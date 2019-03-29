#include "Maze.h"
using namespace std;

Maze::Maze(uint8_t size, uint8_t percentFree, uint32_t seed){
        srand(seed);
        Maze::size = size;
        Maze::percentFree = percentFree;
        generateBoard();

}

Maze::Maze(uint8_t size, uint8_t percentFree){
        srand(time(0));
        Maze::size = size;
        Maze::percentFree = percentFree;
        generateBoard();
}

void Maze::generateBoard(){
        numberObst = (size*size) - ((size*size) * (percentFree/100.0));
        origin = NULL;
        MazeCell *p, *row;
        for (uint8_t i = 0; i < size; i++) {
                row = origin;
                if (row != NULL) {
                        while (row->down != NULL) row = row->down;
                }
                for (uint8_t j = 0; j < size; j++) {
                        if (i == 0) {
                                if (origin == NULL) {
                                        origin = new MazeCell(NULL, NULL, NULL, NULL, 0);
                                } else {
                                        p = origin;
                                        while (p->right != NULL) p = p->right;
                                        p->right = new MazeCell(NULL, NULL, NULL, NULL, 0);
                                        p->right->left = p;
                                }
                        } else {
                                p = row;
                                while (p->down != NULL) p = p->right;
                                p->down = new MazeCell(NULL, NULL, NULL, NULL, 0);
                                p->down->up = p;
                                if (p->left != NULL) {
                                        p->left->down->right = p->down;
                                        p->down->left = p->left->down;
                                }
                        }
                }
        }
        generateCellStates(size);
}


uint8_t Maze::generateCellStates(uint8_t size){
        while(numberObst>0) {
                uint8_t x = rand() % size;
                uint8_t y = rand() % size;
                MazeCell* p = origin;

                for(uint8_t i = 0; i<x; i++) {
                        p = p->right;
                }

                for(uint8_t i=0; i<y; i++) {
                        p = p->down;
                }

                if(p->free == 0) {
                        p->free = 1;
                        numberObst--;
                }
        }
}

//0 = free
//1 = obstable
//2 = Deadalus
//3 = Gate
void Maze::printBoard() {
        MazeCell* p = origin;
        MazeCell* q = p;

        cout << "+";
        for(uint8_t i =0; i<size; i++) {
                cout << "-";
        }
        cout << "+" << endl;

        while(p = q) {
                q = p->down;
                cout << "|";
                while(p != NULL) {
                        if(p->free == 0) cout << " ";
                        else if(p->free == 1) cout << "*";
                        else if(p->free == 2) cout << "+";
                        else if(p->free == 3) cout << "#";
                        p = p->right;
                }
                cout << "|" << endl;
        }

        cout << "+";
        for(uint8_t i =0; i<size; i++) {
                cout << "-";
        }
        cout << "+" << endl;
}

MazeCell* Maze::getDeadalusCurrentCell(){
        MazeCell* p = origin;

        for(uint8_t i=0; i<dx; i++) {
                p = p->right;
        }

        for(uint8_t i=0; i<dy; i++) {
                p = p->down;
        }

        return p;
}

void Maze::setDeadalusCurrentLocation(uint8_t x, uint8_t y){
        dx = x;
        dy = y;

        MazeCell* p = origin;
        for(uint8_t i = 0; i<x; i++) {
                p = p->right;
        }

        for(uint8_t i=0; i<y; i++) {
                p = p->down;
        }

        p->free = 2;
}

void Maze::setGateLocation(uint8_t x, uint8_t y){
        gx = x;
        gy = y;

        MazeCell* p = origin;
        for(uint8_t i = 0; i<x; i++) {
                p = p->right;
        }

        for(uint8_t i=0; i<y; i++) {
                p = p->down;
        }

        p->free = 3;
}
