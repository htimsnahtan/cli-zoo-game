/*********************************************************************
** Program name: Turtle.cpp
** Author: Nathan Smith
** Date: 7-21-18
** Description: Turtle class implimentation file. Contains constructor
* that calls base class constructor then inits data members to data pulled from
* global constants file. Turtle class is derived from base class Animal
*********************************************************************/

#include "Turtle.hpp"
#include "globalConstants.hpp"
#include <iostream>

Turtle::Turtle(int ageIn) : Animal(ageIn)
{
    cost = TURTLE_COST;
    numberOfOffspring = TURTLE_OFFSPRING; // total number of offspring
    baseFoodCost = BASE_FOOD_COST * TURTLE_COST_MULTIPLIER; // cost of food perday
    payoff = TURTLE_PAYOFF_PER_DAY * TURTLE_COST; // payoff per day
}