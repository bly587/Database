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
    Student(int advisor);
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

Student::Student()
{
  waitTime = 0;
  timeNeeded = 0;
}

Student::Student(int tn)
{
  waitTime = 0;
  timeNeeded = tn;
}
