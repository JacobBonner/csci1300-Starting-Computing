// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 5 - Problem # 4

# include <iostream>
# include <string>
using namespace std;


/**
* Algorithm: Encrypt or decrypt a message using a Ceasar Cipher, by substituting each letter with a new letter a given fixed distance (key) away in the alphabet, or doing the reverse.
* 1. Take the parameters passed in to the function: a message to encrypt or decrypt (string), a key to shift the alphabet by (int), and a flag (bool).
* 2. Check if the key (the shift number) is gretaer than 25 or less than 0.
*       If yes, return ERROR.
* 3. Declare a new variable for the new message, and set it equal to an empty string.
* 4. Check if flag (if true)
*       If yes, loop through the message starting from index 0 to the length of the string.
*           Check if the character does not equal a space (' ')
*               If yes, set the character equal to the new letter shifted over by a value of the key.
*           Add the charecter to the new message.
* 5. If no, loop through the length of the message from index 0 through the last character.
*       Check if the character is not equal to a space (' ')
*           If yes, set the character equal to the decrypted letter, by shifting the alphabet the other direction a fixed distance of key.
*       Add the character to the new message.    
* 6. Return the new message.
* Input parameters: a message (string), a key (int), and a flag (bool)
* Output (prints to screen): nothing
* Returns: the encrypted or decrypted message (string)
*/
string caesarCipher(string message, int key, bool flag){
    if (key > 25 || key < 0){ // checks if key is greater than 25 or less than 0
        return "ERROR"; // returns ERROR if key value is not within the required range
    }
    string newMessage = ""; // declares a new variable called newMessage and sets it equal to an empty string
    if (flag){ // checks if flag (true)
        for (int i = 0; i < message.length(); i++){ // loops through each index of the messaage from 0 to the length of the string - 1
            if (message[i] != ' '){ // chekcs if the character is not equal to a space (' ')
                message[i] = char((int)(message[i]+key-65) % 26 + 65); // sets the character equal to the new letter after shifting with key
            }
            newMessage += message[i]; // adds the character to the new message
        }
    }
    
    else { // if False
        for (int i = 0; i < message.length(); i++){ // loops through each index f the message from 0 to the length of the string - 1
            if (message[i] != ' '){ // checks if the character is not equal to a space (' ')
                message[i] = char((int)(message[i]-key-90) % 26 + 90); // sets the character equal to a new letter after shifting the alphabet by the fixed value key
            }
            newMessage += message[i]; // adds the current character to the new message
        }
    }
    
    return newMessage; // returns the new message
}


int main(){
    // Test Case 1
    // expected output
    // CDEF
    cout << caesarCipher("ABCD",2,true) << endl; // first function call to caesarCipher
    
    // Test Case 2
    // expected output
    // YZAB
    cout << caesarCipher("ABCD",2,false) << endl; // second function call to caesarCipher
    
    // Test Case 3
    // expected output
    // KHOOR ZRUOG
    cout << caesarCipher("HELLO WORLD",3,true) << endl; // third function call to caesarCipher
}