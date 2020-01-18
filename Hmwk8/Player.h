#include <string>
#include <iostream>
using namespace std;
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    public:
        Player();
        Player(string,double);
        string getName();
        double getPoints();
        void setName(string);
        void setPoints(double);
        
    private:
        string name;
        double points;
};

#endif