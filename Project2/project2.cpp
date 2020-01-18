// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Project 2 - Problem # 11


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Book.h"
#include "User.h"
#include "Library.h"
using namespace std;


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
	cout << "5. Find number of books user rated" << endl;
	cout << "6. View ratings" << endl;
	cout << "7. Get average rating" << endl;
	cout << "8. Add a user" << endl;
	cout << "9. Checkout a book" << endl;
	cout << "10. Get recommendations" << endl;
	cout << "11. Quit" << endl;
}


int main(int argc, char const *argv[]) {


	// temp variables
    string choice;
    string bookFileName;
    string userFileName;
    string userName, bookTitle;
    string strRating;

    // declaring a Libary object for implementation
    Library myLibrary;
    
    // defining constant variables and variables for updating
    int numBook = myLibrary.getNumBooks(), numUser = myLibrary.getNumUsers();
    int rate, numRated,userAdded, checkOut;
    double avgRating;
    const static int bookArrSize = myLibrary.getSizeBook(), userArrSize = myLibrary.getSizeUser();

    while (choice != "11") {
        displayMenu();

        // take a menu opton
        getline(cin, choice);

        // convert the `choice` to an integer
        int menuChoice = stoi(choice);

        switch (menuChoice) {

            case 1:
                // Initialize library -- readBooks
                cout << "Enter a book file name:" << endl;
                getline(cin, bookFileName);

                // call to readBooks
                numBook = myLibrary.readBooks(bookFileName);
                
                // testing different conditions for different outputs
                if (numBook == -1){
                    cout << "No books saved to the database." << endl;
                    numBook = 0;
                }
                else if(numBook == -2){
                    cout << "Database is already full. No books were added." << endl;
                    numBook = bookArrSize;
                }
                else if(numBook == bookArrSize){
                    cout << "Database is full. Some books may have not been added." << endl;
                }
                else{
                    cout << "Total books in the database: " << numBook << endl;
                }

                cout << endl;
                break;


            case 2:
                //  Initialize user catalog -- readRatings

                cout << "Enter a user file name:" << endl;
                getline(cin, userFileName);

                // calling readRatings
                numUser = myLibrary.readRatings(userFileName);
                
                // checking different conditions for various outputs
                if (numUser == -1){
                    cout << "No users saved to the database." << endl;
                    numUser = 0;
                }
                else if(numUser == -2){
                    cout << "Database is already full. No users were added." << endl;
                    numUser = userArrSize;
                }
                else if(numUser == userArrSize){
                    cout << "Database is full. Some users may have not been added." << endl;
                }
                else{
                    cout << "Total users in the database: " << numUser << endl;
                }
                
                cout << endl;
                break;
                

            case 3:
                // Display library -- printAllBooks

                if (numBook==0){ // if the data base has not been initialized (no books in library)
                    cout << "Database has not been fully initialized." << endl;
                }
                else{ // calls printAllBooks
                    myLibrary.printAllBooks();
                }
               
                cout << endl;
                break;


            case 4:
                //  Get a rating -- getRating

                if (numBook == 0){ // if no books in library
                    cout << "Database has not been fully initialized." << endl;
                }
                else{
            		// take user name
                    cout << "Enter username:" << endl;
                    getline(cin, userName);
    
                    // take book title
                    cout << "Enter book title:" << endl;
                    getline(cin, bookTitle);
                    
                    // calls getRating
                    rate = myLibrary.getRating(userName,bookTitle);
                    
                    // tests various conditions for different outputs
                    if (rate == 0){
                        cout << userName << " has not rated " << bookTitle << endl;
                    }
                    else if(rate == -3){
                        cout << userName << " or " << bookTitle << " does not exist." << endl;
                    }
                    else{
                        cout << userName << " rated " << bookTitle << " with " << rate << endl;
                    }
                }
                
                cout << endl;
                break;


            case 5:
                // Get number of books the user has rated -- getCountReadBooks

                if (numBook==0){ // if no books in library
                   cout << "Database has not been fully initialized." << endl; 
                }
                else{
                    cout << "Enter username:" << endl;
                    getline(cin, userName);
                    
                    // calls getCountReadBooks
                    numRated = myLibrary.getCountReadBooks(userName);
                    
                    // checks different conditions for output
                    if(numRated == 0){
                        cout << userName << " has not rated any books." << endl;
                    }
                    else if(numRated == -3){
                        cout << userName << " does not exist." << endl;
                    }
                    else{
                        cout << userName << " rated " << numRated << " books." << endl;
                    }
                }
                
            	cout << endl;
                break;


            case 6:
                // View user’s ratings -- viewRatings

                if(numBook == 0){ // when library is empty
                    cout << "Database has not been fully initialized." << endl;
                }
                else{
            		// take user name
                    cout << "Enter username:" << endl;
                    getline(cin, userName);
                    
                    // calls viewRatings
                    myLibrary.viewRatings(userName);
                }

            	cout << endl;
                break;


            case 7:
                // Calculate the average rating for the book -- calcAvgRating
                
                if (numBook == 0){ // if library is empty
                    cout << "Database has not been fully initialized." << endl;
                }
                else{
            		// take book title
                    cout << "Enter book title:" << endl;
                    getline(cin, bookTitle);
                    
                    // calls calcAvgRating
                    avgRating = myLibrary.calcAvgRating(bookTitle);
                    
                    // checks different conditions for output
                    if (avgRating == -3){
                        cout << bookTitle << " does not exist." << endl;
                    }
                    else{
                        cout << "The average rating for " << bookTitle << " is " << avgRating << endl;
                    }
                }
                
            	cout << endl;
                break;
                
                
            case 8:
                // Add a user to the database -- addUser
        		// take user name
                cout << "Enter username:" << endl;
                getline(cin, userName);
                
                // call to addUser
                userAdded = myLibrary.addUser(userName);
                
                // different output tests
                if(userAdded == 1){
                    cout << "Welcome to the library " << userName << endl;
                }
                else if(userAdded == 0){
                    cout << userName << " already exists in the database." << endl;
                }
                else if(userAdded == -2){
                    cout << "Database is already full. " << userName << " was not added." << endl;
                }
        
            	cout << endl;
                break;
                
                
            case 9:
                // Check out the book -- checkOutBook
                
                if(numBook == 0){ // if empty library
                    cout << "Database has not been fully initialized." << endl;
                }
                else{

            		// take user name
                    cout << "Enter username:" << endl;
                    getline(cin, userName);
    
                    // take book title
                    cout << "Enter book title:" << endl;
                    getline(cin, bookTitle);
    
                    // take rating
                    cout<<"Enter rating for the book:"<<endl;
                    getline(cin, strRating);
                    
                    // converts given rating to an integer
                    int intRating = stoi(strRating);
                    
                    // call to checkOutBook
                    checkOut = myLibrary.checkOutBook(userName,bookTitle,intRating);
                    
                    // outputs different statements based on conditions
                    if (checkOut == 1){
                        cout << "We hope you enjoyed your book. The rating has been updated." << endl;
                    }
                    else if(checkOut == -4){
                        cout << strRating << " is not valid." << endl;
                    }
                    else if(checkOut == -3){
                        cout << userName << " or " << bookTitle << " does not exist." << endl;
                    }
                }
                
            	cout << endl;
                break;
                
                
            case 10:
                // get recommendations  -- getRecommendations

                if(numBook == 0){ // test if library is empty
                    cout << "Database has not been fully initialized." << endl;
                }
                else{
            		// take user name
                    cout << "Enter username:" << endl;
                    getline(cin, userName);
                    
                    // call to getRecommendations
                    myLibrary.getRecommendations(userName);
                }

            	cout << endl;
                break;


            case 11:
                // quit
                cout << "good bye!" << endl;
                break;

            default:
                cout << "invalid input" << endl;
                cout << endl;
        }
    }

    return 0;
}