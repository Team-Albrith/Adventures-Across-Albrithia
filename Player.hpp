#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Entity.hpp"

class Player: public Entity{
public:
    Player();
    Player(string newName, int newMaxHp, int newStrength, int newSpeed, int newIntelligence);
    void save(string filename);
    void load(string filename);
};
#endif
