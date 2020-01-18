// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 7 - Problem # 2

# include <iostream>
# include "Planet.h"
using namespace std;

/** Algorithm: Finds and returns the index of the planet in the array with the largest radius.
 * 1. Sets the maximum index and maximum radius to that of the very first planet in the planets array.
 * 2. Checks if the size of the array is equal to zero (empty).
 *      If yes, return -1.
 * 3. If no, loop through the size of the planets array and compare the radius of each planet to the maximum radius.
 * 4. If the current planet's radius is larger than the maximum, set that planets radius as the new maximum, and set its index as the max radius index.
 * 5. After looping through all of the planets array, return the index of the planet with maximum radius.
 * Input Parameters: planets array (of class Planet), the array size (int)
 * Outputs (prints to screen): nothing
 * Returns: index of the planet with the maximum radius (int)
 */
 int maxRadius(Planet planets[],int arrSize){
    int maxIdx = 0;
    int maxRad = planets[0].getRadius(); // sets the maximum radius equal to the radius of the first planet in the array
    if(arrSize == 0){
        return -1;
    }
    else{
        for (int i=1;i<arrSize;i++){ // starts from index 1 because 0th index was used above
            int rad = planets[i].getRadius();
            if(rad>maxRad){
                maxRad = rad;
                maxIdx = i;
            }
        }
        return maxIdx;
    }
 }
 
 
 int main(){
     
    // Test Case 1
    // expected output
    // Bird World
    // 4321
    // 3.37941e+11
    Planet planets[5];
    planets[0] = Planet("On A Cob Planet",1234);
    planets[1] = Planet("Bird World",4321);
    int idx = maxRadius(planets, 2); // first function call to maxRadius
    cout << planets[idx].getName() << endl;
    cout << planets[idx].getRadius() << endl;
    cout << planets[idx].getVolume() << endl;
    
    // Test Case 2
    // expected output
    // Nebraska
    // 13.3
    // 9854.7
    Planet planets1[3];
    planets1[0] = Planet("Nebraska",13.3);
    planets1[1] = Planet("Flarbellon-7",8.6);
    planets1[2] = Planet("Parblesnops",6.8);
    int idx1 = maxRadius(planets1, 3); // second function call to maxRadius
    cout << planets1[idx1].getName() << endl;
    cout << planets1[idx1].getRadius() << endl;
    cout << planets1[idx1].getVolume() << endl;

}