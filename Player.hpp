#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Entity.hpp"

class Player: public Entity{
public:
    Player();
    Player(string newName, unsigned int newMaxHp, unsigned int newStrength, unsigned int newSpeed, unsigned int newIntelligence);
    void save(string filename);
    void load(string filename);
};
#endif
