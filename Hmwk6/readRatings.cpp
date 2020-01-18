// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 6 - Problem # 7

# include <iostream>
# include <fstream>
using namespace std;

// See problem 3 for algorithm
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


/** Algorithm: Loads user ratings by reading a file (ratings.txt) and storing each rating with the corresponding person in different arrays.
 * 1. Take the arguments passed in to the function: file name, array of users, array of ratings, number of users, max rows, and max columns.
 * 2. Check if the number of users is equal to the maximum number of rows.
 *      If yes, return -2.
 * 3. Create file stream for opening a file and open the file of given name.
 * 4. Check if theh file opened successfully.
 *      If yes...
 *      Declare a new variable called line as an empty string, to be the basis for each line
 *      Declare a new array that is length of max columns + 1 and will hold the values of each split line.
 *      Loop through the length of the new array (max columns + 1) and set each value equal to '0'.
 *      While there is still a line in the file to read...
 *          Check if the number of users is less than the maximum number of rows.
 *              If yes, check if the current line read is not empty.
 *                  If yes...
 *                  Call the split function and split the current line on each comma, adding each element to the previously created new array.
 *                  Set the current user number index of the users list to be the first element in the current split array.
 *                  Loop from zero to the value of maximum columns.
 *                      Set the jth index of the user number row in the ratings array equal to the j+1 index of the split array as an integer.
 *                  Add one to the number of users.
 *      Return the number of users.
 * 5. If no, return -1.
 * Input parameters: file name (string), array of users (string), array of ratings (int), number of users (int), max rows (int), max columns (int)
 * Output (prints to screen): nothing
 * Returns: -2 if the number of rows is equal to the number of users, -1 if the file unsucessfully opens, and the total number of users at the end if you are able to add ratings.
 */ 
int readRatings(string fileName,string users[],int ratings[][50],int numUsers,int maxRows,int maxColumns){
    if (numUsers == maxRows){ // checks if the number of users is equal to the max number of rows
        return -2; // returns -2
    }
    ifstream myfile; // creates variable to enable file streaming
    myfile.open(fileName); // opens file with given name
    if(myfile.is_open()){ // checks if the file successfully opened
        string line = ""; // declares each line as an empty string to begin with
        string newArray[maxColumns+1]; // creates an array to be filled with the split pieces of each line
        for (int k=0;k<maxColumns+1;k++){ // loops through the length of the new array
            newArray[k]='0'; // sets each element in the array equal to the character '0'
        }
        while(getline(myfile,line)){ // while there are still lines to be read in the opened file
            if (numUsers<maxRows){ // chekcs if the number of users is less than the max number of rows
                if (!(line.empty())){ // checks if the current line is not empty
                    split(line,',',newArray,maxColumns+1);// splits the current line into an array
                    users[numUsers] = newArray[0]; // sets the numUsers value in users equal to the first value of newArray
                    for (int j=0;j<maxColumns;j++){ // loops through the length of the array (number of columns)
                        ratings[numUsers][j] = stoi(newArray[j+1]); // sets the jth value in the numUsers row of ratings equal to the corresponding value in newArray
                    }
                    numUsers++; // adds one to the number of users
                }
            }
        }  
        return numUsers; // returns the number of users after everything is complete
    }
    else{
        return -1; // returns -1
    }
}


int main(){
    // Test 1
    // expected output
    // return: 10
    string users[10] = {}; // Lines 85-89 are declaring variables to be passed into the first calling of readRatings
    int ratings[10][50] = {{0}};
    int numUsers = 0;
    int maxRows = 10;
    int maxColumns = 50;
    cout << readRatings("ratings.txt",users,ratings,numUsers,maxRows,maxColumns) << endl; // first function call to readRatings

    // Test 2
    // expected output
    // return: -1
    string users2[] = {}; // Lines 95-99 are declaring variables to be passed into the second calling of readRatings
    int ratings2[10][50] = {{0}};
    int numUsers2 = 0;
    int maxRows2 = 10;
    int maxColumns2 = 50;
    cout << readRatings("skobuffs.txt",users2,ratings2,numUsers2,maxRows2,maxColumns2) << endl; // second function call to readRatings
    
    // Test 3
    // expected output
    // return: -2
    string users3[4] = {"Ninja", "Myth", "Sphyer", "Daequan"}; // Lines 105-114 are declaring variables to be passed into the third calling of readRatings
    int ratings3[4][50] = {
    {0,1,2,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,4,5,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {3,1,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };
    int numUsers3 = 4;
    int maxRows3 = 4;
    int maxColumns3 = 50;
    cout << readRatings("ratings.txt",users3,ratings3,numUsers3,maxRows3,maxColumns3) << endl; // third function call to readRatings

    return 0;
}