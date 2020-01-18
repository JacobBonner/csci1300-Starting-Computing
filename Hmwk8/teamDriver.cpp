// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 8 - Problem # 3

#include <iostream>
#include "Team.h"
using namespace std;


int main(){
    // Test Case 1
    // expected output
    // The Buffs
    // 4
    // Ralphie 10
    // Chip 9.2
    // The Flatties 8
    // C4C 4.9
    Team team1("The Buffs");
    cout << team1.getTeamName() << endl;
    team1.readRoster("roster1.txt");
    int team1Players = team1.getNumPlayers();
    cout << team1Players << endl;
    for (int i=0; i<team1Players; i++){
        cout << team1.getPlayerName(i) << " " << team1.getPlayerPoints(i) << endl;
    }
    
    
    // Test Case 2
    // expected ouput
    // The Merry Men
    // 7
    // Robin Hood 10.0
    // Little John 9.5
    // Maid Marian 3.2
    // Friar Tuck 4.6
    // Will Scarlet 7.4
    // Much 8.0
    // Alan-A-Dale 8.2
    Team team2("The Merry Men");
    cout << team2.getTeamName() << endl;
    team2.readRoster("roster2.txt");
    int team2Players = team2.getNumPlayers();
    cout << team2Players << endl;
    for (int i=0; i<team2Players; i++){
        cout << team2.getPlayerName(i) << " " << team2.getPlayerPoints(i) << endl;
    }
    
    
    return 0;
}