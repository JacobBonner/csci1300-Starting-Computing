// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 5 - Problem # 2

# include <iostream>
# include <string>
using namespace std;


/**
* Algorithm: Counts the number of words in a string (sentence).
* 1. Take the string passed into the function.
* 2. Define a space counter and a word count and set them both equal to 0.
* 3. Checks if the string sentence is not equal to "" (an empty string)
*       If yes, 
*           Iterate over the whole string, increasing the iteration by 1 each time (starting at 0 and ending at the length of the string).
*               Checks if the index of the string corresponding to the iteration number is a space ' '.
*                   If yes, add 1 to the space counter.
*                   Go back to the start of the for loop until the whole string has been iterated over.
*           Checks if the space counter is equal to 0.
*               If yes, set word count equal to 1.
*           If no, set the word count equal to space count + 1.
* 3. Return the word count.
* Input parameters: A random string (sentence)
* Output (prints to screen): nothing
* Returns: the number of words in the string (int)
*/
int getWordCount(string sentence){
    int spaceCounter = 0; // declares new variable spaceCounter and sets it equal to zero
    int wordCount = 0; // declares new variable wordCount and sets it equal to zero
    if (sentence != ""){ // checks if the sentence is not an empty string
        for (int i = 0; i < sentence.length(); i++){ // loops through each index of the string from 0 to the length of the string
            if (sentence[i] == ' '){ // checks if the character is a space
                spaceCounter++; // adds one to the space counter
            }
        }
        if (spaceCounter == 0){ // checks if the space counter is equal to zero
            wordCount = 1; // sets word count equal to 1
        }
        else{
            wordCount = spaceCounter + 1; // sets word count equal to space counter + 1
        }
    }
    return wordCount; // returns the word count
}


int main(){
    // Test 1
    // expected output
    // 1
    cout << getWordCount("Hello") << endl; // first function call to getWordCount
    
    // Test 2
    // expected output
    // 0
    cout << getWordCount("") << endl; // second function call to getWordCount
    
    // Test 3
    // expected output
    // 5
    cout << getWordCount("Punith is the best TA") << endl; // third function call to getWordCount
    
    return 0;
}