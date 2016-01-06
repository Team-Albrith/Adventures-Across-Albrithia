#ifndef MONSTER_HPP
#define MONSTER_HPP
#include "Entity.hpp"
class Monster: public Entity{
public:
    Monster();
    Monster(string newName, unsigned int newMaxHp, unsigned int newStrength, unsigned int newSpeed, unsigned int newIntelligence);
};
#endif
