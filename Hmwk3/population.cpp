// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 3 - Problem 8

# include <iostream>
# include <cmath>
using namespace std;

/**
* Algorithm: Takes an inittial population and calculates the final population after 365 days (1 year)
* 1. Declare the number of seconds per year and calculate the value
* 2. Declare the birth, death, and immigration rates
* 3. Calculate the total births, deaths and immigrants in the year by multiplying the rates by the total number of seconds in a year
* 4. Calculate the final population by adding the total births and immigrants to the initial population (given as an argument to the function)
*    and by subracting the amount of deaths
* Input parameters: initial population (int)
* Output (prints to screen): nothing
* Returns: final population (int)
*/

int population(int initial_population) {
    int seconds_per_year = (60 * 60 * 24 * 365); // declaring the number of seconds in a year 
    double birth_rate = (1.0/8.0); // declaring the birth rate and assigning it a value
    double death_rate = (1.0/12.0); // declaring the death rate and assigning it a value
    double immigration_rate = (1.0/27.0); // declaring the immigration rate and assigning it a value
    
    double births_per_year = birth_rate * seconds_per_year; // calculating the number of births in 365 days
    double deaths_per_year = death_rate * seconds_per_year; // calculating the number of deaths in a year
    double immigrants_per_year = immigration_rate * seconds_per_year; // calculating the number of immigrants in a year
    
    int final_population;
    final_population = (initial_population) + (births_per_year) + (immigrants_per_year) - (deaths_per_year); // calculating the population after one year
    return final_population; // returning the final population
}


int main() {
    // Test 1
    // expected output
    // 2482000
    int population_in_year_1 = population(0); // first function call to population, storing the return value in a variable
    cout << population_in_year_1 << endl; // output the return value: population after one year
    
    // Test 2
    // expected output
    // 14847478
    int population_in_year_2 = population(12365478); // second function call to population, storing the return value in a variable
    cout << population_in_year_2 << endl; // output the return value: population after one year
    
    return 0;
}