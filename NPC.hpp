#ifndef NPC_HPP
#define NPC_HPP
#include "Entity.hpp"
class NPC: public Entity{
public:
    NPC();
    NPC(string newName, unsigned int newMaxHp, unsigned int newStrength, unsigned int newSpeed, unsigned int newIntelligence);
  
};
#endif
