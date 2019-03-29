#ifndef MAZE_H
#define MAZE_H

#include "MazeCell.h"
#include <math.h>
#include <time.h>

class Maze {
private:
MazeCell* origin;
uint8_t size;
uint8_t percentFree;
void generateBoard();
uint8_t generateCellStates(uint8_t size);
uint32_t numberObst;
uint8_t dx;
uint8_t dy;
uint8_t gx;
uint8_t gy;

public:
void printBoard();
void setDeadalusCurrentLocation(uint8_t x, uint8_t y);
void setGateLocation(uint8_t x, uint8_t y);
MazeCell* getDeadalusCurrentCell();
Maze(uint8_t size, uint8_t percentFree, uint32_t seed);
Maze(uint8_t size, uint8_t percentFree);
};

#endif
