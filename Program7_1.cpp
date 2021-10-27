/*
 * Program Name: Triangle Type - Exercise 1
 * Programmer: Reasoner, Kim
 * Course: CSC160-141 Computer Science I C++ Fall 2021
 * Submission Date: 10/27/2021
 * Description: This program will prompt the user to input the length of the sides of a triangle
 * and output the shape of the triangle, using defined data type and function.
 */

// import library
#include <iostream>
// use standard names pace
using namespace std;
// Define an enumeration type triangleType that has the values scalene, isosceles, equilateral, and noTriangle.
enum triangleType {scalene , isosceles , equilateral , noTriangle};
//declare the variable shape
triangleType shape;
// declare the function
triangleType triangleShape (float side1, float side2, float side3);
// main function - entry point
int main()
{
    //declare variables to store length of sides
    float side1, side2, side3;
    //ask user to input the lengths of 3 sides
    cout << "Please enter 3 numbers as 3 lengths of triangle side (separated by spaces): " << endl;
    cin >> side1 >> side2 >> side3 ;
    //call the function triangleShape
    shape = triangleShape (side1, side2, side3);
    switch (shape)
    {
        case 0: cout << "The shape of the triangle is: scalene" << endl;
            break;
        case 1: cout << "The shape of the triangle is: isosceles" << endl;
            break;
        case 2: cout << "The shape of the triangle is: equilateral" << endl;
            break;
        case 3: cout << "The shape of the triangle is: noTriangle" << endl;
            break;
    }
    return 0;
}
/* Function definition: function triangleShape that takes as parameters three numbers, each of which represents the length
of a side of the triangle. The function return the shape of the triangle. */
triangleType triangleShape (float side1, float side2, float side3)
{
    if ((side1+side2) <= side3 || (side1+side3) <= side2 || (side3+side2) <= side1 )
        shape = noTriangle;
    else if ((side1 == side2) && (side2 == side3))
            shape = equilateral;
    else if (side1 != side2 && side2 != side3 && side1 != side3)
            shape = scalene;
    else
            shape = isosceles;
    return shape;
}
