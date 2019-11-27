#include <iostream>
#include "Student.h"
#include "SDoublyLinkedList.h"

using namespace std;

class Faculty : public Person{
  public:
    string m_department;
    SDoublyLinkedList<int> *m_advisees;

    //constructor
    Faculty(string name, string level, int id);
    //overload
    Faculty(string name, string level, int id, string department, int student);
    // deserialize constructor
    Faculty(istream& i);
    //getters
    string getDepartment();
    SDoublyLinkedList<int>* getList();
    //setters
    void setDepartment(string depo);
    void addAdvisee(int id);
    //methods
    void print();
    // serialize
    ostream& serialize(ostream& o);

};
//constructors
Faculty::Faculty(string name, string level, int id) : Person(name, level, id)
{
  m_department = "";
  m_advisees = new SDoublyLinkedList<int>;
}

Faculty::Faculty(string name, string level, int id, string department, int student) : Person(name, level, id)
{
  m_department = department;
  m_advisees = new SDoublyLinkedList<int>;
  m_advisees->insertFront(student);
}

SDoublyLinkedList<int>* Faculty::getList()
{
  return m_advisees;
}

Faculty::Faculty(istream& i) : Person(i){
  getline(i, m_department); // read in new line char
  getline(i, m_department); // Read in actual department --> getline used so multiple words can be extracted

  int size; // Represents the amount of advisees an advisor has
  i >> size;
  // Initialize linked-list
  m_advisees = new SDoublyLinkedList<int>;
  // Grab every student id based on size given in file
  int id;
  for (int j = 0; j < size; ++j){
    i >> id;
    m_advisees->insertFront(id);
  }

  string temp;
  getline(i, temp); // Grabs a new line --> end of last id
  getline(i, temp); // Grabs a new line --> empty line
}

//getters
string Faculty::getDepartment()
{
  return m_department;
}
//setters
void Faculty::setDepartment(string depo)
{
  m_department = depo;
}

void Faculty::print()
{
  cout << "Name: " << getName() << endl;
  cout << "ID: " << getId() << endl;
  cout << "Level: " << getLevel() << endl;
  cout << "Department: " << getDepartment() << endl;
  cout << "List of Students: " << endl;
  m_advisees->printList();
  cout << "\n" << endl;;
}

void Faculty::addAdvisee(int id)
{
  m_advisees->insertFront(id);
}

// serializes faculty data to file via ostream& o
ostream& Faculty::serialize(ostream& o){
  o << getName() << endl;
  o << getLevel() << endl;
  o << getId() << endl;
  o << m_department << endl;
  // Gets size of list and saves it since our removeFront will change the size during the loop
  int linkedListSize = m_advisees->getSize();
  o << linkedListSize << endl;
  // Loop through linked list
  for (int i = 0; i < linkedListSize; ++i){
    o << m_advisees->removeFront() << endl; // it is okay for us to remove since these serializations will happen at the end of the program
  }
  o << endl;

  return o;
}
