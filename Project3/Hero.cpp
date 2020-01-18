#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Hero.h"
using namespace std;


Hero :: Hero()
{
    heroName = "";
    heroMoney = 0;
    influence = 0;
    armySize = 0;
    warriors[4];
    Location = {0,0}; // {row,column}
    ship = false;
    heroPoints = 0;
    for(int i=0; i<26; i++){
        visitedCities[i] = false;
    }
    isAlive = true;
}


// Getters

string Hero :: getHeroName()
{
    return heroName;
}


int Hero :: getHeroMoney()
{
    return heroMoney;
}


int Hero :: getInfluence()
{
    return influence;
}


int Hero :: getArmySize()
{
    return armySize;
}


Warrior& Hero :: getHeroWarrior(int index)
{
    return warriors[index];
}


vector<int> Hero :: getLocation()
{
    return Location;
}


bool Hero :: getShip()
{
    return ship;
}


int Hero :: getHeroPoints()
{
    return heroPoints;
}


bool Hero :: getVisitedCity(int idx)
{
    return visitedCities[idx];
}


bool Hero :: getIsAlive()
{
    return isAlive;
}
// Setters

void Hero :: setHeroName(string inName)
{
    heroName = inName;
}


void Hero :: setHeroMoney(int inMoney)
{
    heroMoney = inMoney;
}


void Hero :: setInfluence(int inInfluence)
{
    influence = inInfluence;
}


void Hero :: setArmySize(int inArmySize)
{
    armySize = inArmySize;
}


void Hero :: setWarrior(Warrior warrior, int index) // DOUBLE CHECK
{
    warriors[index] = warrior;
}
// OR
// void Hero :: setWarrior(string nameOfWarrior) // DOUBLE CHECK
// {
//     for(int i=0; i<14; i++){
//         if()
//     }
// }


void Hero :: setLocation(int row,int column) // DOUBLE CHECK
{
    Location[0] = row;
    Location[1] = column;
}


void Hero :: setShip(string inShip)
{
    if(inShip[0] == 'y'){
        ship = true;
    }
}


void Hero :: addHeroPoints(int inPoints)
{
    heroPoints += inPoints;
}


void Hero :: setVisitedCity(int indx)
{
    visitedCities[indx] = true;
}


void Hero :: setIsAlive(bool aliveFlag)
{
    isAlive = aliveFlag;
}

// Other Functions
