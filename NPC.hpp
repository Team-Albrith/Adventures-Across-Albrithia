#ifndef NPC_HPP
#define NPC_HPP
#include "Entity.hpp"
#include "Quest.hpp"

class NPC: public Entity{
public:
  NPC();
  NPC(string newName, int newMaxHp, int newStrength, int newSpeed, int newIntelligence);

protected:
  vector<Quest> quests;
  vector<string> conversation; //not 100%. requires discussion
  //require a seperate conversation class?

};
#endif
