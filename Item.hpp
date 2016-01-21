#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
#include <vector>

#include "Spell.hpp"
#include "Enchantment.hpp"
#include "Effect.hpp"

using std::string;
using std::vector;
/*!
  \file Item.hpp This is the file for Item and its children
*/

//!An enum representing the different kinds of damage various attacks can do
enum DAMAGE_TYPE{
  DAMAGE_PIERCE,
  DAMAGE_BLUDGEON,
  DAMAGE_SLASH,
  DAMAGE_ARCANE,
  DAMAGE_NATURE, //!<Represents damage from natural sources such as being on fire
  DAMAGE_DIVINE
};

//!Our base class for Items
/*!
  A class representing a basic Item. It contains stats to store what the item does to the Entity when used/equipped. Ie, a sword of intellect would set intelligence to 3 to represent that equipping it increases your intelligence, or Armour setting speed to a negative value to lower the speed of the Entity upon equipping.
*/
class Item{
public:
  Item(string newTitle, string newDescription, int newMaxHp = 0, int newStrength = 0, int newSpeed = 0, int newIntelligence = 0, DAMAGE_TYPE newDamageType = DAMAGE_BLUDGEON);
  virtual ~Item();
  Item(const Item &other);

  string getDescription()const{return description;}
  string getTitle()const{return title;}
  DAMAGE_TYPE getDamageType()const{return damageType;}
  virtual int getMaxHp()const{return maxHp;}
  virtual int getStrength()const{return strength;}
  virtual int getSpeed()const{return speed;}
  virtual int getIntelligence()const{return intelligence;}

  //!Takes an Enchantment and applies it to this Item
  void enchant(Enchantment newEnchantment);
  void addEffect(Effect * newEffect);

protected:
  string description, title;
  int maxHp, strength, speed, intelligence;//NOTE: These are the values added to stats when item is equipped/used
  //!The type of damage this Item does when used in battle
  /*!
    If this Item is used in battle as a Weapon then it would deal this type of damage, note this is normally DAMAGE_BLUDGEON if this instance isn't a, or a child of Weapon
   */
  DAMAGE_TYPE damageType;
  //!A vector of effects that can happen from using this Item (normally as a child class)
  vector<Effect *> effects;
};

//!An equippable Item
class Armour: public Item{
public:
  Armour(string newTitle, string newDescription, int newDefence = 1, int newMaxHp = 0, int newStrength = 0, int newSpeed = 0, int newIntelligence = 0);

  int getDefence()const{return defence;}

protected:
  //!The amount of damage this Armour pretects you from
  int defence;
};
#endif
