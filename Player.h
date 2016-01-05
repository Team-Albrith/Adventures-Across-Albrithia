#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"

class Player: public Entity{
public:
    Player();
    Player(string newName, unsigned int newMaxHp, unsigned int newStrength, unsigned int newSpeed, unsigned int newIntelligence);
    void save(string filename);
    void load(string filename);
};
#endif
