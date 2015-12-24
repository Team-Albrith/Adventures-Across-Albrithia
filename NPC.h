#ifndef NPC_H
#define NPC_H
#include "Entity.h"
class NPC: public Entity{
public:
  NPC();
  NPC(string newName, unsigned int newMaxHp, unsigned int newStrength, unsigned int newSpeed, unsigned int newIntelligence);
  
};
#endif
