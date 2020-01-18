// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 4 - Problem # 5

# include <iostream>
using namespace std;

/**
* Algorithm: Counts how many digits a given number has and returns the value.
* 1. Take the integer passed into the function.
* 2. Check if the number is less than 0 (checking for negative number).
*       If yes, then set the number equal to itself multiplied by -1 (making the number positive).
* 3. Check if the number is greater than or equal to zero AND less than 10 (checking for one digit number).
*       If yes, then return 1
* 4. If not, check if the number is greater than or equal to 10 AND less than 100 (checking for two digit number).
*       If yes, then return 2
* 5. If not (less than one hundred), return 3 (three digit number).
* Input parameters: some number (int type)
* Output (prints to screen): nothing
* Returns: the number of digits in the value passed as the argument (int type)
*/


int countDigits(int number) {
    if (number < 0) // chekcs if number is less than zero
    {
        number = number * -1; // sets number equal to number times -1 (to make number positive)
    }
    
    if (number >= 0 && number < 10) // checks if number is greater than or equal to zero, and less than 10
    {
        return 1; // returns 1
    }
    
    else if (number >= 10 && number < 100) // checks if number is greater than or equal to 10, and less than 100
    {
        return 2; // returns 2
    }
    
    else // if number is greater than 100
    {
        return 3; // returns 3
    }
}


int main() {
    // Test 1
    // expected output
    // 2
    cout << countDigits(-46) << endl; // first function call to countDigits
    
    // Test 2
    // expected output
    // 1
    cout << countDigits(9) << endl; // second function call to countDigits
    
    // Test 3
    // expected output
    // 3
    cout << countDigits(120) << endl; // third function call to countDigits
    
    return 0;
}