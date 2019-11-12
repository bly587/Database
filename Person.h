#inlcude <iostream>

using namespace std;

class Person{
  public:
    //functions

  private:
    string m_name;
    string m_level;
    int m_id;

    //getters
    string getName();
    string getLevel();
    int getId();
    //setters
    void setName(string name);
    void setLevel(string name);
    void setId(int id);
    //methods
};
