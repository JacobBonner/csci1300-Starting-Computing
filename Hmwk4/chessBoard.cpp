// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 4 - Problem # 4

# include <iostream>
using namespace std;

/**
* Algorithm: Determines if a square with a given letter or number on a chessboard is black or white.
* 1. Take the letter and number passed into the function as parameters.
* 2. Check if the letter is 'a','c','e',or 'g'.
*       If yes...
*           2a. Check if the number is even, AND that it ranges from 1-8.
*               If yes, then print white.
*               2b. If no, check if the number is odd, AND that it ranges from 1-8.
*                   If yes, then print black.
*                   2c. If no, then print - Chessboard squares can only have letters between a-h and numbers between 1-8.
* 3. If no, check if the letter is 'b','d','f',or 'h'.
*       If yes...
*           3a. Check if the number is even, AND that it ranges from 1-8.
*               If yes, then print white.
*               3b. If no, check if the number is odd, AND that it ranges from 1-8.
*                   If yes, then print black.
*                   3c. If no, then print - Chessboard squares can only have letters between a-h and numbers between 1-8.
* 4. If no, then print - Chessboard squares can only have letters between a-h and numbers between 1-8.
* Input parameters: a letter (type char) and a number (type int)
* Output (prints to screen): different string based on different conditions - "black", "white", or 
*                            "Chessboard squares can only have letters between a-h and numbers between 1-8"
* Returns: nothing
*/


void chessBoard(char letter, int number){
    if (letter == 'a' || letter == 'c' || letter == 'e' || letter == 'g') // checks if letter is a,c,e or g
    {
        if (number % 2 == 0 && number >= 1 && number <= 8) // checks if number is even and if it is between 1 and 8
        {
            cout << "white" << endl; // prints white
        }
        else if (number % 2 == 1 && number >= 1 && number <= 8) // checks if number is odd and if it is between 1 and 8
        {
            cout << "black" << endl; // prints black
        }
        else // executes what is inside this statement if the given number is invalid
        {
            cout << "Chessboard squares can only have letters between a-h and numbers between 1-8" << endl; // prints statement for ivalid input
        }
    }
    else if (letter == 'b' || letter == 'd' || letter == 'f' || letter == 'h') // checks if letter is b,d,f or h
    {
       if (number % 2 == 0 && number >= 1 && number <= 8) // checks if number is even and if it is between 1 and 8
       {
           cout << "black" << endl; // prints black
       }
       else if (number % 2 == 1 && number >= 1 && number <= 8) // checks if number is odd and if it is between 1 and 8
       {
           cout << "white" << endl; // prints white
       }
       else // executes what is inside this statement if the given number is invalid
       {
           cout << "Chessboard squares can only have letters between a-h and numbers between 1-8" << endl; // prints statement for ivalid input
       }
    }
    else // executes what is inside this statement if the letter given is invalid
    {
        cout << "Chessboard squares can only have letters between a-h and numbers between 1-8" << endl; // prints statement for ivalid input
    }
}


int main() {
    // Test 1
    // expected output
    // black
    chessBoard('h',8); // first function call to chessBoard
    
    // Test 2
    // expected output
    // white
    chessBoard('d',3); // second function call to chessBoard
    
    // Test 3
    // expected output
    // Chessboard squares can only have letters between a-h and numbers between 1-8
    chessBoard('A',8); // third function call to chessBoard
    
    return 0;
}