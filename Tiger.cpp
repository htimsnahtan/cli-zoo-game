/*********************************************************************
** Program name: Tiger.cpp
** Author: Nathan Smith
** Date: 7-21-18
** Description: Tiger class implimentation file. Contains constructor
* that calls base class constructor then inits data members to data pulled from
* global constants file. Tiger class is derived from base class Animal
*********************************************************************/

#include "Tiger.hpp"
#include "globalConstants.hpp"
#include <iostream>

Tiger::Tiger(int ageIn) : Animal(ageIn)
{
    cost = TIGER_COST;
    numberOfOffspring = TIGER_OFFSPRING; // total number of offspring
    baseFoodCost = BASE_FOOD_COST * TIGER_COST_MULTIPLIER; // cost of food perday
    payoff = TIGER_PAYOFF_PER_DAY * TIGER_COST; // payoff per day
}