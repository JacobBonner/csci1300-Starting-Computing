// CSCI1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 - Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Hmwk 6 Problem 9 (HW6)

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
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



/* readBooks function
 * the function reads a book file from the text into book and author arrays
 *
 * @param: fileName, string, name of the book file
 * @param: titles, string array, titles of the books are stored
 * @param: authors, string array, authors of the books are stored
 * @param: numBookStored, int, the number of books currently stored in the arrays
 * @param: size, int, the size of the arrays (titles and authors)
 * @return: the number of books read into the array (number of lines in the file)
 *          or appropriate return code
 */
int readBooks(string fileName,string titles[],string authors[],int numBookStored,int size){
    if (numBookStored==size){
        return -2;
    }
    
    ifstream myfile;
    myfile.open(fileName);
    if(myfile.is_open()){
        string line = "";
        string tempArray[2];
        while (getline(myfile,line)){
            if(numBookStored<size){
                if(!(line.empty())){
                    split(line,',',tempArray,2);
                    authors[numBookStored] = tempArray[0];
                    titles[numBookStored] = tempArray[1];
                    numBookStored++;
                    tempArray[0]="";
                    tempArray[1]="";
                }
            }
        }
        return numBookStored;
    }
    else{
        return -1;
    }
}



/* readRatings function
 * Read the user ratings from the file and store them
 * into users array and ratings array
 *
 * @param: fileName, string, the name of user rating file
 * @param: users, string array, the array of users
 * @param: ratings, int 2D array, the ratings of each user
 *         row i is user, and column j is a book.
 *         ratings[i][j] is the user_i rated book_j
 * @param: numUsers, int, the number of users currently stored in the array
 * @param: sizeRow, int, the number of rows in the 2D array (capacity)
 * @param: sizeCol, int, the number of column in the 2D array (capacity)
 * @return: the number of users in total or appropriate return code
 */
int readRatings(string fileName,string users[],int ratings[][50],int numUsers,int maxRows,int maxColumns){
    if (numUsers == maxRows){
        return -2;
    }
    ifstream myfile;
    myfile.open(fileName);
    if(myfile.is_open()){
        string line = "";
        string newArray[maxColumns+1];
        for (int k=0;k<maxColumns+1;k++){
            newArray[k]='0';
        }
        while(getline(myfile,line)){
            if (numUsers<maxRows){
                if (!(line.empty())){
                    split(line,',',newArray,maxColumns+1);
                    users[numUsers] = newArray[0];
                    for (int j=0;j<maxColumns;j++){
                        ratings[numUsers][j] = stoi(newArray[j+1]);
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



/* printBookList function (helper function)
 * print the list of books in the array
 *
 * @param: titles, string, the title of books
 * @param: authors, string, the author of books
 * @param: numBooks, int, the number of books
 * @return: void
 */
void printAllBooks(string titles[],string authors[],int numBooks){
    if (numBooks<=0){
        cout << "No books are stored" << endl;
    }
    else{
        cout << "Here is a list of books" << endl;
        for (int i=0;i<numBooks;i++){
            cout << titles[i] << " by " << authors[i] << endl;
        }
    }
}



/* getRating function 
 * Search for a rating given the user's name and 
 * book's title and return that value
 *
 * @param: string, username 
 * @param: string, title of the book 
 * @param: string, array, user names
 * @param: string, array, titles
 * @param: 2D int array, list of ratings for each user
 * @param: int, number of users whose names/ratings are currently 
 *         stored in the string array/2D array respectively
 * @param: int, number of books whose titles/ratings are currently 
 *         stored in the string array/2D array respectively
 * @return: int, users's rating value or appropriate return code
 */
int getRating(string username,string bookTitle,string users[],string titles[],int ratings[][50],int numUsers,int numBooks){
    for (int i=0; i<username.length();i++){
        username[i] = tolower(username[i]);
    }
    
    for (int i=0; i<bookTitle.length();i++){
        bookTitle[i] = tolower(bookTitle[i]);
    }
    
    string name;
    for (int i=0; i<numUsers;i++){
        name = users[i];
        for (int j=0;j<name.length();j++){
            name[j] = tolower(name[j]);
        }
        users[i] = name;
    }
    
    string title;
    for (int i=0; i<numBooks;i++){
        title = titles[i];
        for (int j=0;j<title.length();j++){
            title[j] = tolower(title[j]);
        }
        titles[i] = title;
    }
    
    bool titleExist=false,userExist=false;
    int nameIdx,titleIdx;
    
    for (int j=0; j<numUsers; j++){
        if(users[j] == username){
            nameIdx = j;
            userExist = true;
        }
    }
    
    for (int k=0; k<numBooks; k++){
        if(titles[k] == bookTitle){
            titleIdx = k;
            titleExist = true;
        }
    }
    
    if(userExist && titleExist){
        return ratings[nameIdx][titleIdx];
    }
    else{
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
    int numBooks = 0;
    int numUsers = 0;

    // Use the these values to declare your
    // titles, authors, users and ratings arrays
    const static int  userArrSize = 100;
    const static int  bookArrSize = 50;


    // delaring arrays and variables to store return values
    int userRating; // integer for the value of a user's rating
    string titles[bookArrSize]; // array of book titles
    string authors[bookArrSize]; // array of authors
    string users[userArrSize]; // array of users
    int ratings[userArrSize][bookArrSize]; // array of user ratings
    
    
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
                numBooks = readBooks(bookFileName,titles,authors,numBooks,bookArrSize);
                
                // testing conditions for differnt outputs
                if(numBooks == -1){
                    cout << "No books saved to the database." << endl;
                    numBooks = 0;
                }
                else if(numBooks == -2){
                    cout << "Database is already full. No books were added." << endl;
                    numBooks = 50;
                }
                else if(numBooks == bookArrSize){
                    cout << "Database is full. Some books may have not been added." << endl;
                }
                else{
                    cout << "Total books in the database: " << numBooks << endl;
                }
                
                cout << endl;
                break;


            case 2:
                // read ratings file
                cout << "Enter a user file name:" << endl;
                getline(cin, userFileName);
                
                // calling readRatings function
                numUsers = readRatings(userFileName,users,ratings,numUsers,userArrSize,bookArrSize);
                
                // testing conditions for different outputs
                if(numUsers == -1){
                    cout << "No users saved to the database." << endl;
                    numUsers = 0;
                }
                else if(numUsers == -2){
                    cout << "Database is already full. No users were added." << endl;
                    numUsers = 100;
                }
                else if(numUsers == userArrSize){
                    cout << "Database is full. Some users may have not been added." << endl;
                }
                else{
                    cout << "Total users in the database: " << numUsers << endl;
                }
                
                cout << endl;
                break;


            case 3:

                // print the list of the books
                
                // calls the printAllBooks function
                printAllBooks(titles,authors,numBooks);

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
                userRating = getRating(userName,bookTitle,users,titles,ratings,numUsers,numBooks);
                
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