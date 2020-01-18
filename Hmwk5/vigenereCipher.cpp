// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 5 - Problem # 5

# include <iostream>
# include <string>
using namespace std;


/**
* Algorithm: Takes a message and a key, and encrypts or decrypts the message according to the corresponding letters in the key
* 1. Takes the three inputs: the message (string), the key (string), and the flag (bool)
* 2. Declare the shift variable, and declare the new string that will be decrypted or encrypted version of the message
* 3. Check if flag is true.
*       If yes, loop through the length of the message letter by letter using the iteration i, and loop through the key by using iteration j.
*       Check if the current iteration (character) of the letter is not a space.
*           If yes, set the shift equal to the difference between the key value (key[j]) and the letter A (65).
*               Add the shifted letter to the new message. The shifted letter is calculated by adding the shift to the current letter, and then subtracting A (65) from it. Then modular 26 and add 65 after that.
*               Then, calculate the next value of j, which is the current value + 1, modular the length of the key.
*       If no, add the character to the new message, which will be a space.
* 4. If no, aka flag is false.
*       Loop through the length of the message letter by letter using the iteration i, and loop through the key by using j.
*       Check if the current iteration (character) of the letter is not a space.
*           If yes, set the shift equal to the difference between the key value (key[j]) and 26.
*               Add the shifted letter to the new message. The shifted letter is calculated by subtracting the shift from the current letter, and then taking the remainder from dividing it by 26 (modulus). Then add 65 to that value to get the decrypted letter.
*               Then, calculate the next value of j, which is the current value + 1, modular the length of the key.
*           If no, add the character to the new message, which will be a space.
* 5. Return the new decrypted or encrypted message.
* Input parameters: a message (string), a key (string), and a flag (bool)
* Output (prints to screen): nothing
* Returns: the encrypted or decrypted message (string)
*/
string vigenereCipher(string message, string key, bool flag){
    int shift; // declares the variable that will store the shift number
    string newMessage = ""; // declares a new string for the encrypted/decrypted message and set it equal to an empty string
    if (flag){ // checks if the flag is true
        for (int i=0,j=0; i < message.length(); i++){ // loops through the entire message string letter by letter
            if (message[i] != ' '){ // checks if the character is not a space
                shift = key[j] - 65; // calculates the shift by taking teh difference between the key value and 65 (A)
                newMessage += (message[i]+shift-65)%26 + 65; // calculates the new character and adds it to the new message
                j = (j+1) % key.length(); // calculates the iteration for the key string
            }
            else{
                newMessage+= message[i]; // adds the character to the new message if it is a space
            }
        }    
    }
    else{
        for (int i=0,j=0; i<message.length();i++){ // loops through the messsage string letter by letter
            if (message[i]!= ' '){ // checks if the character is not a space
                shift = key[j] - 26; // calculates the shift value, which is the difference between the key value and 26
                newMessage += (message[i]-shift)%26 + 65; // calculates the new character and adds it to the message
                j = (j+1) % key.length(); // calculates the iteration for the key string
            }
            else{
                newMessage += message[i]; // if the character is a space, just add it to the string
            }
        }
    }
    return newMessage; // return the new encrypted or decrypted message
}
    
    
int main(){
    // Test Case 1
    // expected output
    // NVOGFKVY
    cout << vigenereCipher("UNICORNS","TIGER",true) << endl; // first function call to vigenereCipher
    
    // Test Case 2
    // expected output
    // NVO GFKVY
    cout << vigenereCipher("UNI CORNS","TIGER",true) << endl; // seconds function cal to vigenereCipher
    
    // Test Case 3
    // expected output
    // UNICORNS
    cout << vigenereCipher("NVOGFKVY","TIGER",false) << endl; // third function call to vigenereCipher
}