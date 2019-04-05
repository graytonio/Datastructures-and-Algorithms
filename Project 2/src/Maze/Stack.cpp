#include "Stack.h"

//Construct node with given value
Node::Node(MazeCell* value){
        Node::value = value;
        next = NULL;
}

//Create empty stack
Stack::Stack(){
        head = NULL;
}

//Create stack with initial value
Stack::Stack(MazeCell* value){
        head = new Node(value);
}

//Push new value to stack
void Stack::push(MazeCell* value){
        if(head == NULL) { //If stack empty
                head = new Node(value); //Set head to new Node
        }else{ //If stack has values
                Node* p = new Node(value); //Create a new Node with the value passed
                p->next = head; //Set the next pointer to current head
                head = p; //Set head to new node
        }
}

//Return current top of stack and remove from stack
MazeCell* Stack::pop(){
        if(head != NULL) { //If stack has values
                Node* p = head; //Get the top node
                head = head->next; //Move head down to next node
                MazeCell* v = p->value; //Grab value out of node
                delete(p); //Release memory
                return v; //Return value
        }else{ //Stack is empty
                return NULL; //Return NULL
        }
}

//Search for existence of value in stack
bool Stack::nodeExists(MazeCell* value){
        Node* p = head; //Start at head
        while(p != NULL) { //While not at the end of the stack
                if(p->value == value) return true; //If Node has value that was passed return true
                p = p->next; //Go to next node
        }
        return false; //At the end of the stack and value not found return false
}
