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
};







Student Records
Student records will be stored in a Student class. Student records contain a unique
student ID (an integer), a String name field, a string level field (Freshman, Sophomore,
etc), a String major field, a double GPA field, and an integer advisor field, which will
contain the Faculty ID of their advisor. These are the only fields the class contains.
The Student class must overload equality, less than, greater than operators, etc. so that we
can compare them to one another.


Faculty Records

Faculty records are similar to student records, and will also require overloaded operators.
Faculty records contain an integer Faculty ID, a String name, a String level (lecturer,
assistant prof, associate prof, etc), a String department, and a list of integers
corresponding to all of the faculty member’s advisees’ ids.
