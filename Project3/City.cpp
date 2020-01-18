#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "City.h"
using namespace std;


City :: City()
{
    letter = "";
    cityName = "";
    money = 0;
    army_size = 0;
    points = 0;
}


// getters

string City :: getLetter()
{
    return letter;
}


string City :: getCityName()
{
    return cityName;
}


int City :: getMoney()
{
    return money;
}


int City :: getarmy_size()
{
    return army_size;
}


int City :: getPoints()
{
    return points;
}


// setters

void City :: setLetter(string inLetter)
{
    letter = inLetter;
}


void City :: setCityName(string inCityName)
{
    cityName = inCityName;
}


void City :: setMoney(int inMoney)
{
    money = inMoney;
}


void City :: setarmy_size(int inarmy_size)
{
    army_size = inarmy_size;
}


void City :: setPoints(int inPoints)
{
    points = inPoints;
}