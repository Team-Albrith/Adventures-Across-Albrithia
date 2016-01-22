#ifndef SPELL_HPP
#define SPELL_HPP

#include <string>
#include <vector>

#include "Entity.hpp"
#include "Effect.hpp"

using std::string;
using std::vector;

//! Spell class
/*! Derived from Magic; User-performed magics. */
class Spell {
public:
  Spell(); //!< Default Constructor
  Spell(string newName, string newDescription, vector<Effect*> newOnHitEffects);
  Spell(string newName, string newDescription, int newManaCost, int newIntelligenceCost, vector<Effect*> newOnHitEffects);
  ~Spell(); //!< Destructor
  void PerformOn(const Entity* target); //!< Single-entity perform
  void PerformOn(const vector<Entity*> targets); //! Multi-entity perform

  void setName(string newName);
  void setDescription(string newDescription);
  void setManaCost(int newManaCost);
  void setRequiredIntelligence(int newRequiredIntelligence);
  void setBaseDamage(int newBaseDamage);

  string getName()const{return name;}
  string getDescription()const{return description;}
  int getManaCost()const{return manaCost;}
  int getRequiredIntelligence()const{return requiredIntelligence;}
  int getBaseDamage()const{return baseDamage;}
  const Effect * const * getEffects()const{return effects.data();}

private:
    string name;
    string description;
    int manaCost;
    int requiredIntelligence;
    int baseDamage;
    vector<Effect*> effects;
};

#endif
