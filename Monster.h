#ifndef MONSTER_H
#define MONSTER_H
#include "Entity.h"
class Monster: public Entity{
public:
  Monster();
  Monster(string newName, unsigned int newMaxHp, unsigned int newStrength, unsigned int newSpeed, unsigned int newIntelligence);
};
#endif
