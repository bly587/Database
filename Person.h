#include <iostream>
//#include <fstream>

using namespace std;

class Person{
  public:
    //functions
    //constructor
    Person();
    //overloaded
    Person(string name, string level, int id);
    //destructor
    ~Person();

    //getters
    string getName();
    string getLevel();
    int getId();
    //setters
    void setName(string name);
    void setLevel(string level);
    void setId(int id);
    //methods
    friend bool operator < (Person &obj1, Person &obj2);
    friend bool operator > (Person &obj1, Person &obj2);
    friend ostream& operator << (ostream& o, Person& p);

  private:
    string m_name;
    string m_level;
    int m_id;
};

//constructors
Person::Person()
{
  //constructor
  m_name = "";
  m_level = "";
  //m_id = NULL;
}

Person::Person(string name, string level, int id)
{
  //overloaded
  m_name = name;
  m_level = level;
  m_id = id;
}

Person::~Person()
{

}

//getters
string Person::getName()
{
  return m_name;
}

string Person::getLevel()
{
  return m_level;
}

int Person::getId()
{
  return m_id;
}

//setters
void Person::setName(string name)
{
  m_name = name;
}

void Person::setLevel(string level)
{
  m_level = level;
}

void Person::setId(int id)
{
  m_id = id;
}

// Overload operators
bool operator < (Person &obj1, Person &obj2){
  cout << "comparing " << obj1.m_id << " with " << obj2.m_id << endl;
  if (obj1.m_id < obj2.m_id){
    return true;
  }
  else{
    return false;
  }
}

bool operator > (Person &obj1, Person &obj2){
  cout << "comparing " << obj1.m_id << " with " << obj2.m_id << endl;
  if (obj1.m_id > obj2.m_id){
    return true;
  }
  else{
    return false;
  }
}

// Overload Print
ostream& operator << (ostream& o, Person& p){
  o << "id=" << p.m_id << endl;
  return o;
}
