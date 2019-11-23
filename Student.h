#include <iostream>

using namespace std;

class Student : public Person{
  public:

    string m_major;
    double m_gpa;
    int m_advisor;


    //constructor
    Student(string name, string level, int id);
    //overload
    Student(string name, string level, int id, string major, double gpa, int advisor);
    //getters
    string getMajor();
    double getGPA();
    int getAdvisor();
    //setters
    void setMajor(string major);
    void setGPA(double gpa);
    void setAdvisor(int advisor);
    //methods
    //print all students by ascending number
    void printStudent();
};
//constructors
Student::Student(string name, string level, int id) : Person(name, level, id)
{
  m_major = "";
  m_gpa = 0.00;
  m_advisor = 0;
}

Student::Student(string name, string level, int id, string major, double gpa, int advisor) : Person(name, level, id)
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
void Student::printStudent()
{
  cout << "Student: " << endl;
  cout << "Name: " << getName() << endl;
  cout << "Major: " << getMajor() << endl;
  cout << "GPA: " << getGPA() << endl;
  cout << "Advisor: " << getAdvisor() << endl;
}
