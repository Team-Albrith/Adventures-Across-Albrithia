#ifndef NPC_HPP
#define NPC_HPP
#include "Entity.hpp"
class NPC: public Entity{
public:
    NPC();
    NPC(string newName, int newMaxHp, int newStrength, int newSpeed, int newIntelligence);
  
};
#endif
