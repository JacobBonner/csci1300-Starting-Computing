#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <ctime>
#include "Space.h"
#include "City.h"
#include "Map.h"
#include "Warrior.h"
#include "Hero.h"

#include <typeinfo>
using namespace std;


int split(string toSplit,char delimeter,string splitArray[],int length){
    if (toSplit.length() == 0) { // checks if the length of the string is zero
        return 0; 
    }
    string word = ""; 
    int j=0,k=0; 
    toSplit = toSplit + delimeter; 
    for (int i = 0; i < toSplit.length(); i++) // loops through the entire string
    {
        if (toSplit[i] == delimeter) // checks if the current element in the string is equal to the delimeter
        {
        	if (word.length() == 0) continue; // checks if the length of the word is zero
            splitArray[k] = word; 
            j++; 
            word = ""; 
            k++; 
        } else {
            word = word + toSplit[i]; 
        }
    }
    
    if (k>length){ // checks if k is greater than the length variable passed into the function
        return -1; 
    }
    
    return j;
}


/** Algorithm: Reads the map text file and creates a Map object of the game map
 * 1. Read mapGOT.txt and split each line.
 * 2. For each line, create a new space (Space object).
 * 3. Fill the current space with the information from the text file.
 * 4. Append the current space to the Map.
 * 5. Randomly place dragonglass on 5 land spaces ('p').
 * 6. Return the map.
 * Parameters: None
 * Output: Nothing
 * Return: the complete map (Map)
 */ 
Map createMap(){
    // read map
    Map GOTmap;
    int lineCounter = 0;
    ifstream mapFile;
    mapFile.open("mapGOT.txt");
    string mapLine = "";
    string splitMapArr[16];
    while(getline(mapFile,mapLine)){
        if(lineCounter < 25){
            split(mapLine,',',splitMapArr,16);
            for(int i=0; i<16; i++){
                Space newSpace;
                newSpace.setTileType(splitMapArr[i]);
                newSpace.setControlPoints(splitMapArr[i]);
                newSpace.setControlMoney(splitMapArr[i]);
                newSpace.setControlArmySize(splitMapArr[i]);
                newSpace.setPosition(lineCounter,i);
                newSpace.setSymbol(splitMapArr[i]);
                GOTmap.setTile(lineCounter,i,newSpace);
            }
            lineCounter++;
        }
    }
    
    // Place dragon glass at 5 random locations
    int glassCounter = 0;
    int randRow;
    int randCol;
    while(glassCounter < 5){
        randRow = rand()%24;
        randCol = rand()%15;
        if(GOTmap.getTile(randRow,randCol).getTileType() == "land"){
            GOTmap.setDragonGlass(randRow,randCol,true);
            glassCounter++;
        }
    }
    
    return GOTmap;
}


/** Algorithm: Reads the city, warrior, and hero text files to create arrays of my class objects.
 * 1. Read citiesGOT.txt and split each line.
 * 2. Create a new city for each line and fill that City object with the information from the current line.
 * 3. Add the current city to the cities array.
 * 4. Read warriorsGOT.txt and split each line.
 * 5. Create a new warrior for each line and fill that Warrior object with the information from the current line.
 * 6. Add the current Warrior to the warriors array.
 * 7. Read heroesGOT.txt and split each line.
 * 8. Create a new hero for each line and fill that Hero object with the information from the current line.
 * 9. Add the current Hero to the heroes array.
 * Parameters: an array of cities (City), and array of warriors (Warrior), an array iof heroes (Hero)
 * Output: nothing
 * Return: nothing
 */ 
void setUp(City GOTcities[26], Warrior GOTwarriors[14], Hero GOTheros[6]){
    // read cities
    int cityCounter = 0;
    ifstream cityFile;
    cityFile.open("citiesGOT.txt");
    string cityLine = "";
    string splitCityArr[5];
    while(getline(cityFile,cityLine)){
        if(cityCounter < 26){
            split(cityLine,',',splitCityArr,5);
            City newCity;
            newCity.setLetter(splitCityArr[0]);
            newCity.setCityName(splitCityArr[1]);
            newCity.setMoney(stoi(splitCityArr[2]));
            newCity.setarmy_size(stoi(splitCityArr[3]));
            newCity.setPoints(stoi(splitCityArr[4]));
            GOTcities[cityCounter] = newCity;
            cityCounter++;
        }
    }
    
    // read warriors
    int warriorCounter = 0;
    ifstream warriorFile;
    warriorFile.open("warriorsGOT.txt");
    string warriorLine = "";
    string splitWarriorArr[7];
    while(getline(warriorFile,warriorLine)){
        if (warriorCounter < 14){
            split(warriorLine,',',splitWarriorArr,7);
            Warrior newWarrior;
            newWarrior.setWarriorName(splitWarriorArr[0]);
            newWarrior.setStrength(stoi(splitWarriorArr[1]));
            newWarrior.setLoyalty(stoi(splitWarriorArr[2]));
            newWarrior.setMorale(stoi(splitWarriorArr[3]));
            newWarrior.setIsFree(splitWarriorArr[4]);
            newWarrior.setHasShip(splitWarriorArr[5]);
            newWarrior.setHasDragonglass(splitWarriorArr[6]);
            GOTwarriors[warriorCounter] = newWarrior;
            warriorCounter++;
        }
    }
    
    // read heroes
    int heroCounter = 0;
    ifstream heroFile;
    heroFile.open("heroesGOT.txt");
    string heroLine = "";
    string splitHeroArr[11];
    while(getline(heroFile,heroLine)){
        if(heroCounter < 6){
            split(heroLine,',',splitHeroArr,11);
            Hero newHero;
            newHero.setHeroName(splitHeroArr[0]);
            newHero.setHeroMoney(stoi(splitHeroArr[1]));
            newHero.setInfluence(stoi(splitHeroArr[2]));
            newHero.setArmySize(stoi(splitHeroArr[3]));
            for(int i=0; i<4; i++){
                if(splitHeroArr[i+4] != "NULL"){
                    for(int j=0; j<14; j++){
                        if(GOTwarriors[j].getWarriorName() == splitHeroArr[i+4]){
                            newHero.setWarrior(GOTwarriors[j],i);
                        }
                    }
                }
            }
            newHero.setLocation(stoi(splitHeroArr[8])-1,stoi(splitHeroArr[9])-1);
            newHero.setShip(splitHeroArr[10]);
            GOTheros[heroCounter] = newHero;
            heroCounter++;
        }
    }
    
}


/** Algorithm: Reads the city, warrior, and hero text files to create arrays of my class objects.
 * 1. Print out the user's goal in playing the game
 * 2. Print out the different attributes of each component of the game.
 * Parameters: the name of the user (string)
 * Output: An overview of instructions from the game
 * Return: nothing
 */ 
void showInstructions(string nameOfUser){
    cout << "You, " << nameOfUser << ", will play the role of a hero in a quest through the vast kingdom of Westeros";
    cout << " to defeat the other heroes and sit alone atop the \nIron Throne. Before you can achieve greatness, you must understand";
    cout << " what you're up against, and the tools you will have at your disposal." << endl;
    cout << "\nTraits of Heroes" << endl;
    cout << "  -Money: used to purchase more troops, and buy out other heroes' armies" << endl;
    cout << "  -Knights/Army: used to defeat other heroes in battle" << endl;
    cout << "  -Influence: used to win over other heroes' armies, and obtain their warriors" << endl;
    cout << "  -Starting Location: a pre-determined starting position, different from all other heroes" << endl;
    cout << "  -Warriors: heroes can have between 0 and 4 warriors throughout the game, using them in various situations to help achieve victory" << endl;
    cout << "  -Ship: heroes can only travel on water if they have a ship, or if a warrior in their party has a ship" << endl;
    cout << "  -Points: heroes gain points by completing various tasks and conquering more land\n" << endl;
    
    cout << "Traits of Warriors" << endl;
    cout << "  -Strength: when a part of a heroes' army, strength is used in battle against opposing heroes" << endl;
    cout << "  -Loyalty: used when a hero tries to buy out the army of another hero" << endl;
    cout << "  -Morale: used when a hero tries to use their influence to win over another heroes' army" << endl;
    cout << "  -Free: refers to whether or not a warrior is a part of a heroes' army, or if they are roaming free" << endl;
    cout << "  -Ship: warriors can only move on water if they have a ship" << endl;
    cout << "  -Dragonglass: indicates if a hero has the object dragonglass, a powerful weapon beneficial against the White Walkers" << endl;
    
    cout << "\nCities" << endl;
    cout << "  -Letter: on the map, each city is represented by a letter A-Z" << endl;
    cout << "  -Money: each hero gains the money associated with a city when arriving for the first time" << endl;
    cout << "  -Army Size: when a hero enters a city they obtain the given number of troops at that city" << endl;
    cout << "  -Points: every city has a certain number of points that will be awarded to the hero who captures it\n" << endl;
    

    cout << "You win the game by defeating the White Walkers, a tribe of lovable scamps who are on a mission to murder everyone ";
    cout << "in the kingdom and turn them into yetis. As you start increasing your army and controlling more territory, your ";
    cout << "chances of having to face the White Walkers also increases. Your goal is to have as many points as possible ";
    cout << "when you finally battle the White Walkers. To earn points, you must find and defeat the other heroes in" << endl;
    cout << "the kingdom, conquer territory, and assemble a large army." << endl;
    
    cout << "\nTo complete this task, you may choose to play as one of the provided six heroes, or create your own hero.\n" << endl;
}


/** Algorithm: Shows the user their current visibiity on the map based on their hero's position
 * 1. Create a new visibility array to be filled with symbols corresponding to the spaces around the user's hero.
 * 2. Define the starting row index as: the user's current row position - 3
 * 3. Define the starting column index as: the user's current column position - 3
 * 4. Iterate by row and column through the 7x7 array filling each element with the correct symbol, as follows:
 *      Check if the row or colum index is out of range of the map.
 *          If yes, fill the visibility array at its current (i,j) spot with an 'X'.
 *      Otherwise, fill the visibility array at its current (i,j) position with the symbol on the map corresponding to the current row/column index.
 *      At the end of a column, add one to the starting column index, and continue to iterate through the current row.
 *      At the end of a row, add one ot the starting row index, and continue to the next row.
 * 5. After filling the visibility array, simply print out each element row by column with a space in between each element.
 * Parameters: the user's current position (vector<int>), the map (Map)
 * Output: the 7x7 visibility on the map of the user's current location
 * Return: nothing
 */ 
void showMap(vector<int> pos, Map inMap){
    string visibility[7][7];
    int mapRow = pos[0] - 3;
    int mapCol = pos[1] - 3;
    
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            if(mapRow>24 || mapRow<0 || mapCol>15 || mapCol<0){
                visibility[i][j] = "X";
            }
            else{
                visibility[i][j] = inMap.getTile(mapRow,mapCol).getSymbol();
            }
            mapCol++;
        }
        mapRow++;
        mapCol = pos[1]-3;
    }
    
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            cout << visibility[i][j] << " ";
        }
        cout << endl;
    }
}


/** Algorithm: Welcomes the user to the game and acquires their name
 * 1. Print out a welcome to the user and ask tehm to state their name.
 * 2. Read their input and save the string as their name.
 * 3. Return their name.
 * Parameters: none
 * Output: A welcome statement for the beginning of the game
 * Return: the user's name (string)
 */ 
string getUsername(){
    string username;
    cout << "Welcome to the G A M E of T H R O N E S!" << endl;
    cout << "State your name, Your Grace: ";
    getline(cin,username);
    cout << "\n";
    return username;
}


/** Algorithm: Acquires the information about which hero the user would like to use, or allow them to create their own.
 * 1. Ask the user if they would like to choose an existing hero.
 * 2. Ensure that their input is valid before storing the value and moving on.
 * 3. If the user says yes.
 *      Once their input is valid, use a switch statement to compare their input with the numbers 1-6.
 *      Based on the number they selected, set the user's hero equal to the corresponding hero they desired.
 * 4. If the user says no.
 *      Display valid values for their hero's traits.
 *      Ask for the user to input values and ensure that they are valid.
 *      Once all input is valid, fill the user's hero with the information they entered.
 * 5. Return the user's hero (either one they created, or an existing hero)
 * Parameters: a hero array (Hero), the user name (string0, an array of warriosr (Warrior), a map (Map)
 * Output: Questions and other various statements to recieve proper input
 * Return: the user's chocie of a hero (Hero)
 */ 
Hero userChooseHero(Hero heroes[6], string user_name, Warrior inWarriors[14], Map inMap){
    Hero userHero;
    string userChoice;
    bool userFlag = false;
    cout << "Would you like to choose an existing hero " << user_name << ", Your Grace?(Y/N): ";
    getline(cin,userChoice);
    for(int i=0;i<userChoice.length(); i++){
        userChoice[i] = tolower(userChoice[i]);
    }
    if(userChoice.length() == 1){
        if(userChoice[0]!='y' && userChoice[0]!='n'){
            userFlag = true;
        }
    }
    while(userFlag || userChoice.length()>1){
        userFlag = false;
        cout << "Please choose Y or N: ";   
        getline(cin,userChoice);
        for(int i=0;i<userChoice.length(); i++){
            userChoice[i] = tolower(userChoice[i]);
        }
        if(userChoice.length() == 1){
            if(userChoice[0]!='y' && userChoice[0]!='n'){
                userFlag = true;
            }
        }
    }
    if(userChoice[0] == 'y'){
        cout << endl;
        string heroChoice;
        bool heroFlag = false;
        cout << "Please choose from the following heroes: " << endl;
        cout << "1. Cersei Lannister" << endl;
        cout << "2. Stannis Baratheon" << endl;
        cout << "3. Jon Snow" << endl;
        cout << "4. Sansa Stark" << endl;
        cout << "5. Euron Greyjoy" << endl;
        cout << "6. Daenerys Targaryen" << endl;
        getline(cin,heroChoice);
        if(heroChoice.length() == 1){
            if(heroChoice[0]<'1' || heroChoice[0]>'6'){
                heroFlag = true;
            }
        }
        while(heroFlag || heroChoice.length()>1){
            heroFlag = false;
            cout << "Please enter the number corresponding to the hero you desire: ";
            getline(cin,heroChoice);
            if(heroChoice.length() == 1){
                if(heroChoice[0]<'1' || heroChoice[0]>'6'){
                    heroFlag = true;
                }
            }
        }
        switch(heroChoice[0]){
            case '1':
            userHero = heroes[0];
            break;
            
            case '2':
            userHero = heroes[1];
            break;
            
            case '3':
            userHero = heroes[2];
            break;
            
            case '4':
            userHero = heroes[3];
            break;
            
            case '5':
            userHero = heroes[4];
            break;
            
            case '6':
            userHero = heroes[5];
            break;
        }
    }
    else{
        string userMoney,userInfluence,userArmySize,userRow,userCol;
        cout << "Your Grace " << user_name << ", you have chosen to go on this journey alone. Please provide starting values for your adventure.\n" << endl;
        cout << "Value" << "            " << "Valid Input" << endl;
        cout << "-----" << "            " << "-----------" << endl;
        cout << "Money" << "            " << "  0-10000" << endl;
        cout << "Influence" << "          " << "0-10000" << endl;
        cout << "Army Size" << "          " << "0-10000" << endl;
        cout << "Starting Row" << "         " << "1-25" << endl;
        cout << "Starting Column" << "      " << "1-16" << endl << endl;
        
        // Taking input for hero's money
        bool flag = false;
        cout << "Money: ";
        getline(cin,userMoney);
        for(int i=0; i<userMoney.length(); i++){
            if(userMoney[i]<'0' || userMoney[i]>'9'){
                flag = true;
            }
        }
        if(userMoney.length()>1 && (userMoney[0] == '0')){
            flag = true;
        }
        if(userMoney.length() == 5){
            if(userMoney[0] > '1'){
                flag = true;
            }
            else{
                for(int i=1; i<5; i++){
                    if(userMoney[i] != '0'){
                        flag = true;
                    }
                }
            }
        }
        while(flag || userMoney.length()>5){
            flag = false;
            cout << "Please enter a number between 0 and 10000: ";
            getline(cin,userMoney);
            for(int i=0; i<userMoney.length(); i++){
                if(userMoney[i]<'0' || userMoney[i]>'9'){
                    flag = true;
                }
            }
            if(userMoney.length()>1 && (userMoney[0] == '0')){
                flag = true;
            }
            if(userMoney.length() == 5){
                if(userMoney[0] > '1'){
                    flag = true;
                }
                else{
                    for(int i=1; i<5; i++){
                        if(userMoney[i] != '0'){
                            flag = true;
                        }
                    }
                }
            }
        }
        
        // Taking input for hero's Influence
        bool flag2 = false;
        cout << "Influence: ";
        getline(cin,userInfluence);
        for(int i=0; i<userInfluence.length(); i++){
            if(userInfluence[i]<'0' || userInfluence[i]>'9'){
                flag2 = true;
            }
        }
        if(userInfluence.length()>1 && (userInfluence[0] == '0')){
            flag2 = true;
        }
        if(userInfluence.length() == 5){
            if(userInfluence[0] > '1'){
                flag2 = true;
            }
            else{
                for(int i=1; i<5; i++){
                    if(userInfluence[i] != '0'){
                        flag2 = true;
                    }
                }
            }
        }
        while(flag2 || userInfluence.length()>5){
            flag2 = false;
            cout << "Please enter a number between 0 and 10000: ";
            getline(cin,userInfluence);
            for(int i=0; i<userInfluence.length(); i++){
                if(userInfluence[i]<'0' || userInfluence[i]>'9'){
                    flag2 = true;
                }
            }
            if(userInfluence.length()>1 && (userInfluence[0] == '0')){
                flag2 = true;
            }
            if(userInfluence.length() == 5){
                if(userInfluence[0] > '1'){
                    flag2 = true;
                }
                else{
                    for(int i=1; i<5; i++){
                        if(userInfluence[i] != '0'){
                            flag2 = true;
                        }
                    }
                }
            }
        }
        
        // Taking input for hero's Army Size
        bool flag3 = false;
        cout << "Army Size: ";
        getline(cin,userArmySize);
        for(int i=0; i<userArmySize.length(); i++){
            if(userArmySize[i]<'0' || userArmySize[i]>'9'){
                flag3 = true;
            }
        }
        if(userArmySize.length()>1 && (userArmySize[0] == '0')){
            flag3 = true;
        }
        if(userArmySize.length() == 5){
            if(userArmySize[0] > '1'){
                flag3 = true;
            }
            else{
                for(int i=1; i<5; i++){
                    if(userArmySize[i] != '0'){
                        flag3 = true;
                    }
                }
            }
        }
        while(flag3 || userArmySize.length()>5){
            flag3 = false;
            cout << "Please enter a number between 0 and 10000: ";
            getline(cin,userArmySize);
            for(int i=0; i<userArmySize.length(); i++){
                if(userArmySize[i]<'0' || userArmySize[i]>'9'){
                    flag3 = true;
                }
            }
            if(userArmySize.length()>1 && (userArmySize[0] == '0')){
                flag3 = true;
            }
            if(userArmySize.length() == 5){
                if(userArmySize[0] > '1'){
                    flag3 = true;
                }
                else{
                    for(int i=1; i<5; i++){
                        if(userArmySize[i] != '0'){
                            flag3 = true;
                        }
                    }
                }
            }
        }
        
        // Taking input for hero's Row index
        bool flag4 = false;
        cout << "Starting Row: ";
        getline(cin,userRow);
        if(userRow.length() == 1){
            if(userRow[0] <= '0' || userRow[0] > '9'){
                flag4 = true;
            }
        }
        else if(userRow.length() == 2){
            if(userRow[0]!='1' && userRow[0]!='2'){
                flag4 = true;
            }
            else if(userRow[0] == '1'){
                if(userRow[1] > '9' || userRow[1] < '0'){
                    flag4 = true;
                }
            }
            else if(userRow[0] == '2'){
                if(userRow[1] > '5' || userRow[1] < '0'){
                    flag4 = true;
                }
            }
        }
        while(flag4 || userRow.length()>2){
            flag4 = false;
            cout << "Please enter a number between 1 and 25: ";
            getline(cin,userRow);
            if(userRow.length() == 1){
                if(userRow[0] <= '0' || userRow[0] > '9'){
                    flag4 = true;
                }
            }
            else if(userRow.length() == 2){
                if(userRow[0]!='1' && userRow[0]!='2'){
                    flag4 = true;
                }
                else if(userRow[0] == '1'){
                    if(userRow[1] > '9' || userRow[1] < '0'){
                        flag4 = true;
                    }
                }
                else if(userRow[0] == '2'){
                    if(userRow[1] > '5' || userRow[1] < '0'){
                        flag4 = true;
                    }
                }
            }
        }
        
        // Taking input for hero's Column index
        bool flag5 = false;
        cout << "Starting Column: ";
        getline(cin,userCol);
        if(userCol.length() == 1){
            if(userCol[0] <= '0' || userCol[0] > '9'){
                flag5 = true;
            }
        }
        else if(userCol.length() == 2){
            if(userCol[0]!='1'){
                flag5 = true;
            }
            else if(userCol[0] == '1'){
                if(userCol[1] > '6' || userCol[1] < '0'){
                    flag5 = true;
                }
            }
        }
        while(flag5 || userCol.length()>2){
            flag5 = false;
            cout << "Please enter a number between 1 and 16: ";
            getline(cin,userCol);
            if(userCol.length() == 1){
                if(userCol[0] <= '0' || userCol[0] > '9'){
                    flag5 = true;
                }
            }
            else if(userCol.length() == 2){
                if(userCol[0]!='1'){
                    flag5 = true;
                }
                else if(userCol[0] == '1'){
                    if(userCol[1] > '6' || userCol[1] < '0'){
                        flag5 = true;
                    }
                }
            }
        }
        
        // Variables for determining if the user entered location is taken
        bool validLoc=false,heroLoc=true,warriorLoc=false;
        string userHasShip = "no";
        vector<int> userPosition = {stoi(userRow)-1,stoi(userCol)-1};
        
        // Making sure the location is valid and different from every hero/warrior
        for(int i=0; i<6; i++){
            if(userPosition == heroes[i].getLocation()){
                heroLoc = false;
            }
        }
        if(heroLoc){
            warriorLoc = true;
            for(int j=0; j<14; j++){
                if(userPosition == inWarriors[j].getWarriorPosition()){
                    warriorLoc = false;
                }
            }
        }
        if(warriorLoc){
            validLoc = true;
            if(inMap.getTile(userPosition[0],userPosition[1]).getTileType() == "water"){
                userHasShip = "yes";
            }
        }
        while(!validLoc){
            cout << "That space is already taken. Please pick another position." << endl;
            
            // Taking input for hero's Row index
            bool flag4 = false;
            cout << "Starting Row: ";
            getline(cin,userRow);
            if(userRow.length() == 1){
                if(userRow[0] <= '0' || userRow[0] > '9'){
                    flag4 = true;
                }
            }
            else if(userRow.length() == 2){
                if(userRow[0]!='1' && userRow[0]!='2'){
                    flag4 = true;
                }
                else if(userRow[0] == '1'){
                    if(userRow[1] > '9' || userRow[1] < '0'){
                        flag4 = true;
                    }
                }
                else if(userRow[0] == '2'){
                    if(userRow[1] > '5' || userRow[1] < '0'){
                        flag4 = true;
                    }
                }
            }
            while(flag4 || userRow.length()>2){
                flag4 = false;
                cout << "Please enter a number between 1 and 25: ";
                getline(cin,userRow);
                if(userRow.length() == 1){
                    if(userRow[0] <= '0' || userRow[0] > '9'){
                        flag4 = true;
                    }
                }
                else if(userRow.length() == 2){
                    if(userRow[0]!='1' && userRow[0]!='2'){
                        flag4 = true;
                    }
                    else if(userRow[0] == '1'){
                        if(userRow[1] > '9' || userRow[1] < '0'){
                            flag4 = true;
                        }
                    }
                    else if(userRow[0] == '2'){
                        if(userRow[1] > '5' || userRow[1] < '0'){
                            flag4 = true;
                        }
                    }
                }
            }
            
            // Taking input for hero's Column index
            bool flag5 = false;
            cout << "Starting Column: ";
            getline(cin,userCol);
            if(userCol.length() == 1){
                if(userCol[0] <= '0' || userCol[0] > '9'){
                    flag5 = true;
                }
            }
            else if(userCol.length() == 2){
                if(userCol[0]!='1'){
                    flag5 = true;
                }
                else if(userCol[0] == '1'){
                    if(userCol[1] > '6' || userCol[1] < '0'){
                        flag5 = true;
                    }
                }
            }
            while(flag5 || userCol.length()>2){
                flag5 = false;
                cout << "Please enter a number between 1 and 16: ";
                getline(cin,userCol);
                if(userCol.length() == 1){
                    if(userCol[0] <= '0' || userCol[0] > '9'){
                        flag5 = true;
                    }
                }
                else if(userCol.length() == 2){
                    if(userCol[0]!='1'){
                        flag5 = true;
                    }
                    else if(userCol[0] == '1'){
                        if(userCol[1] > '6' || userCol[1] < '0'){
                            flag5 = true;
                        }
                    }
                }
            }
            
            validLoc=false,heroLoc=true,warriorLoc=false;
            userPosition[0] = stoi(userRow)-1;
            userPosition[1] = stoi(userCol)-1;
            
            // Making sure the location is valid and different from every hero/warrior
            for(int i=0; i<6; i++){
                if(userPosition == heroes[i].getLocation()){
                    heroLoc = false;
                }
            }
            if(heroLoc){
                warriorLoc = true;
                for(int j=0; j<14; j++){
                    if(userPosition == inWarriors[j].getWarriorPosition()){
                        warriorLoc = false;
                    }
                }
            }
            if(warriorLoc){
                validLoc = true;
                if(inMap.getTile(userPosition[0],userPosition[1]).getTileType() == "water"){
                    userHasShip = "yes";
                }
            }
        }
        
        // Setting the values of the hero created by the user
        userHero.setHeroName("Self");
        userHero.setHeroMoney(stoi(userMoney));
        userHero.setInfluence(stoi(userInfluence));
        userHero.setArmySize(stoi(userArmySize));
        userHero.setLocation(userPosition[0],userPosition[1]);
        userHero.setShip(userHasShip);
        
    }
    return userHero;
}


/** Algorithm: Sets the initial locations of all warriors.
 * 1. Iterate through all warriors and check if they are attached to a hero.
 *      If yes, set that warrior's location equal to the same location as their hero.
 * 2. For all warriors not attached to heroes.
 *      Generate a random value for row and column.
 *      Checks that the location is not already occupied by one of the heroes.
 *      Checks if the location is land or water, and whether or not the warrior has a ship.
 *      Once all conditions have been met, assign the current hero the randomly generated position.
 *      Move on to the next Warrior.
 * Parameters: an array of warriors (Warrior), an array of heroes (Hero), a map (Map)
 * Output: A welcome statement for the beginning of the game
 * Return: nothing
 */ 
void setInitialLocations(Warrior warriorsGOT[14], Hero heroesGOT[6], Map mapGOT){
    // Set Warrior positions that are attached to heroes
    for(int i=0; i<14; i++){
        if(!(warriorsGOT[i].getIsFree())){
            for(int j=0; j<6; j++){
                for(int k=0; k<4; k++){
                    if(heroesGOT[j].getHeroWarrior(k).getWarriorName() == warriorsGOT[i].getWarriorName()){
                        warriorsGOT[i].setWarriorPosition(heroesGOT[j].getLocation()[0],heroesGOT[j].getLocation()[1]);
                    }
                }
            }
        }
    }
    
    // Set all other warriors
    vector<int> tempPosition = {0,0};
    bool posFlag,heroSpot=false,warriorSpot=false;
    for(int i=0; i<14; i++){
        if(warriorsGOT[i].getIsFree()){
            posFlag = true;
            while(posFlag){
                // generates position 
                tempPosition[0] = rand()%24;
                tempPosition[1] = rand()%15;
                // checks if the position is equal to a position of one of the heroes
                for(int j=0; j<6; j++){
                     if(tempPosition != heroesGOT[j].getLocation()){
                        heroSpot = true;
                    }
                }
                // If the random location is not equal to one of the heroes' location
                if(heroSpot){
                    for(int k=0; k<14; k++){
                        if(k!=i){
                            if(tempPosition != warriorsGOT[k].getWarriorPosition()){
                            warriorSpot = true;
                            }
                        }
                    }
                    // If the location is not one of the other warrior's locations
                    if(warriorSpot){
                        // Check if the warrior has a ship
                        if(warriorsGOT[i].getHasShip() && (mapGOT.getTile(tempPosition[0],tempPosition[1]).getTileType() == "water")){
                            warriorsGOT[i].setWarriorPosition(tempPosition[0],tempPosition[1]);
                            posFlag = false;
                        }
                        else if(!(warriorsGOT[i].getHasShip()) && (mapGOT.getTile(tempPosition[0],tempPosition[1]).getTileType() == "land")){
                            warriorsGOT[i].setWarriorPosition(tempPosition[0],tempPosition[1]);
                            posFlag = false;
                        }
                    }
                }
            }
        }
    }
}


/** Algorithm: Adds points to a hero based on their current location
 * 1. Check if the hero's position is a city.
 *      If yes, add the corresponding number of points to the hero's points.
 * 2. If no, add the number of points to the hero corresponding to whether the space is water or land.
 * Parameters: a hero (Hero&), a map (Map), an array of cities (City)
 * Output: nothing
 * Return: nothing
 */ 
void addPointsToHero(Hero& GOThero, Map mapIn,City cityArr[26]){
    int pointsToAdd;
    if(mapIn.getTile(GOThero.getLocation()[0],GOThero.getLocation()[1]).getTileType() == "city"){
        for(int i=0; i<25; i++){
            if(mapIn.getTile(GOThero.getLocation()[0],GOThero.getLocation()[1]).getSymbol() == cityArr[i].getLetter()){
                pointsToAdd = cityArr[i].getPoints();
            }
        }
    }
    else{
        pointsToAdd = mapIn.getTile(GOThero.getLocation()[0],GOThero.getLocation()[1]).getControlPoints();
    }
    
    GOThero.addHeroPoints(pointsToAdd);
}


/** Algorithm: Give the user options for what they can do on their turn, and carry out the decision they make.
 * 1. Present the user with choices for their turn.
 * 2. Ensure valid input, and once input is valid check what their response was.
 * 3. Use a switch statement to carry out the user's decision.
 *      If the user entered 1 (travel), ask which direction they want to go.
 *          Ensure that the direction they pick is valid, based on whether the position is off the map or if it's water.
 *          Use a switch statement to move the user's hero in the chosen direction, and update the position of the hero.
 *      If the user entered 2 (rest), add one to the strength of every warrior in their party.
 *      If the user entered 3 (consult the gods), add one to the morale of every warrior in their party.
 * 
 * Parameters: a hero (Hero&), a map (Map), an array of warriors (Warrior)
 * Output: Various statements to give the user options and ensure valid input
 * Return: none
 */ 
void takeTurn(Hero& inUserHero, Map turnMap, Warrior GOTWarriors[14]){
    string userTurnChoice;
    bool userTurnFlag = false;
    cout << "\nIt is now your turn. Here is your current visibility with your hero located at the center:" << endl;
    showMap(inUserHero.getLocation(),turnMap);
    cout << "\nWhat would you like to do? " << endl;
    cout << "1. Travel" << endl << "   " << "-Move North, South, East, or West" << endl;
    cout << "2. Rest" << endl << "   " << "-Location remains unchanged" << endl << "   ";
    cout << "-Each warrior in your party increases their strength by 1" << endl;
    cout << "3. Consult with the gods" << endl << "   " << "-Location remains unchanged" << endl << "   ";
    cout << "-Each warrior in your party increases their morale by 1" << endl;
    getline(cin,userTurnChoice);
    if(userTurnChoice.length() == 1){
        if(userTurnChoice[0]<'1' || userTurnChoice[0]>'3'){
            userTurnFlag = true;
        }
    }
    while(userTurnFlag || userTurnChoice.length()>1){
        userTurnFlag = false;
        cout << "Please enter the number corresponding to your decision: ";
        getline(cin,userTurnChoice);
        if(userTurnChoice.length() == 1){
            if(userTurnChoice[0]<'1' || userTurnChoice[0]>'3'){
                userTurnFlag = true;
            }
        }
    }
    
    
    // Variables for determining valid inputs
    string travelDirection;
    bool travelFlag = false,canTravelWater=false,validDirection=false;
    int newHeroRow;
    int newHeroCol;
    
    switch(userTurnChoice[0]){
        
        case '1':
        
        while(!validDirection){
            cout << "\nDo you want to travel N,E,S or W? ";
            getline(cin,travelDirection);
            for(int i=0;i<travelDirection.length(); i++){
                travelDirection[i] = tolower(travelDirection[i]);
            }
            if(travelDirection.length() > 1){
                travelFlag = true;
            }
            else if(travelDirection.length() == 1){
                if(travelDirection[0] != 'n' && travelDirection[0] != 'e' && travelDirection[0] != 's' && travelDirection[0] != 'w'){
                    travelFlag = true;
                }
            }
            while(travelFlag){
                travelFlag = false;
                cout << "Please enter N,E,S or W: ";
                getline(cin,travelDirection);
                for(int i=0;i<travelDirection.length(); i++){
                    travelDirection[i] = tolower(travelDirection[i]);
                }
                if(travelDirection.length() > 1){
                    travelFlag = true;
                }
                else if(travelDirection.length() == 1){
                    if(travelDirection[0] != 'n' && travelDirection[0] != 'e' && travelDirection[0] != 's' && travelDirection[0] != 'w'){
                        travelFlag = true;
                    }
                }
            }
            
            switch(travelDirection[0]){
                
                case 'n':
                    newHeroRow = inUserHero.getLocation()[0]-1;
                    if(newHeroRow < 0){
                        cout << "You cannot travel outside of Westeros. ";
                        validDirection = false;
                    }
                    else if(turnMap.getTile(newHeroRow,inUserHero.getLocation()[1]).getTileType() == "water"){
                        if(inUserHero.getShip()){
                            canTravelWater = true;
                        }
                        for(int i=0; i<4; i++){
                            if(inUserHero.getHeroWarrior(i).getHasShip()){
                                canTravelWater = true;
                            }
                        }
                        if(!canTravelWater){
                            cout << "You cannot travel across water beacuse neither you nor any of your warriors has a ship. ";
                            validDirection = false;
                        }
                        else{
                            validDirection = true;
                        }
                    }
                    else{
                        validDirection = true;
                    }
                    
                    if(validDirection){
                        inUserHero.setLocation(newHeroRow,inUserHero.getLocation()[1]);
                    }
                    else{
                        cout << "You must travel a direction other than North." << endl;
                    }
                    
                    break;
                
                case 'e':
                    newHeroCol = inUserHero.getLocation()[1]+1;
                    if(newHeroCol > 15){
                        cout << "You cannot travel outside of Westeros. ";
                        validDirection = false;
                    }
                    else if(turnMap.getTile(inUserHero.getLocation()[0],newHeroCol).getTileType() == "water"){
                        if(inUserHero.getShip()){
                            canTravelWater = true;
                        }
                        for(int i=0; i<4; i++){
                            if(inUserHero.getHeroWarrior(i).getHasShip()){
                                canTravelWater = true;
                            }
                        }
                        if(!canTravelWater){
                            cout << "You cannot travel across water beacuse neither you nor any of your warriors has a ship. ";
                            validDirection = false;
                        }
                        else{
                            validDirection = true;
                        }
                    }
                    else{
                        validDirection = true;
                    }
                    
                    if(validDirection){
                        inUserHero.setLocation(inUserHero.getLocation()[0],newHeroCol);
                    }
                    else{
                        cout << "You must travel a direction other than East." << endl;
                    }
                    
                    break;
                    
                case 's':
                    newHeroRow = inUserHero.getLocation()[0]+1;
                    if(newHeroRow > 24){
                        cout << "You cannot travel outside of Westeros. ";
                        validDirection = false;
                    }
                    else if(turnMap.getTile(newHeroRow,inUserHero.getLocation()[1]).getTileType() == "water"){
                        if(inUserHero.getShip()){
                            canTravelWater = true;
                        }
                        for(int i=0; i<4; i++){
                            if(inUserHero.getHeroWarrior(i).getHasShip()){
                                canTravelWater = true;
                            }
                        }
                        if(!canTravelWater){
                            cout << "You cannot travel across water because neither you nor any of your warriors has a ship. ";
                            validDirection = false;
                        }
                        else{
                            validDirection = true;
                        }
                    }
                    else{
                        validDirection = true;
                    }
                    
                    if(validDirection){
                        inUserHero.setLocation(newHeroRow,inUserHero.getLocation()[1]);
                    }
                    else{
                        cout << "You must travel a direction other than South." << endl;
                    }
                    
                    break;
                    
                case 'w':
                    newHeroCol = inUserHero.getLocation()[1]-1;
                    if(newHeroCol < 0){
                        cout << "You cannot travel outside of Westeros. ";
                        validDirection = false;
                    }
                    else if(turnMap.getTile(inUserHero.getLocation()[0],newHeroCol).getTileType() == "water"){
                        if(inUserHero.getShip()){
                            canTravelWater = true;
                        }
                        for(int i=0; i<4; i++){
                            if(inUserHero.getHeroWarrior(i).getHasShip()){
                                canTravelWater = true;
                            }
                        }
                        if(!canTravelWater){
                            cout << "You cannot travel across water beacuse neither you nor any of your warriors has a ship. ";
                            validDirection = false;
                        }
                        else{
                            validDirection = true;
                        }
                    }
                    else{
                        validDirection = true;
                    }
                    
                    if(validDirection){
                        inUserHero.setLocation(inUserHero.getLocation()[0],newHeroCol);
                    }
                    else{
                        cout << "You must travel a direction other than West." << endl;
                    }
                    
                    break;
            }
        }
        
        break;
        
        case '2':
        
        for(int i=0; i<4; i++){
            if(inUserHero.getHeroWarrior(i).getWarriorName() != ""){
                if(inUserHero.getHeroWarrior(i).getStrength()+1 > 200){
                    inUserHero.getHeroWarrior(i).setStrength(200);
                }
                else{
                    inUserHero.getHeroWarrior(i).setStrength(inUserHero.getHeroWarrior(i).getStrength()+1);
                }
            }
            for(int j=0; j<14; j++){
                if(GOTWarriors[j].getWarriorName() == inUserHero.getHeroWarrior(i).getWarriorName()){
                    if(GOTWarriors[i].getStrength()+1 > 200){
                        GOTWarriors[j].setStrength(200); 
                    }
                    else{
                        GOTWarriors[j].setStrength(GOTWarriors[j].getStrength()+1); 
                    }
                }
            }
        }
        
        break;
        
        case '3':
        
        for(int i=0; i<4; i++){
            if(inUserHero.getHeroWarrior(i).getWarriorName() != ""){
                if(inUserHero.getHeroWarrior(i).getMorale()+1 > 100){
                    inUserHero.getHeroWarrior(i).setMorale(100);
                }
                else{
                    inUserHero.getHeroWarrior(i).setMorale(inUserHero.getHeroWarrior(i).getMorale()+1);
                }
            }
            for(int j=0; j<14; j++){
                if(GOTWarriors[j].getWarriorName() == inUserHero.getHeroWarrior(i).getWarriorName()){
                    if(GOTWarriors[i].getMorale()+1 > 100){
                        GOTWarriors[j].setMorale(100); 
                    }
                    else{
                        GOTWarriors[j].setMorale(GOTWarriors[j].getMorale()+1); 
                    }
                }
            }
        }
        
        break;
    }
}


/** Algorithm: Move every hero in the game in a random direction that is valid.
 * 1. Loop through each hero in the heroes array.
 * 2. Check if the current hero's name is not equal to the user's hero name, and the hero is alive
 * 3. Generate a random value between 0 and 3 to determine the direction of movement.
 * 4. Use a switch statement to move the current hero in the direction corresponding to the random number generated.
 * 5. Check that the hero can move in that direction, based on whether or not they have a ship or if the new space is out of bounds.
 * 6. Keep generating a direction until the current hero can move there, then update their location.
 * 7. Do this for each hero in the game.
 * Parameters: a hero array (Hero), a map (Map), the hero corresponding to the user (Hero)
 * Output: none
 * Return: none
 */
void moveHeroesRandomly(Hero heroesArr[6], Map moveMap, Hero heroUser){
    // Variables to determine valid directions
    int randomDirection,newRow,newCol;
    bool locationIsValid,travelWater;
    
    for(int i=0; i<6; i++){
        if((heroesArr[i].getHeroName() != heroUser.getHeroName()) && heroesArr[i].getIsAlive()){
            locationIsValid = false;
            travelWater = false;
            while(!locationIsValid){
                randomDirection = rand() % 3;
                switch(randomDirection){
                    case 0: // north
                        newRow = heroesArr[i].getLocation()[0]-1;
                        if(newRow < 0){
                            locationIsValid = false;
                        }
                        else if(moveMap.getTile(newRow,heroesArr[i].getLocation()[1]).getTileType() == "water"){
                            if(heroesArr[i].getShip()){
                                travelWater = true;
                            }
                            for(int i=0; i<4; i++){
                                if(heroesArr[i].getHeroWarrior(i).getHasShip()){
                                    travelWater = true;
                                }
                            }
                            if(!travelWater){
                                locationIsValid = false;
                            }
                            else{
                                locationIsValid = true;
                            }
                        }
                        else{
                            locationIsValid = true;
                        }
                        
                        if(locationIsValid){
                            heroesArr[i].setLocation(newRow,heroesArr[i].getLocation()[1]);
                        }
                    break;
                    
                    case 1: // east
                        newCol = heroesArr[i].getLocation()[1]+1;
                        if(newCol > 15){
                            locationIsValid = false;
                        }
                        else if(moveMap.getTile(heroesArr[i].getLocation()[0],newCol).getTileType() == "water"){
                            if(heroesArr[i].getShip()){
                                travelWater = true;
                            }
                            for(int i=0; i<4; i++){
                                if(heroesArr[i].getHeroWarrior(i).getHasShip()){
                                    travelWater = true;
                                }
                            }
                            if(!travelWater){
                                locationIsValid = false;
                            }
                            else{
                                locationIsValid = true;
                            }
                        }
                        else{
                            locationIsValid = true;
                        }
                        if(locationIsValid){
                            heroesArr[i].setLocation(heroesArr[i].getLocation()[0],newCol);
                        }
                        break;
                    
                    case 2: // south
                        newRow = heroesArr[i].getLocation()[0]+1;
                        if(newRow > 24){
                            locationIsValid = false;
                        }
                        else if(moveMap.getTile(newRow,heroesArr[i].getLocation()[1]).getTileType() == "water"){
                            if(heroesArr[i].getShip()){
                                travelWater = true;
                            }
                            for(int i=0; i<4; i++){
                                if(heroesArr[i].getHeroWarrior(i).getHasShip()){
                                    travelWater = true;
                                }
                            }
                            if(!travelWater){
                                locationIsValid = false;
                            }
                            else{
                                locationIsValid = true;
                            }
                        }
                        else{
                            locationIsValid = true;
                        }
                        
                        if(locationIsValid){
                            heroesArr[i].setLocation(newRow,heroesArr[i].getLocation()[1]);
                        }
                    break;
                    
                    case 3: // west
                        newCol = heroesArr[i].getLocation()[1]-1;
                        if(newCol < 0){
                            locationIsValid = false;
                        }
                        else if(moveMap.getTile(heroesArr[i].getLocation()[0],newCol).getTileType() == "water"){
                            if(heroesArr[i].getShip()){
                                travelWater = true;
                            }
                            for(int i=0; i<4; i++){
                                if(heroesArr[i].getHeroWarrior(i).getHasShip()){
                                    travelWater = true;
                                }
                            }
                            if(!travelWater){
                                locationIsValid = false;
                            }
                            else{
                                locationIsValid = true;
                            }
                        }
                        else{
                            locationIsValid = true;
                        }
                        if(locationIsValid){
                            heroesArr[i].setLocation(heroesArr[i].getLocation()[0],newCol);
                        }
                        break;
                }
            }
        }
    }
}


/** Algorithm: Moves every free roaming warrior in the game to a random position, or sets their position equal to their hero's location.
 * 1. Loop through each warrior in the warriors array.
 * 2. Check if the current warrior is free.
 *      If yes...
 *          Generate a random value between 0 and 3 to determine the direction of movement.
 *          Use a switch statement to move the current warrior in the direction corresponding to the random number generated.
 *          Check that the warrior can move in that direction, based on whether or not they have a ship or if the new space is out of bounds.
 *          Keep generating a direction until the current warrior can move there, then update their location.
 * 3. If they are not free, set their location equal to the position of the hero they are attached to.
 * Parameters: a hero array (hero), a warrior array (Warrior), a map (Map)
 * Output: none
 * Return: none
 */ 
void moveWarriorsRandomly(Hero heroArr[6], Warrior warriorArr[14], Map warriorMap){
    int randomDirection,newRow,newCol;
    bool locationIsValid,travelWater;
    
    for(int i=0; i<14; i++){
        if(warriorArr[i].getIsFree()){
            locationIsValid = false;
            travelWater = false;
            while(!locationIsValid){
                randomDirection = rand() % 3;
                switch(randomDirection){
                    case 0: // north
                        newRow = warriorArr[i].getWarriorPosition()[0]-1;
                        if(newRow < 0){
                            locationIsValid = false;
                        }
                        else if(warriorMap.getTile(newRow,warriorArr[i].getWarriorPosition()[1]).getTileType() == "water"){
                            if(warriorArr[i].getHasShip()){
                                travelWater = true;
                            }
                            if(!travelWater){
                                locationIsValid = false;
                            }
                            else{
                                locationIsValid = true;
                            }
                        }
                        else{
                            locationIsValid = true;
                        }
                        
                        if(locationIsValid){
                            warriorArr[i].setWarriorPosition(newRow,warriorArr[i].getWarriorPosition()[1]);
                        }
                    break;
                    
                    case 1: // east
                        newCol = warriorArr[i].getWarriorPosition()[1]+1;
                        if(newCol > 15){
                            locationIsValid = false;
                        }
                        else if(warriorMap.getTile(warriorArr[i].getWarriorPosition()[0],newCol).getTileType() == "water"){
                            if(warriorArr[i].getHasShip()){
                                travelWater = true;
                            }
                            if(!travelWater){
                                locationIsValid = false;
                            }
                            else{
                                locationIsValid = true;
                            }
                        }
                        else{
                            locationIsValid = true;
                        }
                        if(locationIsValid){
                            warriorArr[i].setWarriorPosition(warriorArr[i].getWarriorPosition()[0],newCol);
                        }
                        break;
                    
                    case 2: // south
                        newRow = warriorArr[i].getWarriorPosition()[0]+1;
                        if(newRow > 24){
                            locationIsValid = false;
                        }
                        else if(warriorMap.getTile(newRow,warriorArr[i].getWarriorPosition()[1]).getTileType() == "water"){
                            if(warriorArr[i].getHasShip()){
                                travelWater = true;
                            }
                            if(!travelWater){
                                locationIsValid = false;
                            }
                            else{
                                locationIsValid = true;
                            }
                        }
                        else{
                            locationIsValid = true;
                        }
                        
                        if(locationIsValid){
                            warriorArr[i].setWarriorPosition(newRow,warriorArr[i].getWarriorPosition()[1]);
                        }
                    break;
                    
                    case 3: // west
                        newCol = warriorArr[i].getWarriorPosition()[1]-1;
                        if(newCol < 0){
                            locationIsValid = false;
                        }
                        else if(warriorMap.getTile(warriorArr[i].getWarriorPosition()[0],newCol).getTileType() == "water"){
                            if(warriorArr[i].getHasShip()){
                                travelWater = true;
                            }
                            if(!travelWater){
                                locationIsValid = false;
                            }
                            else{
                                locationIsValid = true;
                            }
                        }
                        else{
                            locationIsValid = true;
                        }
                        if(locationIsValid){
                            warriorArr[i].setWarriorPosition(warriorArr[i].getWarriorPosition()[0],newCol);
                        }
                        break;
                }
            }
        }
        else{
            for(int j=0; j<6; j++){
                for(int k=0; k<4; k++){
                    if(warriorArr[i].getWarriorName() == heroArr[j].getHeroWarrior(k).getWarriorName()){
                        warriorArr[i].setWarriorPosition(heroArr[j].getLocation()[0],heroArr[j].getLocation()[1]);
                        heroArr[j].getHeroWarrior(k).setWarriorPosition(heroArr[j].getLocation()[0],heroArr[j].getLocation()[1]);
                    }
                }
            }
        }
    }
}


/** Algorithm: Determines if there are any enemy heroes in the proximity of the user's hero.
 * 1. Creates a location vector representing the first index of the 5x5 box around the user's hero.
 * 2. Loops through 5 rows and 5 columns checking if the location vector is equal to the location of the opposing hero.
 * 3. If yes, set the encounter variable equal to true.
 * 3. Add one to the column value after every column has been iterated through, and add one to the row value after each row.
 * 4. After a row, reset the colum value to the original value.
 * 6. Return the boolean value representing whether or not the given opposing hero is in the 
 * Parameters: the main hero (Hero), an opposing hero (Hero)
 * Output: none
 * Return: a value indicating whether or not an encounter is going to take place (bool)
 */ 
bool checkUserEncounter(Hero mainHero, Hero otherHero){
    vector<int> locationVector = {mainHero.getLocation()[0] - 2,mainHero.getLocation()[1] - 2};
    bool isEncounter = false;
    for(int i=0; i<5; i++){
        for(int j=0; j<5;j++){
            if(otherHero.getLocation() == locationVector){
                isEncounter = true;
            }
            locationVector[1]++;
        }
        locationVector[1] = mainHero.getLocation()[1] - 2;
        locationVector[0]++;
    }
    return isEncounter;
}


/** Algorithm: Presents the user with their options when faced with an encounter.
 * 1. Display to the user what their options are during an encounter.
 * 2. Ensures that their choice is valid, and then returns the string corresponding to their choice.
 * Parameters: the hero who is engaging in the encounter with the main hero (Hero)
 * Output: various statements to aqcuire input for the user's decisions
 * Return: the letter corresponding to the user's decision (string)
 */ 
string heroEncounterOption(Hero encounterHero){
    bool encounterFlag = false;
    string userEncounterChoice;
    cout << "\nYou have encountered " << encounterHero.getHeroName() << ". What would you like to do?" << endl;
    cout << "1. Give a speech" << endl;
    cout << "  -Rely on your influence to win over the other hero’s army" << endl;
    cout << "2. Buy them outright" << endl;
    cout << "  -Rely on your money to buy out the other hero’s army." << endl;
    cout << "3. Battle" << endl;
    cout << "  -You and the other hero rely on the size of your army and the strength of your warriors." << endl;
    getline(cin,userEncounterChoice);
    if(userEncounterChoice.length() == 1){
        if(userEncounterChoice[0]<'1' || userEncounterChoice[0]>'3'){
            encounterFlag = true;
        }
    }
    while(encounterFlag || userEncounterChoice.length()>1){
        encounterFlag = false;
        cout << "Please enter the number corresponding to your decision: ";
        getline(cin,userEncounterChoice);
        if(userEncounterChoice.length() == 1){
            if(userEncounterChoice[0]<'1' || userEncounterChoice[0]>'3'){
                encounterFlag = true;
            }
        }
    }
    return userEncounterChoice;
}


/** Algorithm: Conducts the process of the user giving a speech.
 * 1. Calculates the probability of the user winning the encounter.
 * 2. If the user loses (the probability is less than or equal to 1)...
 *      Set the user hero's influence to half of its current value.
 * 3. If the hero wins (the probability is equal to 1)...       
 *      Add the opposing hero's money, influence, and army size to the user's hero, and give the user the warriors of the opposing hero.
 * Parameters: the main hero (Hero), the opposing hero in the encounter (Hero), the map (Map&), a warrior array (Warrior)
 * Output: that the opposing hero has retired if they lose the encounter
 * Return: none
 */ 
void giveSpeech(Hero heroMain, Hero opposingHero, Map& mapSpeech, Warrior speechWarriors[14]){
    double heroWin = (1 - opposingHero.getHeroWarrior(0).getMorale()/100.0)*(heroMain.getInfluence()/1600.0);
    
    if(heroWin <= 0){
        heroMain.setInfluence(heroMain.getInfluence()/2);
    }
    else if(heroWin == 1){
        cout << opposingHero.getHeroName() << " has retired." << endl;
        opposingHero.setIsAlive(false);
        
        // --> Present Option to pick warriors
        heroMain.setHeroMoney(heroMain.getHeroMoney()+opposingHero.getHeroMoney());
        heroMain.setInfluence(heroMain.getInfluence()+opposingHero.getInfluence());
        heroMain.setArmySize(heroMain.getArmySize()+opposingHero.getArmySize());
        for(int i=0; i<25; i++){
            for(int j=0; j<16; j++){
                if(mapSpeech.getTile(i,j).getOwner().getHeroName() == opposingHero.getHeroName()){
                    mapSpeech.getTile(i,j).setOwner(heroMain);
                }
            }
        }
    }
}


/** Algorithm: Carries out the process of the user buying out another hero's army.
 * 1. Calculates the probability of the user winning the encounter.
 * 2. If the user loses (the probability is less than or equal to 1)...
 *      Set the user hero's Money to half of its current value.
 * 3. If the hero wins (the probability is greater than or equal to 1)...       
 *      Add the opposing hero's money, influence, and army size to the user's hero, and give the user the warriors of the opposing hero.
 * Parameters: the user's hero (Hero), an opposing hero (Hero), a map (Map), a warriors array (Warrior)
 * Output: that the opposing hero has retired if they lose
 * Return: none
 */ 
void buyOutright(Hero usersHero, Hero oppHero, Map& mapBuy, Warrior buyWarriors[14]){
    double heroProbWin = (1 - oppHero.getHeroWarrior(0).getLoyalty()/100.0)*(usersHero.getHeroMoney()/17800.0);
    
    if(heroProbWin <= 0){
        usersHero.setHeroMoney(usersHero.getHeroMoney()/2);
    }
    else if(heroProbWin >= 1){
        cout << oppHero.getHeroName() << " has retired." << endl;
        oppHero.setIsAlive(false);
        
        // --> Present Option to pick warriors
        usersHero.setHeroMoney(usersHero.getHeroMoney()+oppHero.getHeroMoney());
        usersHero.setInfluence(usersHero.getInfluence()+oppHero.getInfluence());
        usersHero.setArmySize(usersHero.getArmySize()+oppHero.getArmySize());
        for(int i=0; i<25; i++){
            for(int j=0; j<16; j++){
                if(mapBuy.getTile(i,j).getOwner().getHeroName() == oppHero.getHeroName()){
                    mapBuy.getTile(i,j).setOwner(usersHero);
                }
            }
        }
    }
}


/** Algorithm: Carries out the process/calculations of a battle between the user and another hero.
 * 1. Count the number of warriors in both hero'es party.
 * 2. If one hero has at least 1 warrior while the other has none, that hero wins.
 * 3. If both heroes have no warriors, the encounter is a tie.
 * Parameters: the user's hero (Hero), the opposing hero (Hero), the map (Map), an array of warriors (Warrior)
 * Output: A welcome statement for the beginning of the game
 * Return: the user's name (string)
 */ 
Hero battle(Hero hero1, Hero hero2, Map& battleMap, Warrior battleWarriors[14]){
    bool hero1Win, heroTie = false;
    int warriorCount1 = 0, warriorCount2 = 0, hero1Strength, hero2Strength;
    Hero winningHero;
    Warrior warriorUser, warriorRandom;
    for(int i=0; i<4; i++){
        if(hero1.getHeroWarrior(i).getWarriorName() != ""){
            warriorCount1++;
        }
        if(hero2.getHeroWarrior(i).getWarriorName() != ""){
            warriorCount2++;
        }
    }
    
    if(warriorCount1 == 0 || warriorCount2 == 0){
        if(warriorCount1 == 0){
            hero1Win = false;
        }
        else if(warriorCount2 == 0){
            hero1Win = true;
        }
    }
    else{
        if(warriorCount1 > 1){
            cout << "Which warrior would you like to represent you in battle?" << endl;
            // Present warrior options to user
            //warriorUser = // their choice;
        }
        else{
            warriorUser = hero1.getHeroWarrior(0);
        }
        
        if(warriorCount2 > 1){
            // Randomly choose a warrior from the other hero
            //warriorRandom = // a randomly picked warrior
        }
        else{
            warriorRandom = hero2.getHeroWarrior(0);
        }
        
        hero1Strength = (hero1.getArmySize())*(warriorUser.getStrength());
        hero2Strength = (hero2.getArmySize())*(warriorRandom.getStrength());
        
        if(hero1Strength > hero2Strength){
            hero1Win = true;
        }
        else if(hero1Strength < hero2Strength){
            hero1Win = false;
        }
        
        if(hero1Strength == hero2Strength){
            cout << "You and " << hero2.getHeroName() << " have tied in battle." << endl;
            heroTie = true;
        }
    }
    
    if(hero1Win && !heroTie){
        cout << hero2.getHeroName() << " has retired." << endl;
        hero2.setIsAlive(false);
        winningHero = hero1;
        
        // --> Present Option to pick warriors
        hero1.setHeroMoney(hero1.getHeroMoney()+hero2.getHeroMoney());
        hero1.setInfluence(hero1.getInfluence()+hero2.getInfluence());
        hero1.setArmySize(hero1.getArmySize()+hero2.getArmySize());
        for(int i=0; i<25; i++){
            for(int j=0; j<16; j++){
                if(battleMap.getTile(i,j).getOwner().getHeroName() == hero2.getHeroName()){
                    battleMap.getTile(i,j).setOwner(hero1);
                }
            }
        }
    }
    else if(!hero1Win && !heroTie){
        winningHero = hero2;
    }
    
    return winningHero;
    
}


/** Algorithm: Welcomes the user to the game and acquires their name
 * 1. Loops through each space on the map.
 * 2. If the name of the owner of the current space is equal to the name of the hero passed into the function, add one 
 *    to the count of hoe many spaces the given hero owns.
 * 3. Return the total number of spaces controlled by the hero.
 * Parameters: a given hero (Hero), the map (Map)
 * Output: nothing
 * Return: the number of spaces controlled by the given hero (int)
 */
int getTilesControlled(Hero HeroIn, Map controlMap){
    int controlTileCount = 0;
    for(int i=0; i<25; i++){
        for(int j=0; j<16; j++){
            if(controlMap.getTile(i,j).getOwner().getHeroName() == HeroIn.getHeroName()){
                controlTileCount++;
            }
        }
    }
    return controlTileCount;
}

// ALGORITHM COMMENTS FOR GAMEPLAY
/** 
 * TAKING TURN
 * At the start of each turn, ask the user whether they would like to Travel, Rest, or Consult with the gods.
 *  -Travel (possibly function)
 *      Ask the user for a direction they would like to go (N,E,S,W), using while loop until the input is valid.
 *      Using a switch statement or a series of if/else statements,
 *          Use a while loop to check if the Hero is actually able to move in the direction, based on the following conditions:
 *              If the space is out of bounds, the user cannot move there.
 *              If the space is water, the user needs a ship to travel.
 *          Keep asking the user to pick again until conditions are met.
 *  
 *  -Rest (possibly function)
 *      Hero's location remains unchanged.
 *      Loop through each warrior in the hero's party and add one to their strength.
 * 
 *  -Consult with the gods
 *      Hero's location doesn't change.
 *      Loop through each warrior in the the hero's party and add one to their morale.
 *      
 * Loop through every other hero and free warrior in the game, moving them to a new random location. (maybe function)
 *      Use conditionals to make sure each warrior and hero moves to a different location than every other hero and warrior.
 *      Use conditional to check if the hero/warrior moving has a ship, which will allow them to move on water.
 *      Use more conditionals to follow same rules as for user's hero.
 * 
 * ENCOUNTERS
 * Use conditionals to check for surrounding heroes and carry out encounters.
 *      Check if a warrior is in proximity to any heroes, and if there is only one hero in proximity, assign that warrior to the hero if they have space in their warriors array.
 *  -Give a Speech (possibly Hero member function)
 *      Compare the two heroes in the encounter and carry out the needed calculations.
 *      Decide the winner and do the following.
 *          Retire the losing hero.
 *          Give losing hero's warriors to the winning warrior (if the winning hero has room in their warrior array), or give the user a choice to pick the warriors they want.
 *          Give winning hero all money, influence, and army size from losing hero.
 *          Update every space controlled by the losing hero to be the winning hero's space.
 * 
 *  -Buy them outright (possibly Hero member function)
 *      Compare the two heroes in the encounter and carry out the needed calculations.
 *      Decide the winner and do the following.
 *          Retire the losing hero.
 *          Give losing hero's warriors to the winning warrior (if the winning hero has room in their warrior array), or give the user a choice to pick the warriors they want.
 *          Give winning hero all money, influence, and army size from losing hero.
 *          Update every space controlled by the losing hero to be the winning hero's space.
 *  -Battle (possibly Hero member function)
 *      Compare the two heroes in the encounter and carry out the needed calculations.
 *      Decide the winner and do the following.
 *          Retire the losing hero.
 *          Give losing hero's warriors to the winning warrior (if the winning hero has room in their warrior array), or give the user a choice to pick the warriors they want.
 *          Give winning hero all money, influence, and army size from losing hero.
 *          Update every space controlled by the losing hero to be the winning hero's space.
 *  If the main hero loses, the game ends.
 * 
 * DURING GAME
 *      Use a while loop until the conditions for winning are met.
 *      Give the user one of the three options at the beginning of their turn.
 *      Keep track of the turn number, starting at zero.
 *      Move all other heroes and warriors to random locations.
 *      Carry out all encounters.
 *      Update all values for each hero/warrior.
 *      Calculate the probability for random events and carry them out.
 *      Carry out pre determined events based on the turn number.
 */
 

int main(){
    Hero battleOutcome;
    srand(time(0));
    Map map = createMap(); // initializes map
    City Cities[26];
    Warrior Warriors[14];
    Hero Heroes[6];
    setUp(Cities,Warriors,Heroes); // initializes cities, warriors, and heroes
    setInitialLocations(Warriors,Heroes,map);
    string userName = getUsername();
    showInstructions(userName);
    Hero UserHero = userChooseHero(Heroes,userName,Warriors,map);
    
    // Set the owners of each occupied space
    map.getTile(UserHero.getLocation()[0],UserHero.getLocation()[1]).setOwner(UserHero);
    for(int j=0; j<6; j++){
        if(Heroes[j].getHeroName() != UserHero.getHeroName()){
            map.getTile(Heroes[j].getLocation()[0],Heroes[j].getLocation()[1]).setOwner(Heroes[j]);  
        }
        
    }
    
    // Initial update of points for each hero
    addPointsToHero(UserHero,map,Cities);
    for(int i=0; i<6; i++){
        if(Heroes[i].getHeroName() != UserHero.getHeroName()){
            addPointsToHero(Heroes[i],map,Cities);
        }
        
    }
    
    cout << "\nAt the start of each turn you will see a map of your hero's visibility, with your hero located at the center."; 
    cout << " The displayed map is comprised of" << endl;
    cout << "the following characters:" << endl;
    cout << "  ~ = water" << endl << "  * = land" << endl << "  X = outside of map" << endl << "  Letters A-Z = city" << endl;
    
    int turnCount = 0;
    bool userWon = false;
    string choiceOfEncounter;
    
    // checks that the user is alive and that they have not won the game
    while(!userWon && UserHero.getIsAlive()){
        cout << "\nMain Hero's Status" << endl;
        cout << "Money: " << UserHero.getHeroMoney() << endl;
        cout << "Influence: " << UserHero.getInfluence() << endl;
        cout << "Army Size: " << UserHero.getArmySize() << endl;
        cout << "Points: " << UserHero.getHeroPoints() << endl;
        cout << "Location: " << "{" << UserHero.getLocation()[0] << "," << UserHero.getLocation()[1] << "}" << endl;
        
        
        takeTurn(UserHero,map,Warriors);
        moveHeroesRandomly(Heroes,map,UserHero);
        moveWarriorsRandomly(Heroes,Warriors,map);
        
        // Checking encounters
        for(int i=0; i<6; i++){
            if(Heroes[i].getIsAlive() && UserHero.getIsAlive()){
                if(Heroes[i].getHeroName() != UserHero.getHeroName()){
                    if(checkUserEncounter(UserHero,Heroes[i])){
                        choiceOfEncounter = heroEncounterOption(Heroes[i]);
                        switch(choiceOfEncounter[0]){
                            case '1':
                                giveSpeech(UserHero,Heroes[i],map,Warriors);
                                break;
                            
                            case '2':
                                buyOutright(UserHero,Heroes[i],map,Warriors);
                                break;
                                
                            case '3':
                                battleOutcome = battle(UserHero,Heroes[i],map,Warriors);
                                if(battleOutcome.getHeroName() == Heroes[i].getHeroName()){
                                    // GAME OVER
                                    UserHero.setIsAlive(false);
                                }
                                
                                break;
                        }
                    }
                }
            }
        }
        
        // Only checks other encounters and carries them out if the user's hero is alive
        if(UserHero.getIsAlive()){
            // CHECK OTHER ENCOUTERS
            
            // Update Ownership and add points
            for(int i=0; i<6 ;i++){
              if(map.getTile(Heroes[i].getLocation()[0], Heroes[i].getLocation()[1]).getOwner().getHeroName() != Heroes[i].getHeroName()){
                    map.getTile(Heroes[i].getLocation()[0], Heroes[i].getLocation()[1]).setOwner(Heroes[i]);
                }
            }
            
            // Random Events
                // Drought 
                // Deserters 
                // Jackpot 
                // Kindness
            
            turnCount++;
            
            if(turnCount == 10){
                // Pre-determined events
                    // Daenerys acquires dragons
                    // Stannis gets consumed by his demon and dies
                    // Sansa acquires Arya (no exceptions)
                    // Cersei loses Jaime and he becomes free roaming
            }
            
            if(turnCount == 10 || UserHero.getArmySize() >= 2000 || getTilesControlled(UserHero,map) >= 200 || UserHero.getHeroPoints() == 400){
                // White Walkers
                cout << "Sad news! The White Walkers are approaching our location. Would you like to battle them now? (Y/N): " << endl;
                
            }
        }
    }
    
    // Checks if the user died, and therefore lost
    if(!UserHero.getIsAlive()){
        cout << userName << ", you have been defeated." << endl;
        cout << "Would you like to play again?" << endl;
    }
    else{ // or if the user won the game
        // write to file
        ofstream out_file;
        out_file.open("resultsGOT.txt");
        out_file << userName << "\t" << UserHero.getHeroName() << "\t" << UserHero.getHeroPoints() << "Points" << endl;
    }
    
    return 0;
}