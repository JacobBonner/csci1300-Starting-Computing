// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 7 - Problem # 9


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Book.h"
#include "User.h"
using namespace std;


// See all previous problems for algorithm and comments explaining each function


// split function
int split(string toSplit,char delimeter,string splitArray[],int length){
    if (toSplit.length() == 0) {
        return 0;
    }
    string word = "";
    int j=0,k=0;
    toSplit = toSplit + delimeter;
    for (int i = 0; i < toSplit.length(); i++)
    {
        if (toSplit[i] == delimeter) 
        {
        	if (word.length() == 0) continue;
            splitArray[k] = word; 
            j++;
            word = "";
            k++;
        } else {
            word = word + toSplit[i];
        }
    }
    
    if (k>length){
        return -1;
    }
    
    return j ;
}



// readBooks function
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



// readRatings function
int readRatings(string filename,User users[],int numUsersStored,int usersArrSize,int maxCol){
    if (numUsersStored >= usersArrSize){ // checks if the number of users is equal to the max number of rows
        return -2; 
    }
    ifstream myfile; 
    myfile.open(filename);
    if(myfile.is_open()){ // checks if the file successfully opened
        string line = ""; 
        string newArray[maxCol+1]; 
        for (int k=0;k<maxCol+1;k++){ // loops through the length of the new array
            newArray[k]='0';
        }
        while(getline(myfile,line)){ // while there are still lines to be read in the opened file
            if (numUsersStored<usersArrSize){ // chekcs if the number of users is less than the max number of rows
                if (!(line.empty())){ // checks if the current line is not empty
                    split(line,',',newArray,maxCol+1);
                    users[numUsersStored].setUsername(newArray[0]);
                    for (int j=0;j<maxCol;j++){ // loops through the length of the array (number of columns)
                        users[numUsersStored].setRatingAt(j,stoi(newArray[j+1]));
                    }
                    numUsersStored++; 
                }
            }
        }  
        return numUsersStored; 
    }
    else{
        return -1; 
    }
}



// printAllBooks function
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



// getRating function 
int getRating(string username, string bookTitle, User users[], Book books[], int numUsers, int numBooks){
    // iterates through the username and changes it to all lowercase letters
    for (int i=0; i<username.length();i++){
        username[i] = tolower(username[i]);
    }
    
    // iterates through the book title and changes it to all lowercase letters
    for (int i=0; i<bookTitle.length();i++){
        bookTitle[i] = tolower(bookTitle[i]); 
    }
    
    // iterates through the users array and makes each element all lowercase
    string name; 
    for (int i=0; i<numUsers;i++){ 
        name = users[i].getUsername(); 
        for (int j=0;j<name.length();j++){ 
            name[j] = tolower(name[j]);
        }
        users[i].setUsername(name); // sets the ith element of the users array equal to the lower case name
    }

    // iterates through the books array and makes each title element all lowercase
    string title; 
    for (int i=0; i<numBooks;i++){ 
        title = books[i].getTitle();
        for (int j=0;j<title.length();j++){
            title[j] = tolower(title[j]); 
        }
        books[i].setTitle(title); 
    }
    
    // declare variables to be tested and used below
    bool titleExist=false,userExist=false; // declares a boolean variable for the existence of the title and username
    int nameIdx,titleIdx; // declares variables for the name and title index to be able to access the proper rating
    
    // loop through names, save true or false, and save row index if name exists users in array
    for (int j=0; j<numUsers; j++){ // iterates through the number of users passed into the function
        if(users[j].getUsername() == username){ // checks if the jth elements of the users array is equal to the username
            nameIdx = j; // sets the name index equal to the value of j 
            userExist = true; // sets the previously declared user existence variable equal to true
        }
    }
    
    // loop through books, saves true or false, and saves column index if title exists in books array
    for (int k=0; k<numBooks; k++){ 
        if(books[k].getTitle() == bookTitle){ 
            titleIdx = k; 
            titleExist = true; 
        }
    }
    
    // Checks if both the title and name exist in the arrays, and if so returns the value at the corresponding index
    if(userExist && titleExist){
        return users[nameIdx].getRatingAt(titleIdx); 
    }
    else{ // if the title or the name doesn't exist in the given arrays
        return -3; 
    }
}




/* displayMenu:
 * displays a menu with options
 * DO NOT MODIFY THIS FUNCTION
 */
void displayMenu(){
  cout << "Select a numerical option:" << endl;
  cout << "======Main Menu=====" << endl;
  cout << "1. Read book file" << endl;
  cout << "2. Read user file" << endl;
  cout << "3. Print book list" << endl;
  cout << "4. Get rating" << endl;
  cout << "5. Quit" << endl;
}



int main(int argc, char const *argv[]) {

    // taking menu choice 
    string choice;

    // number of books and users stored in the arrays
    int numBooksStored = 0;
    int numUsersStored = 0;

    // Use the these values to declare your
    // titles, authors, users and ratings arrays
    const static int  usersArrSize = 100;
    const static int  booksArrSize = 50;


    // delaring arrays and variables to store return values
    int userRating; // integer for the value of a user's rating
    Book books[booksArrSize];
    User users[usersArrSize];
    
    
    // variables to store user inputs 
    string bookFileName;
    string userFileName;
    string userName, bookTitle;    

    while (choice != "5") {
        displayMenu();

        // take an opton (1, 2, 3, or 4)
        getline(cin, choice);

        // convert the `choice` to an integer 
        int menuChoice = stoi(choice); 
        switch (menuChoice) {
            case 1:
                // read book file
                cout << "Enter a book file name:" << endl;
                getline(cin, bookFileName);
                
                
                // calling readBooks function
                numBooksStored = readBooks(bookFileName,books,numBooksStored,booksArrSize);
                
                // testing conditions for differnt outputs
                if(numBooksStored == -1){
                    cout << "No books saved to the database." << endl;
                    numBooksStored = 0;
                }
                else if(numBooksStored == -2){
                    cout << "Database is already full. No books were added." << endl;
                    numBooksStored = 50;
                }
                else if(numBooksStored == booksArrSize){
                    cout << "Database is full. Some books may have not been added." << endl;
                }
                else{
                    cout << "Total books in the database: " << numBooksStored << endl;
                }
                
                cout << endl;
                break;


            case 2:
                // read ratings file
                cout << "Enter a user file name:" << endl;
                getline(cin, userFileName);
                
                // calling readRatings function
                numUsersStored = readRatings(userFileName,users,numUsersStored,usersArrSize,booksArrSize);
                
                // testing conditions for different outputs
                if(numUsersStored == -1){
                    cout << "No users saved to the database." << endl;
                    numUsersStored = 0;
                }
                else if(numUsersStored == -2){
                    cout << "Database is already full. No users were added." << endl;
                    numUsersStored = 100;
                }
                else if(numUsersStored == usersArrSize){
                    cout << "Database is full. Some users may have not been added." << endl;
                }
                else{
                    cout << "Total users in the database: " << numUsersStored << endl;
                }
                
                cout << endl;
                break;


            case 3:

                // print the list of the books
                
                // calls the printAllBooks function
                printAllBooks(books,numBooksStored);

                cout << endl;
                break;


            case 4:
                // get user's rating 
                // take user name
                cout << "Enter username:" << endl;
                getline(cin, userName);

                // take book title 
                cout << "Enter book title:" << endl;
                getline(cin, bookTitle);
                
                // calls getRating function
                userRating = getRating(userName,bookTitle,users,books,numUsersStored,numBooksStored);
                
                // testing different conditions for different ouputs
                if(userRating == 0){
                    cout << userName << " has not rated " << bookTitle << endl; 
                }
                else if(userRating == -3){
                    cout << userName << " or " << bookTitle << " does not exist" << endl;
                }
                else{
                    cout << userName << " rated " << bookTitle << " with " << userRating << endl;
                }

                cout << endl;
                break;
                
                
            case 5:
                // quit
                cout << "good bye!" << endl;
                break;

            default:
                cout << "invalid input" << endl;
        }
    }

    return 0;
}