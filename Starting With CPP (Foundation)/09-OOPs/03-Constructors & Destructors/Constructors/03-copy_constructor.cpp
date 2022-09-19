/* Copy Constructor
 * Copy Constructor is used copy the content of one object to another object while creating a new object.
 * Copy Constructor is called when a new object is created from assigning an existing object.
 * By use of copy constructor, The content of one object can be copied to another object.
 * It is auto called while creating a new object from an existing object by assignment.
 * It creates copy object that's why it is called copy constructor.
 *
 * It is nothing but a constructor that takes an object of same class as argument. That's enough to understand the concept.
 */

#include <iostream>
using namespace std;

class College
{
    string collegeName;
    int totalStudents;

public:
    /*default constructor*/
    College()
    {
        collegeName = "";
        totalStudents = 0;
    }

    /*parameterized constructor*/
    College(const char *collegeName, int totalStudents)
    {
        this->collegeName = collegeName;
        this->totalStudents = totalStudents;
    }

    /*copy constructor*/
    College(const College &existingObject)
    {
        collegeName = existingObject.collegeName;
        totalStudents = existingObject.totalStudents;
    }

    /*function to display the data of object*/
    void displayData()
    {
        cout << "College Name: " << collegeName << endl;
        cout << "Total Students: " << totalStudents << endl;
    }
};

int main()
{
    College obj("RDS College", 5000);
    /* College obj = College("RDS College", 5000);*/ // we can also use like this to create a new instance. (Explicit Call)
    obj.displayData();
    /* Ouput:
     * College Name: RDS College
     * Total Students: 5000
     */

    /************COPY CONSTRUCTOR*************/
    /*Now, creating a new instance of College by copying the data of existing object = obj by use of copying constructor */
    College newInstance(obj);
    /*College newInstance = College(obj);*/ // we can also use like this to create a new instance. (Explicit Call)
    newInstance.displayData();
    /* Output:
     * College Name: RDS College
     * Total Students: 5000
     */
}