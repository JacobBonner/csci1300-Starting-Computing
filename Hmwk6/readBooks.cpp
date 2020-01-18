// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 6 - Problem # 5

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


/** Algorithm: Populates a pair of arrays with the titles and authors found in a text file.
 * 1. Takes the arguments passed into the function: file name, title array, author array, number of books stored, and the array size.
 * 2. Checks if the number of books stored is equal to the size.
 *      If yes, return -2.
 * 3. Creates a variable for opening a file and and opens the given file by name.
 * 4. Checks if the file successfully opened.
 *      If yes...
 *      Declare a new variable for each line and set it equal to an empty string.
 *      Declare a new array of type string and size 2 to hold the two substrings of each split line.
 *      While there is still a line in the file to read...
 *          Check if the current number of books stored is less than the size.
 *              If yes, check if the line is not empty.
 *                  If yes...
 *                  Call the split function on the previous array of type string and size 2, with a delimeter of ','.
 *                  Set the index of authors corresponding to the number of books stored equal to the first element of the array used in split.
 *                  Set the index of titles corresponding to the number of books stored equal to the second element of the array used in split.
 *                  Add one to the number of books stored.
 *                  Set both elements of the array used in the split function equal to empty strings.
 *      Return the value for the number of books stored.
 * 5. If no, return -1.
* Input parameters: fileName (string), titles (array of strings), authors (array of strings), numBookStored (int), size (int)
* Output (prints to screen): nothing
* Returns: -1 if the file is not opened successfully, -2 if the numBookStored is equal to size, or the number of books added to the array
*/
int readBooks(string fileName,string titles[],string authors[],int numBookStored,int size){
    if (numBookStored==size){ // checks if the number of books stored is equal to the size
        return -2; // returns the value -2
    }
    ifstream myfile; // creates variable for reading in the file
    myfile.open(fileName); // opens the file
    if(myfile.is_open()){ // checks if the file opened correctly
        string line = ""; // declares new variable line as empty string
        string splitArray[2]; // declares new array splitArray as size 2
        while (getline(myfile,line)){ // checks if there is still a line to read in the file
            if(numBookStored<size){ // checks if the number of books stored is less than the size
                if(!(line.empty())){ // checks if the line is not empty
                    split(line,',',splitArray,2); // calls the split function
                    authors[numBookStored] = splitArray[0]; // sets the index value of authors equal to the 0th element of splitArray
                    titles[numBookStored] = splitArray[1]; // sets the index value of titles equal to the index 1 element of splitArray
                    numBookStored++; // adds one to the book counter
                    splitArray[0]=""; // sets the 0th element of splitArray equal to an empty string
                    splitArray[1]=""; // sets the index 1 element of splitArray equal to an empty string
                }
            }
        }
        return numBookStored; // returns the number of books stored in the array
    }
    else{
        return -1; // returns -1
    }
}


int main(){
    // Test 1
    // expected output
    // 3
    // Book 1 by Author 1
    // Book 2 by Author 2
    // The Hitchhiker's Guide To The Galaxy by Douglas Adams
    string titles1[3] = {"Book 1","Book 2"};
    string authors1[3] = {"Author 1","Author 2"};
    cout << readBooks("books.txt",titles1,authors1,2,3) << endl; // first function call to readBooks
    for (int i =0;i<3;i++){ // prints out each title and author in the arrays used in this function calling
        cout << titles1[i] << " by " << authors1[i] << endl;
    }
    
    cout << "\n"; // prints a new line
    
    // Test 2
    // expected output
    // -2
    // RandomTitle1 by RandomAuthor1
    // RandomTitle2 by RandomAuthor2
    // RandomTitle3 by RandomAuthor3
    string titles2[3] = {"RandomTitle1", "RandomTitle2", "RandomTitle3"};
    string authors2[3] = {"RandomAuthor1", "RandomAuthor2", "RandomAuthor3"};
    cout << readBooks("books.txt",titles2,authors2,3,3) << endl; // second function call to readBooks
    for (int i =0;i<3;i++){ // prints out each title and author in the arrays used in this function calling
        cout << titles2[i] << " by " << authors2[i] << endl;
    }
    
    cout << "\n"; // prints a new line
    
    // Test 3
    // expected output
    // 5
    // The Prince by Niccolo Machiavelli
    // The Education of Cyrus by Xenophon
    // The Wright Brothers by David McCullough
    // Hamlet by William Shakespeare
    // The Odyssey by Homer
    string titles3[10];
    string authors3[10];
    cout << readBooks("myBooks.txt",titles3,authors3,0,10) << endl; // third function call to readBooks
    for (int i =0;i<5;i++){ // prints out each title and author in the arrays used in this function calling
        cout << titles3[i] << " by " << authors3[i] << endl;
    }
    
    return 0; // returns 0
}