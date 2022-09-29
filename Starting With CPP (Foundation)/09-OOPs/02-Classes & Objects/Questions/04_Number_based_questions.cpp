#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

class Year
{
    int year;

protected:
    /*returns true if year is leap else false*/
    bool isLeapYear()
    {
        if (!year % 100)
            return year % 400 ? false : true;
        else
            return year % 4 ? false : true;
    }

    /*to assign data in data member*/
    void assign(int year)
    {
        this->year = year;
    }

public:
    /*default constructor*/
    Year()
    {
        year = 0;
    }

    /*parameterized constructor*/
    Year(int year)
    {
        this->year = year;
    }

    /*destructor*/
    ~Year() {}
};

class Number : public Year
{
    int value;

    /*returns no. of digits of the given number (here value)*/
    short numberOfDigits()
    {
        int temp = value; // to store the value temporarily.`
        short counter = 0;
        while (temp > 0)
        {
            temp /= 10;
            counter++;
        }
        return counter;
    }

    /*returns factorial of the given number*/
    unsigned long fact(Number n)
    {
        return n.value == 0 || n.value == 1 ? 1 : (n.value-- * fact(n));
    }

    /*returns true if number is prime else false*/
    bool isPrime(Number n)
    {
        if (n.value < 2)
            return false;
        for (int i = 2; i < n.value; i++)
            if (n.value % i == 0)
                return false;
        return true;
    }

public:
    /*default constructor*/
    Number()
    {
        value = 0;
    }

    /*parameterized constructor*/
    Number(int value) : Year(value)
    {
        this->value = value;
    }

    /*Copy Constructor*/
    Number(const Number &obj)
    {
        value = obj.value;
    }

    /*destructor*/
    ~Number() {}

    /*to input data in the data member (value). Input of only one number. @param: Message to be printed before input screen.*/
    void get(const char *message = "Write number: ")
    {
        cout << message << endl
             << "$ ";
        cin >> value;
    }

    /*returns true if zero else false*/
    bool isZero()
    {
        return value == 0 ? true : false;
    }

    /*returns true if value is negative*/
    bool isNegative()
    {
        return value < 0 ? true : false;
    }

    /*returns true if even else false*/
    bool isEven()
    {
        return value % 2 ? false : true;
    }

    /*returns true if number is perfect else false*/
    bool isPerfect()
    {
        int sum = 0;
        for (int i = 1; i <= value / 2; i++)
            sum += i;
        return sum == value ? true : false;
    }

    /*returns summation of digits of the number*/
    int sumOfDigits()
    {
        int temp = value; // to store the value temporarily.
        int sum = 0;      // to store the summation
        while (temp > 0)
        {
            short r = temp % 10;
            temp /= 10;
            sum += r;
        }
        return sum;
    }

    /*returns reverse of the number*/
    int reverse()
    {
        int temp = value;  // to store the value temporarily.
        int reverseNo = 0; // to store the reverse
        while (temp > 0)
        {
            short r = temp % 10;
            reverseNo = reverseNo * 10 + r;
            temp /= 10;
        }
        return reverseNo;
    }

    /*returns true if number is palindrome else false*/
    bool isPalindrome()
    {
        return reverse() == value ? true : false;
    }

    /*returns true if number is armstrong else false*/
    bool isArmstrong()
    {
        short digits = numberOfDigits(); // to store the number of digits
        int temp = value;                // to store the value temporarily
        int specialSum = 0;              // to store the specialSum for armstrong
        while (temp > 0)
        {
            short r = temp % 10;
            specialSum += ceil(pow(r, digits));
            temp /= 10;
        }
        return specialSum == value ? true : false;
    }

    /*returns factorial of the number. If not possible then returns -1*/
    unsigned long factorial()
    {
        return value >= 0 ? fact(*this) : -1;
    }

    /*returns npr of the number where n is of current object and r will be taken as function argument.*/
    float npr(Number r)
    {
        // formula: n! / (n - r)!
        Number tempObject(value - r.value);
        return factorial() / fact(tempObject);
    }

    /*returns ncr of the number where n is of current object and r will be taken as function argument.*/
    float ncr(Number r)
    {
        // formula: n!/(r!*(n-r)!) =  npr / r!
        return npr(r) / fact(r);
    }

    /*returns the greatest/smallest number of the two numbers (current object data member and the argument). By default, return greatest.*/
    int maxMinInTwo(Number num, bool max = true)
    {
        if (max)
            return value > num.value ? value : num.value;
        return value < num.value ? value : num.value;
    }

    /*returns HCF of the two numbers (current object and the argument)*/
    int hcf(Number n)
    {
        int min = maxMinInTwo(n, false);
        for (int i = min; i > 0; i--)
            if (value % i == 0 && n.value % i == 0)
                return i;
    }

    /*returns LCM of the two numbers (current object and the argument)*/
    int lcm(Number n)
    {
        int max = maxMinInTwo(n);
        for (int i = 1;; i++, max *= i)
            if (max % value == 0 && max % n.value == 0)
                return max;
    }

    /*returns power of current object data member(value) to the power passed number as argument*/
    int power(Number n)
    {
        return (int)ceil(pow(value, n.value));
    }

    /* returns fibonacci series from n1 to n2(including) where n1 is the data member of current object and n2 will be data member of received object via argument.
     * Also takes argument of length of array by reference in which the length of the returned array of fibonacci series will store.
     */
    int *fibonacci(Number n2, short &arrayLength)
    {
        int a = -1, b = 1, c;
        int max = maxMinInTwo(n2);
        int min = maxMinInTwo(n2, false);
        int *series = (int *)calloc(1, sizeof(int));
        int i = 0;

        while (true)
        {
            c = a + b;
            a = b;
            b = c;
            if (c >= min && c <= max) /*because we have to generate series only from min to max (including)*/
            {
                series[i++] = c;
                series = (int *)realloc(series, i + 1); // reallocating memory
            }
            else if (c > max)
                break;
        }
        arrayLength = i;
        return series;
    }

    /* returns fibonacci series between n1 to n2 where n1 is the data member of current object and n2 will be data member of received object via argument.
     * Also takes argument of length of array by reference in which the length of the returned array of prime numbers will store.
     */
    int *primeSequence(Number n2, short &arrayLength)
    {
        int *series = (int *)calloc(1, sizeof(int));
        int max = maxMinInTwo(n2);
        int min = maxMinInTwo(n2, false);
        int i = 0;
        while (min < max)
        {
            min++;
            n2.value = min;
            if (isPrime(min))
            {
                series[i++] = min;
                series = (int *)realloc(series, i + 1); // reallocating memory
            }
        }
        arrayLength = i;
        return series;
    }

    /*returns true if year is leap else false*/
    bool isLeapYear()
    {
        assign(value); // Year::assign();
        return Year::isLeapYear();
    }

    /*returns greatest number in three. One is current data member and rest are from argument*/
    int greaterInThree(Number n2, Number n3)
    {
        int max = maxMinInTwo(n2); /*max will contains maximum in n2 and value*/
        return max > n3.value ? max : n3.value;
    }
};

/*display menu to user and take input and return the same. Also handle wrong input by user.*/
short mainMenu()
{
    cout << "[01] For odd or even." << endl
         << "[02] For +ve or -ve or neither +ve nor -ve." << endl
         << "[03] Perfect or not." << endl
         << "[04] Summation of digits." << endl
         << "[05] Reverse of the number." << endl
         << "[06] Palindrome or not." << endl
         << "[07] Armstrong of not." << endl
         << "[08] Factorial." << endl

         << "[09] npr" << endl
         << "[10] ncr" << endl
         << "[11] HCF" << endl
         << "[12] LCM" << endl
         << "[13] Power" << endl
         << "[14] Fibonacci series between 2 no (including)" << endl
         << "[15] Prime number between 2 no. (Excluding)" << endl
         << "[16] Leap Year " << endl
         << "[17] Greatest in three." << endl
         << "[18] Compound Interest" << endl
         << "[19] Bonus Calculator" << endl
         << "[20] Catalan Number" << endl
         << "[0] To clear the display." << endl
         << "[-1] To exit." << endl;

    cout << "Write your choice: " << endl
         << "$ ";
    short choice;
    cin >> choice;
    return choice;
}

class Interest
{
    float pr, rate, time;

public:
    /*default Constructor*/
    Interest()
    {
        pr = 0.0;
        rate = 0.0;
        time = 0.0;
    }

    /*Parameterized constructor*/
    Interest(float pr, float rate, float time)
    {
        this->pr = (float)pr;
        this->rate = (float)rate;
        this->time = (float)time;
    }

    /*destructor*/
    ~Interest() {}

    float compoundInterest()
    {
        return pr * pow((1.0 + (rate / 100.0)), time);
    }
};

class Sales
{
    int costPrice;     /*by shop keeper*/
    int purchasePrice; /*by customer*/

public:
    /*default Constructor*/
    Sales()
    {
        costPrice = 0;
        purchasePrice = 0;
    }
    /*parameterized constructor*/
    Sales(float purchasePrice, int costPrice = 0) /*const price is not compulsory in current scenario*/
    {
        this->costPrice = costPrice;
        this->purchasePrice = purchasePrice;
    }

    /*destructor*/
    ~Sales() {}

    /*returns bonus as predefined rule*/
    const int bonus()
    {
        if (purchasePrice < 1000)
            return 0;
        else if (purchasePrice >= 1000 && purchasePrice <= 2000)
            return 350;
        else
            return 700;
    }
};
/*returns true on successful execution else false on failure */
bool performOperation()
{
    Number num;
    while (true)
    {
        switch (mainMenu())
        {
        /*for exit*/
        case -1:
            return true;

        /*for clear the screen*/
        case 0:
            system("cls");
            break;

        /*for odd and even*/
        case 1:
            num.get();
            if (num.isEven())
                cout << "Number is even." << endl;
            else
                cout << "Number is odd" << endl;
            break;

        /*for negative, positive or zero*/
        case 2:
            num.get();
            if (!num.isZero())
            {
                if (num.isNegative())
                    cout << "Number is -ve." << endl;
                else
                    cout << "Number is +ve" << endl;
            }
            else
                cout << "Number is neither -ve nor +ve." << endl;
            break;

        /*for perfect or not*/
        case 3:
            num.get();
            if (num.isPerfect())
                cout << "Number is perfect." << endl;
            else
                cout << "Number is not perfect." << endl;
            break;

        /*for summation of digits*/
        case 4:
            num.get();
            cout << "Summation of digits = " << num.sumOfDigits() << endl;
            break;

        /*for reverse of number*/
        case 5:
            num.get();
            cout << "Reverse of number = " << num.reverse() << endl;
            break;

        /*for checking palindrome*/
        case 6:
            num.get();
            if (num.isPalindrome())
                cout << "Number is palindrome." << endl;
            else
                cout << "Number is not palindrome." << endl;
            break;

        /*for checking armstrong*/
        case 7:
            num.get();
            if (num.isArmstrong())
                cout << "Number is armstrong." << endl;
            else
                cout << "Number is not armstrong." << endl;
            break;

        /*To find factorial*/
        case 8:
            num.get();
            if (num.factorial() != -1)
                cout << "Factorial of number = " << num.factorial() << endl;
            else
                cout << "Factorial of -ve number is not defined." << endl;
            break;

        /*To find npr*/
        case 9:
        {
            num.get("Write n: ");
            Number r;
            r.get("Write r: ");
            cout << "npr = " << num.npr(r) << endl;
            break;
        }

        /*To find ncr*/
        case 10:
        {
            num.get("Write n: ");
            Number r;
            r.get("Write r: ");
            cout << "ncr = " << num.ncr(r) << endl;
            break;
        }

        /*To find HCF*/
        case 11:
        {
            num.get("Write 1st number: ");
            Number n;
            n.get("Write 2nd number: ");
            cout << "HCF = " << num.hcf(n) << endl;
            break;
        }

        /*To find LCM*/
        case 12:
        {
            num.get("Write 1st number: ");
            Number n;
            n.get("Write 2nd number: ");
            cout << "LCM = " << num.lcm(n) << endl;
            break;
        }

        /*Power*/
        case 13:
        {
            num.get("Write base: ");
            Number n;
            n.get("Write exponent: ");
            cout << "HCF = " << num.power(n) << endl;
            break;
        }

        /*Fibonacci Series*/
        case 14:
        {
            num.get("Write initial number: ");
            Number n;
            n.get("Write final number: ");
            short arrayLength = 0;
            int *series = num.fibonacci(n, arrayLength);
            /*printing*/
            cout << "Desired Fibonacci Series: ";
            for (int i = 0; i < arrayLength; i++)
                cout << series[i] << " ";
            cout << endl;
            free(series); // freeing memory
            break;
        }

        /*Prime Number Series*/
        case 15:
        {
            num.get("Write initial number: ");
            Number n;
            n.get("Write final number: ");
            short arrayLength = 0;
            int *series = num.primeSequence(n, arrayLength);
            /*printing*/
            cout << "Desired Prime Numbers: ";
            for (int i = 0; i < arrayLength; i++)
                cout << series[i] << " ";
            cout << endl;
            free(series); // freeing memory
            break;
        }

        /*Leap year*/
        case 16:
            num.get("Write year: ");
            if (num.isLeapYear())
                cout << "Leap Year." << endl;
            else
                cout << "Non-Leap Year." << endl;
            break;

        /*Greatest among 3*/
        case 17:
        {
            Number n2, n3;
            num.get("Write 1st number: ");
            n2.get("Write 3rd number: ");
            n3.get("Write 2nd number: ");
            cout << "Greatest is " << num.greaterInThree(n2, n3) << endl;
        }
        break;

        /*Compound Interest*/
        case 18:
        {
            cout << "write principle,rate & time(year) separated by space: ";
            float pr, rate, time;
            cin >> pr >> rate >> time;
            Interest obj(pr, rate, time);
            cout << "Compound Interest = " << obj.compoundInterest() << endl;
        }
        break;

        /*bonus calculator*/
        case 19:
        {
            int purchasePrice;
            cout << "Write purchase price: ";
            cin >> purchasePrice;
            Sales obj(purchasePrice);
            cout << "Bonus is " << obj.bonus() << endl;
        }
        break;

        /*Catalan Number*/
        case 20:
            cout << "Code is not written yet..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
        system("pause");
    }
}

int main()
{
    return !performOperation(); /*0 on success else on failure*/
}
