#ifndef STACK_H
#define STACK_H

#include "MazeCell.h"

class Node {
public:
MazeCell* value;
Node* next;
Node(MazeCell* value);
};

class Stack {
private:
Node* head;

public:
Stack();
Stack(MazeCell* value);
void push(MazeCell* value);
MazeCell* pop();
bool nodeExists(MazeCell* value);
};

#endif
