#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Map.h"
using namespace std;


Map :: Map()
{
    Space tiles[25][16];
    for(int i=0; i<25; i++){
        for(int j=0; j<16; j++){
            dragonGlass[i][j] = false;
        }
    }
}


// getters

Space& Map :: getTile(int row,int col)
{
    return tiles[row][col];
}


bool Map :: getDragonGlass(int i, int j)
{
    return dragonGlass[i][j];
}

//setters

void Map :: setTile(int r, int c, Space tileIn)
{
    tiles[r][c] = tileIn;
}


void Map :: setDragonGlass(int row, int column, bool flag)
{
    dragonGlass[row][column] = flag;
}