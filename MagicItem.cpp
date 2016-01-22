#include "MagicItem.hpp"

Potion::Potion(string newTitle, string newDescription, Spell newEffect, int newMaxHp, int newStrength, int newSpeed, int newIntelligence):Item(newTitle, newDescription, newMaxHp, newStrength, newSpeed, newIntelligence){
  effect = newEffect;
}

void Potion::setEffect(Spell newEffect){
  effect = newEffect;
}

Scroll::Scroll(string newTitle, string newDescription, Spell newEffect, int newMaxHp, int newStrength, int newSpeed, int newIntelligence):Item(newTitle, newDescription, newMaxHp, newStrength, newSpeed, newIntelligence){
  effect = newEffect;
}

void Scroll::setEffect(Spell newEffect){
  effect = newEffect;
}

Grimoire::Grimoire(string newTitle, string newDescription, int newMaxHp, int newStrength, int newSpeed, int newIntelligence):Item(newTitle, newDescription, newMaxHp, newStrength, newSpeed, newIntelligence){

}

Grimoire::~Grimoire(){
  for(unsigned int i = 0; i < pages.size(); i++){
    delete pages[i];
  }
}

void Grimoire::addPage(Scroll *newPage){
  pages.push_back(newPage);
  totalCharge += 1; //TODO: have this be calculated from the Spell contained within newPage once Spell has been fleshed out
}
