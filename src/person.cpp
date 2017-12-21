#include "person.hpp"
#include "astar.hpp"
#include "constants.hpp"
#include "map.hpp"

#define PERSON_DEBUG

#ifdef PERSON_DEBUG
#include <iostream>
#endif

const int DEFAULT_FOOD_INIT = 1000;
const int DEFAULT_DRINK_INIT = 1000;
const int DEFAULT_SLEEP_INIT = 1000;

const int DEFAULT_FOOD_DEPL = 1;
const int DEFAULT_DRINK_DEPL = 1;
const int DEFAULT_SLEEP_DEPL = 1;

const int DRINK_RIVER_INCREASE = 25;
const int EAT_FOOD_INCREASE = 25;
const int SLEEP_BED_INCREASE = 25;

Person::Person(): Moveable()
{
  init();
}

Person::Person(int _x, int _y): Moveable(_x, _y)
{
  init();
}

void Person::init(void)
{
  food = DEFAULT_FOOD_INIT;
  drink = DEFAULT_DRINK_INIT;
  sleep = DEFAULT_SLEEP_INIT;

  foodDepRate = DEFAULT_FOOD_DEPL;
  drinkDepRate = DEFAULT_DRINK_DEPL;
  sleepDepRate = DEFAULT_SLEEP_DEPL;
  currentAction = WAIT;

  dead = false;
}

void Person::tick(void)
{
  if (!dead)
  {
    food -= foodDepRate;
    drink -= drinkDepRate;
    sleep -= sleepDepRate;

    if ( food < 0
      || drink < 0
      || sleep < 0)
    {
      dead = true;
    }

    if (drink < 950 && currentAction == WAIT)
    {
      currentAction = TO_WATER;
      Point tempDest = getNearestTile(WATER);
      ASTAR_Begin(this, &tempDest);
      while (!ASTAR_Step());
    // #ifdef PERSON_DEBUG
    //   std::cout << "ASTAR Began" << std::endl;
    // #endif
    }
    else if (food < 600 && currentAction == WAIT)
    {
      currentAction = TO_FOOD;
      Point tempDest = getNearestTile(FOOD);
      if (tempDest.x != -1)
      {
        ASTAR_Begin(this, &tempDest);
        while (!ASTAR_Step());

      #ifdef PERSON_DEBUG
        std::cout << "ASTAR Began - food" << std::endl;
      #endif
      
      }
    }
    else if (sleep < 200 && currentAction == WAIT)
    {
      currentAction = TO_BED;
      Point tempDest = getNearestTile(BED);
      if (tempDest.x != -1)
      {
        ASTAR_Begin(this, &tempDest);
        while (!ASTAR_Step());

      #ifdef PERSON_DEBUG
        std::cout << "ASTAR Began - bed" << std::endl;
      #endif

      }
    }
    else if (
      currentAction == TO_WATER
      || currentAction == TO_FOOD
      || currentAction == TO_BED
      )
    {
      Point nextPoint = ASTAR_PathNextPoint();
      if (nextPoint.x == -1) currentAction = WAIT;
      else
      {
        if (nextPoint.x == x)
        {
          if (nextPoint.y == y - 1) move(UP);
          else if (nextPoint.y == y + 1) move(DOWN);
        }
        else if (nextPoint.y == y)
        {
          if (nextPoint.x == x - 1) move(LEFT);
          else if (nextPoint.x == x + 1) move(RIGHT);
        }
      }

    #ifdef PERSON_DEBUG
      std::cout << "ASTAR Step. "
      << "Next step: x " << nextPoint.x
      << ", y " << nextPoint.y
      << std::endl;
    #endif
    }

    if (nextTo(WATER))
    {
      drink += DRINK_RIVER_INCREASE;
      if (drink > DEFAULT_DRINK_INIT) drink = DEFAULT_DRINK_INIT;
    }

    if (nextTo(FOOD))
    {
      food += EAT_FOOD_INCREASE;
      if (food > DEFAULT_FOOD_INIT) food = DEFAULT_FOOD_INIT;
    }

    if (nextTo(BED))
    {
      sleep += SLEEP_BED_INCREASE;
      if (sleep > DEFAULT_SLEEP_INIT) sleep = DEFAULT_SLEEP_INIT;
    }

  #ifdef PERSON_DEBUG
    std::cout 
    << "Drink: " << drink 
    << " | Food: " << food 
    << " | Sleep: " << sleep 
    << std::endl;
  #endif
  }
}
