#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <vector>
#include <string>

using std::vector;
using std::string;

class Item;

class Entity{
public:
  Entity();
  Entity(string newName, int newMaxHp, int newStrength, int newSpeed, int newIntelligence);
  virtual ~Entity();

  //TODO: make setters and getters for rest of stats
  virtual string getName()const{return name;}
  virtual int getMaxHp()const;
  virtual int getCurrentHp()const;
  virtual int getStrength()const;
  virtual int getSpeed()const;
  virtual int getIntelligence()const;

  virtual void setName(string newName);
  virtual void setMaxHp(int newMaxHp);
  virtual void setCurrentHp(int newCurrentHp);
  virtual void setStrength(int newStrength);
  virtual void setSpeed(int newSpeed);
  virtual void setIntelligence(int newIntelligence);

  virtual bool defend(Entity * attacker) = 0; //NOTE: This will be defined in the child classes
  virtual bool removeItem(string description);
  virtual void addItem(Item * item);
  virtual void equip(Item * item); //NOTE: this takes a pointer rather than an iterator/index to allow for combo pickup-equip. AKA if item is not in inventory, add it to inventory

protected:
  int maxHp, currentHp, strength, speed, intelligence; //TODO: Fill in rest of stats
  vector<Item *> inventory;
  Item * currentArmour;
  Item * currentWeapon;
  string name;
};
#endif
