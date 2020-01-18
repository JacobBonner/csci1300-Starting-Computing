#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include "Planet.h"
using namespace std;

Planet::Planet() // default constructor
{
    planetName = "";
    planetRadius = 0.0;
}

Planet::Planet(string name,double radius1) // parametrized constructor
{
    planetName = name;
    planetRadius = radius1;
}

string Planet::getName()
{
    return planetName;
}

void Planet::setName(string name)
{
    planetName = name;
}

double Planet::getRadius()
{
    return planetRadius;
}

void Planet::setRadius(double radius)
{
    planetRadius = radius;
}

double Planet::getVolume()
{
    double volume = (4.0/3.0)*(M_PI)*pow(planetRadius,3); // calculates volume of a sphere
    return volume;
}