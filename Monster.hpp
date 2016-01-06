#ifndef MONSTER_HPP
#define MONSTER_HPP
#include "Entity.hpp"
class Monster: public Entity{
public:
    Monster();
    Monster(string newName, int newMaxHp, int newStrength, int newSpeed, int newIntelligence);
};
#endif
