#include "Item.hpp"

Item::Item(string newDescription, int newMaxHp, int newStrength, int newSpeed, int newIntelligence){
  description = newDescription;
  maxHp = newMaxHp;
  strength = newStrength;
  speed = newSpeed;
  intelligence = newIntelligence;
}

void Item::enchant(Enchantment newEnchantment){
  //TODO: Apply effects once Enchantment has been fleshed out
}

Armour::Armour(string newDescription, int newDefence, int newMaxHp, int newStrength, int newSpeed, int newIntelligence):Item(newDescription, newMaxHp, newStrength, newSpeed, newIntelligence){
  defence = newDefence;
}
