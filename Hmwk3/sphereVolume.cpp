// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 3 - Problem 5

# include <iostream>
# include <math.h>
using namespace std;

/**
* Algorithm: Takes a radius and calulates the volume of a sphere with the given radius
* 1. Takes radius as parameter
* 2. Caluclates the volume of a sphere with given radius
* 3. Prints out "volume: " and whatever the calculated volume is
* Input parameters: radius (double)
* Output (prints to screen): "volume: ****"
* Returns: none
*/

void sphereVolume(double radius) { // defining return type (void), function name, and the one argument (double)
    double volume; // define volume as a double
    volume = (4.0/3.0) * M_PI * pow(radius, 3); // calculate the volume of sphere with given radius
    cout << "volume: " << volume << endl; // output the volume
}

int main() {
    // Test 1
    // expected output
    // volume: 137.258
    sphereVolume(3.2); // first function call to sphereVolume
    
    // Test 2
    // expected output
    // volume: 4188.79
    sphereVolume(10); // second function call to sphereVolume
    
    return 0;
}