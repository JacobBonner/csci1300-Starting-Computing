// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 3 - Problem 7

# include <iostream>
using namespace std;

/**
* Algorithm: Convert a given number of seconds into hours, minutes, and seconds
* 1. Take the number of seconds given in the input variable and calculate the amount of whole hours 
* 2. Calculate the number of whole minutes from the remaining seconds
* 3. Subtract the number of seconds from hours and minutes and that remainder is the left over seconds in the total amount
* 4. Print out the number of hours, minutes, and seconds
* Input parameters: seconds (int)
* Output (prints to screen): *** hour(s)  *** minute(s)  *** second(s)
* Returns: nothing
*/

void convertSeconds(int seconds) {
    int h, m, s; // defines h, m, and s as ints
    h = seconds / 3600; // calculating the number of whole hours from the given amount of seconds
    m = (seconds % 3600) / 60; // calculating the number of whole minutes from the remaining seconds
    s = (seconds % 3600) % 60; // calculating the number of remaining seconds after accounting for hours and minutes
    cout << h << " hour(s) " << m << " minute(s) " << s << " second(s) " << endl; // outputs the message of hours, minutes, and seconds
}

int main() {
    // Test 1
    // expected output
    // 18 hour(s) 12 minute(s) 16 second(s)
    convertSeconds(65536); // first function call to convertSeconds
    
    // Test 2
    // expected output
    // 1 hour(s) 0 minute(s) 0 second(s)
    convertSeconds(3600); // second function call to convertSeconds
    
    return 0;
}