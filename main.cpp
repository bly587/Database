#include <iostream>
#include "BST.h"
#include "Person.h"

using namespace std;

// Assign 5 todo list:
/*
1. 2 BSTs that act as our two tables for students and faculty respectively (masterFaculty and masterStudent)
---MENU---
2.  Print print print, order the stuff
3. Add new student and add new advisor
4. Delete student and delete advisor --> must adjust accordingly for advisee list and such
5. Misc functons for menu
6. Rollback --> stack
---Structure of main---
7. Check current directory for facultyTable and studentTable
8. If neither of them exist, Initialize two new empty trees, otherwise, read file data into tree objects
9. Run menu loop until user exits
10. After exiting, write/serialize trees to facultyTable and studentTable files
*/

// Other shtuff:
// Convert BST to GenBST that finishes the implementation and makes it generic
// Extend person class


int main(int argc, char** argv){
  cout << "test main" << endl;

  // do
  // the
  // things

  // test with int
  BST<int>* intTree = new BST<int>();
  int a = 134;
  int b = 136;
  int c = 174;
  int d = 188;
  int e = 199;
  intTree->insert(a);
  intTree->insert(b);
  intTree->insert(c);
  intTree->insert(d);
  intTree->insert(e);
  intTree->printTree();
  delete intTree;


  BST<Person*>* theTree = new BST<Person*>();
  Person* p1 = new Person("Name1", "Level1", 1001);
  Person* p2 = new Person("Name2", "Level2", 1002);
  Person* p3 = new Person("Name3", "Level3", 1003);
  Person* p4 = new Person("Name4", "Level4", 1004);
  Person* p5 = new Person("Name5", "Level5", 995);
  Person* p6 = new Person("Name6", "Level6", 996);
  theTree->insert(p1);
  theTree->insert(p2);
  theTree->insert(p3);
  theTree->insert(p4);
  theTree->insert(p5);
  theTree->insert(p6);
  theTree->printTree();

  return 0;
}
