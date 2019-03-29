#ifndef MAZECELL_H
#define MAZECELL_H

#include <iostream>
#include <string>

class MazeCell {
public:
MazeCell* up;
MazeCell* down;
MazeCell* left;
MazeCell* right;
uint8_t free;

MazeCell(MazeCell* up_p, MazeCell* down_p, MazeCell* left_p, MazeCell* right_p, uint8_t free_p);
};

#endif
