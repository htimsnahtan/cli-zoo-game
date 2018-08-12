/*********************************************************************
** Program name: Zoo.cpp
** Author: Nathan Smith
** Date: 7-21-18
** Description: Zoo class implimentation file. Contains constructor, destructor
* print function, 3 add animal functions, 3 get animal functions, 3 kill
* animal functions, a function to kill a random animal, 3 get animal count functions,
* a function to age animals by a user input amount, a function to feed animals,
* functions to get and add to bank account, and 3 functions to get 1 adult animal (over
* 3 days old).
*********************************************************************/

#include "Zoo.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"
#include "Tiger.hpp"
#include "globalConstants.hpp"
#include "libraryFunctions.hpp"
#include <string>
#include <iostream>

// Zoo constructor
Zoo::Zoo()
{
    // set animal counts to 0
    tigerCount = 0;
    turtleCount = 0;
    penguinCount = 0;
    
    // setup bank account
    bankAccount = INITIAL_BANK_ACCOUNT_SUM;
    
    // define array sizes
    tigerContainerSize = DYNAMIC_ANIMAL_ARRAY_SIZE;
    turtleContainerSize = DYNAMIC_ANIMAL_ARRAY_SIZE;
    penguinContainerSize = DYNAMIC_ANIMAL_ARRAY_SIZE;
    
    // initalize animal containers
    tigerContainer = new Tiger*[tigerContainerSize];
    turtleContainer = new Turtle*[turtleContainerSize];
    penguinContainer = new Penguin*[penguinContainerSize];
}

// Zoo destructor
Zoo::~Zoo()
{
    // delete animals
    for (int i=0;i<tigerCount;i++)
    {
        delete tigerContainer[i];
    }
    
    for (int i=0;i<turtleCount;i++)
    {
        delete turtleContainer[i];
    }
    
    for (int i=0;i<penguinCount;i++)
    {
        delete penguinContainer[i];
    }
    
    // delete animal containers
    if(tigerContainer)
    {
        delete [] tigerContainer;
        tigerContainer = NULL;
    }
    if(turtleContainer)
    {
        delete [] turtleContainer;
        turtleContainer = NULL;
    }
    if(penguinContainer)
    {
        delete [] penguinContainer;
        penguinContainer = NULL;
    }
}

// prints every animal and its age at zoo to console
void Zoo::printZoo()
{
    // print turtles
    std::cout << "Total turtles: " << turtleCount << std::endl;
    for (int i=0;i<turtleCount;i++)
    {
        std::cout << "\tTurtle " << i+1 << ": "<< turtleContainer[i]->getAge() <<
                " day(s) old." << std::endl;
    }
    
    // print tigers
    std::cout << "Total tigers: " << tigerCount << std::endl;
    for (int i=0;i<tigerCount;i++)
    {
        std::cout << "\tTiger " << i+1 << ": "<< tigerContainer[i]->getAge() <<
                " day(s) old." << std::endl;
    }
    // print penguins
    std::cout << "Total penguins: " << penguinCount << std::endl;
    for (int i=0;i<penguinCount;i++)
    {
        std::cout << "\tPenguin " << i+1 << ": "<< penguinContainer[i]->getAge() <<
                " day(s) old." << std::endl;
    }
}

// adds a turtle to its respective array
// requires integer for age of animal to create
// returns pointer to that animal
Animal* Zoo::addTurtle(int ageIn)
{
    // dynamically double turtle array if needed
    if (turtleCount >= turtleContainerSize)
    {
        //update turtle container size
        turtleContainerSize*=2;
        
        Turtle** tempContainer = new Turtle*[turtleContainerSize];
        // add turtles to temp container
        for (int i = 0; i < turtleCount; i++)
        {
            tempContainer[i] = turtleContainer[i];
        }
        delete [] turtleContainer;
        turtleContainer = tempContainer;
    }
    
    // create new Turtle and add to turtle container
    Turtle* turtle = new Turtle(ageIn);
    turtleContainer[turtleCount] = turtle;
    
    // increase total turtle count by 
    turtleCount++;
    
    // return pointer to turtle
    return turtle;
}

// adds requires integer for age of animal to create
// adds a tiger to its respective array
// returns pointer that that animal
Animal* Zoo::addTiger(int ageIn)
{
    // dynamically double tiger array if needed
    if (tigerCount >= tigerContainerSize)
    {
        //update tiger container size
        tigerContainerSize*=2;
        
        Tiger** tempContainer = new Tiger*[tigerContainerSize];
        for (int i = 0; i < tigerCount; i++)
        {
            tempContainer[i] = tigerContainer[i];
        }
        delete [] tigerContainer;
        tigerContainer = tempContainer;
    }
    
    // create new Turtle and add to turtle container
    Tiger* tiger = new Tiger(ageIn);
    tigerContainer[tigerCount] = tiger;
    
    // increase total tiger count by 
    tigerCount++;
    
    // return pointer to tiger
    return tiger;
}

// adds a penguin to its respective array
// requires integer for age of animal to create
// returns pointer to that animal
Animal* Zoo::addPenguin(int ageIn)
{
    // dynamically double tiger array if needed
    if (penguinCount >= penguinContainerSize)
    {
        //update penguin container size
        penguinContainerSize*=2;
        
        Penguin** tempContainer = new Penguin*[penguinContainerSize];
        for (int i = 0; i < penguinCount; i++)
        {
            tempContainer[i] = penguinContainer[i];
        }
        delete [] penguinContainer;
        penguinContainer = tempContainer;
    }
    
    // create new Turtle and add to turtle container
    Penguin* penguin = new Penguin(ageIn);
    penguinContainer[penguinCount] = penguin;
    
    // increase total turtle count by 
    penguinCount++;
    
    // return pointer to penguin
    return penguin;
}
// get animal pointer at index
Animal* Zoo::getTiger(int index)
{
    return tigerContainer[index];
}

// get animal pointer at index
Animal* Zoo::getPenguin(int index)
{
    return penguinContainer[index];
}

// get animal pointer at index
Animal* Zoo::getTurtle(int index)
{
    return turtleContainer[index];
}

// deletes turtle from array then shifts down turtles
// default value -1 which kills random turtle
void Zoo::killTurtle(int deletedTurtleIndex)
{
    if (deletedTurtleIndex == -1) // if user wants to delete random turtle
    {
        deletedTurtleIndex = randomRange(0,turtleCount);
    }
    
    for (int i = deletedTurtleIndex; i < turtleCount; ++i)
    {
        turtleContainer[i] = turtleContainer[i + 1];
    }
    
    turtleCount--;
}

// deletes tiger from array then shifts down tigers
// default value -1 which kills random tiger
void Zoo::killTiger(int deletedTigerIndex)
{
    if (deletedTigerIndex == -1) // if user wants to delete random tiger
    {
        deletedTigerIndex = randomRange(0,tigerCount);
    }
    
    for (int i = deletedTigerIndex; i < tigerCount; ++i)
    {
        tigerContainer[i] = tigerContainer[i + 1];
    }
    
    tigerCount--;
}

// deletes penguin from array then shifts down penguin
// default value -1 which kills random penguin
void Zoo::killPenguin(int deletedPenguinIndex)
{
    if (deletedPenguinIndex == -1) // if user wants to delete random pengin
    {
        deletedPenguinIndex = randomRange(0,penguinCount);
    }
    
    for (int i = deletedPenguinIndex; i < penguinCount; ++i)
    {
        penguinContainer[i] = penguinContainer[i + 1];
    }
    
    penguinCount--;
}

int Zoo::getTigerCount()
{
    return tigerCount;
}

int Zoo::getTurtleCount()
{
    return turtleCount;
}

int Zoo::getPenguinCount()
{
    return penguinCount;
}

// kills random animal
// if no random animal exists returns none
std::string Zoo::killRandomAnimal()
{
    // if no animals
    if (!penguinCount && !tigerCount && !turtleCount)
    {
        return "none";
    }
    bool killedFlag = false;
    while (!killedFlag)
    {
        int typeAnimalToKill = randomRange(0,4);
        
        switch(typeAnimalToKill)
        {
            case 1:
                if (penguinCount)
                {
                    killPenguin();
                    killedFlag = true;
                    return "penguin";
                }
            case 2:
                if (tigerCount)
                {
                    killTiger();
                    killedFlag = true;
                    return "tiger";
                }
            case 3:
                if (turtleCount)
                {
                    killTurtle();
                    killedFlag = true;
                    return "turtle";
                }
        }
    }
}

// accepts pointer to animal, then uses pointer to get cost
// returns cost
int Zoo::buyAnimal(Animal* animalIn)
{
    return animalIn->getCost();
}

// increases age of each animal in zoo by 1
void Zoo::ageAnimalsInZoo()
{
    for (int i=0;i<turtleCount;i++)
    {
        turtleContainer[i]->makeOlder();
    }
    
    for (int i=0;i<tigerCount;i++)
    {
        tigerContainer[i]->makeOlder();
    }
    for (int i=0;i<penguinCount;i++)
    {
        penguinContainer[i]->makeOlder();
    }
}

// returns total cost to feed all animals
double Zoo::feedAnimalsInZoo()
{
    double totalCost = 0;
    
    for (int i=0;i<turtleCount;i++)
    {
        totalCost += turtleContainer[i]->getBaseFoodCost();
    }
    
    for (int i=0;i<tigerCount;i++)
    {
        totalCost += tigerContainer[i]->getBaseFoodCost();
    }
    for (int i=0;i<penguinCount;i++)
    {
        totalCost += penguinContainer[i]->getBaseFoodCost();
    }

    return totalCost;
}

int Zoo::getBankAccount()
{
    return bankAccount;
}

// accepts money input then adds/removes to/from bank account
void Zoo::addBankAccount(int moneyIn)
{
    bankAccount += moneyIn;
}

// returns -1 if no adults or fist index of animal if possible
int Zoo::adultTigerIndex()
{
    for (int i=0;i<tigerCount;i++)
    {
        int tigerAge = tigerContainer[i]->getAge();
        if (tigerAge >=3)
        {
            return i;
        }
    }
    return -1;
}

// returns -1 if no adults or fist index of animal if possible
int Zoo::adultPenguinIndex()
{
    for (int i=0;i<penguinCount;i++)
    {
        int penguinAge = penguinContainer[i]->getAge();
        if (penguinAge >=3)
        {
            return i;
        }
    }
    return -1;
}

// returns -1 if no adults or fist index of animal if possible
int Zoo::adultTurtleIndex()
{
    for (int i=0;i<turtleCount;i++)
    {
        int turtleAge = turtleContainer[i]->getAge();
        if (turtleAge >=3)
        {
            return i;
        }
    }
    return -1;
}