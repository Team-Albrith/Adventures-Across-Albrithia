#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
#include <vector>
#include "Magic.hpp"

using std::string;
using std::vector;

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
    Weapon(string newDescription, int newMinDamage = 1, int newRange = 0, int newMaxHp = 0, int newStrength = 0, int newSpeed = 0, int newIntelligence = 0);

    int getDamage()const;
    int getMinDamage()const{return minDamage;}
    int getRange()const{return range;}

protected:
    int minDamage, range;
};

class Armour: public Item{
public:
    Armour(string newDescription, int newDefence = 1, int newMaxHp = 0, int newStrength = 0, int newSpeed = 0, int newIntelligence = 0);

    int getDefence()const{return defence;}
protected:
    int defence;
};

//TODO: Potions, Scrolls, etc
class Potion: public Item{
public:
    Potion(string newDescription, int newMaxHp = 0, int newStrength = 0, int newSpeed = 0, int newIntelligence = 0);

};

class Scroll: public Item{
public:
    Scroll(string newDescription, unsigned int newCharge = 1, int newMaxHp = 0, int newStrength = 0, int newSpeed = 0, int newIntelligence = 0);

    unsigned int getCharge()const{return charge;}
    void setCharge(unsigned int newCharge);
protected:
    unsigned int charge;
};

class Grimoire: public Item{
public:
    Grimoire(string newDescription, int newMaxHp = 0, int newStrength = 0, int newSpeed = 0, int newIntelligence = 0);
    virtual ~Grimoire();

    void addPage(Scroll * newPage);
    unsigned int getTotalCharge()const{return totalCharge;}
protected:
    vector<Scroll *> pages;
    unsigned int totalCharge;
};
#endif
