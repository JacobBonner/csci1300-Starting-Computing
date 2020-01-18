#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Warrior.h"
using namespace std;

#ifndef HERO_H
#define HERO_H

class Hero
{
    public:
        // constructors
        Hero();
        // getters
        string getHeroName();
        int getHeroMoney();
        int getInfluence();
        int getArmySize();
        Warrior& getHeroWarrior(int); // EDIT
        vector<int> getLocation();
        bool getShip();
        int getHeroPoints();
        bool getVisitedCity(int);
        bool getIsAlive(); // for when a hero retires
        // setters
        void setHeroName(string);
        void setHeroMoney(int);
        void setInfluence(int);
        void setArmySize(int);
        void setWarrior(Warrior,int); // EDIT
        void setLocation(int,int);
        void setShip(string);
        void addHeroPoints(int);
        void setVisitedCity(int);
        void setIsAlive(bool);
        
    private:
        string heroName;
        int heroMoney;
        int influence;
        int armySize;
        Warrior warriors[4];
        vector<int> Location; // [row,column]
        bool ship;
        int heroPoints;
        bool visitedCities[26]; // for tracking what city a hero has been to
        bool isAlive;
};

#endif