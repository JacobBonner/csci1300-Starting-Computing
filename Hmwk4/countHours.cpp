// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 4 - Problem # 6

# include <iostream>
using namespace std;

/**
* Algorithm: Calculates the number of hours in a given month and returns the value.
* 1. Take the integer month passed into the function.
* 2. Using a switch statement, test the variabe month against each of the different values (1-12).
* 3. Compare month to case 1 (1)
*       If month is equal to 1, return 744, and break to the next case.
*       If not, move to next case.
* 4. Compare month to case 2 (2)
*       If month is equal to 1, return 672, and break to the next case.
*       If not, move to next case.
* 5. Compare month to case 3 (3)
*       If month is equal to 1, return 744, and break to the next case.
*       If not, move to next case.
* 6. Compare month to case 4 (4)
*       If month is equal to 1, return 720, and break to the next case.
*       If not, move to next case.
* 7. Compare month to case 5 (5)
*       If month is equal to 1, return 744, and break to the next case.
*       If not, move to next case.
* 8. Compare month to case 6 (6)
*       If month is equal to 1, return 720, and break to the next case.
*       If not, move to next case.
* 9. Compare month to case 7 (7)
*       If month is equal to 1, return 744, and break to the next case.
*       If not, move to next case.
* 10. Compare month to case 8 (8)
*       If month is equal to 1, return 744, and break to the next case.
*       If not, move to next case.
* 11. Compare month to case 9 (9)
*       If month is equal to 1, return 720, and break to the next case.
*       If not, move to next case.
* 12. Compare month to case 10 (10)
*       If month is equal to 1, return 744, and break to the next case.
*       If not, move to next case.
* 13. Compare month to case 11 (11)
*       If month is equal to 1, return 720, and break to the next case.
*       If not, move to next case.
* 14. Compare month to case 12 (12)
*       If month is equal to 1, return 744, and break to the end of the switch.
*       If not, the switch is over.
* Input parameters: a number corresponding to a month of the year (int type)
* Output (prints to screen): nothing
* Returns: the number of hours in the given month (int type)
*/


int countHours(int month) {
    switch(month) {
        case 1 : // tests month against the value 1
            return 24*31; // returns 744
            break; // breaks to next testing case
        case 2 : // tests month against the value 2
            return 24*28; // returns 672
            break; // breaks to next testing case
        case 3 : // tests month against the value 3
            return 24*31; // returns 744
            break; // breaks to next testing case
        case 4 : // tests month against the value 4
            return 24*30; // returns 720
            break; // breaks to next testing case
        case 5 : // tests month against the value 5
            return 24*31; // returns 744
            break; // breaks to next testing case
        case 6 : // tests month against the value 6
            return 24*30; // returns 720
            break; // breaks to next testing case
        case 7 : // tests month against the value 7
            return 24*31; // returns 744
            break; // breaks to next testing case
        case 8 : // tests month against the value 8
            return 24*31; // returns 744
            break; // breaks to next testing case
        case 9 : // tests month against the value 9
            return 24*30; // returns 720
            break; // breaks to next testing case
        case 10 : // tests month against the value 10
            return 24*31; // returns 744
            break; // breaks to next testing case
        case 11 : // tests month against the value 12
            return 24*30; // returns 720
            break; // breaks to next testing case
        case 12 : // tests month against the value 12
            return 24*31; // returns 744
            break; // breaks and the switch is finished
    }
}


int main() {
    // Test 1
    // expected output
    // 744
    cout << countHours(3) << endl;
    
    // Test 2
    // expected output
    // 672
    cout << countHours(2) << endl;
    
    // Test 3
    // expected output
    // 720
    cout << countHours(11) << endl;
    
    return 0;
}