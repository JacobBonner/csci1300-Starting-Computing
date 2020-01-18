// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 4 - Problem # 3

# include <iostream>
using namespace std;

/**
* Algorithm: Checks if three numbers are all the same, all different, or neither.
* 1. Take the three integers passed into the function.
* 2. Check if the three numbers are all the same (num1==num2 && num2==num3 && num1==num3).
*       If yes, then print "All same"
* 3. If not, check if the three numbers are all different (num1!=num2 && num2!=num3 && num1!=num3).
*       If yes, then print "All different"
* 4. If not (all the same or all different), then print "Neither".
* Input parameters: 3 numbers (all int type)
* Output (prints to screen): different string based on three categories - if the numbers are all the same ("All same"),
* if they're all different ("All different"), or if neither of the previous two are true ("Neither").
* Returns: nothing
*/


void checkEqual(int num1,int num2,int num3){
    if (num1 == num2 && num2 == num3 && num1 == num3) // checks if num1, num2, and num3 are all the same
    {
        cout << "All same" << endl; // prints "All same"
    }
    
    else if (num1 != num2 && num2 != num3 && num1 != num3) // checks if num1, num2, and num3 are all different
    {
        cout << "All different" << endl; // prints "All different"
    }
    
    else // if num1, num2, and num3 are neither all the same or all different
    {
        cout << "Neither" << endl; // prints "Neither"
    }
}


int main() {
    
    // Test 1
    // expected output
    // All different
    checkEqual(1,2,3); // first function call to checkEqual
    
    // Test 2
    // expected output
    // All same
    checkEqual(2,2,2); // second function call to checkEqual
    
    // Test 3
    // expected output
    // Neither
    checkEqual(1,2,2); // third function call to checkEqual
    
    return 0;
}