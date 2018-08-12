/*********************************************************************
** Program name: main.cpp
** Author: Nathan Smith
** Date: 7-21-18
** Description: Main function for zoo tycoon game.
* Inits zooTycoon, gets user input to start game by purchasing 1 or 2
* animals of each kind, then loops user in game day by day allowing them
* to purchase a new animal. For each day, a random event occurs from 1 of 4
* types. At end of day if user runs out of money, game quits (user allowed
* to go negative during the day).
*********************************************************************/

#include "Animal.hpp"
#include "Penguin.hpp"
#include "Tiger.hpp"
#include "Turtle.hpp"
#include "Zoo.hpp"
#include "globalConstants.hpp"
#include "libraryFunctions.hpp"

#include <iostream>
#include <string>

int main()
{
    // random number generator functor
    GetRandIntInRange randomRange;
    
    // init zoo
    Zoo zooTycoon;
    
    // setup zoo
    // force user to purchase 1 or 2 animals of each kind
    
    std::cout << "You currently have " << zooTycoon.getBankAccount() << " dollars" << std::endl;
    
    std::string purchaseTigerPrompt = "How many Tigers would you like to purchase (1 or 2)?";
    std::string purchaseTurtlePrompt = "How many Turtles would you like to purchase (1 or 2)?";
    std::string purchasePenguinPrompt = "How many Penguins would you like to purchase (1 or 2)?";
    
    // buy tiger(s)
    int numberOfTigers = getValidNumber(purchaseTigerPrompt,"Please enter a valid number",0,3);
    for (int i = 0;i < numberOfTigers; i++)
    {
        zooTycoon.addBankAccount(-zooTycoon.buyAnimal(zooTycoon.addTiger()));
    }
    std::cout << "You currently have " << zooTycoon.getBankAccount() << " dollars" << std::endl;
    
    // buy turtle(s)
    int numberOfTurtles = getValidNumber(purchaseTurtlePrompt,"Please enter a valid number",0,3);
        for (int i = 0;i < numberOfTurtles; i++)
    {
        zooTycoon.addBankAccount(-zooTycoon.buyAnimal(zooTycoon.addTurtle()));
    }
    std::cout << "You currently have " << zooTycoon.getBankAccount() << " dollars" << std::endl;
    
    // buy penguin(s)
    int numberOfPenguins = getValidNumber(purchasePenguinPrompt,"Please enter a valid number",0,3);
    for (int i = 0;i < numberOfPenguins; i++)
    {
        zooTycoon.addBankAccount(-zooTycoon.buyAnimal(zooTycoon.addPenguin()));
    }
    
    // zoo is now setup and ready to loop days
    bool zooInBusiness = true;
    int dayCount = 1;
    
    while (zooInBusiness) // each iteration 1 day
    {
        std::cout << "<------------------------------------------>" << std::endl;
        std::cout << "Welcome to day " << dayCount <<" in the zoo!" << std::endl;
        std::cout << "You currently have " << zooTycoon.getBankAccount() << " dollars" << std::endl;
        
        // age animals by 1 day
        zooTycoon.ageAnimalsInZoo();
        
        std::cout << "Here are the quantities of animals in your zoo:" << std::endl;
        zooTycoon.printZoo();
        
        int totalPayoff = 0;
        
        // initiates with the total cost to feed animals
        int costToFeed = zooTycoon.feedAnimalsInZoo();
        totalPayoff -= costToFeed;
        
        std::cout << "Animals have been fed. This cost " << costToFeed <<
                    " dollars." << std::endl;
        
        int randomEvent = randomRange(1,5);
        
        switch (randomEvent)
        {
            case 1:
            {
                std::string animalKilled = zooTycoon.killRandomAnimal();
                if (animalKilled == "none")
                {
                    break;
                }
                std::cout << "Alert! 1 " << animalKilled <<
                            " has died in your zoo." << std::endl;
                break;
            }
            case 2:
            {
                std::cout << "Boom in business!" << std::endl;
                // generates random bonus of 250-500 for each tiger
                // adds bonus to payroll as reward
                int tigerCount = zooTycoon.getTigerCount();
                // get random bonus for each tiger between 250 and 500
                int randomAmount = randomRange(250,500+1);
                // add total bonus to payoff
                int totalBonus = (tigerCount * randomAmount);
                totalPayoff += totalBonus;
                std::cout << "You earn " << totalBonus << " dollars." << std::endl;

                
                break;
            }
            case 3:
            {
                bool checkedPregnantPenguin = false;
                bool checkedPregnantTiger = false;
                bool checkedPregnantTurtle = false;
                bool foundPregnantAnimal = false;
                
                while (!foundPregnantAnimal && 
                        (!checkedPregnantPenguin || !checkedPregnantTiger || 
                        !checkedPregnantTurtle))
                {
                    int randomAnimalToBirth = randomRange(0,4);
                    switch (randomAnimalToBirth)
                    {
                        case 1:
                        {
                            int pregnantPenguin = zooTycoon.adultPenguinIndex();
                            if (pregnantPenguin != -1)
                            {
                                int numberOfPenguins = zooTycoon.getPenguin(pregnantPenguin)->getNumberOfOffspring();
                                std::cout << "Penguin gave birth to " << numberOfPenguins << " penguin(s)." << std::endl;
                                // give birth to animals (each animal 0 days old)
                                for (int i=0; i < numberOfPenguins; i++)
                                {
                                    zooTycoon.addPenguin(0);
                                }
                                std::cout << "You now have " << zooTycoon.getPenguinCount() << 
                                            " penguins." << std::endl;
                                foundPregnantAnimal = true;
                            }
                            checkedPregnantPenguin = true;
                            break;
                        }
                        case 2:
                        {
                            int pregnantTiger = zooTycoon.adultTigerIndex();
                            if (pregnantTiger != -1)
                            {
                                int numberOfTigers = zooTycoon.getTiger(pregnantTiger)->getNumberOfOffspring();
                                std::cout << "Tiger gave birth to " << numberOfTigers << " tiger(s)." << std::endl;
                                // give birth to animals (each animal 0 days old)
                                for (int i=0; i < numberOfTigers; i++)
                                {
                                    zooTycoon.addTiger(0);
                                }
                                std::cout << "You now have " << zooTycoon.getTigerCount() << 
                                            " tigers." << std::endl;
                                foundPregnantAnimal = true;
                            }
                            checkedPregnantTiger = true;
                            break;
                        }
                        case 3:
                        {
                            int pregnantTurtle = zooTycoon.adultTurtleIndex();
                            if (pregnantTurtle != -1)
                            {
                                int numberOfTurtles = zooTycoon.getTurtle(pregnantTurtle)->getNumberOfOffspring();
                                std::cout << "Turtle gave birth to " << numberOfTurtles << " turtle(s)." << std::endl;
                                // give birth to animals (each animal 0 days old)
                                for (int i=0; i < numberOfTurtles; i++)
                                {
                                    zooTycoon.addTurtle(0);
                                }
                                std::cout << "You now have " << zooTycoon.getTurtleCount() << 
                                            " turtles." << std::endl;
                                foundPregnantAnimal = true;
                            }
                            checkedPregnantTurtle = true;
                            break;
                        }
                    }
                }

                break;
            }
            case 4:
            {
                std::cout << "Nothing happens!" << std::endl;
                break;
            }
        }
        
        // calculate profit
        // ask if user would like to buy an adult animal (3 days old)
        
        std::string purchaseAnimalPrompt = "Would you like to purchase an adult animal?\n"
                                            "1. No\n"
                                            "2. Yes, I'd like to buy a tiger.\n"
                                            "3. Yes, I'd like to buy a penguin.\n"
                                            "4. Yes, I'd like to buy a turtle.\n";
        
        int purchaseAnimal = getValidNumber(purchaseAnimalPrompt,"Please enter a valid number",
                            0,
                            5
                            );

        switch(purchaseAnimal)
        {
            case 1:
            {
                std::cout << "No animal purchased." << std::endl;
                break;
            }
            case 2:
            {
                std::cout << "One tiger purchased." << std::endl;
                totalPayoff -= zooTycoon.buyAnimal(zooTycoon.addTiger());
                break;
            }
            case 3:
            {
                std::cout << "One penguin purchased." << std::endl;
                totalPayoff -= zooTycoon.buyAnimal(zooTycoon.addPenguin());
                break;
            }
            case 4:
            {
                std::cout << "One turtle purchased." << std::endl;
                totalPayoff -= zooTycoon.buyAnimal(zooTycoon.addTurtle());
                break;
            }
        }
        // calculate daily payoff and add/subtract to bank account
        
        // add payoff for turtles
        for (int i=0; i < zooTycoon.getTurtleCount(); i++)
        {
            totalPayoff += zooTycoon.getTurtle(i)->getPayoff();
        }
        // add payoff for tigers
        for (int i=0; i < zooTycoon.getTigerCount(); i++)
        {
            totalPayoff += zooTycoon.getTiger(i)->getPayoff();
        }
        // add payoff for penguins
        for (int i=0; i < zooTycoon.getPenguinCount(); i++)
        {
            totalPayoff += zooTycoon.getPenguin(i)->getPayoff();
        }

        std::cout << "You earned " << totalPayoff << " dollars today." << std::endl;
        zooTycoon.addBankAccount(totalPayoff);
        
        // if user has no money let them know game is over
        if (zooTycoon.getBankAccount() <= 0)
        {
            std::cout << "You are bankrupt. Quitting game." << std::endl;
            zooInBusiness = false;
            break;
        }
        else
        {
            // ask user if they want to keep playing game
            std::string endGamePrompt = "Would you like to keep playing?\n"
                                        "1. No\n"
                                        "2. Yes\n";
            int endGame = getValidNumber(endGamePrompt, "Please enter a valid number",
                                            0,
                                            3
                                            );
            switch(endGame)
            {
                case 1:
                {
                    std::cout << "Quitting game." << std::endl;
                    zooInBusiness = false;
                    break;
                }
                case 2:
                {
                    std::cout << "Continuing game." << std::endl;
                    break;
                }
            }
            
            dayCount++;
        }
    }
    
    std::cout << "Goodbye!" << std::endl;

    return 0;
}