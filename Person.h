#inlcude <iostream>

using namespace std;

class Person{
  public:
    //functions
    //constructor
    Person();
    //overloaded
    Person(string name, string level, int id);
    //destrutor
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

  private:
    string m_name;
    string m_level;
    int m_id;
};

//constructors
Person::Person()
{
  //constructor
  m_name = NULL;
  m_level = NULL;
  m_id = NULL;
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
void setLevel(string level)
{
  m_level = level;
}
void setId(int id)
{
  m_id = id;
}
