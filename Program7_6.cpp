/*
 * Program Name: Operation Menu - Exercise 6
 * Programmer: Reasoner, Kim
 * Course: CSC160-141 Computer Science I C++ Fall 2021
 * Submission Date: 10/26/2021
 * Description: Write a program that uses a random number generator
 * to generate a two digit positive integer and allows the user to perform one or more of the
 * following operations
 */

 // import library
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
// use standard names pace
using namespace std;
//declare the function to double the number
int doubleTheNumber(int randNum);
//declare the function to reverse the digits of the number
int reverseTheDigits(int randNum);
//declare the function to raise the number to the power of 2,3,4
int powerTheNumber(int randNum);
//declare the function to sum the digits of the number
int sumTheDigits(int randNum);
//declare the function to raise the first digit to the power of the second digit
int powerDigit(int randNum);
//declare the function to raise the first two digits to the power of the third digit
int powThreeDigit(int randNum);
//declare the function to determine if the number is prime
void isPrime (int randNum);

int main()
{
    int randNum;
    // get the system time.
    int seed = time(0);
    // seed the random number generator to start the program
    srand(seed);
    randNum = (rand() % 90) + 10;
    // print out the first number, is the random number from computer
    cout << "Random number from computer: " << randNum << endl;
    char choice;
        cout << "-----------OPERATION-------------" << endl;
        cout << "Choose one of the following operations: " << endl;
        cout << "a. Double the number." << endl;
        cout << "b. Reverse the digits of the number." << endl;
        cout << "c. Raise the number to the power 2,3 or 4." << endl;
        cout << "d. Sum the digits of the number." << endl;
        cout << "e. If the number is two-digit number, then raise the digit" << endl;
        cout << "   to the power of the second digit." << endl;
        cout << "f. If the number is a three-digit number and the last" << endl;
        cout << "   digit is less than or equal to 4, then raise the first" << endl;
        cout << "   two digits to the power of the last digit" << endl;
        cout << endl;
        //ask user to choose one of the operation.
        cout << "Your choice is ( a, b, c, d, e or f): " ;
        cin >> choice;
        enum ifValid {
            valid, invalid}; //to determine if a operation is valid, if not, no need to determine prime number after that operation.
        //process the loop to continue the program until the user want to stop
        do
        {
            ifValid test = valid;
            //perform the operation as user's choice.
            switch (choice)
            {
            case 'a':
                randNum = doubleTheNumber(randNum);
                cout << randNum << endl;
                break;
            case 'b':
                randNum = reverseTheDigits(randNum);
                cout << randNum << endl;
                break;
            case 'c': randNum = powerTheNumber(randNum);
                cout << randNum << endl;
                break;
            case 'd': randNum = sumTheDigits(randNum);
                cout << randNum << endl;
                break;
            case 'e':
                if (randNum >= 10 && randNum <= 99)
                {
                    randNum = powerDigit(randNum);
                    cout << randNum << endl;
                }
                else
                {
                    test = invalid;
                    cout << "Invalid operation because " << randNum << " is not a two-digit number " << endl;
                }
                break;
            case 'f':
                if (randNum >= 100 && randNum <= 999)
                {
                    randNum = powThreeDigit(randNum);
                    cout << randNum << endl;
                }
                else
                {
                    test = invalid;
                    cout << "Invalid operation because " << randNum << " is not a three-digit number "<< endl;
                }
                break;
            default:
                cout << "Invalid input, you should enter only a, b, c, d, e or f." << endl;
                test = invalid;
                break;
            }
            //determine if the number is prime, only after performing a valid operation
            if (test == valid)
                isPrime (randNum);
            //n if the number is less than 10, add 10 to the number
            if (randNum < 10 && randNum >= 0)
            {
                cout << "Because the number now less than 10 after the lass operation, add 10 to the number" << endl;
                randNum = randNum + 10;
                cout <<"The number now is " << randNum << endl;
            }
        cout << endl;
        cout << "Enter the next operation (a,b,c,d,e,f) or a different random key to stop the program " << endl;
        cin >> choice;
        } while (choice == 'a' || choice == 'b' || choice == 'c' || choice == 'd' || choice == 'e' || choice == 'f');
            return 0;
}
// Function definition: double the number
int doubleTheNumber(int randNum)
{
    int doubledNum = randNum * 2;
    cout << "Double of "<< randNum << " is: ";
    return doubledNum;
}
// Function definition: reverse the digits of the number
int reverseTheDigits(int randNum)
{
    int reversedNum = 0;
    int n = randNum;
    while (n > 0)
    {
        reversedNum = reversedNum*10 + n%10;
        n = n/10;
    }
    cout << "Reverse the of the number " << randNum << " is: ";
    return reversedNum;
}
// Function definition: raise the number to the power of 2, 3 or 4.
int powerTheNumber(int randNum)
{
    int p;
    cout << "Enter the power, pick one of the numbers 2, 3 or 4: ";
    cin >> p;
    double powerNum = pow(randNum, p);
    cout << randNum << " raised by the power of " << p << " is: ";
    return powerNum;
}
// Function definition: sum the digits of the number
int sumTheDigits(int randNum)
{
    int sum = 0;
    int n = randNum;
    while ( n > 0)
    {
        sum = sum + n % 10;
        n = n/10;
    }
    cout << "Sum of the digits of the number " << randNum << " is: ";
    return sum;
}
// Function definition: raise the first digit to the power of the second digit
int powerDigit(int randNum)
{
    cout <<"Raise " << randNum / 10 << " to the power of " << randNum % 10 << ": ";
    int powerDigit = pow(randNum / 10, randNum % 10);
    return powerDigit;
}
// Function definition: raise the first two digit to the power of the third digit
int powThreeDigit(int randNum)
{
    cout <<"Raise " << randNum / 10 << " to the power of " << randNum % 10 << ": ";
    int powerThreeDigit = pow(randNum / 10, randNum % 10);
    return powerThreeDigit;
}
// Function definition: determine if the number is prime.
void isPrime (int randNum)
{
    bool primeNum = true;
    // if the value of number is 1 or 2
    if (randNum == 1 || randNum ==2)
    {
        primeNum = false;
    }
    else
    {
        int i;
        for ( i=2 ; i<=randNum/2;++i)
        {
            if (randNum%i ==0)
            {
                primeNum = false;
                break;
            }
        }
    }
    if (primeNum)
        cout << randNum << " is a prime number. " << endl;
    else
        cout << randNum << " is not a prime number." << endl;
}




