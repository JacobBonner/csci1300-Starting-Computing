#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#ifndef WARRIOR_H
#define WARRIOR_H

class Warrior
{
    public:
        // constructors
        Warrior();
        // getters
        string getWarriorName();
        int getStrength();
        int getLoyalty();
        int getMorale();
        bool getIsFree();
        bool getHasShip();
        bool getHasDragonglass();
        vector<int> getWarriorPosition();
        // setters
        void setWarriorName(string);
        void setStrength(int);
        void setLoyalty(int);
        void setMorale(int);
        void setIsFree(string);
        void setHasShip(string);
        void setHasDragonglass(string);
        void setWarriorPosition(int,int);
        
    private:
        string warriorName;
        int strength; // 0-200
        int loyalty; // 0-100
        int morale; // 0-100
        bool is_free;
        bool has_ship;
        bool has_dragonglass;
        vector<int> warriorPosition;
        
};

#endif