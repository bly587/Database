#include <iostream>
#include <fstream>
#include "BST.h"
#include "SpecialBST.h"
//#include "Person.h"
#include "Faculty.h"

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
  /*
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

  cout << "Attempting to create a student" << endl;
  Student* s1 = new Student("Jt", "Beast(Student)" , 2317445, "Data Analytics", 4.00, 2001);
  cout << "Attempting to print student" << endl;
  // s1->printStudent();
  //Student* s1 = new Student("Data Science", 3.03, 1001);
  //creating faculty tree
  BST<Faculty*>* facTree = new BST<Faculty*>();
  cout << "Attempting to create faculty" << endl;
  Faculty* f1 = new Faculty("Rene", "Professor", 2001, "Computer Science", 2317445);
  Faculty* f2 = new Faculty("Linstead", "Professor", 2002, "Computer Science", 2317445);
  f2->addAdvisee(101);
  f2->addAdvisee(102);
  f2->addAdvisee(103);
  facTree->insert(f1);
  facTree->insert(f2);
  cout << "Attempting to print out faculty" << endl;
  // f1->printFaculty();
  // f2->printFaculty();

  theTree->insert(p1);
  //theTree->printTree();
  theTree->insert(p2);
  theTree->insert(p3);
  theTree->insert(p4);
  theTree->insert(p5);
  theTree->insert(p6);

  cout << "Max Number getting printed" << endl;
  cout << p1->getId() << endl;
  cout << "Attempting to find Name3 person in tree" << endl;
  Person* temp = theTree->find(1003);
  cout << temp->getName() << endl;

  //Creating student tree
  BST<Student*>* stuTree = new BST<Student*>();
  Student* s7 = new Student("Name1", "Level1", 1001, "Math", 4.00, 2001);
  Student* s2 = new Student("Name2", "Level2", 1002, "Math2", 4.00, 2001);
  Student* s3 = new Student("Name3", "Level3", 1003, "Math3", 4.00, 2001);
  Student* s4 = new Student("Name4", "Level4", 1004, "Math4", 4.00, 2001);
  Student* s5 = new Student("Name5", "Level5", 1005, "Math5", 4.00, 2001);
  Student* s6 = new Student("Name6", "Level6", 1006, "Math6", 4.00, 2001);
  stuTree->insert(s7);
  stuTree->insert(s2);
  stuTree->insert(s3);
  stuTree->insert(s4);
  stuTree->insert(s5);
  stuTree->insert(s6);

  cout << "Attempting to print entire tree" << endl;
  //print person must be different for each person
  //stuTree->recPrintStudent(stuTree->getRoot());
  cout << "\n" << endl;



  // -------------Start of the program-----------------(jk more testing still)

  cout << "\n\n\ni am the captain now" << endl;

  /*
  SpecialBST<Faculty*>* masterFaculty = new SpecialBST<Faculty*>();
  masterFaculty->insert(f2);
  masterFaculty->insert(f1);

  SpecialBST<Student*>* masterStudent = new SpecialBST<Student*>();
  masterStudent->insert(s1);
  masterStudent->insert(s2);
  masterStudent->insert(s3);
  masterStudent->insert(s4);
  masterStudent->insert(s5);
  masterStudent->insert(s6);
  masterStudent->insert(s7);
  */

  // ---------------------------------------------------------------

  // Check current directory for studentTable and facultyTable
  ifstream facultyTable, studentTable;
  facultyTable.open("facultyTable");
  studentTable.open("studentTable");
  // Create trees
  SpecialBST<Student*>* masterStudent = new SpecialBST<Student*>();
  SpecialBST<Faculty*>* masterFaculty = new SpecialBST<Faculty*>();

  if (facultyTable.is_open() && studentTable.is_open()){
    cout << "\n\n\n\n\n\n\nThe serialized files exist!!!" << endl;

    // deserialize students

    while(true){
      Student* s = new Student(studentTable);
      cout << s->getName() << endl;

      if (s->getName() == "done"){ // Breaks out of loop if last node was just filled
        break;
      }
      else{
        // add student to tree
        cout << "inserting into tree: " << s->getId() << endl;
        masterStudent->insert(s);
      }
    }

    // ----------------------------------------------------------------------
    // deserialize faculty members

    while(true){
      Faculty* f = new Faculty(facultyTable);

      if (f->getName() == "done"){ // Breaks out of loop if last node was just filled
        break;
      }
      else{
        // add faculty to tree
        cout << "inserting into tree: " << f->getId() << endl;
        masterFaculty->insert(f);
      }
    }

    // Close ifstream files
    facultyTable.close();
    studentTable.close();

  }
  else{
    cout << "files don't exist; starting with empty trees" << endl;
  }

  // Create outfiles
  ofstream faculty_out;
  ofstream student_out;

  // ---------------------------------------------------------------
  // Main Menu time
  int userInput = 0;
  while(userInput != 14)
  {
    cout << "\nHere are your options\n" << endl;

    cout << "1) Print all students and their information (sorted by ascending id #)" << endl;
    cout << "2) Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "3) Find and display student information given the students id" << endl;
    cout << "4) Find and display faculty information given the faculty id" << endl;
    cout << "5) Given a student’s id, print the name and info of their faculty advisor" << endl;
    cout << "6) Given a faculty id, print ALL the names and info of his/her advisees" << endl;
    cout << "7) Add a new student" << endl;
    cout << "8) Delete a student given the id" << endl;
    cout << "9) Add a new faculty member" << endl;
    cout << "10) Delete a faculty member given the id" << endl;
    cout << "11) Change a student’s advisor given the student id and the new faculty id" << endl;
    cout << "12) Remove an advisee from a faculty member given the ids" << endl;
    cout << "13) Rollback" << endl;
    cout << "14) Exit" << endl;
    //get user input
    cin >> userInput;
    //switch statement for different operations
    switch (userInput)
    {
      case 1:
              //print student tree in ascending order
              masterStudent->printTree();
              break;

      case 2:
              //print faculty tree in ascending order
              masterFaculty->printTree();
              break;

      case 3:
              //print information of student given ID #
              int lookId;
              cout << "Enter the student ID# of the student you'd like to look up." << endl;
              cin >> lookId;
              // stuTree->find(lookId)->printStudent();
              break;

      case 4:
              //print information of faculty given ID #
              cout << "Enter the faculty ID# of the student you'd like to look up." << endl;
              cin >> lookId;
              // facTree->find(lookId)->printFaculty();
              break;

      case 5: //print info of student's faculty advisor given student id
              cout << "Enter the student's ID#" << endl;
              cin >> lookId;
              // lookId = stuTree->find(lookId)->getAdvisor();
              // cout << "Advisor's name is: " << facTree->find(lookId)->getName() << endl;
              break;

      case 6: //print all names of facutlies advisees given faculty ID #
              cout << "Enter the faculty's ID#" << endl;
              cin >> lookId;
              //need to get linked list and then use find() method on each value given to display names of students
              break;

      case 7: //everytime you create a student make sure you add them to the advisors list of advisees
              break;


      case 14:
              // Write to files

              faculty_out.open("facultyTable");
              student_out.open("studentTable");

              masterFaculty->serializeTree(faculty_out);
              faculty_out.close();

              masterStudent->serializeTree(student_out);
              student_out.close();

              // that was easy (it wasn't, but it sure looks easy)
              return 0;
              break;

      default:
              cout << "Invalid input. Try again!" << endl;
              break;
    }
  }

  return 0;
}
