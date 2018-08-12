/*********************************************************************
** Program name: Animal.cpp
** Author: Nathan Smith
** Date: 7-21-18
** Description: Animal Class implimentation file
*  Base class for 3 animal types (turtle, penguin, and tiger).
* Includes constructor to set age, getter methods for all data,
* and a function to increase age by an integer input.
*********************************************************************/

#include "Animal.hpp"
#include <iostream>

//constructor
Animal::Animal(int ageIn)
{
    age = ageIn;
}

int Animal::getAge()
{
    return age;
}

int Animal::getCost()
{
    return cost;
}

int Animal::getNumberOfOffspring()
{
    return numberOfOffspring;
}

int Animal::getBaseFoodCost()
{
    return baseFoodCost;
}

int Animal::getPayoff()
{
    return payoff;
}

// increases animal's age by ageIn
void Animal::makeOlder(int ageIn)
{
    age+= ageIn;
}
