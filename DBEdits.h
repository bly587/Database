#include <iostream>
#include "GenStack.h"

using namespace std;

class DBEdits{
  public:
    GenStack<Person*>* stackOfAdds;
    GenStack<Person*>* stackOfRemoves;

    DBEdits();
    ~DBEdits();

};
