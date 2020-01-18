// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 4 - Problem # 2

# include <iostream>
using namespace std;

/**
* Algorithm: Takes a single integer argument, performs calculations depending on if it is odd or even, and returns a new integer n 
*            that is the next in the Collatz sequence.
* 1. Take the integer n that is passed into the function.
* 2. Check if n is less than 0.
*       If yes, then return 0
* 3. If not, check if n is even.
*       If yes, return (n/2)
* 4. If not (negative or even), return (3*n + 1)
* Input parameters: some number n (int type)
* Output (prints to screen): nothing
* Returns: Either 0 or an integer calculated in the function, depending on the value of n passed as a parameter. (int type)
*/


int collatzStep(int n){
    if (n < 0) // checks if n is less than 0
    {
        return 0; // returns 0
    }
    else if (n % 2 == 0) // checks if n is an even number
    {
        return (n/2); // returns n divided by 2
    }
    
    else // if n is neither less than 0 or even
    {
        return (3*n + 1); // returns 3 times n, plus 1
    }
}


int main() {
    
    // Test 1
    // expected output
    // 3
    cout << collatzStep(6) << endl; // first function call to collatzStep
    
    // Test 2
    // expected output
    // 100
    cout << collatzStep(33) << endl; // second function call to collatzStep
    
    // Test 3
    // expected output
    // 0
    cout << collatzStep(-12) << endl; // third function call to collatzStep
    
    return 0;
}