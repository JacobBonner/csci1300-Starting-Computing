// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 7 - Problem # 5


# include <iostream>
# include <fstream>
# include "Book.h"
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
        return 0; 
    }
    string word = ""; 
    int j=0,k=0; // counter variables
    toSplit = toSplit + delimeter; 
    for (int i = 0; i < toSplit.length(); i++) // loops through the entire string
    {
        if (toSplit[i] == delimeter) // checks if the current element in the string is equal to the delimeter
        {
        	if (word.length() == 0) continue; // checks if the length of the word is zero
            splitArray[k] = word; // sets the kth array index equal to word
            j++; 
            word = ""; 
            k++; 
        } else {
            word = word + toSplit[i]; // sets word equal to word + the ith index of the string
        }
    }
    
    if (k>length){ // checks if k is greater than the length variable passed into the function
        return -1;
    }
    
    return j; 
}


/** Algorithm: Populates an array of Planet class with books and authors, and returns the number of books stored.
 * 1. Checks if the number of books stored is equal to the books array size.
 *      If yes, return -2.
 * 4. Checks if the file successfully opened.
 *      If yes...
 *      Declare a new variable for each line and set it equal to an empty string.
 *      Declare a new array of type string and size 2 to hold the two substrings of each split line.
 *      While there is still a line in the file to read...
 *          Check if the current number of books stored is less than the array size.
 *              If yes, check if the line is not empty.
 *                  If yes...
 *                  Call the split function on the previous array of type string and size 2, with a delimeter of ','.
 *                  Call the setAuthor() function of class Book, that sets the author equal to the first element in the split array.
 *                  Call the setTitle() function of class Book, that sets the title equal to the second element in the split array. *                  
 *                  Add one to the number of books stored.
 *                  Set both elements of the array used in the split function equal to empty strings.
 *      Return the value for the number of books stored.
 * 5. If no, return -1.
* Input parameters: fileName (string), books (array of type Book), numBooksStored (int), bookArrSize (int)
* Output (prints to screen): nothing
* Returns: -1 if the file is not opened successfully, -2 if the numBooksStored is equal to bookArrSize, or the number of books added to the books array
*/
int readBooks(string fileName,Book books[],int numBooksStored,int bookArrSize){
    if (numBooksStored==bookArrSize){ // checks if the number of books stored is equal to the size
        return -2;
    }
    ifstream myfile; 
    myfile.open(fileName); 
    if(myfile.is_open()){ // checks if the file opened correctly
        string line = ""; 
        string splitArray[2]; 
        while (getline(myfile,line)){ // checks if there is still a line to read in the file
            if(numBooksStored<bookArrSize){ // checks if the number of books stored is less than the size
                if(!(line.empty())){ // checks if the line is not empty
                    split(line,',',splitArray,2); 
                    books[numBooksStored].setAuthor(splitArray[0]); // sets the author in books equal to the 0th element of splitArray
                    books[numBooksStored].setTitle(splitArray[1]) ; // sets the title in books equal to the index 1 element of splitArray
                    numBooksStored++; 
                    splitArray[0]=""; 
                    splitArray[1]=""; 
                }
            }
        }
        return numBooksStored; 
    }
    else{
        return -1; 
    }
}


int main(){
    
    // Test Case 1
    // expected output
    // 2
    // Author A
    // Author B
    // Book 1
    // Book 2
    Book books[10];
    cout << readBooks("hmwk7File1.txt",books, 0, 10) << endl; // first function call to readBooks
    // creating authors and titles for books array
    cout << books[0].getAuthor() << endl;
    cout << books[1].getAuthor() << endl;
    cout << books[0].getTitle() << endl;
    cout << books[1].getTitle() << endl;

    // Test Case 2
    // expected output
    // 3
    // Author Z
    // Author A
    // Author B
    // Book N
    // Book 1
    // Book 2
    Book books2[10];
    books2[0].setAuthor("Author Z");
    books2[0].setTitle("Book N");
    cout << readBooks("hmwk7File1.txt",books2, 1, 10) << endl; // second function call to readBooks
    // creating authors and titles for books array
    cout << books2[0].getAuthor() << endl;
    cout << books2[1].getAuthor() << endl;
    cout << books2[2].getAuthor() << endl;
    cout << books2[0].getTitle() << endl;
    cout << books2[1].getTitle() << endl;
    cout << books2[2].getTitle() << endl;
}