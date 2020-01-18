// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 7 - Problem # 1 

#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include "Planet.h"
using namespace std;

// Testing implementation of Planet class

int main(){
   
    // Test Case 1
    // expected output
    // Pluto?
    // 2
    // 33.5103
    Planet planet1;
    planet1.setName("Pluto?");
    planet1.setRadius(2);
    cout << planet1.getName() << endl;
    cout << planet1.getRadius() << endl;
    cout << planet1.getVolume() << endl;
    
    // Test Case 2
    // expected output
    // Earth
    // 5
    // 523.599
    Planet planet2;
    planet2.setName("Earth");
    planet2.setRadius(5);
    cout << planet2.getName() << endl;
    cout << planet2.getRadius() << endl;
    cout << planet2.getVolume() << endl;
}