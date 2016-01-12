#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
#include <vector>

#include "Spell.hpp"

using std::string;
using std::vector;

//!Our base class for Items
/*!
   A class representing a basic Item. It contains stats to store what the item does to the Entity when used/equipped. Ie, a sword of intellect would set intelligence to 3 to represent that equipping it increases your intelligence, or Armour setting speed to a negative value to lower the speed of the Entity upon equipping.
*/
class Item{
public:
  Item(string newDescription, int newMaxHp = 0, int newStrength = 0, int newSpeed = 0, int newIntelligence = 0);

  string getDescription()const{return description;}

protected:
  string description;
  int maxHp, strength, speed, intelligence;//NOTE: These are the values added to stats when item is equipped/used
};

//!A wieldable Item
class Weapon: public Item{
public:
  Weapon(string newDescription, int newMinDamage = 1, int newRange = 0, int newMaxHp = 0, int newStrength = 0, int newSpeed = 0, int newIntelligence = 0);

  int getDamage()const;
  int getMinDamage()const{return minDamage;}
  int getRange()const{return range;}

protected:
  int minDamage,//!<The base damage this weapon does
    range;    //!<the range in which to generate the amount of damage
};


//!An equippable Item
class Armour: public Item{
public:
  Armour(string newDescription, int newDefence = 1, int newMaxHp = 0, int newStrength = 0, int newSpeed = 0, int newIntelligence = 0);

  int getDefence()const{return defence;}

protected:
  //!The amount of damage this Armour pretects you from
  int defence;
};

//TODO: Magical items need to either inherit or contain Spell's

//!An Item which grants a magical effect when consumed
class Potion: public Item{
public:
  Potion(string newDescription, Buff newEffect, int newMaxHp = 0, int newStrength = 0, int newSpeed = 0, int newIntelligence = 0);

  Buff getEffect()const{return effect;}
  void setEffect(Buff newEffect);
protected:
  Buff effect; //!<The effect that happens upon consumption of this Potion
};

//!An Item which casts a spell when used
/*!
  Using the Scroll costs no mana, but mana is consumed in the creation of Scrolls
*/
class Scroll: public Item{
public:
  Scroll(string newDescription, Spell newEffect,  int newMaxHp = 0, int newStrength = 0, int newSpeed = 0, int newIntelligence = 0);

  Spell getEffect()const{return effect;}
  void setEffect(Spell newEffect);

protected:
  Spell effect; //!<The effect that happens upon the use of the Scroll
};

//!A collection of Scrolls into one book
/*!
  Several Scolls combined into one book which may be used to cast the spells in the scrolls or studied to learn said spells
*/
class Grimoire: public Item{
public:
  Grimoire(string newDescription, int newMaxHp = 0, int newStrength = 0, int newSpeed = 0, int newIntelligence = 0);
  virtual ~Grimoire();

  //!Add a Scroll to the Grimoire
  void addPage(Scroll *newPage);
  unsigned int getTotalCharge()const{return totalCharge;}

protected:
  //!The Scrolls contained within this Grimoire
  vector<Scroll *> pages;
  //!The current amount of charge left in this Grimoire
  unsigned int totalCharge; /*!<This is the total amount of charge of all Scrolls contained in pages when created, decreases with use until 0 when the Grimoire is rendered useless*/
};
#endif
