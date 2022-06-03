/*income tax calculator on the basis of different income tax slabs (As by Income Tax of India)*/
/*source of info:https://www.incometax.gov.in/iec/foportal/help/individual/return-applicable-1*/
#include <iostream>
using namespace std;
class maths
{
protected:
    float calculatePercentage(float amount, float percentage)
    {
        return amount * percentage / 100.0;
    }
};

class incomeTax : private maths
{
public:
    void taxCalculator()
    {
        
    }
};