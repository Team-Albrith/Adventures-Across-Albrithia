#ifndef WEAPON_HPP
#define WEAPON_HPP
#include "Item.hpp"

enum DAMAGE_TYPE{
  DAMAGE_PIERCE,
  DAMAGE_BLUDGEON,
  DAMAGE_SLASH
};

//!A wieldable Item
class Weapon: public Item{
public:
  Weapon(string newDescription, DAMAGE_TYPE newDamageType, int newMinDamage = 1, int newRange = 1, int newMaxHp = 0, int newStrength = 0, int newSpeed = 0, int newIntelligence = 0);

  virtual int getDamage();
  int getMinDamage()const{return minDamage;}
  int getRange()const{return range;}
  DAMAGE_TYPE getDamageType()const{return damageType;}

protected:
  int minDamage,//!<The base damage this weapon does
    range;    //!<the range in which to generate the amount of damage
  DAMAGE_TYPE damageType;
};

//!Describes what type of ammo a RangedWeapon fires
struct Ammunition{
  string description;
  DAMAGE_TYPE damageType;
};

//!A child of weapon representing things like bows or guns
class RangedWeapon: public Weapon{
public:
  RangedWeapon(string newDescription, Ammunition ammoType, unsigned int newCurrentAmmo, unsigned int newDepletionAmount = 1, int newMinDamage = 1, int newRange = 1, int newMaxHp = 0, int newStrength = 0, int newSpeed = 0, int newIntelligence = 0);

  //!If canFire then returns damage and deducts ammo, otherwise returns 0
  /*!
    \return if canFire then returns proper damage, otherwise returns 0
  */
  virtual int getDamage();
  Ammunition getAmmoDescription()const{return ammo;}
  unsigned int getCurrentAmmo()const{return currentAmmo;}
  unsigned int getDepletionAmmount()const{return depletionAmount;}
  Ammunition getAmmo()const{return ammo;}
  //!Sets the type of ammo this RangedWeapon fires, also sets damageType
  void setAmmo(Ammunition newAmmo);

  bool canFire()const;//!<Checks to see if there is enough ammo to fire

protected:
  Ammunition ammo;
  unsigned int currentAmmo;
  unsigned int depletionAmount;//!<How much ammo to consume upon attack
};
#endif
