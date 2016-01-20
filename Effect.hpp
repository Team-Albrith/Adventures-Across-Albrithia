#ifndef EFFECT_HPP
#define EFFECT_HPP
#include <string>
#include "Entity.hpp"

using std::string;

//!An abstract class representing status effects such as burn, paralysis, or poison
class Effect{
public:
  Effect(string newTitle, string newDescription, unsigned int duration, float percentChanceOfHit);
  virtual ~Effect(){}

  unsigned int getRemainingTurns()const{return remainingTurns;}
  string getDescription()const{return description;}
  string getTitle()const{return title;}
  float getChanceOfHit()const{return chanceOfHit;}

  //!Apply this effect to the target
  virtual void apply(Entity *target) = 0;
  //!returns a copy of this Effect
  virtual Effect *clone() = 0;

protected:
  string description, title;
  //!How many more turns this Effect lasts for
  unsigned int remainingTurns;
  //!The chance in percent of this Effect actually happening
  float chanceOfHit;
};
#endif
