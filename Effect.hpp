#ifndef EFFECT_HPP
#define EFFECT_HPP
#include <string>
#include "Entity.hpp"

using std::string;

class Effect{
public:
  Effect(string newTitle, string newDescription, unsigned int duration, float percentChanceOfHit);
  virtual ~Effect(){}

  unsigned int getRemainingTurns()const{return remainingTurns;}
  string getDescription()const{return description;}
  string getTitle()const{return title;}

  virtual void apply(Entity *target) = 0;
  virtual Effect *clone() = 0;

protected:
  string description, title;
  unsigned int remainingTurns;
  float chanceOfHit;
};
#endif
