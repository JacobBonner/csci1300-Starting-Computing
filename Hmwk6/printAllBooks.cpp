// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 6 - Problem # 6

# include <iostream>
# include <fstream>
using namespace std;

/** Algorithm: Prints out a a list of books and authors, or prints out that the "library" is empty.
* 1. Take the three arguments passed into the function: array of titles, array of authors, and a number of books (int).
* 2. Check if the number of books is less than or equal to zero.
*       If yes, print out "No books are stored".
* 3. If not..
*       Print out "Here is a list of books".
*       Use variable i to loop from 0 to the number of books given.
*           Print out: the ith value of titles[] " by " the ith value of authors[]
* Input parameters: fileName (string), titles (array of strings), authors (array of strings), numBookStored (int), size (int)
* Output (prints to screen): title " by " author - for each index in the given arrays
* Returns: nothing
*/
void printAllBooks(string titles[],string authors[],int numBooks){
    if (numBooks<=0){ // checks if the number of books is equal to zero
        cout << "No books are stored" << endl; // prints out "No Books are stored"
    }
    else{
        cout << "Here is a list of books" << endl; // prints out "Here is a list of books"
        for (int i=0;i<numBooks;i++){ // loops through the number of books starting at 0
            cout << titles[i] << " by " << authors[i] << endl; // prints out the corresponding title and author
        }
    }
}


int main(){
    // Test 1
    // expected output
    // Here is a list of books
    // Differential Equations and Linear Algebra by Farlow
    string books_1[1]= {"Differential Equations and Linear Algebra"}; // array of book names to be passed into the function
    string authors_1[1]= {"Farlow"}; // array of authors to be passed into the function
    printAllBooks(books_1,authors_1,1); // first function call to printAllBooks
    
    cout << "\n";
    
    // Test 2
    // expected output
    // Here is a list of books
    // Calculus by Mathematician
    // Algebra by Alan Turing
    // Physics by Isaac Newton
    string books_2[3]= {"Calculus", "Algebra", "Physics"}; // array of book names to be passed into the function
    string authors_2[3]= {"Mathematician", "Alan Turing", "Isaac Newton"}; // array of authors to be passed into the function
    printAllBooks(books_2,authors_2,3); // second function call to printAllBooks
    
    cout << "\n";

    // Test 3
    // expected output
    // No books are stored
    string books_3[]= {}; // array of book names to be passed into the function
    string authors_3[]= {}; // array of authors to be passed into the function
    printAllBooks(books_3,authors_3,0); // third function call to printAllBooks
    
    return 0;
}