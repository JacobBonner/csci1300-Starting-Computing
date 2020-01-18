// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Project 2 - Problem # 0 - 10


# include <iostream>
# include <fstream>
# include <locale>
# include "Library.h"
# include <cmath>
using namespace std;


Library :: Library() // constructor
{
    numBooks = 0;
    numUsers = 0;
}


int Library :: getSizeBook()
{
    return sizeBook;
}


int Library :: getSizeUser()
{
    return sizeUser;
}


int Library :: getNumBooks()
{
    return numBooks;
}


int Library :: getNumUsers()
{
    return numUsers;
}


// Splits a given string on a specified delimeter
int Library :: split(string toSplit,char delimeter,string splitArray[],int length)
{
    if (toSplit.length() == 0) { // checks if the length of the string is zero
        return 0; 
    }
    string word = ""; 
    int j=0,k=0; 
    toSplit = toSplit + delimeter; 
    for (int i = 0; i < toSplit.length(); i++) // loops through the entire string
    {
        if (toSplit[i] == delimeter) // checks if the current element in the string is equal to the delimeter
        {
        	if (word.length() == 0) continue; // checks if the length of the word is zero
            splitArray[k] = word; 
            j++; 
            word = ""; 
            k++; 
        } else {
            word = word + toSplit[i]; 
        }
    }
    
    if (k>length){ // checks if k is greater than the length variable passed into the function
        return -1; 
    }
    
    return j;
}


/** Algorithm: Populates an array of Planet class with books and authors, and returns the number of books stored.
 * 1. Checks if the number of books stored is equal to the constant sizeBook variable.
 *      If yes, return -2.
 * 4. Checks if the file successfully opened.
 *      If yes...
 *      Declare a new variable for each line and set it equal to an empty string.
 *      Declare a new array of type string and size 2 to hold the two substrings of each split line.
 *      While there is still a line in the file to read...
 *          Check if the current number of books stored is less than the book size.
 *              If yes, check if the line is not empty.
 *                  If yes...
 *                  Call the split function on the previous array of type string and size 2, with a delimeter of ','.
 *                  Call the setAuthor() function of class Book, that sets the author equal to the first element in the split array.
 *                  Call the setTitle() function of class Book, that sets the title equal to the second element in the split array.                
 *                  Add one to the number of books.
 *                  Set both elements of the array used in the split function equal to empty strings.
 *      Return the value for the number of books.
 * 5. If no, return -1.
* Input parameters: fileName (string)
* Output (prints to screen): nothing
* Returns: -1 if the file is not opened successfully, -2 if the numBooks is equal to sizeBook, or the number of books in the books array
*/
int Library :: readBooks(string fileName) 
{
    if (numBooks==sizeBook){ // checks if the number of books stored is equal to the size
        return -2;
    }
    ifstream myfile; 
    myfile.open(fileName); 
    if(myfile.is_open()){ // checks if the file opened correctly
        string line = ""; 
        string splitArray[2]; 
        while (getline(myfile,line)){ 
            if(numBooks<sizeBook){ // checks if the number of books stored is less than the size
                if(!(line.empty())){ 
                    split(line,',',splitArray,2); 
                    books[numBooks].setAuthor(splitArray[0]); 
                    books[numBooks].setTitle(splitArray[1]) ;
                    numBooks++; 
                    splitArray[0]=""; 
                    splitArray[1]=""; 
                }
            }
        }
        return numBooks; 
    }
    else{
        return -1; 
    }
}


/**
* Algorithm: Prints out the contents of a library (books array)
* 1. Prints out "Here is a list of books".
* 2. Loops through the number of books stored and prints out: title " by " author.
* Input parameters: none
* Output (prints to screen): "Here is a list of books" followed each book and its author
* Returns: nothing
*/
void Library :: printAllBooks() 
{
    cout << "Here is a list of books" << endl; 
    for (int i=0;i<numBooks;i++){ // loops through the number of books 
        cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
    }
}


/** Algorithm: Loads user ratings by reading a file (ratings.txt) and storing each rating with the corresponding person in a User array.
 * 1. Take the argument passed in to the function: file name.
 * 2. Check if the number of users is equal to the size user variable.
 *      If yes, return -2.
 * 3. Check if the file opened successfully.
 *      If yes...
 *      Declare a new variable called line as an empty string, to be the basis for each line.
 *      Declare a new array that is length of book size + 1 and will hold the values of each split line.
 *      Loop through the length of the new array (size book + 1) and set each value equal to '0'.
 *      While there is still a line in the file to read...
 *          Check if the number of users is less than size user variable.
 *              If yes, check if the current line read is not empty.
 *                  If yes...
 *                  Call the split function and split the current line on each comma, adding each element to the previously created new array.
 *                  Set the current user number index of the users list to be the first element in the current split array.
 *                  Loop from zero to the value of maximum columns.
 *                      Set the jth index of the user number row in the users array (rating) equal to the j+1 index of the split array as an integer.
 *                  Add one to the number of users.
 *      Return the number of users.
 * 4. If no, return -1.
 * Input parameters: file name (string)
 * Output (prints to screen): nothing
 * Returns: -2 if the number of users stored is equal to the user size, -1 if the file unsucessfully opens, and the total number of users at the end if you are able to add ratings.
 */ 
int Library :: readRatings(string fileName)
{
    if (numUsers >= sizeUser){ // checks if the number of users is equal to the max number of rows
        return -2; 
    }
    ifstream myfile; 
    myfile.open(fileName);
    if(myfile.is_open()){ // checks if the file successfully opened
        string line = ""; 
        string newArray[sizeBook+1]; 
        for (int k=0;k<sizeBook+1;k++){ 
            newArray[k]='0';
        }
        while(getline(myfile,line)){ 
            if (numUsers<sizeUser){ 
                if (!(line.empty())){
                    split(line,',',newArray,sizeBook+1);
                    users[numUsers].setUsername(newArray[0]);
                    for (int j=0;j<sizeBook;j++){ 
                        users[numUsers].setRatingAt(j,stoi(newArray[j+1])); // converts ratings to integer and assigns to each index
                    }
                    numUsers++; 
                }
            }
        }  
        return numUsers; 
    }
    else{
        return -1; 
    }
}


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
 * Input parameters: a username (string), a book title (string)
 * Output (prints to screen): Nothing
 * Returns: -3 if either the given title or name do not exist in the given arrays, or the rating value corresponding to the index of [name][title]
 */ 
int Library :: getRating(string username,string bookTitle) 
{
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
    for (int j=0; j<numUsers; j++){ 
        if(users[j].getUsername() == username){ 
            nameIdx = j;
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


/**
* Algorithm: Determines how many books a particular user has read and reviewed.
* 1. Convert each to lower case: the given username, and every username in the users array.
* 2. Check if the username exist in the users array.
* 3. If yes, loop through the ratings and each time the rating is greater than zero, add one to the number of ratings.
*       Return the number of ratings after looping through every rating.
* 4. If no, return -3.
* Input parameters: a user name (string)
* Output (prints to screen): nothing
* Returns: the number of ratings (int), or -3 if the given user name has not read and reviewed any books.
*/
int Library :: getCountReadBooks(string username) 
{
    int numberOfRatings = 0;
    
    for (int i=0; i<username.length();i++){ // converts username to lowercase
        username[i] = tolower(username[i]);
    }
    
    string name; 
    for (int i=0; i<numUsers;i++){ // converts each username in users array to lowercase
        name = users[i].getUsername(); 
        for (int j=0;j<name.length();j++){ 
            name[j] = tolower(name[j]);
        }
        users[i].setUsername(name); // sets the ith element of the users array equal to the lower case name
    }
    
    for (int i=0;i<sizeUser;i++){ // first checks that the username exists, and then adds to the number of ratings for each rating that is greater than zero
        if(users[i].getUsername()==username){
            for (int j=0;j<sizeUser;j++){
                if(users[i].getRatingAt(j)>0){
                    numberOfRatings++;
                }
            }
            return numberOfRatings;
        }
    }
    return -3; // returns this if the username does not exist in the database
}


/**
* Algorithm: Prints all books a user has provided ratings for.
* 1. Convert the following to lowercase: the given username, every username in the users array.
* 2. Check if the username exist in the user array and save the index at which the username is found.
*       If yes, check if the number of books the user has read is greater than zero.
*           If yes, print out every book title and corresponding rating for each book the user rated.
*       If no, print out "<username> has not rated any books yet."
* 3. If no, print out "<username> does not exist".
* Input parameters: a username (string)
* Output (prints to screen): One of three options...
* 1. Prints " <username> does not exist" if the username is not found in the database
* 2. Prints "<username> has not rated any books yet" if the user exists but has no ratings.
* 3. Prints "Here are the books that <username> rated", followed by each title and rating for each book they rated.
* Returns: nothing
*/
void Library :: viewRatings(string username) 
{
    bool flag = false;
    int useridx,ratingNumUser;
    string name,lowerName = username;
    
    for(int i=0;i<lowerName.length();i++){
        lowerName[i] = tolower(lowerName[i]);
    }
    
    for (int i=0; i<numUsers;i++){ 
        name = users[i].getUsername(); 
        for (int j=0;j<name.length();j++){ 
            name[j] = tolower(name[j]);
        }
        users[i].setUsername(name);
    }
    
    for (int i=0;i<sizeUser;i++){ // checks if the user exists, finds the number of books they've rated, and saves the user's index
        if(users[i].getUsername() == lowerName){
            ratingNumUser = getCountReadBooks(username);
            flag = true;
            useridx = i;
        }
    }
    
    if (flag){ // if the user exists
        if(ratingNumUser > 0){ // prints out each book and corresponding rating for each rated book by the given username
            cout << "Here are the books that " << username << " rated" << endl;
            for (int j=0;j<sizeBook;j++){
                if(users[useridx].getRatingAt(j) != 0){
                    cout << "Title : " << books[j].getTitle() << endl;
                    cout << "Rating : " << users[useridx].getRatingAt(j) << endl;
                    cout << "-----" << endl;
                }
            }
        }
        else{ // if no books have been rated
            cout << username << " has not rated any books yet." << endl;
        }
    }
    else{ // if the user does not exist
        cout << username << " does not exist." << endl;
    }
}


/**
* Algorithm: Calculates the average rating for a given book.
* 1. Convert the given title and all titles in the books array to lowercase.
* 2. Check if the book title exists in the books array.
*       If yes, loop through every rating for the given book and calculate the sum of all ratings, and track the number of ratings.
*       If there are no ratings, return 0.
*       Otherwise, calculate the average rating (sum / # ratings) and return the value.
* 3. If no, return -3.
* Input parameters: a book title (string)
* Output (prints to screen): nothing
* Returns: 0 if there are no ratings for a book, the average rating for the given book if there are ratings, or -3 if the title is not found.
*/
double Library :: calcAvgRating(string bookTitle) 
{   
    string title;
    bool flag = false;
    int ratingCount = 0,titleidx;
    double avg,ratingTot = 0;
    
    for (int i=0;i<bookTitle.length();i++){ // converts to lowercase
        bookTitle[i] = tolower(bookTitle[i]);
    }
    
    for (int j=0;j<sizeBook;j++){ // converts to lowercase
        title = books[j].getTitle();
        for (int k=0;k<title.length();k++){
            title[k] = tolower(title[k]);
        }
        books[j].setTitle(title);
    }
    
    for (int l=0;l<sizeBook;l++){ // checks if the book title exist in the database
        if(books[l].getTitle() == bookTitle){
            flag = true;
            titleidx = l;
        }
    }
    
    if(flag){ // if the title exists
        for (int i=0;i<sizeUser;i++){ // calculates the sum of all ratings for the given title, and counts the number of ratings
            if(users[i].getRatingAt(titleidx)>0){
                ratingTot+=users[i].getRatingAt(titleidx);
                ratingCount++;
            }
        }
        if (ratingCount == 0){ // if there are no ratings
            return 0;
        }
        else{ // calculates mean if there are ratings
            avg = ratingTot / ratingCount; 
            return avg;
        }
    }
    else{ // if the title does not exist
        return -3;
    }
}


/**
* Algorithm: Adds a new user to the database.
* 1. Check if the number of users is equal to the size of the users array, and return -2 if yes.
* 2. Convert the given username and every username in the users array to lowercase.
* 3. Check if the username already exists in the array.
*       If yes, return 0.
* 4. If no, set the empty index user equal to the given username, set every rating equal to zero, add one to the total number of users, and return 1.
* Input parameters: a username (string)
* Output (prints to screen): nothing
* Returns: 0 if the given username already exists in the users array, -2 if the number of users is equal to the user arry size, or 1 if the user was successfully added.
*/
int Library :: addUser(string username) 
{
    if (numUsers == sizeUser){ // if there are the max number of users already
        return -2;
    }
    
    string lowerName = username;
    for(int i=0;i<lowerName.length();i++){ // converts to lowercase
        lowerName[i] = tolower(lowerName[i]);
    }
    
    string tempUsers[sizeUser], userName = ""; // converts to lowercase and checks if the username is already in the array
    bool flag = false;
    for (int j=0;j<sizeUser;j++){
        tempUsers[j] = users[j].getUsername();
        userName = tempUsers[j];
        for (int k=0;k<userName.length();k++){
            userName[k] = tolower(userName[k]);
        }
        if (lowerName == userName){
            flag = true;
        }
    }
    
    if (flag){ // if the username already exists in the array
        return 0;
    }
    else{ 
        for (int i=0;i<sizeUser;i++){ // sets the username to the given username and sets the ratings equal to zero
            if (users[i].getUsername() == ""){
                users[i].setUsername(username);
                for (int j=0;j<sizeBook;j++){
                    users[i].setRatingAt(j,0);
                }
                numUsers++;
                return 1;
            }
        }
    }
}


/**
* Algorithm: Updates the rating of the given book for the given user.
* 1. Convert the following to lowercase: the given username, the given title, every title in the books array, every username in the users array. 
* 2. Check if the title and the username exist in the database.
* 3. If the rating is invalid (grater than 5 or less than 0), return -4.
* 4. If the title and user both exist, set the rating for the given book from the given user equal to the given rating. Return 1.
* 5. If either the title or the username do not exist (or both), return -3.
* Input parameters: the name of a file (string)
* Output (prints to screen): nothing
* Returns: -3 if the username or book does not exist, 1 if the rating is succesfully updated, or -4 if the ratings is invalid.
*/
int Library :: checkOutBook(string username,string bookTitle,int newRating)
{
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
    for (int i=0; i<sizeUser;i++){ 
        name = users[i].getUsername(); 
        for (int j=0;j<name.length();j++){ 
            name[j] = tolower(name[j]);
        }
        users[i].setUsername(name); // sets the ith element of the users array equal to the lower case name
    }

    // iterates through the books array and makes each title element all lowercase
    string title, tempbooks[sizeBook]; 
    for (int i=0; i<sizeBook;i++){ 
        title = books[i].getTitle();
        for (int j=0;j<title.length();j++){
            title[j] = tolower(title[j]); 
        }
        tempbooks[i] = title; 
    }
    
    // declare variables to be tested and used below
    bool titleExist=false,userExist=false; 
    int nameIdx,titleIdx; 
    
    // loop through names, save true or false, and save row index if name exists users in array
    for (int j=0; j<sizeUser; j++){ 
        if(users[j].getUsername() == username){ 
            nameIdx = j;
            userExist = true; // sets the previously declared user existence variable equal to true
        }
    }
    
    // loop through books, saves true or false, and saves column index if title exists in books array
    for (int k=0; k<sizeBook; k++){ 
        if(tempbooks[k] == bookTitle){ 
            titleIdx = k; 
            titleExist = true; 
        }
    }
    
    if (newRating < 0 || newRating > 5){ // if the rating is invalid
        return -4;
    }
    if (titleExist && userExist){ // if the username and title both exist
        users[nameIdx].setRatingAt(titleIdx,newRating);
        return 1;
    }
    else{
        return -3; // if the username and/or the title does not exist
    }
    
}


/**
* Algorithm: Recommend book titles to a user, based on the book ratings of another user who likes similar books.
* 1. Convert to lowercase: the given username and every username in the users array.
* 2. Check if the username exists in the data base.
* 3. For every user in the users array...
*       Check if the number of books they have read is greater than zero.
*           If yes, calculate the sum of squared differences for the given user and each other user in the array.
*           Find the smallest sum of squared differences and save the index. (finds the most similar user)
* 4. For each book in the books array...
*       Count how many books the given user has not rated, but that the most similar user has rated greater than 2.
* 5. Print out the list of recommendations, which is whenever a book has not been rated by the given user, and has a rating greater than 2 for the most similar user.
*       A maximum of 5 recommendations.
* 6. If there are no recommendations, print out "There are no recommendations for <username> at present."
* 7. If the user does not exist, print "<username> does nto exist."
* Input parameters: a username (string)
* Output (prints to screen): One of three options...
* 1. Print "<username> does not exist" if the username is not found.
* 2. Print "There are no recommendations for <username> at present" if there are no books to recommend.
* 3. Print "Here is the list of recommendations" followed by each recommended title and author.
* Returns: nothing
*/
void Library :: getRecommendations(string username)
{
    string name,lowerName = username;
    bool userExist = false;
    int nameIdx,simIndex;
    int userRatingTot=0,counter=0,counter2=0;
    int SSD = 0,minSSD = 1000;
    
    for(int i=0;i<lowerName.length();i++){ // converts to lowercase
        lowerName[i] = tolower(lowerName[i]);
    }
    
    for (int i=0; i<numUsers;i++){ // converts to lowercase
        name = users[i].getUsername(); 
        for (int j=0;j<name.length();j++){ 
            name[j] = tolower(name[j]);
        }
        users[i].setUsername(name);
    }
    
    for (int j=0; j<numUsers; j++){ // checks if the username exists
        if(users[j].getUsername() == lowerName){ 
            nameIdx = j;
            userExist = true;
        }
    }
    
    if (userExist){ // if the username exists
        for (int i=0;i<sizeUser;i++){
            if (getCountReadBooks(users[i].getUsername()) > 0){ // if the number of books read for the current user is greater than zero
                for(int j=0;j<sizeBook;j++){
                    SSD += pow(users[nameIdx].getRatingAt(j) - users[i].getRatingAt(j),2); // calculates the sum of squared differences for each user and the given user
                }
            
                if(SSD < minSSD && SSD!=0){ // checks if the current SSD is less than the current minimum, and not equal to zero
                    minSSD = SSD;
                    simIndex = i;
                }
                SSD = 0; // resets SSD
            }
        }
        
        for (int i=0;i<sizeBook;i++){ // counts how many books can be recommended
            if (counter<6){
                if (users[simIndex].getRatingAt(i)>2 && users[nameIdx].getRatingAt(i)==0){
                    counter++;
                }
            }    
        }
        
        if(counter>0){ // prints out the list of recommedations
            cout << "Here is the list of recommendations" << endl;
            for (int i=0;i<sizeBook;i++){
                if(counter2<5){
                    if (users[simIndex].getRatingAt(i)>2 && users[nameIdx].getRatingAt(i)==0){
                        cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
                        counter2++;
                    }
                }    
            }
        }
        else{ // if there are no recommendations
            cout << "There are no recommendations for " << username << " at present." << endl;
        }
    }
    
    else{ // if the user does not exist
        cout << username << " does not exist." << endl;
    }
}