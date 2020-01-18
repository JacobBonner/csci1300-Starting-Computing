#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Warrior.h"
using namespace std;


Warrior :: Warrior()
{
    warriorName = "";
    strength = 0;
    loyalty = 0;
    morale = 0;
    is_free = false;
    has_ship = false;
    has_dragonglass = false;
    warriorPosition = {0,0};
}


// getters

string Warrior :: getWarriorName()
{
    return warriorName;
}


int Warrior :: getStrength()
{
    return strength;
}


int Warrior :: getLoyalty()
{
    return loyalty;
}


int Warrior :: getMorale()
{
    return morale;
}


bool Warrior :: getIsFree()
{
    return is_free;
}


bool Warrior :: getHasShip()
{
    return has_ship;
}


bool Warrior :: getHasDragonglass()
{
    return has_dragonglass;
}


vector<int> Warrior :: getWarriorPosition()
{
    return warriorPosition;
}


// setters 

void Warrior :: setWarriorName(string inWarriorName)
{
    warriorName = inWarriorName;
}


void Warrior :: setStrength(int inStrength)
{
    strength = inStrength;
}


void Warrior :: setLoyalty(int inLoyalty)
{
    loyalty = inLoyalty;
}


void Warrior :: setMorale(int inMorale)
{
    morale = inMorale;
}


void Warrior :: setIsFree(string inFree)
{
    if(inFree == "yes"){
        is_free = true;
    }
    else{
        is_free = false;
    }
}


void Warrior :: setHasShip(string inHasShip)
{
    if(inHasShip == "yes"){
        has_ship = true;
    }
    else{
        has_ship = false;
    }
}


void Warrior :: setHasDragonglass(string inHasDragonglass)
{
    if (inHasDragonglass[0] == 'y'){
        has_dragonglass = true;
    }
}


void Warrior :: setWarriorPosition(int row, int column)
{
    warriorPosition[0] = row;
    warriorPosition[1] = column;
}