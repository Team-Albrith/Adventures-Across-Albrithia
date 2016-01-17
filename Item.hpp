#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
#include <vector>

#include "Spell.hpp"
#include "Enchantment.hpp"

using std::string;
using std::vector;
/*!
  \file Item.hpp This is the file for Item and its children
*/

//!Our base class for Items
/*!
  A class representing a basic Item. It contains stats to store what the item does to the Entity when used/equipped. Ie, a sword of intellect would set intelligence to 3 to represent that equipping it increases your intelligence, or Armour setting speed to a negative value to lower the speed of the Entity upon equipping.
*/
class Item{
public:
  Item(string newDescription, int newMaxHp = 0, int newStrength = 0, int newSpeed = 0, int newIntelligence = 0);
  virtual ~Item(){}

  string getDescription()const{return description;}
  virtual int getMaxHp()const{return maxHp;}
  virtual int getStrength()const{return strength;}
  virtual int getSpeed()const{return speed;}
  virtual int getIntelligence()const{return intelligence;}

  //!Takes an Enchantment and applies it to this Item
  void enchant(Enchantment newEnchantment);

protected:
  string description;
  int maxHp, strength, speed, intelligence;//NOTE: These are the values added to stats when item is equipped/used
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
#endif
