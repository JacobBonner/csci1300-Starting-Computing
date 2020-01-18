# include <iostream> 
using namespace std;

#ifndef PLANET_H
#define PLANET_H

class Planet
{
    public:
        Planet(); // default constructor
        Planet(string,double); // parametrized constructor
        string getName();
        void setName(string);
        double getRadius();
        void setRadius(double);
        double getVolume();
    
    private:
        string planetName;
        double planetRadius;
};

#endif