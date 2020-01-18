// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 5 - Problem # 3

# include <iostream>
# include <string>
using namespace std;


/**
* Algorithm: Split a string into smaller substrings, separated by a given delimeter. Print the substrings on separate lines, and return the number of words.
* 1. Declare a new variable for the split string and set it equal to an empty string.
* 2. Declare a new variable as the split count and set it equal to zero.
* 3. Take the two parameters passed into the function - the string and the delimeter.
* 4. Check if the string is empty.
*       If yes, return 0.
* 5. For the each character in the string (i=0 to the length of the string)...
*       Check if the character is equal to the the delimeter, and that i does not equal 0, and that i does not equal the length of the string - 1, and that the previous character is not equal to the delimeter.
*           If yes, add a new line ("\n") to the current split string, and add one to the split count.
*       Check if the current character is not equal to the delimeter.
*           If yes, add the character to the current split string.
* 6. Print out the final split string.
* 7. Return the split count, aka the number of words.
* Input parameters: a string to split (string), and a delimeter to split the string on (char)
* Output (prints to screen): Each substring that the delimeter splits the string into, each on its own line
* Returns: The number of sub strings that the string was split into (# of words)
*/
int split(string strToSplit, char delimeter){
    string splitString = ""; // declares new variable splitString as an empty string
    int splitCount = 1; // declares new variable split count and sets it equal to 1
    if (strToSplit == ""){ // checks if the inputted string is empty
        return 0; // returns 0
    }
    for (int i = 0; i < strToSplit.length(); i++){ // loops through the string, starting with the first character and ending with the last
        if (strToSplit[i] == delimeter && i != 0 && i != (strToSplit.length() - 1) && strToSplit[i-1]!= delimeter){ // checks if the character is equal to the delimeter, and i does not equal 1, and i does not equal the length of the string - 1, and the previous character does not equal the delimeter
            splitString = splitString + "\n"; // adds a new line the splitString
            splitCount++; // adds one to the split count
        }
        if (strToSplit[i] != delimeter){ // checks if the character is not equal to the delimeter
            splitString += strToSplit[i]; // adds the character to the split string
        }
    }
    cout << splitString << endl; // prints out the split string
    return splitCount; // returns the split count
}


int main(){
     // Test 1
    // expected output
    // ABCD
    // EFG
    // (return 2)
    split("ABCD EFG",' '); // first function call to split
    
    // Test 2
    // expected output
    // RST
    // UVW
    // XYZ
    // (return 3)
    split("RST,UVW,XYZ",','); // second function call to split
    
    // Test 3
    // expected output
    // ABCDEFG
    // (return 1)
    split("ABCDEFG",' '); // third function call to split
}