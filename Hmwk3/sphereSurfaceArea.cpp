// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 3 - Problem 6

# include <iostream>
# include <math.h>
using namespace std;

/**
* Algorithm: Takes a radius and calulates the surface area of a sphere with the given radius
* 1. Takes radius as parameter
* 2. Caluclates the surface area of a sphere with given radius
* 3. Prints out "surface area: " and whatever the calculated surface area is
* Input parameters: radius (double)
* Output (prints to screen): "surface area: ****"
* Returns: none
*/

void sphereSurfaceArea(double radius) { // defining return type (void), function name, and the one argument (double)
    double surface_area; // defining surface area as a double
    surface_area = 4 * M_PI * pow(radius, 2); // calculating the surface area with given radius
    cout << "surface area: " << surface_area << endl; // output the surface area
}

int main() {
    // Test 1
    // expected output
    // surface area: 669.662
    sphereSurfaceArea(7.3); // first function call to sphereSurfaceArea
    
    // Test 2
    // expected output
    // surface area: 5076.94
    sphereSurfaceArea(20.1); // second function call to sphereSurfaceArea

    return 0;
}