#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Team.h"
using namespace std;


int split(string toSplit,char delimeter,string splitArray[],int length){
    if (toSplit.length() == 0) { // checks if the length of the string is zero
        return 0; 
    }
    string word = ""; 
    int j=0,k=0; 
    toSplit = toSplit + delimeter; 
    for (int i = 0; i < toSplit.length(); i++) // loops through the entire string
    {
        if (toSplit[i] == delimeter) // checks if the current element in the string is equal to the delimeter
        {
        	if (word.length() == 0) continue; // checks if the length of the word is zero
            splitArray[k] = word; 
            j++; 
            word = ""; 
            k++; 
        } else {
            word = word + toSplit[i]; 
        }
    }
    
    if (k>length){ // checks if k is greater than the length variable passed into the function
        return -1; 
    }
    
    return j;
}


Team :: Team()
{
    teamName = "";
    vector<Player> players;
}


Team :: Team(string team)
{
    teamName = team;
    vector<Player> players;
}


void Team :: setTeamName(string tempTeam)
{
    teamName = tempTeam;
}

/**
 * Algorithm: Reads from an input file and appends the players to the players vector (type Player).
 * 1. Open the file and read every line.
 * 2. For each line...
 *      Call the split function to separate the player name from the score.
 *      Use Player member functions to set the name of the current player equal to the first element in the split array, 
 *      and the score of the player equal to the second element converted to a double.
 * Input Parameters: a file name (string)
 * Ouput: nothing
 * Returns: nothing
 */ 
void Team :: readRoster(string fileName)
{
    ifstream myfile;
    myfile.open(fileName);
    string line = "";
    //Player newPlayer;
    string lineArr[2];
    while(getline(myfile,line)){
        split(line,',',lineArr,2);
        Player newPlayer(lineArr[0],stod(lineArr[1]));
        players.push_back(newPlayer);
    }
}


string Team :: getPlayerName(int i)
{
    if(i < 0 || i >= players.size()){ // checks if the index is not valid
        return "ERROR";
    }
    else{
        return players[i].getName();
    }
}


double Team :: getPlayerPoints(int i)
{
    if(i < 0 || i >= players.size()){ // checks if the index is not valid
        return -1;
    }
    else{
        return players[i].getPoints();
    }
}


int Team :: getNumPlayers()
{
    return players.size();
}


string Team :: getTeamName()
{
    return teamName;
}