// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 3 - Problem 9

# include <iostream>
# include <iomanip>
using namespace std;

/**
* Algorithm: Convert a given temperature in celsius to fahrenheit and print the result
* 1.  Take the temperature in celsius passed as an argument and multiply by (9/5) then add 32 to convert to Fahrenheit
* 2. Set the precision to 2 so that the temperature in Fahrenheit has two values after the decimal
* 3. Print out the message of how many degrees the temperautre in celsius is when converted to Fahrenheit
* Input parameters: temperature in celsius (int)
* Output (prints to screen): The temperature of temp_celsius in Fahrenheit is temp_fahrenheit
* Returns: nothing
*/

void celsiusToFahrenheit(int temp_celsius) {
    double temp_fahrenheit = ((9.0/5.0) * temp_celsius) + 32;
    cout << fixed << setprecision(2);
    cout << "The temperature of " << temp_celsius << " in Fahrenheit is " << temp_fahrenheit << endl;
}


int main() {
    // Test 1
    // expected output
    // The temperature of 35 in Fahrenheit is 95.00
    celsiusToFahrenheit(35); // first function call to celsiusToFahrenheit
    
    // Test 2
    // expected output
    // The temperature of -22 in Fahrenheit is -7.60
    celsiusToFahrenheit(-22); // second function call to celsiusToFahrenheit 
    
    return 0;
}