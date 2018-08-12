/*********************************************************************
** Program name: Animal.hpp
** Author: Nathan Smith
** Date: 7-21-18
** Description: Animal class declaration file. Base class for animal derived
* classes.
*********************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
protected:
    int age;
    int cost;
    int numberOfOffspring;
    int baseFoodCost;
    int payoff;
public:
    Animal(int = 1);
    int getAge();
    int getCost();
    int getNumberOfOffspring();
    int getBaseFoodCost();
    int getPayoff();
    void makeOlder(int = 1);
};

#endif