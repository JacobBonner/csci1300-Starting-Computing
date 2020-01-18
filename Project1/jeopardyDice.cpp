// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Project 1 - Problem # 3

// Step 1: Steps to solve this problem 
// write an algorithm in pseudocode explaining how you are approaching the problem, step by step
/** ALGORITHM
 * 1. I will start by making four functions: one for the human's turn, one for the computer's turn, one that calculates the playerTotal,
 *    and one that prints out the playerTotal for the computer and human.
 * 2. For the human's turn, the function will return an integer that is the turn total after their turn is complete:
 *      Takes no paremeters.
 *      Set turnTotal equal to 0.
 *      Ask the user if they want to roll the dice.
 *      If the user enters yes,
 *          Use the given rollDie function to roll the dice.
 *          If the roll is 1 or 3 or 6, add the value of the die to turnTotal and roll again.
 *          If the roll is 2 or 5, set turnTotal equal to 0 and end their turn.
 *          If the roll is 4, set turnTotal equal to 15 and end their turn.
 *      If the user enters no, end their turn.
 *      Return the turnTotal.
 * 3. For the computer's turn, the function will return an integer that is the turn total after the computer's turn is finished:
 *      Takes no parameters.
 *      Set turnTotal equal to 0.
 *      Use the given rollDie function to roll the dice.
 *      If the roll is 1 or 3 or 6, add the value of the die to turnTotal and roll again.
 *          If the value of turnTotal reaches 10 from this process, end the computer's turn.
 *      If the roll is 2 or 5, set turnTotal equal to 0 and end the computer's turn.
 *      If the roll is 4, set turnTotal equal to 15 and end the computer's turn.
 *      Return the turnTotal.
 * 4. For the function that calculates the playerTotal:
 *      Take two integer parameters - the player's current total, and the total of their most recent turn.
 *      Define new variable playerTotal, and set it equal to the current total plus the most recent turnTotal.
 *      Return the playerTotal
 * 5. For the function that prints out the playerTotal for the computer and the human:
 *      Take two integer parameters - the human playerTotal and the computer playerTotal.
 *      Print out the computer total.
 *      Print out the human total.
 *      Returns nothing.
 * 6. Inside the game function:
 *      Set both the computer and human playerTotal equal to 0.
 *      Use a while loop - while both the human and computer playerTotal are less than 80:
 *          Call the function for the human's turn and store the turnTotal.
 *          Calculate the human's player total by calling the playerTotal function, with the current player total and the most recent 
 *          turnTotal as parameters, and save the total in a variable (humanTotal).
 *          Call the function that prints out the playerTotals, passing the humanTotal and the computer playerTotal as arguments.
 *          Check if the human total is less than 80.
 *              If yes...
 *                  Call the function for the computer's turn and store the turnTotal.
 *                  Calculate the computer's player total by calling the playerTotal function, , with the current player total and the most recent 
 *                  turnTotal as parameters, and save the total in a variable (computerTotal).
 *                  Call the function that prints out the playerTotals, passing the current humanTotal and computerTotal as arguments.
 *          Go back to the start of the while loop until the playerTotal of either the computer or human are greater than or equal to 80.
 *      If the computerTotal is greater than the humanTotal
 *          Print out the winning statement for the computer.
 *      Else (if the humanTotal is greater than the computerTotal)
 *          Print out the winning statement for the human.
 * 7. Run the main function and edit my functions as necessary.
*/


// Step 2: Code it up! 
// After finishing up your pseudocode, translate them into c++ 
// IMPORTANT: rollDie() and main() are already written for you.
// You need to complete game function as well as at least 3 other additional functions
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std; 

/**
 * rollDie 
 * returns a random integer between 1 and 6, works as rolling a dice.
 * return value, int number (1-6)
 */
int rollDie()
{
	return random() % 6 + 1; 
}

/**
 * Algorithm: Prompt the user to make a decision to roll the die or not, and if they do, calculate and return their turn total.
 * 1. Set the turn total equal to 0.
 * 2. Ask the user if they want to roll a die (Y/N).
 *      While the user enters y or Y (yes)...
 *          Use the rollDie function to randomly roll a die.
 *              Check if the roll is 1 or 3 or 6.
 *                  If yes, print out what the user rolled and add that value to the turn total.
 *                  Print out what the current turn total is and ask the user if they want to roll again (Y/N).
 *                  If y or Y (yes), go back to the beginning of the while loop.
 *              If no, check if the roll is 2 or 5.
 *                  If yes, print out what the user rolled, set the turn total equal to 0, and end their turn.
 *              If no, check if the roll is 4.
 *                  If yes, print out what the user rolled, set the turn total equal to 15, and end their turn.
 * 3. If no, exit the while loop and return the current value of turn total.
 * Input Parameter(s): none
 * Output: nothing
 * Returns: the turn total of the user (int type)
 */
int humanRoll(){
    cout << "\nIt is now human's turn\n" << endl; // outputs that it is the human's turn
    char userChoice; // defines new variable
    cout << "Do you want to roll a dice (Y/N)?:" << endl; // asks the user to say yes or no to rolling a die
    cin >> userChoice; // stores the users input in the variable userChoice
    int turnTotal = 0; // defines and sets turn total equal to 0
    while (userChoice == 'y' || userChoice == 'Y'){ // checks if the user's choice is y or Y
        int roll = rollDie(); // calls the rollDie function
        if (roll == 1 || roll == 3 || roll == 6){ // checks if the roll is equal to 1 or 3 or 6
            cout << "You rolled a " << roll << endl; // outputs what the user rolled
            turnTotal += roll; // adds the roll value to the turn total
            cout << "Your turn total is " << turnTotal << endl; // outputs the current turn total
            cout << "Do you want to roll again (Y/N)?:" << endl; // asks the user if they want to roll again
            cin >> userChoice; // stores the users choice in a variable
        }
        else if (roll == 2 || roll == 5){ // checks if the roll is equal to 2 or 5
            cout << "You rolled a " << roll << endl; // outputs what the user rolled
            turnTotal = 0; // sets the turn total equal to zero
            cout << "Your turn total is " << turnTotal << endl; // outputs the current turn total
            return turnTotal;
        }
        else if (roll == 4){ // checks if the roll is equal to 4
            cout << "You rolled a " << roll << endl; // outputs what the user rolles
            turnTotal = 15; // sets the turn total equal to 15
            cout << "Your turn total is " << turnTotal << endl; // outputs the current turn total
            return turnTotal;
        }
    }
    return turnTotal; // returns the turn total
}

/**
 * Algorithm: Roll the dice for the computer, and calculate and return the turn total.
 * 1. Set the turn total equal to 0.
 * 2. Use the rollDie function to randomly roll a die.
 * 3. While the computer turn total is less than 10, and the roll is either 1 or 3 or 6...
 *      If yes...
 *          Print out what the computer rolled and add the value to the turn total. Print out the turn total.
 *          Check if the turn total is greater than or equal to 10.
 *              If yes, return the turn total.
 *          Use the rollDie function to roll a die again.
 *          Go back to check the condition of the while statement.
 * 4. If no, check if the roll is 2 or 5.
 *      If yes, print out what the computer rolled and set the turn total equal to 0.
 * 5. If no, check if the roll is 4.
 *      If yes, print out what the computer rolled and set the turn total equal to 15.
 * 6. Return the turn total.
 * Input Parameter(s): none
 * Output: nothing
 * Returns: the turn total of the computer (int type)
 */
int computerTurn(){
    cout << "\nIt is now computer's turn\n" << endl; // outputs that it is now the computer's turn
    int computerTurnTot = 0; // sets the computer turn total equal to zero
    int computerRoll = rollDie(); // calls the rollDie function and stores it as the computer roll
        while ((computerTurnTot < 10) && (computerRoll == 1 || computerRoll == 3 || computerRoll == 6)){ // checks if the turn total is less than 10, and if the computer roll is equal to 1 or 3 or 6
            cout << "Computer rolled a " << computerRoll << endl; // outputs what the computer rolled
            computerTurnTot += computerRoll; // adds the computer roll to the turn total
            cout << "Computer turn total is " << computerTurnTot << endl; // outputs what the current turn total is
            if (computerTurnTot >= 10){ // checks if the computer turn total is greater than or equal to 10
                return computerTurnTot; // return the current computer turn total
            }
            computerRoll = rollDie(); // rolls the die again by calling the rollDie() function
        }
        if (computerRoll == 2 || computerRoll == 5){ // checks if the computer roll is equal to 2 or 5
            cout << "Computer rolled a " << computerRoll << endl; // outputs what the computer rolled
            computerTurnTot = 0; // sets the computer turn total equal to zero
            cout << "Computer turn total is " << computerTurnTot << endl; // outputs the final computer turn total
        }
        else if (computerRoll == 4){ // checks if the computer roll is equal to 4
            cout << "Computer rolled a " << computerRoll << endl; // outputs what the computer rolled
            computerTurnTot = 15; // sets the computer turn total equal to 15
            cout << "Computer turn total is " << computerTurnTot << endl; // outputs the final computer turn total
        }
    return computerTurnTot; // returns the computer turn total
}

/**
 * Algorithm: Calculate the total value of all of a player's rolls.
 * 1. Take the two numbers passed into the function.
 * 2. Define a new variable, player total, and set it equal to the current total plus the turn total.
 * Input Parameter(s): turn total (int) and current total (int)
 * Output: nothing
 * Returns: the player total for either the computer or the human (int)
 */
int playerTotal(int turnTot,int currentTot){
    int playerTot = currentTot + turnTot; // adds the current total to the turn total
    return playerTot; // returns player total
}

/**
 * Algorithm: Print the total accumulative dice value of the computer and the person.
 * 1. Take the two numbers passed into the function.
 * 2. Print:
 *      computer: computer total
 *      human: human total
 * Input Parameter(s): the computer total (int) and the user total (int)
 * Output: computer: [computer total]   
 *         human: [user total]
 * Returns: nothing
 */
void displayTotals(int compTot,int playTot){
    cout << "computer: " << compTot << endl; // displays the computer player total
    cout << "human: " << playTot << endl; // displays the human player total
}

/**
 * game 
 * driver function to play the game
 * the function does not return any value
 */
void game()
{
    cout << "Welcome to Jeopardy Dice!" << endl; // outputs the opening statement of the game
    int computerTotal = 0; // sets the computer's total to 0
    int humanTotal = 0; // sets the human's total to 0
    while (computerTotal < 80 && humanTotal < 80){ // checks if the computer total and human total are both less than 80
        int humanTurnTotal = humanRoll(); // defines the human turn total, and calls the human roll function
        humanTotal = playerTotal(humanTurnTotal,humanTotal); // defines the human total, and calls the player total function
        displayTotals(computerTotal,humanTotal); // calls the display totals function to show the current totals
        if (humanTotal < 80){ // checks if human total is less than 80
            int computerTurnTotal = computerTurn(); // defines the computer turn total, and calls the computer turn function
            computerTotal = playerTotal(computerTurnTotal,computerTotal); // defiens the computer total, and calls the player total function
            displayTotals(computerTotal,humanTotal); // calls the display total function to show the current totals
        }
    }
	if (computerTotal > humanTotal){ // checks if the computer total is greater than the human total
	    cout << "\nCongratulations! computer won this round of Jeopardy Dice!" << endl; // outputs a winning statement for the computer
	}
	else {
	    cout << "\nCongratulations! human won this round of Jeopardy Dice!" << endl; // outputs a winning statement for the human
	}
}

int main()
{
	srand(123);
	// start the game! 
	game(); // function call to game
	return 0;
}