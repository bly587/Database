#include <iostream>
#include "GenStack.h"

using namespace std;

class DBEdits{
  public:
    bool lastMoveWasAdd;

    GenStack<Person*>* stackOfAdds;
    GenStack<Person*>* stackOfRemoves;

    DBEdits();
    ~DBEdits();

};

DBEdits::DBEdits(){
  stackOfAdds = new GenStack<Person*>();
  stackOfRemoves = new GenStack<Person*>();
}

DBEdits::~DBEdits(){
  delete stackOfAdds;
  delete stackOfRemoves;
}
