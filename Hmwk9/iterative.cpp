// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 9 - Problem # 1


#include <iostream>
#include <string>
#include <cmath>
using namespace std;


/** Algorithm: Convert a given integer to binary
 * 1. Take the input integer.
 * 2. Define binary string.
 * 3. While the number divided by two does not equal 0.
 *      Divide the number by two and add the remainder as a string to the binary string.
 *      Divide the number by 2 and save that value.
 *      Set the new number equal to the old number divided by 2.
 * 4. Reverse the order of the string by creating a new string and adding the elements of the original string in reverse.
 * 5. Return the binary string.
 * Input Parameters: a number (int)
 * Output: nothing
 * Returns: the binary number for the given integer (string)
*/
string decimalToBinaryIterative(int number){
    string binaryStr = "";
    int newNum = number;
    int n = 1;
    while(n != 0){
        binaryStr += to_string(newNum % 2);
        n = newNum / 2;
        newNum = n;
    }
    string binaryStr2 = "";
    for(int i=0; i<binaryStr.length()+1; i++){
        binaryStr2 += binaryStr[binaryStr.length()-i];
    }
    return binaryStr2;
}


int main(){
    
    // Test Case 1
    // expected output
    // 101
    cout << decimalToBinaryIterative(5) << endl;
    
    
    // Test Case 2
    // expected output
    // 0
    cout << decimalToBinaryIterative(0) << endl;
    
    
    // Test Case 3
    // expected output
    // 10010
    cout << decimalToBinaryIterative(18) << endl;
    
    return 0;
}