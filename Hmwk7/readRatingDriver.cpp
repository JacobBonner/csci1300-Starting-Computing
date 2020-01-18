// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 7 - Problem # 8


# include <iostream>
# include <fstream>
# include <string>
# include <locale>
# include "User.h"
# include "Book.h"
using namespace std;


/** Algorithm: Search for a given user’s rating for a particular book title, and return the rating the user gave for that book.
 * 1. Take all of the arguments passed into the function (see below)
 * 2. Iterate through the given username and change every latter to lowercase.
 * 3. Iterate through the given title and change every latter to lowercase.
 * 4. Iterate through every element in the users array, and change every letter of each title and user to lowercase.
 * 6. Declare two boolean variables to represent the existence of the title and the user name.
 * 7. Declare two integer variables that will represent the index of the given title and given name in the arrays.
 * 8. Iterate through the given number of users and check if the current username in the users array is equal to given username.
 *      If yes, set the name index equal to the index that the element existed at, and set the user existence variable to true.
 * 9. Iterate through the given number of books and check if the current title in the books array is equal to the given title.
 *      If yes, set the title index equal to the index that the element existed at, and set the title existence variable to true.
 * 10. Check if the user existence variable and the title existence variable are both true.
 *      If yes, return the value in the rating value in users array corresponding to the position [name index][title index].
 * 11. If no, return -3.
 * Input parameters: a username (string), a book title (string), users array (User), books array (Book), number of users (int), number of books (int).
 * Output (prints to screen): Nothing
 * Returns: -3 if either the given title or name do not exist in the given arrays, or the rating value corresponding to the index of [name][title]
 */ 
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


int main(){
    
    // Test Case 1
    // expected output
    // 4
    Book books1[2];
    // assigning authors and titles to the books array
    books1[0].setTitle("The Prince");
    books1[0].setAuthor("Niccolo Machiavelli");
    books1[1].setTitle("The Education of Cyrus");
    books1[1].setAuthor("Xenophon");
    User users1[2];
    // assigning usernames and ratings to the users array
    users1[0].setUsername("UserName1");
    users1[0].setNumRatings(2);
    users1[0].setRatingAt(0,1);
    users1[0].setRatingAt(1,3);
    users1[1].setUsername("UserName2");
    users1[1].setNumRatings(2);
    users1[1].setRatingAt(0,2);
    users1[1].setRatingAt(1,4);
    cout << getRating("UserName2","The Education of Cyrus",users1,books1,2,2) << endl; // first function call to getRating
    
    
    // Test Case 2
    // expected output
    // 3
    Book books2[1];
    // assigning authors and titles to the books array
    books2[0].setTitle("The Lightning Thief");
    books2[0].setAuthor("Rick Riordan");
    User users2[4];
    // assigning usernames and ratings to the users array
    users2[0].setUsername("Name A");
    users2[0].setNumRatings(1);
    users2[0].setRatingAt(0,5);
    users2[1].setUsername("Name B");
    users2[1].setNumRatings(1);
    users2[1].setRatingAt(0,2);
    users2[2].setUsername("Name C");
    users2[2].setNumRatings(1);
    users2[2].setRatingAt(0,3);
    users2[3].setUsername("Name D");
    users2[3].setNumRatings(1);
    users2[3].setRatingAt(0,1);
    cout << getRating("Name C","The Lightning Thief",users2,books2,4,1) << endl; // second function call to getRating

    
    return 0;
}