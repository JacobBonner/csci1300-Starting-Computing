// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 3 - Problem 2

# include <iostream>
using namespace std;

/**
* Algorithm: take a course number and insert it into the saying "Hello, CS ____ World!"
* 1. Ask the user to enter a course number 
* 2. Store that course number in a variable (course_number)
* 3. Print "Hello, CS **** (course_number) World!"
* Input parameters: none
* Output (prints to screen): Hello, CS **** (course number) World!
* Returns: nothing
*/

int main() {
    int course_number; // definition of course_number as an integer
    cout << "Enter a CS course number: " << endl; // asking the user for input (course number)
    cin >> course_number; // storing the user's input in the variable course_number
    cout << "Hello, CS " << course_number << " World!" << endl; // output message with course_number inserted
    return 0;
}