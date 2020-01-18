// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 3 - Problem 10

# include <iostream>
# include <cmath>
using namespace std;

/**
* Algorithm: Takes the initial speed of a driver (Baby Mario) and the distance to where he needs to stop, and calculates the deceleration required
* 1. Calculates the deceleration by taking the initial speed (passed as an argument) and squares it, 
*    and divides by the distance (also an argument) doubled.
* 2. Returns the decelerations needed to stop
* Input parameters: intial speed (double) and distance (double)
* Output (prints to screen): nothing
* Returns: deceleration (double)
*/

double marioKart(double initialSpeed, double distance) {
    double deceleration = pow(initialSpeed,2) / (2 * distance); // Calculating the deceleration by squaring the initial speed and dividing by the distance doubled
    return deceleration; // returning the deceleration
}

int main() {
    // Test 1
    // expected output
    // 1
    double deceleration_1 = marioKart(4,8); // first function call to marioKart
    cout << deceleration_1 << endl; // output the return value: deceleration
    
    // Test 2
    // expected output
    // 0.5
    double deceleration_2 = marioKart(3,9); // first function call to marioKart
    cout << deceleration_2 << endl; // output the return value: deceleration
    
    return 0;
}