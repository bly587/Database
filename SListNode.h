#include <iostream>
#ifndef SLISTNODE_H
#define SLISTNODE_H

using namespace std;

// List node for single linked list
template <class T>
class SListNode{
  public:
    T data;
    SListNode *next; // pointer to the next node
    SListNode *prev;

    SListNode(); //constructor
    SListNode(T d); // overload constructor
    ~SListNode(); // destructor
};
#endif

template <class T>
SListNode<T>::SListNode(){}

template <class T>
SListNode<T>::SListNode(T d){
  data = d;
  next = NULL; // null pointer
  prev = NULL;
}

template <class T>
SListNode<T>::~SListNode(){
  if (next == NULL){
    delete next;
  }
  if (prev = NULL)
  {
    delete prev;
  }
}
