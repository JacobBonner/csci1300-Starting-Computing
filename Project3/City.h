#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#ifndef CITY_H
#define CITY_H

class City
{
    public:
        // constructors
        City();
        // getters
        string getLetter();
        string getCityName();
        int getMoney();
        int getarmy_size();
        int getPoints();
        // setters
        void setLetter(string);
        void setCityName(string);
        void setMoney(int);
        void setarmy_size(int);
        void setPoints(int);
        
    private:
        string letter;
        string cityName;
        int money;
        int army_size;
        int points;
};

#endif