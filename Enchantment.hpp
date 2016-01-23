#ifndef ENCHANTMENT_HPP
#define ENCHANTMENT_HPP

#include <vector>
#include <string>

using std::string;
using std::vector;

#include "Effect.hpp"

//! Enchantment class
/*! Derived from Magic; Applies bonus stats to weapons and armor. */
class Enchantment {
public:
  Enchantment(); //!< Default Constructor
  ~Enchantment(); //!< Destructor
  Enchantment(string newName, string newDescription);

  void setName(string newName);
  void setDescription(string description);
  void setStatIncrease(int hp, int strength, int speed, int intelligence);
  void setStatIncrease(int stats[4]);

  string getName()const{return name;}
  string getDescription()const{return description;}
  int returnHPIncrease()const{return statIncrease[0];}
  int returnStrengthIncrease()const{return statIncrease[1];}
  int returnSpeedIncrease()const{return statIncrease[2];}
  int returnIntelligenceIncrease()const{return statIncrease[3];}

private:
    string name;
    string description;

    //Increase of Stat
    int statIncrease[4]; //<! HP, Strength, Speed, Intelligence

    vector<Effect*> effects;
};

#endif
