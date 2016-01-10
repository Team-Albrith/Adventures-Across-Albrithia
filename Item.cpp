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

Potion::Potion(string newDescription, Buff newEffect, int newMaxHp, int newStrength, int newSpeed, int newIntelligence):Item(newDescription, newMaxHp, newStrength, newSpeed, newIntelligence){
  effect = newEffect;
}

void Potion::setEffect(Buff newEffect){
  effect = newEffect;
}

Scroll::Scroll(string newDescription, Spell newEffect, int newMaxHp, int newStrength, int newSpeed, int newIntelligence):Item(newDescription, newMaxHp, newStrength, newSpeed, newIntelligence){
  effect = newEffect;
}

void Scroll::setEffect(Spell newEffect){
  effect = newEffect;
}

Grimoire::Grimoire(string newDescription, int newMaxHp, int newStrength, int newSpeed, int newIntelligence):Item(newDescription, newMaxHp, newStrength, newSpeed, newIntelligence){

}

Grimoire::~Grimoire(){
  for(unsigned int i = 0; i < pages.size(); i++){
    delete pages[i];
  }
}

void Grimoire::addPage(Scroll *newPage){
  pages.push_back(newPage);
  totalCharge += 1; //TODO: have this be calculated from the Spell contained within newPage
}
