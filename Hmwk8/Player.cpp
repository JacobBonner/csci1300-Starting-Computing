#include <iostream>
#include "Player.h"
#include <string>
using namespace std;


Player :: Player()
{
    name = "";
    points = 0;
}


Player :: Player(string tempName,double tempPoints)
{
    name = tempName;
    points = tempPoints;
}


string Player :: getName()
{
    return name;
}


double Player :: getPoints()
{
    return points;
}


void Player :: setName(string inName)
{
    name = inName;
}


void Player :: setPoints(double inPoints)
{
    points = inPoints;
}