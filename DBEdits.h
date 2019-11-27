#include <iostream>
#include "GenStack.h"

using namespace std;

class DBEdits{
  public:
    bool lastMoveWasAdd;
    bool lastMoveWasS;

    GenStack<Student*>* stackOfAddS;
    GenStack<Faculty*>* stackOfAddF;
    GenStack<Faculty*>* stackOfRemovesF;
    GenStack<Student*>* stackOfRemovesS;

    DBEdits();
    ~DBEdits();

};

DBEdits::DBEdits(){
  stackOfAddS = new GenStack<Student*>();
  stackOfAddF = new GenStack<Faculty*>();
  stackOfRemovesF = new GenStack<Faculty*>();
  stackOfRemovesS = new GenStack<Student*>();
}

DBEdits::~DBEdits(){
  delete stackOfAddS;
  delete stackOfAddF;
  delete stackOfRemovesF;
  delete stackOfRemovesS;
  cout << "stacks have been deleted" << endl;
}
