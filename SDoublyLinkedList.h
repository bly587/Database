#include <iostream>
#ifndef SDOUBLYLINKEDLIST_H
#define SDOUBLYLINKEDLIST_H
#include "SListNode.h"

using namespace std;

template <class T>
class SDoublyLinkedList
{
  public:
    SListNode<T>* front;
    SListNode<T>* back;
    unsigned int size;

    SDoublyLinkedList();
    ~SDoublyLinkedList();

    void insertFront(T elem);
    void insertBack(T elem);
    T removeFront();
    SListNode<T>* remove(T elem);
    SListNode<T>* deletePos(int pos);

    bool find(T elem);

    bool isEmpty();
    void printList();
    int getSize();
};
#endif

//default
template <class T>
SDoublyLinkedList<T>::SDoublyLinkedList()
{
  size = 0;
  front = NULL;
  back = NULL;
}
//destructor
template <class T>
SDoublyLinkedList<T>::~SDoublyLinkedList()
{
  //will need to iterate through the list
}
template <class T>
void SDoublyLinkedList<T>::insertFront(T elem)
{
  SListNode<T> *node = new SListNode<T>(elem);
  //check if is empty
  if(isEmpty()) //if size == 0
  {
    //we have an empty list
    back = node;
  }
  else
  {
    //not an empty list
    node->next = front;
    front->prev = node;
  }
  front = node;
  size++;
}

template <class T>
int SDoublyLinkedList<T>::getSize()
{
  return size;
}

template <class T>
bool SDoublyLinkedList<T>::find(T elem){
  bool idx = false;
  SListNode<T>* curr = front;
  while (curr != NULL)
  {
    if(curr->data == elem)
    {
      //cout << "Found him!" << endl;
      return true;
    }
    curr = curr->next;
  }
  //cout << "Returning false" << endl;
  return false;
}

template <class T>
T SDoublyLinkedList<T>::removeFront()
{
  //check if empty
  //front temp
  SListNode<T>* ft = front;
  //check if there is only one element
  if(front->next == NULL)
  {
    back = NULL;

  }
  else
  {
    //more than one element in the list
    front->next->prev = NULL;
  }
  //update where the front is
  front = front->next;
  //get data from temp
  T temp = ft->data;
  //null out the next link
  ft->next = NULL;
  //decrement size
  size--;
  //delete the original front (what we are removing)
  delete ft;
  //return temp
  return temp;
}
template <class T>
void SDoublyLinkedList<T>::insertBack(T elem)
{
  SListNode<T> *node = new SListNode<T>(elem);
  //check if is empty
  if(isEmpty()) //if size == 0
  {
    //we have an empty list
    front = node;
  }
  else
  {
    //not an empty list
    back->next = node;
    node->prev = node;
  }
  back = node;
  size++;
}

template <class T>
SListNode<T>* SDoublyLinkedList<T>::remove(T elem)
{
  //returning pointer to node
  //not returning the data because it won't always be an int

  //first check if empty
  if(isEmpty() == true)
  {
    return NULL;
  }
  //iterate through list
  SListNode<T>* curr = front;
  //run loop until data is the data we are looking for
  while(curr->data != elem)
  {
    curr = curr->next;

    if(curr == NULL)//value doesn't exist
    {
      return NULL;
    }
  }
  //found the node that contains the data 'd'
  //check if front, back, or in the middle of the linkedlist
  if(curr == front)
  {
    front = curr->next;
  }
  else if(curr == back)
  {
    //its the back
    back = curr->prev;
  }
  //it's not the front
  else
  {
    //update pointers
    //this skips over curr
    curr->prev->next = curr->next;
    //same thing
    curr->next->prev = curr->prev;
  }

  curr->next = NULL;
  curr->prev = NULL;
  size--;

  return curr;
}

template <class T>
bool SDoublyLinkedList<T>::isEmpty()
{
  if(size > 0)
  {
    return false;
  }
  else
  {
    return true;
  }
}

template <class T>
void SDoublyLinkedList<T>::printList()
{
  SListNode<T> *curr = front;
  while(curr != NULL)
  {
    cout << curr->data << endl;
    curr = curr->next;
  }
}
