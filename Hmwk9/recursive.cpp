// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 9 - Problem # 2


#include <iostream>
#include <string>
using namespace std;


/** Algorithm: Convert a given integer to binary
 * 1. Check if the number is equal to 0.
 *      If yes, return "0".
 * 2. Check if the number is equal to 1.
 *      If yes, return "1".
 * 3. Otherwise...
 *      Call the function with input number/2, and save the return value.
 *      Calculate number % 2 and save the value converted to a string.
 *      Return (value from function call with number/2 + string(number % 2))
 * Input Parameters: a number (int)
 * Output: nothing
 * Returns: the binary number for the given integer (string)
*/
string decimalToBinaryRecursive(int number){
    if(number == 0){
        return "0";
    }
    else if(number == 1){
        return "1";
    }
    else{
        string binarySubStr = decimalToBinaryRecursive(number/2); // call function with number/2
        string binNum = to_string(number%2); // either "0" or "1"
        return (binarySubStr + binNum); // returns new string at the end of each function call
    }
}


int main(){
    
    // Test Case 1
    // expected output
    // 101
    cout << decimalToBinaryRecursive(5) << endl;
    
    
    // Test Case 2
    // expected output
    // 0
    cout << decimalToBinaryRecursive(0) << endl;
    
    
    // Test Case 3
    // expected output
    // 10010
    cout << decimalToBinaryRecursive(18) << endl;
    
    
    return 0;
}