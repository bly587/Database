#include <iostream>

using namespace std;

class Student{
  public:

    string m_major;
    double m_gpa;
    int m_advisor;


    //constructor
    Student();
    //overload
    Student(string major, double gpa, int advisor);
    //getters
    string getMajor();
    double getGPA();
    int getAdvisor();
    //setters
    void setMajor(string major);
    void setGPA(double gpa);
    void setAdvisor(int advisor);
    //methods
};
//constructors
Student::Student()
{
  m_major = NULL;
  m_gpa = 0.00;
  m_advisor = NULL;
}

Student::Student(string major, double gpa, int advisor)
{
  m_major = major;
  m_gpa = gpa;
  m_advisor = advisor;
}
//getters
string Student::getMajor()
{
  return m_major;
}

double Student::getGPA()
{
  return m_gpa;
}

int Student::getAdvisor()
{
  return m_advisor;
}
//setters
void Student::setMajor(string major)
{
  m_major = major;
}
void Student::setGPA(double gpa)
{
  m_gpa = gpa;
}
void Student::setAdvisor(int advisor)
{
  m_advisor = advisor;
}
//methods
