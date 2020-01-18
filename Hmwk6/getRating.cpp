// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 6 - Problem # 8

# include <iostream>
# include <fstream>
# include <string>
# include <locale>
using namespace std;

/** Algorithm: Search for a given user’s rating for a particular book title, and return the rating the user gave for that book.
 * 1. Take all of the arguments passed into the function (see below)
 * 2. Iterate through the given username and change every latter to lowercase.
 * 3. Iterate through the given title and change every latter to lowercase.
 * 4. Iterate through every element in the users array, and change every letter of each element to lower case.
 * 5. Iterate through every element in the titles array, and change every letter of each element to lower case.
 * 6. Declare two boolean variables to represent the existence of the title and the user name.
 * 7. Declare two integer variables that will represent the index of the given title and given name in the arrays.
 * 8. Iterate through the given number of users and check if the current element in the users array is equal to given username.
 *      If yes, set the name index equal to the index that the element existed at, and set the user existence variable to true.
 * 9. Iterate through the given number of books and check if the current element in the titles array is equal to given title.
 *      If yes, set the title index equal to the index that the element existed at, and set the title existence variable to true.
 * 10. Check if the user existence variable and the title eixistence variable are both true.
 *      If yes, return the value in the ratings array corresponding to the position [name index][title index].
 * 11. if no, return -3.
 * Input parameters: a username (string), a book title (string), users array (string), titles array (string), ratings array (int), number of users (int), number of books (int).
 * Output (prints to screen): Nothing
 * Returns: -3 if either the given title or name do not exist in the given arrays, or the rating value corresponding to the index of [name][title]
 */ 
int getRating(string username,string bookTitle,string users[],string titles[],int ratings[][50],int numUsers,int numBooks){
    // iterate through the username and change it to all lowercase letters
    for (int i=0; i<username.length();i++){ // iterates through the length of the given username
        username[i] = tolower(username[i]); // changes each letter to lowercase
    }
    
    // iterate through the book title and change it to all lowercase letters
    for (int i=0; i<bookTitle.length();i++){ // iterates through the length of the given title
        bookTitle[i] = tolower(bookTitle[i]); // changes each letter to lowercase
    }
    
    // iterate through the users array and make each element all lowercase
    string name; // declares new variable to store the lowercase version of the array elements
    for (int i=0; i<numUsers;i++){ // iterates through the number of users passed through the function
        name = users[i]; // sets the name variable equal to the ith element of the users array
        for (int j=0;j<name.length();j++){ // iterates through the length of the name variable
            name[j] = tolower(name[j]); // changes each letter in name to lowercase
        }
        users[i] = name; // sets the ith element of the users array equal to the lower case name
    }

    // iterate through the titles array and make each element all lowercase
    string title; // declares new variable to store the lowercase version of the array elements
    for (int i=0; i<numBooks;i++){ // iterates through the number of books passed through the function
        title = titles[i]; // sets the title variable equal to the ith element of the titles array
        for (int j=0;j<title.length();j++){ // iterates through the length of the title variable
            title[j] = tolower(title[j]); // changes each letter in name to lowercase
        }
        titles[i] = title; // sets the ith element of the titles array equal to the lower case title
    }
    
    // declare variables to be tested and used below
    bool titleExist=false,userExist=false; // declares a boolean variable for the existence of the title and username
    int nameIdx,titleIdx; // declares variables for the name and title index to be able to access the proper rating
    
    // loop through names, save true or false, and save row index if name exists users in array
    for (int j=0; j<numUsers; j++){ // iterates through the number of users passed into the function
        if(users[j] == username){ // checks if the jth elements of the users array is equal to the username
            nameIdx = j; // sets the name index equal to the value of j 
            userExist = true; // sets the previously declared user existence variable equal to true
        }
    }
    
    // loop through titles, save true or false, and save column index if title exists in titles array
    for (int k=0; k<numBooks; k++){ // iterates through the number of books passed into the function
        if(titles[k] == bookTitle){ // checks if the jth elements of the titles array is equal to the title
            titleIdx = k; // sets the title index equal to the value of k
            titleExist = true; // sets the previously declared title existence variable equal to true
        }
    }
    
    // Checks if both the title and name exist in the arrays
    if(userExist && titleExist){ // checks if user existence and title existence are both true
        return ratings[nameIdx][titleIdx]; // returns the value in the ratings array at index [name index][title index]
    }
    else{ // if the title or the name doesn't exist in the given arrays
        return -3; // returns -3
    }
}


int main(){
    // Test 1
    // expected output
    // 4
    string users1[2] = {"User1","User2"}; // users array to be passed into function
    string titles1[3] = {"Title1","Title2","Title3"}; // titles array to be passed into function
    int ratings1[2][50]= {{1,4,2},{0,5,3}}; // ratings array to be passed into function
    cout << getRating("User1", "Title2",users1,titles1,ratings1,2,3) << endl; // first function call to getRating

    // Test 1
    // expected output
    // -3
    string users2[2] = {"Ralphie","Chip"}; // users array to be passed into function
    string titles2[3] = {"Sko","Buffs","CU"}; // titles array to be passed into function
    int ratings2[2][50]= {{4,2,3},{9,7,8}}; // ratings array to be passed into function
    cout << getRating("Ralphie", "Fight CU",users2,titles2,ratings2,2,3) << endl; // second function call to getRating
    
    // Test 1
    // expected output
    // 0 
    string users3[3] = {"Pete","Jake","Forrest"}; // users array to be passed into function
    string titles3[3] = {"Harry Potter","The Prince","The Education of Cyrus"}; // titles array to be passed into function
    int ratings3[3][50]= {{6,1,3},{9000,0,2},{4,5,6}}; // ratings array to be passed into function
    cout << getRating("Jake", "The Prince",users3,titles3,ratings3,3,3) << endl; // third function call to getRating
}