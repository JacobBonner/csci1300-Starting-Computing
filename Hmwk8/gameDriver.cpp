// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 8 - Problem # 4

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Player.h"
#include "Team.h"
using namespace std;


/** Algorithm: Calculate the total score of the first four players of a team
 * 1. Initilize the total to zero.
 * 2. Loop through the team and add the scores of the first four players to the total.
 * 3. Return the total.
 * Input Parameters: a team (type Team)
 * Output: nothing
 * Returns: The sum of the scores of the first four players on a team (double)
*/
double teamTotal(Team team){
    double tot = 0;
    for (int i=0; i<4; i++){
        tot += team.getPlayerPoints(i);
    }
    return tot;
}


/** Algorithm: Calculates the sum of the scores of the first four players of two teams, and returns the name of the team with more points.
 * 1. Check if either of the teams has less than 4 players.
 *      If yes, return "forfeit".
 * 2. If no...
 *      Calculate the total score for each team (the sum of the scores of the first four players).
 *      Check if the team totals are equal.
 *          If yes, return "draw".
 *      If no, check which team has a larger total score, and return the name of the team with the larger score.
 * Input Parameters: two teams (type Team)
 * Output: nothing
 * Returns: "forfeit" if one or both teams has less than 4 players, "draw" if both teams have the same total score, or the name of the team with a higher total score.
*/
string game(Team team1,Team team2){
    int team1_Total, team2_Total;
    if (team1.getNumPlayers() < 4 || team2.getNumPlayers() < 4){ // less than 4 players for either team
        return "forfeit";
    }
    else{
        team1_Total = teamTotal(team1); // calulates the total of team 1
        team2_Total = teamTotal(team2); // calculates the total of team 2
        if (team1_Total == team2_Total){ // same scores
            return "draw";
        }
        else if(team1_Total > team2_Total){ // team 1 has greater score
            return team1.getTeamName();
        }
        else{ // team 2 has greater score
            return team2.getTeamName();
        }
    }
}


int main(){
    // Test Case 1
    // expected output
    // The winner is: Seg Faultline
    Team team1("Seg Faultline");
    team1.readRoster("roster3.txt");
    Team team2("Team Maim");
    team2.readRoster("roster4.txt");
    cout << "The winner is: " << game(team1,team2) << endl;
    
    
    // Test Case 2
    // expected output
    // The winner is: The Buffs
    Team team3("The Buffs");
    team3.readRoster("roster1.txt");
    Team team4("The Merry Men");
    team4.readRoster("roster2.txt");
    cout << "The winner is: " << game(team3,team4) << endl;
    
    
    return 0;
}
