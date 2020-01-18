#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Space.h"
using namespace std;

#ifndef MAP_H
#define MAP_H

class Map
{
    public:
        // constructors
        Map();
        // getters
        Space& getTile(int,int);
        bool getDragonGlass(int,int);
        // setters
        void setTile(int,int,Space);
        void setDragonGlass(int,int,bool);
        
    private:
        Space tiles[25][16];
        bool dragonGlass[25][16]; // randomly put true in 
};

#endif