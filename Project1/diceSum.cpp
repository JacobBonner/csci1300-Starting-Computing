// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Project 1 - Problem # 2

# include <iostream>
using namespace std;

/** rollDie
* returns a random integer between 1 and 6,
* works as rolling a die.
* return value, int number (1-6)
*/
int rollDie(){
    return random() % 6 + 1;
}

/** 
* Algorithm: Repeatedly rolls two six-sided dice until their sum is equal to a given desired sum.
* 1. Take the integer, desired sum, passed into the function.
* 2. Check if the desired sum is less than 2 or greater than 12
*       If yes, print out "The desired sum should be between 2 and 12".
* 3. If no..
*       Define a variable to be the roll count and set it equal to zero.
*       Define a variable for the sum of the dice and set it equal to zero.
*       Check if the sum is not equal to the desired sum.
*           If yes, WHILE the sum is not equal to the desired sum...
*               Add one to the roll count.
*               Roll one die and save the value.
*               Roll a second die and save the value.
*               Print out the value of the value of each die.
*               Add the two dice values together and store that as the sum.
*               Go back to start of the while loop.
*           If no, print out how many rolls it took to reach teh desired sum.
* Input parameters: the desired sum (int type)
* Output (prints to screen): Either "The desired sum should be between 2 and 12" if the number passed into the function is less than 
* 2 or greater than 12, or "You rolled a ___ and a ___" until the desired sum is met. Once the sum is reached, print out "Got a 
* [desired sum] in [roll count] rolls!".
* Returns: nothing
*/
void diceSum(int desiredSum){
    if (desiredSum < 2 || desiredSum > 12){ // checks if the desired sum is less than 2 or greater than 12
        cout << "The desired sum should be between 2 and 12" << endl; // outputs an error statement
    }
    else{
        int rollCount = 0; // declares the roll count and sets it equal to zero
        int sum = 0; // sets the sum equal to zero
        while (sum != desiredSum) // checks if the sum is not equal to the desired sum
        {
            rollCount ++; // add on to the roll count
            int dieOne = rollDie(); // calls the rollDie function and stores the value in a variable
            int dieTwo = rollDie(); // call the rollDie function again and stores the value in a different variable
            cout << "You rolled a " << dieOne << " and a " << dieTwo << endl; // outputs what the two dice rolls are
            sum = dieOne + dieTwo; // adds the two values of the dice rolls together
        }
        cout << "Got a " << desiredSum << " in " << rollCount << " rolls!" << endl; // prints out how many rolls it took to reach the desired sum
    }
}

int main(){
    // Test case 1
    // expected output
    // The desired sum should be between 2 and 12
    diceSum(15); // first function call to diceSum
    
    // Test case 2
    // expected output
    // You rolled a __ and a __ (until the desired sum is reached)
    diceSum(10); // second function call to diceSum
    
    // Test case 3
    // expected output
    // The desired sum should be between 2 and 12
    diceSum(0); // third function call to diceSum
}