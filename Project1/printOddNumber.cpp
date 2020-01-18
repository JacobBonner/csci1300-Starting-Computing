// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Project 1 - Problem # 1

# include <iostream>
using namespace std;

/**
* Algorithm: Prints all positive odd integers less than or equal to a given maximum value
* 1. Define a counter variable and set it equal to zero.
* 2. Take the integer (maximum value) passed into the function.
* 3. Check if the counter variable is less than or equal to the given maximum value.
*       If yes, while the previous condition is true..
*           Check if the counter is odd.
*               If yes, print the value of the counter.
*           Add 1 to the counter.
*           Go back to step 3.
* 4. If the counter variable is greater than the maximum value after an iteration, the loop will not run, and the program will be over.
* Input parameters: a maximum value (int type)
* Output (prints to screen): Every positive odd integer that is less than or equal to the maximum value
* Returns: nothing
*/


void printOddNums(int maxValue) {
    int i = 0; // sets a counter variable equal to zero
    while (i <= maxValue) // checks if the counter variable is less than or equal to the given maximum value
    {
        if (i % 2 == 1) // checks if the counter value is an odd integer
        {
            cout << i << endl; // outputs the value of the counter
        }
        i += 1; // adds 1 to the counter
    }
}


int main() {
    // Test Case 1
    // expected output
    /*  1
        3
        5
        7
        9
        11
    */
    printOddNums(11); // first function call to printOddNums
    
    // Test Case 2
    // expected output
    /*  1
        3
        5
    */
    printOddNums(5); // second function call to printOddNums
}