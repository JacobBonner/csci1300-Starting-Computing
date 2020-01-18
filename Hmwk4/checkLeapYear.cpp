// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 4 - Problem # 7

# include <iostream>
using namespace std;

/**
* Algorithm: Checks if a given year is a Leap Year. Returns true if it is, and false if it is not.
* 1. Take the year passed into the function
* 2. Check if the year is divisible by 4 AND before 1582, or, check if the year is divisible by 4 AND not divisible by 100 
*    OR it is divisible by 400.
*       If yes, then return true
* 3. Return false if the year does not apply to the given conditions (if it is not a leap year).
* Input parameters: a year (int type)
* Output (prints to screen): nothing
* Returns: true if the year given is a Leap Year, or false if the year is not a Leap Year (bool type)
*/


bool checkLeapYear(int year) {
    if ((year % 4 == 0 && year < 1582) || (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) // checks if year is a Leap Year
    {
        return true; // returns true
    }
    return false; // returns false otherwise
}


int main() {
    // Test 1
    // expected output
    // false : 0
    cout << checkLeapYear(1900) << endl; // first funtion call to checkLeapYear
    
    // Test 2
    // expected output
    // true : 1
    cout << checkLeapYear(2000) << endl; // second function call to checkLeapYear
    
    // Test 3
    // expected output
    // true : 1
    cout << checkLeapYear(1500) << endl; // third function call to checkLeapYear
    
    return 0;
}