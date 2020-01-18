// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 7 - Problem # 4


# include <iostream>
# include "User.h"
using namespace std;


// Testing Implementation of User class

int main(){
    
    // Test Case 1
    // expected output
    // Username: Jake
    // Rating: 6
    // Number of Ratings: 10
    int testRatings[] = {10,9,8,7,6,5,4,3,2,1};
    User u1 = User("Jake",testRatings,10);
    cout << "Username: " << u1.getUsername() << endl;
    cout << "Rating: " << u1.getRatingAt(4) << endl;
    cout << "Number of Ratings: " << u1.getNumRatings() << endl;
    
    
    // Test Case 2
    // expected output
    // Username: Forrest
    // Rating: 2
    // Number of Ratings: 5
    int testRatings2[] = {1,3,2,4,5};
    User u2 = User("Forrest",testRatings2,5);
    cout << "Username: " << u2.getUsername() << endl;
    cout << "Rating: " << u2.getRatingAt(2) << endl;
    cout << "Number of Ratings: " << u2.getNumRatings() << endl;
    
}