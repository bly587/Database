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
    Faculty(string department, int student);
    //getters
    string getDepartment();
    //setters
    void setDepartment();
    //methods
    void printFaculty();

};

Faculty::Faculty(string name, string level, int id) : Person(name, level, id)
{
  m_department = "";
  m_advisees = new SLinkedList<int>;
}

Faculty::Faculty(string department, int student)
{
  m_department = department;
  m_advisees = new SLinkedList<int>;
  m_advisees->insertFront(student);
}

void Faculty::printFaculty()
{
  cout << "Faculty: " << endl;
  cout << "Name: " << getName() << endl;
}
