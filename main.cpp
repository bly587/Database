#include <iostream>
#include <fstream>
#include "BST.h"
#include "SpecialBST.h"
#include "Faculty.h"
#include "DBEdits.h"

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

  // Declare variables
  ofstream faculty_out;
  ofstream student_out; // Create outfiles early because they cannot be declared in the switch/case
  string rollItBack;

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
    int sizeOfList;
    int oldAdvisor;
    string um_id;
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
              cin.ignore();
              //print information of student given ID #
              int lookId;

              cout << "Enter the student ID# of the student you'd like to look up." << endl;
              getline(cin, um_id);
              // Try catch block refuses (not punishes lol) to allow user to input incorrect value
              try
              {
                lookId = stoi(um_id);
              }
              catch (invalid_argument e)
              {
                cout << "Invalid input given. Please try again." << endl;
                break;
              }
              catch (out_of_range e)
              {
                cout << "Your input is too large. Please try again." << endl;
                break;
              }
              //if no errors thrown then do this
              masterStudent->find(lookId)->print();
              break;

      case 4:
              cin.ignore();
              //print information of student given ID #

              cout << "Enter the faculty ID# of the faculty you'd like to look up." << endl;
              getline(cin, um_id);
              // Try catch block refuses (not punishes lol) to allow user to input incorrect value
              try
              {
                lookId = stoi(um_id);
              }
              catch (invalid_argument e)
              {
                cout << "Invalid input given. Please try again." << endl;
                break;
              }
              catch (out_of_range e)
              {
                cout << "Your input is too large. Please try again." << endl;
                break;
              }
              //print information of faculty given ID #
              masterFaculty->find(lookId)->print();
              break;

      case 5: //print info of student's faculty advisor given student id
              cin.ignore();
              //print information of student given ID #

              cout << "Enter the student's ID#" << endl;
              getline(cin, um_id);
              // Try catch block refuses (not punishes lol) to allow user to input incorrect value
              try
              {
                lookId = stoi(um_id);
              }
              catch (invalid_argument e)
              {
                cout << "Invalid input given. Please try again." << endl;
                break;
              }
              catch (out_of_range e)
              {
                cout << "Your input is too large. Please try again." << endl;
                break;
              }
              //get advisor ID from student object
              lookId = masterStudent->find(lookId)->getAdvisor();
              cout << "Here is the information of this student's advisor:" << endl;
              masterFaculty->find(lookId)->print();
              break;

      case 6: //print all names of facutly's advisees given faculty ID #
              cin.ignore();
              //print information of student given ID #

              cout << "Enter the faculty ID# of the faculty" << endl;
              getline(cin, um_id);
              // Try catch block refuses (not punishes lol) to allow user to input incorrect value
              try
              {
                lookId = stoi(um_id);
              }
              catch (invalid_argument e)
              {
                cout << "Invalid input given. Please try again." << endl;
                break;
              }
              catch (out_of_range e)
              {
                cout << "Your input is too large. Please try again." << endl;
                break;
              }
              //make variable for the size of the faculty's linkedlist
              sizeOfList = masterFaculty->find(lookId)->getList()->getSize();
              //check if list has anyone in it
              cout << "Advisees: " << endl;
              if(sizeOfList != 0)
              {
                int tempId;
                //for the size of the list, print out the name of every student
                for(int i = 0; i < sizeOfList; ++i)
                {
                  tempId = masterFaculty->find(lookId)->getList()->removeFront();
                  //have integer, time to use find method on that id number
                  cout << masterStudent->find(tempId)->getName() << "   ";
                  //insert the student id into the back of the list
                  masterFaculty->find(lookId)->getList()->insertBack(tempId);
                }
                cout << "\n" << endl;
              }
              break;

      case 7: // add student
      {

              cin.ignore(); // need to catch the last input's newline char so our input will work here

              // declare variables
              string name, level, major;
              int id, advisor;
              double gpa;

              // Gathers name and level
              cout << "Please input the new student's full name: " << endl;
              getline(cin, name);
              cout << "Please input the new student's level: " << endl;
              getline(cin, level);
              // Ask user if they want to pick an id number or not
              string str_id_choice;
              int id_choice = 0;
              while(id_choice != 1 && id_choice != 2){
                cout << "Would you like to \n1) Choose a student id\n2) Generate a random student id" << endl;
                getline(cin, str_id_choice);
                try{
                  id_choice = stoi(str_id_choice);
                }
                catch(invalid_argument e){}

              }
              // Lets the user choose the id number
              string str_id;
              if (id_choice == 1){
                cout << "Please input an id for the new student: " << endl;
                getline(cin, str_id);
                // Try catch block punishes the user for entering something that isnt a number (or too large to be an integer)
                try{
                  id = stoi(str_id);
                }
                catch (invalid_argument e){
                  cout << "Invalid input given. Please try again." << endl;
                  break;
                }
                catch (out_of_range e){
                  cout << "Your input is too large. Please try again." << endl;
                  break;
                }

              }
              else{ // id_choice == 2
                id = 42069;
              }

              // Gathers major
              cout << "Please input the new student's major" << endl;
              getline(cin, major);
              // Gathers GPA
              string str_gpa;
              cout << "Please input the new student's GPA (decimal value): " << endl;
              getline(cin, str_gpa);
              // Try catch block punishes the user for entering something that isnt a number
              try{
                gpa = stod(str_gpa);
              }
              catch (invalid_argument e){
                cout << "Invalid input given. Please try again." << endl;
                break;
              }

              // Gathers faculty advisor
              string str_advisor;
              cout << "Please input the id number of the advisor for this new student: " << endl;
              getline(cin, str_advisor);
              // Try catch block punishes the user for entering something that isnt a number (or too large to be an integer)
              try{
                advisor = stoi(str_advisor);
              }
              catch (invalid_argument e){
                cout << "Invalid input given. Please try again." << endl;
                break;
              }
              catch (out_of_range e){
                cout << "Your input is too large. Please try again." << endl;
                break;
              }

              // Ensures the given id number is valid
              if (masterFaculty->find(advisor) == NULL){
                cout << "No faculty member exists with that id. Please try again." << endl;
                break;
              }


              // Double check information for user
              cout << "Does this information look right? (y/n)" << endl;
              string good2go;
              cout << "Name: " << name << endl;
              cout << "Level: " << level << endl;
              cout << "ID: " << id << endl;
              cout << "Major: " << major << endl;
              cout << "GPA: " << gpa << endl;
              cout << "Advisor ID: " << advisor << endl;
              getline(cin, good2go);

              // Ensures valid input
              while (good2go != "y" && good2go != "n"){
                cout << "Please input a valid value: \'y\' or \'n\'" << endl;
                getline(cin, good2go);
              }

              // Good to go. Make new student and insert into tree
              if (good2go == "y"){
                Student* s = new Student(name, level, id, major, gpa, advisor);
                masterStudent->insert(s);

                //everytime you create a student, make sure you add them to the advisors list of advisees
                Faculty* f = masterFaculty->find(advisor);
                f->addAdvisee(id);

                // Add this student to stack of adds

              }
              // information is wrong
              else{
                cout << "Please come back and re-input your values..." << endl;
                break;
              }

              break;
      }
      case 8:
              cout << "case 8" << endl;
              break;
      case 9:
              cout << "case 9" << endl;
              break;
      case 10:
              cout << "case 10" << endl;
              break;
      case 11: //change advisor given student's id and the new faculty id
              cin.ignore(); //you right
              int newFacId;
              //error check input
              cout << "Enter the Student's ID#" << endl;
              getline(cin, um_id);
              // Try catch block refuses (not punishes lol) to allow user to input incorrect value
              try
              {
                lookId = stoi(um_id);
              }
              catch (invalid_argument e)
              {
                cout << "Invalid input given. Please try again." << endl;
                break;
              }
              catch (out_of_range e)
              {
                cout << "Your input is too large. Please try again." << endl;
                break;
              }
              //error check input
              cout << "Enter the Faculty's ID#" << endl;
              getline(cin, um_id);
              // Try catch block refuses (not punishes lol) to allow user to input incorrect value
              try
              {
                newFacId = stoi(um_id);
              }
              catch (invalid_argument e)
              {
                cout << "Invalid input given. Please try again." << endl;
                break;
              }
              catch (out_of_range e)
              {
                cout << "Your input is too large. Please try again." << endl;
                break;
              }
              //check if student has an advisor and if they are deleted from their list
              oldAdvisor = masterStudent->find(lookId)->getAdvisor();

              if(oldAdvisor != newFacId)
              {
                //delete student from old faculty advisor's list
                if(masterFaculty->find(oldAdvisor)->getList()->find(lookId) == true)
                {
                  masterFaculty->find(oldAdvisor)->getList()->remove(lookId);
                }
                //change advisor in student class
                masterStudent->find(lookId)->setAdvisor(newFacId);
                //add student to faculty id
                masterFaculty->find(newFacId)->getList()->insertFront(lookId);
              }
              else
              {
                cout << "Bruh he already his advisor..." << endl;
              }
              cout << "Set new fac id for " << lookId << " to " << masterStudent->find(lookId)->getAdvisor() << endl;
              break;
      case 12: //remove student from faculty's linked list given respective ids
              cin.ignore(); //you right
              int facId;
              //error check input
              cout << "Enter the Student's ID# you'd like to have removed" << endl;
              getline(cin, um_id);
              // Try catch block refuses (not punishes lol) to allow user to input incorrect value
              try
              {
                lookId = stoi(um_id);
              }
              catch (invalid_argument e)
              {
                cout << "Invalid input given. Please try again." << endl;
                break;
              }
              catch (out_of_range e)
              {
                cout << "Your input is too large. Please try again." << endl;
                break;
              }
              cout << "Enter the Faculty's ID#" << endl;
              getline(cin, um_id);
              // Try catch block refuses (not punishes lol) to allow user to input incorrect value
              try
              {
                facId = stoi(um_id);
              }
              catch (invalid_argument e)
              {
                cout << "Invalid input given. Please try again." << endl;
                break;
              }
              catch (out_of_range e)
              {
                cout << "Your input is too large. Please try again." << endl;
                break;
              }

              //check to make sure the student's Id is in the respective faculty's linkedlist
              if(masterFaculty->find(facId)->getList()->find(lookId) == true)
              {
                //deleting student from faculty's linked list
                masterFaculty->find(facId)->getList()->remove(lookId);
                //update student to have no advisor
                masterStudent->find(lookId)->setAdvisor(0); //0 refers to no faculty ID
              }
              else
              {
                cout << "Um maybe wrong faculty Id? Cuz that's not his advisor..." << endl;
                break;
              }
              break;

      case 13:
              cout << "Hey what's up we about to roll it BACK" << endl;
              rollItBack = "roll it back. ";
              for (int i = 0; i < 420; ++i){
                cout << rollItBack << endl;
                rollItBack += "roll it back. ";
              }

              // Actual rollback to implemented right here



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

              // delete trees before closing out of program
              delete masterFaculty;
              delete masterStudent;

              return 0;
              break;

      default:
              cout << "Invalid input. Try again!" << endl;
              break;
    }
  }

  return 0;
}
