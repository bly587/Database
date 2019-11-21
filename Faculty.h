#include <iostream>

using namespace std;

class Faculty{
  public:
    string m_department;
    LinkedList* m_advisees;

    //constructor
    Faculty();
    //overload
    Faculty(int student);
    //getters
    string getDepartment();
    //setters
    void setDepartment();
};

Faculty::Faculty()
{
  m_department = NULL;
  m_advisees = NULL;
}

Faculty::Faculty(int student)
{
  m_advisees.push(student);
}
