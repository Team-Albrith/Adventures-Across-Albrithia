#include "Item.hpp"
#include <stdlib.h>

Item::Item(string newDescription, int newMaxHp, int newStrength, int newSpeed, int newIntelligence){
    description = newDescription;
    maxHp = newMaxHp;
    strength = newStrength;
    speed = newSpeed;
    intelligence = newIntelligence;
}

Weapon::Weapon(string newDescription, int newMinDamage, int newRange, int newMaxHp, int newStrength, int newSpeed, int newIntelligence):Item(newDescription, newMaxHp, newStrength, newSpeed, newIntelligence){
    minDamage = newMinDamage;
    range = newRange;
}

int Weapon::getDamage()const{
    return (rand() % minDamage) + range;
}

Armour::Armour(string newDescription, int newDefence, int newMaxHp, int newStrength, int newSpeed, int newIntelligence):Item(newDescription, newMaxHp, newStrength, newSpeed, newIntelligence){
    defence = newDefence;
}

Potion::Potion(string newDescription, int newMaxHp, int newStrength, int newSpeed, int newIntelligence):Item(newDescription, newMaxHp, newStrength, newSpeed, newIntelligence){

}

Scroll::Scroll(string newDescription, unsigned int newCharge, int newMaxHp, int newStrength, int newSpeed, int newIntelligence):Item(newDescription, newMaxHp, newStrength, newSpeed, newIntelligence){
    charge = newCharge;
}

void Scroll::setCharge(unsigned int newCharge){
    charge = newCharge;
}

Grimoire::Grimoire(string newDescription, int newMaxHp, int newStrength, int newSpeed, int newIntelligence):Item(newDescription, newMaxHp, newStrength, newSpeed, newIntelligence){

}

Grimoire::~Grimoire(){
    for(unsigned int i = 0; i < pages.size(); i++){
        delete pages[i];
    }
}

void Grimoire::addPage(Scroll * newPage){
    pages.push_back(newPage);
    totalCharge += newPage->getCharge();
}
