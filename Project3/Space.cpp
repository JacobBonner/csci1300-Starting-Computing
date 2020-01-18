#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Space.h"
using namespace std;


Space :: Space()
{
    tileType = "";
    controlPoints = 0;
    controlMoney = 0;
    controlArmySize = 0;
    position = {0,0};
    symbol = "";
    ownerName = "";
    Owner;
    //Owner = "Constructor set this"; // I wonder if redeclaration has anything to do with it - Punith  this is an object I can't do that
    //Owner.setHeroName("onstructor set this");
    // okay. would it work though?
    // I commented out that line and tried it, it had the same "no owner" output
    // look at the last function in this file, is that a valid way to do that?
    // yeah i see it
    
    // So i cant create a hero object like Owner and just set it equal to different Hero object?
    // lol
    // okay how do i
    // hmmm, give me 5 minutes to google intensely 
    // confirm what I think is going on and what you will need to do
    // these is a concept of copy constructor, that you will need.
    // if you passed around refences of the object that should do, in this case I guess it is not working 
    // hold on, still reading
    
    
    // I have an idea once you're done
    // All i really need to know about who is owning a space is the name of the hero, so I could just use a string 
    // like heroOwnerName or something right? Instead of using an entire hero object as the owner
    
    // I see, you can go ahead to develop to make changes you like. I will work on this on the side lines.
    // The issue is that, what I think is to deal with "copy constructor" and "assignment oprator"
    // go ahead, I will leave you with an email on my findings 
    
    // okay thank you!
    
}


// getters 

string Space :: getTileType()
{
    return tileType;
}


int Space :: getControlPoints()
{
    return controlPoints;
}


int Space :: getControlMoney()
{
    return controlMoney;
}


int Space :: getControlArmySize()
{
    return controlArmySize;
}


vector<int> Space:: getPosition()
{
    return position;
}


string Space :: getSymbol()
{
    return symbol;
}


string Space :: getOwnerName()
{
    return ownerName;
}


Hero Space :: getOwner()
{
    return Owner;
}


// setters

void Space :: setTileType(string charac)
{
    for(int i=0; i<charac.length(); i++){
        if(charac[i] == 'p'){
            tileType = "land";
        }
        else if(charac[i] == 'w'){
            tileType = "water";
        }
    }   
    if(tileType != "land" && tileType != "water"){
            tileType = "city";
        }
}


void Space :: setControlPoints(string character)
{
    if(character[0] == 'p'){
        controlPoints = 2;
    }
    else if(character[0] == 'w'){
        controlPoints = 1;
    }
}


void Space :: setControlMoney(string character)
{
    if(character[0] == 'p'){
        controlMoney = 20;
    }
    else if(character[0] == 'w'){
        controlMoney = 10;
    }
}


void Space :: setControlArmySize(string character)
{
    if(character[0] == 'p'){
        controlArmySize = 0;
    }
    else if(character[0] == 'w'){
        controlArmySize = 10;
    }
}


void Space :: setPosition(int i,int j)
{
    position[0] = i;
    position[1] = j;
}


void Space :: setSymbol(string inSpaceLetter)
{
    if(inSpaceLetter[0] == 'p'){
        symbol = "*";
    }
    else if(inSpaceLetter[0] == 'w'){
        symbol = "~";
    }
    else if(inSpaceLetter[0] != ' '){
        symbol = inSpaceLetter[0];
    }
}


void Space :: setOwnerName(string inOwnerName)
{
    ownerName = inOwnerName;
}

void Space :: setOwner(Hero heroIn)
{
    Owner = heroIn;
}