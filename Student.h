#include <iostream>

using namespace std;

class Student : public Person{
  public:

    string m_major;
    double m_gpa;
    int m_advisor;

    // empty constructor
    Student();
    //constructor
    Student(string name, string level, int id);
    //overload
    Student(string name, string level, int id, string major, double gpa, int advisor);
    // deserialize
    Student(istream& i);
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
    void print();
    // serialize
    ostream& serialize(ostream& o);
};
//constructors
Student::Student() : Person(){
  string name;
  cout << "Please input the new student's full name" << endl;
  getline(cin, name);
  //cin >> name;
  cout << "name: " << name << endl;
}

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

Student::Student(istream& i) : Person(i){
  getline(i, m_major); // Read in a new line char
  getline(i, m_major); // Read in major --> using getline so multiple words can be extracted
  i >> m_gpa;
  i >> m_advisor;

  string temp;
  getline(i, temp); // Grabs a new line --> end of m_advisor
  getline(i, temp); // Grabs a new line --> actual empty line
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
void Student::print()
{
  cout << "Name: " << getName() << endl;
  cout << "Level: " << getLevel() << endl;
  cout << "ID: " << getId() << endl;
  cout << "Major: " << getMajor() << endl;
  cout << "GPA: " << getGPA() << endl;
  cout << "Advisor: " << getAdvisor() << endl;
  cout << "\n" << endl;
}

// serializes student data to file via ostream& o
ostream& Student::serialize(ostream& o){
  o << getName() << endl;
  o << getLevel() << endl;
  o << getId() << endl;
  o << m_major << endl;
  o << m_gpa << endl;
  o << m_advisor << endl;

  o << endl;

  return o;
}
