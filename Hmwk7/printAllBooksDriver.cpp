// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 7 - Problem # 6


# include <iostream>
# include "Book.h"
using namespace std;


/** Algorithm: Prints out the book and author of each element in a books array, or prints out that the "library" is empty.
* 1. Take the two arguments passed into the function: Books books[], and numBooks (int)
* 2. Check if the number of books is less than or equal to zero.
*       If yes, print out "No books are stored".
* 3. If not..
*       Print out "Here is a list of books".
*       Use variable i to loop from 0 to the number of books given.
*           Print out: the book " by "  author, corresponding to the ith element of the books array
* Input parameters: books array (type Book), numBooks (int)
* Output (prints to screen): title " by " author - for each index in the books array
* Returns: nothing
*/
void printAllBooks(Book books[],int numBooks){
    if (numBooks<=0){ // checks if the number of books is equal to zero
        cout << "No books are stored" << endl; 
    }
    else{
        cout << "Here is a list of books" << endl; 
        for (int i=0;i<numBooks;i++){ // loops through the number of books starting at 0
            cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
        }
    }
}


int main(){
    
    // Test 1
    // expected output
    // Here is a list of books
    // Differential Equations and Linear Algebra by Farlow
    Book books1[1];
    books1[0].setTitle("Differential Equations and Linear Algebra");
    books1[0].setAuthor("Farlow");
    printAllBooks(books1,1); // first function call to printAllBooks
    
    cout << "\n";
    
    // Test 2
    // expected output
    // Here is a list of books
    // Calculus by Mathematician
    // Algebra by Alan Turing
    // Physics by Isaac Newton
    Book books2[3];
    books2[0].setTitle("Calculus");
    books2[0].setAuthor("Mathematician");
    books2[1].setTitle("Algebra");
    books2[1].setAuthor("Alan Turing");
    books2[2].setTitle("Physics");
    books2[2].setAuthor("Isaac Newton");
    printAllBooks(books2,3); // second function call to printAllBooks
}