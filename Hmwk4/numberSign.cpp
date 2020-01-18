// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 4 - Problem # 1

# include <iostream>
using namespace std;

/**
* Algorithm: Checks if an integer passed as the argument is zero, negative, or positive.
* 1. Take the number passed into the function (integer).
* 2. Check if it is less than 0.
*       If yes, then print "negative"
* 3. If not, check if it is greater than 0.
*       If yes,  then print "positive"
* 4. If not (greater than zero or less than zero), then print "zero".
* Input parameters: a number (int type)
* Output (prints to screen): different string based on three categories - number > 0 ("positive"), number < 0 ("negative"), 
* or number == 0 ("zero").
* Returns: nothing
*/


void numberSign(int number) {
    if (number < 0) // checks if number is less than zero
    {
        cout << "negative" << endl; // prints "negative"
    }
    
    else if (number > 0) // checks if number is greataer than 0
    {
        cout << "positive" << endl; // prints "positive"
    }
    
    else // if number is not greater than 0 or less than 0
    {
        cout << "zero" << endl; // prints "zero"
    }
}


int main() {
    
    // Test 1
    // expected output
    // zero
    numberSign(0); // first function call to numberSign
    
    // Test 2
    // expected output
    // negative
    numberSign(-5); // second function call to numberSign
    
    // Test 3
    // expected output
    // positive
    numberSign(3); // third function call to numberSign
    
    return 0;
}