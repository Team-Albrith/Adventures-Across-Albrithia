#ifndef ENTITY_H
#define ENTITY_H
#include "Item.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

class Entity{
public:
    Entity();
    Entity(string newName, unsigned int newMaxHp, unsigned int newStrength, unsigned int newSpeed, unsigned int newIntelligence);
    virtual ~Entity();

    //TODO: make setters and getters for rest of stats
    virtual string getName()const{return name;}
    virtual unsigned int getMaxHp()const;
    virtual unsigned int getCurrentHp()const;
    virtual unsigned int getStrength()const;
    virtual unsigned int getSpeed()const;
    virtual unsigned int getIntelligence()const;

    virtual void setName(string newName);
    virtual void setMaxHp(unsigned int newMaxHp);
    virtual void setCurrentHp(unsigned int newCurrentHp);
    virtual void setStrength(unsigned int newStrength);
    virtual void setSpeed(unsigned int newSpeed);
    virtual void setIntelligence(unsigned int newIntelligence);

    virtual bool defend(Entity * attacker) = 0; //NOTE: This will be defined in the child classes
    virtual bool removeItem(string description);
    virtual void addItem(Item * item);
    virtual void equip(Item * item); //NOTE: this takes a pointer rather than an iterator/index to allow for combo pickup-equip. AKA if item is not in inventory, add it to inventory
  
protected:
    unsigned int maxHp, currentHp, strength, speed, intelligence; //TODO: Fill in rest of stats
    vector<Item *> inventory;
    Item * armour;
    Item * equiped;
    string name;
};
#endif
