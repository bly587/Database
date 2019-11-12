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
