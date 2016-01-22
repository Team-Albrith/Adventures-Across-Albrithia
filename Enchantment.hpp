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
  //TODO: Constructors for skill, stat increase and effects

  void setName(string newName);
  void setDescription(string description);

  string getName()const{return name;}
  string getDescription()const{return description;}

  //TODO: getter/setter for skills and effects

private:
    string name;
    string description;

    //Parallel array of skill and its increase
    int statIncrease[4];

    vector<Effect*> effects;
};

#endif
