// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 7 - Problem # 7


# include <iostream>
# include <fstream>
# include "User.h"
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


/** Algorithm: Loads user ratings by reading a file (ratings.txt) and storing each rating with the corresponding person in a User array.
 * 1. Take the arguments passed in to the function: file name, array of users, number of users stored, users array size, and max columns.
 * 2. Check if the number of users is equal to the user array size.
 *      If yes, return -2.
 * 3. Create file stream for opening a file and open the file of given name.
 * 4. Check if the file opened successfully.
 *      If yes...
 *      Declare a new variable called line as an empty string, to be the basis for each line.
 *      Declare a new array that is length of max columns + 1 and will hold the values of each split line.
 *      Loop through the length of the new array (max columns + 1) and set each value equal to '0'.
 *      While there is still a line in the file to read...
 *          Check if the number of users is less than users array size.
 *              If yes, check if the current line read is not empty.
 *                  If yes...
 *                  Call the split function and split the current line on each comma, adding each element to the previously created new array.
 *                  Set the current user number index of the users list to be the first element in the current split array.
 *                  Loop from zero to the value of maximum columns.
 *                      Set the jth index of the user number row in the users array (rating) equal to the j+1 index of the split array as an integer.
 *                  Add one to the number of users.
 *      Return the number of users.
 * 5. If no, return -1.
 * Input parameters: file name (string), array of users (class User), number of users stored (int), users array size (int), max columns (int)
 * Output (prints to screen): nothing
 * Returns: -2 if the number of users stored is equal to the array size, -1 if the file unsucessfully opens, and the total number of users at the end if you are able to add ratings.
 */ 
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


int main(){
    // Test 1
    // expected output
    // Return: 10
    // cynthia
    // diane
    // joan
    // barbara
    // 4
    // 3
    // 1
    // 0
    // 3
    User users1[10]; 
    int numUsers1 = 0;
    int usersArrSize1 = 10;
    cout << "Return: " << readRatings("ratings.txt",users1,numUsers1,usersArrSize1,50) << endl; // first function call to readRatings
    cout << users1[0].getUsername() << endl;
    cout << users1[1].getUsername() << endl;
    cout << users1[2].getUsername() << endl;
    cout << users1[3].getUsername() << endl;
    cout << users1[0].getRatingAt(0) << endl;
    cout << users1[0].getRatingAt(1) << endl;
    cout << users1[0].getRatingAt(2) << endl;
    cout << users1[0].getRatingAt(3) << endl;
    cout << users1[0].getRatingAt(4) << endl;
    
    cout << "\n";
    
    // Test Case 2
    // expected output
    // Return: -2
    //
    User users2[3];
    int numUsers2 = 3;
    int usersArrSize2 = 3;
    // setting usernames for users array
    users2[0].setUsername("Donald Duck");
    users2[1].setUsername("Luke Skywalker");
    users2[2].setUsername("Aladdin");
    // setting ratigns for each username
    users2[0].setRatingAt(0,1);
    users2[0].setRatingAt(1,2);
    users2[0].setRatingAt(2,3);
    users2[1].setRatingAt(0,0);
    users2[1].setRatingAt(1,2);
    users2[1].setRatingAt(2,4);
    users2[2].setRatingAt(0,3);
    users2[2].setRatingAt(1,4);
    users2[2].setRatingAt(2,5);
    cout << "Return: " << readRatings("ratings.txt",users2,numUsers2,usersArrSize2,50) << endl; // second function call to readRatings
    // printing out the usernames, and their ratings at different indices
    cout << users2[0].getUsername() << endl;
    cout << users2[0].getRatingAt(0) << endl;
    cout << users2[0].getRatingAt(1) << endl;
    cout << users2[0].getRatingAt(2) << endl;
    cout << users2[1].getUsername() << endl;
    cout << users2[1].getRatingAt(0) << endl;
    cout << users2[1].getRatingAt(1) << endl;
    cout << users2[1].getRatingAt(2) << endl;
    cout << users2[2].getUsername() << endl;
    cout << users2[2].getRatingAt(0) << endl;
    cout << users2[2].getRatingAt(1) << endl;
    cout << users2[2].getRatingAt(2) << endl;
    
    return 0;
}