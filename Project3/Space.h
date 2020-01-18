#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Hero.h"
using namespace std;

#ifndef SPACE_H
#define SPACE_H

class Space // did you remove the hero object? looks like you did. Okay go ahead, if you could send me your old code I can try to debug further
{
    public:
        // constructors
        Space();
        // getters
        string getTileType();
        int getControlPoints();
        int getControlMoney();
        int getControlArmySize();
        vector<int> getPosition();
        string getSymbol();
        string getOwnerName();
        Hero getOwner();
        // setters
        void setTileType(string);
        void setControlPoints(string);
        void setControlMoney(string);
        void setControlArmySize(string);
        void setPosition(int,int);
        void setSymbol(string);
        void setOwnerName(string);
        void setOwner(Hero);
        
    private:
       string tileType; // water, land, city
       int controlPoints; 
       int controlMoney;
       int controlArmySize;
       vector<int> position; 
       string symbol; // ~ * or city letter
       string ownerName;
       Hero Owner; // tracks who owns the space
};

#endif