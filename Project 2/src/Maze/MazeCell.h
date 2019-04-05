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
bool searched;

MazeCell();
};

#endif
