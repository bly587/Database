#include <iostream>

using namespace std;

template <class T>
class GenStack{
public:
  GenStack(); //constructor
  GenStack(int maxSize); // overload constructor
  ~GenStack(); // destructor

  void push(T elem);
  T pop();
  T peek(); // AKA top()

  bool isFull();
  bool isEmpty();

  int size;
  int top;

  T *myArray; // declare memory address for array of chars --- pointer to a char
};

// default constructor
template <class T>
GenStack<T>::GenStack(){
  // initialization of default values
  myArray = new T[128];
  size = 128;
  top = -1;
}

// overload constructor
template <class T>
GenStack<T>::GenStack(int maxSize){
  myArray = new T[maxSize]; // dynamically allocated array ----- on the heap
  size = maxSize;
  top = -1;
}

// destructor
template <class T>
GenStack<T>::~GenStack(){
  delete []myArray;
}

template <class T>
void GenStack<T>::push(T elem){
  // adds more memory for stack if it full
  if (isFull()){
    T* newStack = new T[2 * size];
    // Puts info from old stack into new one
    for (int i = 0; i < size; ++i){
      newStack[i] = myArray[i];
    }
    // taking care of variables
    size *= 2;
    delete myArray;
    myArray = newStack;
    cout << "Allocating more memory to the stack. Size increased from " << size/2 << " to " << size << "." << endl;
  }
  // finally pushes the new element onto the stack
  myArray[++top] = elem;
}

template <class T>
T GenStack<T>::pop(){
  // error checking, make sure its not isEmpty
  if (isEmpty()){
    cout << "Error: Stack is empty and cannot be popped" << endl;
    exit(1);
  }
  else{
    return myArray[top--]; // returns that value and THEN decreases the top value
  }
}

template <class T>
T GenStack<T>::peek(){
  // checks to make sure it is not empty
  if (isEmpty()){
    cout << "Error: Stack is empty and cannot be popped" << endl;
    exit(1);
  }
  else{
    return myArray[top];
  }
}

template <class T>
bool GenStack<T>::isFull(){
  return (top == size-1);
}

template <class T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}
