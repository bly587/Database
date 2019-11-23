#include <iostream>
#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H
#include "SListNode.h"

using namespace std;

// Single linked list
template <class T>
class SLinkedList{
  private:
    SListNode<T>* front;
    unsigned int size; // unsigned --> can't be negative --> makes sense here
  public:
    SLinkedList(); // constructor
    ~SLinkedList(); // destructor

    void insertFront(T d);
    int removeFront();
    int deletePos(int pos);
    int find(T d);

    // helper functions
    bool isEmpty();
    void printList();
    unsigned int getSize();
};
#endif

template <class T>
SLinkedList<T>::SLinkedList(){
  size = 0;
  front = NULL; // nullptr
}

template <class T>
SLinkedList<T>::~SLinkedList(){
  // iterates through the list, nulls out the pointers, and deletes the nodes
  SListNode<T> *current = front;
  while (current != NULL){
    SListNode<T>* next = current->next;
    delete current;
    --size;
    current = next;
  }
}

template <class T>
unsigned int SLinkedList<T>::getSize(){
  return size;
}

template <class T>
void SLinkedList<T>::printList(){
  SListNode<T> *current = front;
  while (current != NULL)
  {
    cout << current->data;
    cout << ", ";
    current = current->next;
  }
}

template <class T>
void SLinkedList<T>::insertFront(T d){
  SListNode<T> *node = new SListNode<T>(d);
  node->next = front;
  front = node;
  size++;
}

template <class T>
int SLinkedList<T>::removeFront(){
  // checks for empty list
  if (isEmpty()){
    cout << "Error! Linked list is empty, cannot remove node." << endl;
    exit(1);
    //throw "Error! List is empty, cannot remove node.";
  }
  T tmp = front->data;
  SListNode<T> *old = front;
  front = front->next;
  old->next = NULL; // just to be safe
  delete old;
  size--;

  return tmp;
}

template <class T>
int SLinkedList<T>::deletePos(int pos){

  int idx = 0;
  SListNode<T> *prev = front;
  SListNode<T> *curr = front;

  while (idx != pos){
    prev = curr; // stays behind current
    curr = curr->next;
    idx++;
  }
  // Make sure to add checks for valid pos and curr != nullptr

  prev->next = curr->next;
  curr->next = NULL; // null out the one you're deleting
  int temp = curr->data;
  delete curr;
  size--;
  return temp;
}
//located a node with data d
template <class T>
int SLinkedList<T>::find(T d){
  int idx = 0;
  SListNode<T> *curr = front;
  while (curr != NULL){
    if (curr->data == d){
      break;
    }
    idx++;
    curr = curr->next;
  }

  if (curr == NULL){
    idx = -1;
  }
  return idx;
}
//bool if our list is empty
template <class T>
bool SLinkedList<T>::isEmpty(){
  if (size == 0){
    return true;
  }
  else{
    return false;
  }
}
