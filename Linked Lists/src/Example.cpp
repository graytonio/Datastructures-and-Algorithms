#include<iostream>

using namespace std;

class Node {
  uint32_t value;
  Node *next;

public:
  Node(uint32_t valuePar){
    value = valuePar;
    next = NULL;
  }

  Node *getNext(){
    return next;
  }

  void setNext(Node *next){
    Node::next = next;
  }

  uint32_t getValue() {
    return value;
  }

  void setValue(uint32_t value){
    Node::value = value;
  }
};

class LinkedList{
  Node *head = NULL;
  Node *tail = NULL;

public:
  LinkedList(){}

  void addNode(uint32_t value){
    if(head == NULL){
      head = new Node(value);
      tail = head;
    }else{
      tail->setNext(new Node(value));
      tail = tail->getNext();
    }
  }

  void insertValueAtIndex(uint32_t value, uint32_t index){
    Node *n = new Node(value);
    Node *p = head;

    if(index == 0){
      n->setNext(head);
      head = n;
    }else{
      for(uint32_t i =0; i < index-1; i++){
        p = p->getNext();
        if(p == NULL) return;
      }

      n->setNext(p->getNext());
      p->setNext(n);
    }
  }

  void deleteNode(uint32_t index){
    Node *p = head;

    for(uint32_t i=0; i<index; i++){
      p=p->getNext();
      if(p==NULL) return;
    }

    if(p == head){
      head = p->getNext();
      delete p;
    }else{
      Node *q = head;
      while(q->getNext() != p) q = q->getNext();

      q->setNext(p->getNext());
      delete p;
    }
  }

  uint32_t getValueAt(uint32_t index){
    Node *p = head;
    for(uint32_t i = 0; i<index; i++){
      p = p->getNext();
      if(p == NULL) return -1;
    }
    return p->getValue();
  }

  void printList(){
    Node *p = head;

    while(p != NULL){
      cout << p->getValue() << endl;
      p = p->getNext();
    }

    cout << endl << endl;
  }
};

int main(){
  LinkedList l;

  l.addNode(3);
  l.addNode(5);
  l.addNode(7);
  l.printList();

  l.insertValueAtIndex(4, 2);
  l.printList();

  //l.deleteNode(2);
  //l.printList();

  //l.insertValueAtIndex(5, 2);
  //l.printList();

  return 0;
}
