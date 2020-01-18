// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 5 - Problem # 1

# include <iostream>
# include <string>
using namespace std;


/**
* Algorithm: Counts the number of digits in a string.
* 1. Take the string passed into the function.
* 2. Use the built in function string.length() to calculate the length of the string.
* 3. Declare a variable as a counter for the number of digits and set it equal to zero.
* 4. For each character in the string..
*       Check if the value of the character is greater than or equal to 48, and less than or equal to 57.
*           If yes, add one to the digit counter.
*       If no, go to the start of the loop.
* 5. Return the digit counter (number if digits in the string)
* Input parameters: A random string
* Output (prints to screen): nothing
* Returns: the number of digits in the string (int)
*/
int getDigitCount(string randomString){
    int digitCount = 0; // declares the digit counter and set it equal to zero
    for (int i = 0; i < randomString.length();i++){ // loops through the given string (i=0 to string.length())
        if ((int)(randomString[i]) >= 48 && (int)(randomString[i]) <= 57){ // checks if the ascii value of the character is between 48 and 57
            digitCount++; // adds one to the digit count
        }
    }
    return digitCount; // returns the digit count
}


int main(){
    // Test 1
    // expected output
    // 5
    cout << getDigitCount("12345") << endl; // first function call to getDigitCount
    
    // Test 2
    // expected output
    // 1
    cout << getDigitCount("I have 1 brother") << endl; // second function call to getDigitCount
    
    // Test 3
    // expected output
    // 4
    cout << getDigitCount("CSCI1300") << endl; // third function call to getDigitCount
    
    return 0;
}