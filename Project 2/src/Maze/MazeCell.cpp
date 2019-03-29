#include "MazeCell.h"

MazeCell::MazeCell (MazeCell* up_p, MazeCell* down_p, MazeCell* left_p, MazeCell* right_p, uint8_t free_p){
        up = up_p;
        down = down_p;
        left = left_p;
        right = right_p;
        free = free_p;
}
