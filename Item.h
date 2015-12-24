#ifndef ITEM_H
#define ITEM_H
#include <string>

using std::string;

class Item{
public:
  Item(string newDescription, unsigned int newMaxHp = 0, unsigned int newStrength = 0, unsigned int newSpeed = 0, unsigned int newIntelligence = 0, bool armourEquipable = false);

  bool isArmour()const{return armour;}
  string getDescription()const{return description;}
  
protected:
  bool armour;
  string description;
  unsigned int maxHp, strength, speed, intelligence;//NOTE: These are the values added to stats when item is equipped
};
#endif
