// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 3 - Problem 4

#include <iostream>
#include <math.h>
using namespace std;

/**
* Algorithm: Calculate and print both the volume and surface area of a sphere with given radius
* 1. Ask the user to input the radius of a sphere
* 2. Store their input in the variable radius (double)
* 3. Calculate the volume with the radius and print it out
* 4. Calculate the surface area with the given radius and print it out
* Input parameters: none
* Output (prints to screen): "volume: **** \n surface area: *****"
* Returns: nothing (except the main function returns an integer)
*/

int main(){
    cout << "Enter a radius: " << endl; // asking the user to input a radius
    double radius; // defining radius as a double
    cin >> radius; // storing the inout as the variable radius
    double volume; // defining volume as a double
    volume = (4.0/3.0) * M_PI * pow(radius, 3); // calculating the volume of the sphere
    cout << "volume: " << volume << endl; // ouput the volume
    
    // my new code for surface area
    double surface_area; // defining surface_area as type double
    surface_area = 4 * M_PI * pow(radius, 2); // calculating the surface area of the sphere
    cout << "surface area: " << surface_area << endl; // output the surface area
    
    return 0;
}