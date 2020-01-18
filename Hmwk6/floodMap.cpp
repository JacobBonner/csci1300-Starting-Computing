// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 6 - Problem # 2

#include <iostream>
using namespace std;

/**
* Algorithm: Prints out a "map" of which points in an array are below the given water level.
* 1. Take the three arguments passed in to the function: heights(array), rows(int), and water level (double)
* 2. Use a for loop, starting at i=0, to iterate through each row of the heights array. a
*       Use a for loop, starting at j=0, to iterate through each column in the current row of the array.
*           Check if the element at position (i,j) is less than or equal to the water level.
*               If yes, print out "*".
*           Check if the element at position (i,j) is greater than the water level.
*               If yes, print out "_".
*       End the current line and go back to the start of the first for loop (i++).
* Input parameters: The heights (array), the number of rows (int), and the water level (double)
* Output (prints to screen): A combination of "*" and "_", depending on the value at each position in the array
* Returns: nothing
*/
void floodMap(double heights[][4],int rows,double waterLevel){
    for (int i=0; i<rows;i++){ // loops through each row of the array
        
        for (int j=0;j<4;j++){ // loops through each column in the current row
            if (heights[i][j] <= waterLevel){ // checks if the current position value is less than or equal to the water level
                cout << "*"; // prints out *
            }
            else if (heights[i][j]>waterLevel){ // checks if the current position value is greater than the water level
                cout << "_"; // prints out _
            }
        }
        cout << endl; // ends the line
    }
}


int main(){
    // Test 1
    // expected output
    // *_*_
    double map1[1][4] = {5.0, 7.6, 3.1, 292};
    floodMap(map1,1,6.0); // first function call to floodMap
    
    cout << "\n";
    
    // Test 2
    // expected output
    // ____
    // ____
    double map2[2][4] = {{0.2, 0.8, 0.8, 0.2},{0.2, 0.2, 0.8, 0.5}};
    floodMap(map2,2,0.0); // second function call to floodMap
    
    cout << "\n";
    
    // Test 3
    // expected output
    // *_**
    // *__*
    // _*__
    // ****
    double map3[4][4] = {{1.0, 5.0, 1.0, 1.0},{1.0, 5.0, 5.0, 1.0},{5.0, 1.0, 5.0, 5.0},{1.0, 1.0, 1.0, 1.0}};
    floodMap(map3,4,3.14); // third function call to floodMap
    
    return 0;
}