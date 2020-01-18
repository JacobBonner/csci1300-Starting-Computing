// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 8 - Problem # 2


#include <iostream>
#include "Player.h"
#include <string>
using namespace std;


int main(){
    // test Case 1
    // expected output
    // Name: Zach
    // Points: 2360
    Player player1;
    player1.setName("Zach");
    player1.setPoints(2360.0);
    cout << "Name: " << player1.getName() << endl;
    cout << "Points: " << player1.getPoints() << endl;
    
    // Test Case 2
    // expected output
    // Name: Mark
    // Points: 2350
    Player player2("Mark",2350.0);
    cout << "Name: " << player2.getName() << endl;
    cout << "Points: " << player2.getPoints() << endl;
    
    return 0;
}