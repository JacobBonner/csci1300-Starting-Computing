# include <iostream>
# include "User.h"
using namespace std;

User :: User() // default constructor
{
    username = "";
    numRatings = 0;
    size = 50;
    for(int i=0;i<size;i++){
        ratings[i] = 0;
    }
}

User :: User(string name,int nums[],int num) // parametrized constructor
{
    username = name;
    numRatings = num;
    size = num;
    for(int i=0;i<numRatings;i++){
        ratings[i] = nums[i];
    }
}

string User :: getUsername()
{
    return username;
}

void User :: setUsername(string s)
{
    username = s;
}

int User :: getRatingAt(int index)
{
    if(index>=size){
        return -1;
    }
    else{
        return ratings[index];
    }
}

bool User :: setRatingAt(int indx,int value)
{
    if(indx>=0 && indx<=size && value>=0 && value<=5){ // makes sure the rating and index are in the correct ranges
        ratings[indx] = value;
        return true;
    }
    else{
        return false;
    }
}

int User :: getNumRatings()
{
    return numRatings;
}

void User :: setNumRatings(int num_of_ratings)
{
    numRatings = num_of_ratings;
}

int User :: getSize()
{
    return size;
}