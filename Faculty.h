#include <iostream>
#include "Student.h"
#include "SLinkedList.h"

using namespace std;

class Faculty : public Person{
  public:
    string m_department;
    SLinkedList<int> *m_advisees;

    //constructor
    Faculty(string name, string level, int id);
    //overload
    Faculty(string name, string level, int id, string department, int student);
    //getters
    string getDepartment();
    //setters
    void setDepartment(string depo);
    void addAdvisee(int id);
    //methods
    void printFaculty();

};
//constructors
Faculty::Faculty(string name, string level, int id) : Person(name, level, id)
{
  m_department = "";
  m_advisees = new SLinkedList<int>;
}

Faculty::Faculty(string name, string level, int id, string department, int student) : Person(name, level, id)
{
  m_department = department;
  m_advisees = new SLinkedList<int>;
  m_advisees->insertFront(student);
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

void Faculty::printFaculty()
{
  cout << "Faculty: " << endl;
  cout << "Name: " << getName() << endl;
  cout << "Level: " << getLevel() << endl;
  cout << "Department: " << getDepartment() << endl;
  cout << "List of Students: ";
  m_advisees->printList();
  cout << "\n";
}

void Faculty::addAdvisee(int id)
{
  m_advisees->insertFront(id);
}
