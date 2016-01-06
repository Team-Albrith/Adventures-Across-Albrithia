#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>

using std::string;

class Item{
public:
    Item(string newDescription, int newMaxHp = 0, int newStrength = 0, int newSpeed = 0, int newIntelligence = 0);

    string getDescription()const{return description;}
  
protected:
    string description;
    int maxHp, strength, speed, intelligence;//NOTE: These are the values added to stats when item is equipped
};

class Weapon: public Item{
public:
    Weapon(string newDescription, int newMaxHp = 0, int newStrength = 0, int newSpeed = 0, int newIntelligence = 0);
    int getDamage()const;
protected:
    int minDamage, maxDamage;
};

class Armour: public Item{
public:
    Armour(string newDescription);

};

//TODO: Potions, Scrolls, etc
#endif
