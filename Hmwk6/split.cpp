// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 6 - Problem # 3

# include <iostream>
# include <string>
using namespace std;

/**
* Algorithm: Split the input string in to pieces separated by the delimiter, and fill the array of strings with the split pieces up to 
* the provided maximum number of pieces.
* 1. Take the four argumants passed into the function: string to split (string), a delimeter (char), an empty array, and the maximum number of columns (int).
* 2. Check if the string passed into the function is of length zero, and returns zero if yes.
* 3. Declare a new variable, word, that is an empty string (str), and declare two counter vaiables, j and k (int), and set them equal to zero.
* 4. Set the passed string equal to the string plus the delimeter.
* 5. Loop through the string starting from the first index.
*       Check if the current index of the string is equal to the delimeter.
*           If yes, set the split array index of the counter k equal to the string declared above.
*               Add one to the counter j and k, and word equal to an empty string.
*       If no, add the value of index i of the string to word.
* 6. Check if k is greater than the variable length passed into the function (number of columns).
*       If yes, return -1.
* 7. Return the counter j.
* Input parameters: a string to split (string), a delimeter (char), an array of strings (string), the length of the given array (int)
* Output (prints to screen): nothing
* Returns: the number of strings the input string was split into (int)
*/
int split(string toSplit,char delimeter,string splitArray[],int length){
    if (toSplit.length() == 0) { // checks if the length of the string is zero
        return 0; // returns zero
    }
    string word = ""; // declares new variable "word" and defines it as an emtpy string
    int j=0,k=0; // defines two counter variables and set them equal to zero
    toSplit = toSplit + delimeter; // sets the input string equal to the string plus the delimeter
    for (int i = 0; i < toSplit.length(); i++) // loops through the entire string
    {
        if (toSplit[i] == delimeter) // checks if the current element in the string is equal to the delimeter
        {
        	if (word.length() == 0) continue; // checks if the length of the word is zero
            splitArray[k] = word; // sets the kth array index equal to word
            j++; // adds one to the j counter
            word = ""; // sets word equal to an empty string
            k++; // adds one to the k counter
        } else {
            word = word + toSplit[i]; // sets sowrd equal to wrod + teh ith index of the string
        }
    }
    
    if (k>length){ // checks if k is greater than the length variable passed into the function
        return -1; // retunrs -1
    }
    
    return j; // returns j
}


int main(){
    // Test 1
    // expected output
    // one
    // small
    // step
    string words1[6]; // declares the empty array to be passed into split
    cout << split("one small step",' ',words1,6) << endl; // first function call to split
    
    for (int i=0;i<3;i++){ // loops through each element in the array
        cout << words1[i] << endl; // prints out the current index value of the array
    }
    
    // Test 2
    // expected output
    // one
    // small
    // step
    string words2[6]; // declares the empty array to be passed into split
    cout << split(" one small step ",' ',words2,6) << endl; // second function call to split
    
    for (int i=0;i<3;i++){ // loops through each element in the array
        cout << words2[i] << endl; // prints out the current index value of the array
    }
    
    // Test 3
    // expected output
    // cow
    // big pig
    // fish
    // doplhin
    string words3[6]; // declares the empty array to be passed into split
    cout << split("cow/big pig//fish//dolphin",'/',words3,6) << endl; // third function call to split
    
    for (int i=0;i<4;i++){ // loops through each element in the array
        cout << words3[i] << endl; // prints out the current index value of the array
    }
}


