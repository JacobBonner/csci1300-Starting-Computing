// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 6 - Problem # 4

# include <iostream>
# include <fstream>
# include <string>
using namespace std;

/** Algorithm: Reads from a text file and stores its contents in an array.
 * 1. Takes the three parameters passed into the function: file name, array, and length.
 * 2. Opens the file corresponding to the given name.
 * 3. Checks if the file successfully opened.
 *      If yes...
 *          Declare a new variable called line to represent each lien of the file (string).
 *          Declare new variable to be the counter of how many integers there are (int) and set it equal to zero.
 *          While there is still a line to be read from the file.
 *              Checks if the line is not empty.
 *                  If yes...
 *                      Check if the counter variable is less than the given length of the array.
 *                          If yes...
 *                              Set the index of the array corresponding to the counter variable equal to the current line turned into an integer.
 *                              Add one to the counter variable.
 *          Return the value of the counter variable.
 * 4. If no, return -1.
 * 5. Close the file.
* Input parameters: A file name (string), an array of given length (int), the length of the array (int)
* Output (prints to screen): Nothing
* Returns: The number of integers added to the array, or -1 if the file does not exist.
*/
int getLinesFromFile(string fileName, int arr[],int length){
    ifstream myfile; // creates an output file stream
    myfile.open(fileName); // opens the file with the given name
    if (myfile.is_open()){ // checks if the file successfully opened
        string line = ""; // declares new variable line as an empty string
        int j=0; // declares new counter variable j as 0
        while (getline(myfile, line)) { // checks if there is still a line to read in the file
            if (!(line.empty())){ // checks if the line is not empty
                if (j<length){ // checks if the value of j is less than the given length of the array
                    arr[j] = stoi(line); // sets the jth index of the array equal to the current line transformed into an integer
                    j++; // adds one to j
                }
            }
        }
        return j; // returns the value of j
    } 
    else {
        return -1; // returns -1
    }
    
    myfile.close(); // closes the file that was opened
}


int main(){
    // Test 1
    // expected output
    // 1
    // 5
    // 23
    // 18
    int arrOne[4]; // declares new array to be passed in to function
    cout << getLinesFromFile("file1.txt",arrOne,4) << endl; // first function call to getLinesFromFile
    
    for (int i=0;i<4;i++){ // loops through the length of the arrOne
        cout << arrOne[i] << endl; // prints out the current element of arrOne
    }
    cout << "\n"; // prints out a new line
    
    // Test 2
    // expected output
    // 10
    // 20
    // 30
    // 40
    int arrTwo[4]; // declares new array to be passed in to function
    cout << getLinesFromFile("file2.txt",arrTwo,4) << endl; // second function call to getLinesFromFile
    
    for (int i=0;i<4;i++){ // loops through the length of the arrTwo
        cout << arrTwo[i] << endl; // prints out the current element of arrTwo
    }
    cout << "\n"; // prints out a new line
    
    // Test 3
    // expected output
    // 7
    // 11
    // 22
    // 33
    // 44
    // 55
    // 66
    // 77
    int arrThree[7]; // declares new array to be passed in to function
    cout << getLinesFromFile("file3.txt",arrThree,7) << endl; // third function call to getLinesFromFile
    
    for (int i=0;i<7;i++){ // loops through the length of the arrThree
        cout << arrThree[i] << endl; // prints out the current element of arrThree
    }
    
    return 0;
}