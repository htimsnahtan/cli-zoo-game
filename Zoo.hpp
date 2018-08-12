/*********************************************************************
** Program name: Zoo.hpp
** Author: Nathan Smith
** Date: 7-21-18
** Description: Zoo class declaration file
*********************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "Animal.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"
#include "Tiger.hpp"
#include "libraryFunctions.hpp"
#include <cstdlib>
#include <cstddef>

class Zoo
{
private:
    // random number generator functor
    GetRandIntInRange randomRange;
    
    // setup bank account
    double bankAccount;
    
    // Animal containers
    Tiger** tigerContainer = NULL;
    Turtle** turtleContainer = NULL;
    Penguin** penguinContainer = NULL;
    
    // variable to hold current Animal container size
    int tigerContainerSize;
    int turtleContainerSize;
    int penguinContainerSize;
    
    // current numbers of Animals
    int tigerCount;
    int turtleCount;
    int penguinCount;
    
    
public:
    Zoo();
    ~Zoo();
    int getBankAccount();
    void addBankAccount(int);
    void printZoo();
    
    // adds then returns pointer to animal
    Animal* addTurtle(int = 1);
    Animal* addTiger(int = 1);
    Animal* addPenguin(int = 1);
    
    // get animal pointer at index
    Animal* getTiger(int);
    Animal* getPenguin(int);
    Animal* getTurtle(int);
    
    std::string killRandomAnimal(); // returns type of animal killed
    void killTurtle(int = -1);
    void killPenguin(int = -1);
    void killTiger(int = -1);
    
    // returns cost of animal
    int buyAnimal(Animal*);
    
    // age all animals in zoo by 1 day
    void ageAnimalsInZoo();
    
    // feed all animals in zoo then get total cost
    double feedAnimalsInZoo();
    
    // get numbers of Animals
    int getTigerCount();
    int getTurtleCount();
    int getPenguinCount();
    
    // get index of adult animals
    // return -1 if none exist
    int adultTigerIndex();
    int adultPenguinIndex();
    int adultTurtleIndex();
};

#endif