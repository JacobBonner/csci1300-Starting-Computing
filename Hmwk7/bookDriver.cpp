// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 7 - Problem # 3


# include <iostream>
# include "Book.h"
using namespace std;


// Testing implementation of Book class

int main(){
   
    // Test Case 1
    // expected output
    // The Lord of the Rings by JRR Tolkien
    Book book1;
    book1.setTitle("The Lord of the Rings");
    book1.setAuthor("JRR Tolkien");
    cout << book1.getTitle() << " by " << book1.getAuthor() << endl;
    
    // Test Case 2
    // expected output
    // Harry Potter by JK Rowling
    Book book2;
    book2.setTitle("Harry Potter");
    book2.setAuthor("JK Rowling");
    cout << book2.getTitle() << " by " << book2.getAuthor() << endl;
}