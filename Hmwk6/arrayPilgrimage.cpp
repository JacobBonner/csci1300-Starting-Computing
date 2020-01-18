// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 6 - Problem # 1

#include <iostream>
using namespace std;

/**
* Algorithm: Defines arrays, fills them, and prints out each element
* 1. Define and fill temps array by setting each value equal to -459.67
* 2. Print out each element in the temps array
* 
* 3. Define and fill colors array by setting each value equal to a different color name
* 4. Print out each element in the colors array
* 
* 5. Define and fill sequence array by setting each value equal to the iteration value from 1-100
* 6. Print out each element in the sequence array
* 
* 7. Define and fill letters array by setting each value equal to the upper and lower case of a letter
* 8. Print out each element in the letters array
* Input parameters: None
* Output (prints to screen): Every value in each of the defined arrays
* Returns: nothing
*/

int main(){
    
    double temps[10]; // declares array temps with 10 columns
    for (int i=0; i<10;i++){ // loops through the length of remps
        temps[i] = -459.67; // sets the current index of temps equal to -459.67
    }
    for (int i=0;i<10;i++){ // loops through the length of temps
        cout << temps[i] << endl; // prints out the current element of temps
    }
    
    cout << "\n"; // prints out a new line
    
    string colors[5] = {"Red","Blue","Green","Cyan","Magenta"}; // declares and creates array called colors and fills it with the values
    for (int i=0;i<5;i++){ // loops through the length of colors
        cout << colors[i] << endl; // prints out the current element of colors
    }
    
    cout << "\n"; // prints out a new line
    
    int sequence[100]; // declares array sequence and sets it size as 100
    int j = 1; // declares new variable j and sets it equal to 1
    while (j<=100){ // loops through 1 to 100
        sequence[j] = j; // sets the current element of sequence equal to the value of j
        j++; //adds one to j
    }
    
    for (int i=1;i<=100;i++){ // loops through the length of sequence
        cout << sequence[i] << endl; // prints out the current element of sequence
    }
    
    cout << "\n"; // prints out a new line
    
    char letters[52]; // declares array called letters of size 52
    for (int i=0,j=0; i<52; i++){ // loops through the length of letters
        if (i%2==0){ // checks if i is even
            letters[i] = char((j)%26 + 65); // sets the current element of letters equal to corect upper case letter
            j++; // adds one to j
        }
        else{
            letters[i] = char((i-j)%26 + 97); // sets the curent elemenbt of letters eqyal to the correct lower case letter
        }
    }
    for (int i=0,j=1; i<52; i++){ // loops through the length of letters
        cout << letters[i] << ' ' << letters[i+1] << endl; // prints out the ith element of letters, as well as the i+1 element
        i++; // adds one to i
    }
}