/*
 **ADVANCED CALCULATOR
 *1. Basic Arithmetic Calculator
 *2. Income Tax Calculator
 *   income tax calculator on the basis of different income tax slabs (As by Income Tax of India)
 *   source of info:https://www.incometax.gov.in/iec/foportal/help/individual/return-applicable-1
 *3. Interest Calculator (with Investment Calculator)
 *4. Loan Calculator (EMI etc)
 *5. GST Calculator
 *6. Discount Calculator
 *7. Age Calculator
 *
 *
 */

#include <iostream>
using namespace std;
class mathsOperations
{
protected:
    float calculatePercentage(float amount, float percentage)
    {
        return amount * percentage / 100.0;
    }
};

class arithmeticCalculator
{
    void menu()
    {
    }

public:
};

class incomeTax : private mathsOperations
{
public:
    void taxCalculator()
    {
    }
};