#include "Item.hpp"

Item::Item(string newTitle, string newDescription, int newMaxHp, int newStrength, int newSpeed, int newIntelligence, DAMAGE_TYPE newDamageType){
  title = newTitle;
  description = newDescription;
  maxHp = newMaxHp;
  strength = newStrength;
  speed = newSpeed;
  intelligence = newIntelligence;
  damageType = newDamageType;
}

Item::Item(const Item &other){
  title = other.title;
  description = other.description;
  maxHp = other.maxHp;
  strength = other.strength;
  speed = other.speed;
  intelligence = other.intelligence;
  damageType = other.damageType;
  for(unsigned int ctr = 0; ctr < other.effects.size(); ctr++){
    effects.push_back(other.effects[ctr]->clone());
  }
}

Item::~Item(){
  for(unsigned int ctr = 0; ctr < effects.size(); ctr++){
    delete effects[ctr];
  }
}

void Item::enchant(Enchantment newEnchantment){
  //TODO: Apply effects once Enchantment has been fleshed out
}

void Item::addEffect(Effect * newEffect){
  effects.push_back(newEffect);
}

Armour::Armour(string newTitle, string newDescription, int newDefence, int newMaxHp, int newStrength, int newSpeed, int newIntelligence):Item(newTitle, newDescription, newMaxHp, newStrength, newSpeed, newIntelligence){
  defence = newDefence;
}
