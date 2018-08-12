/*********************************************************************
** Program name: Penguin.cpp
** Author: Nathan Smith
** Date: 7-21-18
** Description: Penguin class implimentation file. Contains constructor
* that calls base class constructor then inits data members to data pulled from
* global constants file. Penguin class is derived from base class Animal
*********************************************************************/

#include "Penguin.hpp"
#include "globalConstants.hpp"
#include <iostream>

Penguin::Penguin(int ageIn) : Animal(ageIn)
{
    cost = PENGUIN_COST;
    numberOfOffspring = PENGUIN_OFFSPRING; // total number of offspring
    baseFoodCost = BASE_FOOD_COST * PENGUIN_COST_MULTIPLIER; // cost of food perday
    payoff = PENGUIN_PAYOFF_PER_DAY * PENGUIN_COST; // payoff per day
}