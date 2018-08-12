/*********************************************************************
** Program name: globalConstants.hpp
** Author: Nathan Smith
** Date: 7-21-18
** Description: Contains various constant values used in this application.
*********************************************************************/

#ifndef GLOBAL_CONSTANTS_HPP
#define GLOBAL_CONSTANTS_HPP

// size to start each array as well as how many spots to add when enlarging
const int DYNAMIC_ANIMAL_ARRAY_SIZE = 10;

// animal costs
const int TIGER_COST = 10000;
const int PENGUIN_COST = 1000;
const int TURTLE_COST = 100;

// number of offspring
const int TIGER_OFFSPRING = 1;
const int PENGUIN_OFFSPRING = 5;
const int TURTLE_OFFSPRING = 10;

// food costs
const int BASE_FOOD_COST = 10;
const int TIGER_COST_MULTIPLIER = 5;
const int PENGUIN_COST_MULTIPLIER = 1;
const float TURTLE_COST_MULTIPLIER = 0.5;

// payoff (as a percent of cost per animal)
const float TIGER_PAYOFF_PER_DAY = 0.2;
const float PENGUIN_PAYOFF_PER_DAY = 0.1;
const float TURTLE_PAYOFF_PER_DAY = 0.05;

// player begins with this specific amount of money in bank
const int INITIAL_BANK_ACCOUNT_SUM = 100000;

#endif