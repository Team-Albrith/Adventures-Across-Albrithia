#include "Weapon.hpp"
#include <stdlib.h>

Weapon::Weapon(string newTitle, string newDescription, DAMAGE_TYPE newDamageType, int newMinDamage, int newRange, int newMaxHp, int newStrength, int newSpeed, int newIntelligence):Item(newTitle, newDescription, newMaxHp, newStrength, newSpeed, newIntelligence, newDamageType){
  minDamage = newMinDamage;
  range = newRange;
}

int Weapon::getDamage(){
  return (rand() % range) + minDamage;
}

RangedWeapon::RangedWeapon(string newTitle, string newDescription, Ammunition ammoType, unsigned int newCurrentAmmo, unsigned int newDepletionAmount, int newMinDamage, int newRange, int newMaxHp, int newStrength, int newSpeed, int newIntelligence):Weapon(newTitle, newDescription, ammoType.damageType, newMinDamage, newRange, newMaxHp, newStrength, newSpeed, newIntelligence){
  setAmmo(ammoType);
  currentAmmo = newCurrentAmmo;
  depletionAmount = newDepletionAmount;
}

int RangedWeapon::getDamage(){
  int result = 0;
  if(canFire()){
    currentAmmo -= depletionAmount;
    result = Weapon::getDamage();
  }
  return result;
}

void RangedWeapon::setAmmo(Ammunition newAmmo){
  ammo = newAmmo;
  damageType = ammo.damageType;
}

bool RangedWeapon::canFire()const{
  return currentAmmo > depletionAmount;
}
