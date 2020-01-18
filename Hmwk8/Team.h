#include <string>
#include <vector>
#include <iostream>
#include "Player.h"
using namespace std;

#ifndef TEAM_H
#define TEAM_H

class Team
{
    public:
        Team();
        Team(string);
        void setTeamName(string);
        void readRoster(string);
        string getPlayerName(int);
        double getPlayerPoints(int);
        int getNumPlayers();
        string getTeamName();
        
    private:
        string teamName;
        vector<Player> players;
};
#endif