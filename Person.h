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
    // deserialize constructor
    Person(istream& i);
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
    friend istream& operator >> (istream& i, Person& p);
    void printPerson();

    //virtual string serialize();

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

Person::Person(istream& i){
  // getline used for strings and >> for other types
  getline(i, m_name);
  getline(i, m_level);
  i >> m_id;
}

Person::~Person()
{

}

//method
void Person::printPerson()
{
  cout << "Name: " << getName() << endl;
  cout << "Level: " << getLevel() << endl;
  cout << "ID: " << getId() << endl;
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
  //cout << "doing the prints" << endl;
  o << p.m_name << endl;
  o << p.m_level << endl;
  o << p.m_id << endl;
  return o;
}

istream& operator >> (istream& i, Person& p){
  i >> p.m_name;
  i >> p.m_level;
  i >> p.m_id;
  return i;
}
