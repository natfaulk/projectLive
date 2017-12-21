#ifndef PERSON_HPP
#define PERSON_HPP

#include "moveable.hpp"


class Person: public Moveable {
public:
  Person();
  Person(int _x, int _y);
  void tick(void);

  enum Actions {WAIT, TO_WATER, TO_FOOD, TO_BED};
private:
  void init(void);
  // needs
  int food;
  int drink;
  int sleep;

  Actions currentAction;

  // need depletions
  int foodDepRate;
  int drinkDepRate;
  int sleepDepRate;

  bool dead;
};

#endif /* end of include guard: PERSON_HPP */