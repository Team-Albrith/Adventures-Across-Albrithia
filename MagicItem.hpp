#ifndef MAGICITEM_HPP
#define MAGICITEM_HPP
#include "Item.hpp"

//!An Item which grants a magical effect when consumed
class Potion: public Item{
public:
  Potion(string newTitle, string newDescription, Spell newEffect, int newMaxHp = 0, int newStrength = 0, int newSpeed = 0, int newIntelligence = 0);

  Spell getEffect()const{return effect;}
  void setEffect(Spell newEffect);

protected:
  Spell effect; //!<The effect that happens upon consumption of this Potion
};

//!An Item which casts a spell when used
/*!
  Using the Scroll costs no mana, but mana is consumed in the creation of Scrolls
*/
class Scroll: public Item{
public:
  Scroll(string newTitle, string newDescription, Spell newEffect,  int newMaxHp = 0, int newStrength = 0, int newSpeed = 0, int newIntelligence = 0);

  Spell getEffect()const{return effect;}
  void setEffect(Spell newEffect);

protected:
  Spell effect; //!<The effect that happens upon the use of the Scroll
};

//!A collection of Scrolls into one book
/*!
  Several Scolls combined into one book which may be used to cast the spells in the scrolls or studied to learn said spells
*/
class Grimoire: public Item{
public:
  Grimoire(string newTitle, string newDescription, int newMaxHp = 0, int newStrength = 0, int newSpeed = 0, int newIntelligence = 0);
  virtual ~Grimoire();

  //!Add a Scroll to the Grimoire
  void addPage(Scroll *newPage);
  unsigned int getTotalCharge()const{return totalCharge;}

protected:
  //!The Scrolls contained within this Grimoire
  vector<Scroll *> pages;
  //!The current amount of charge left in this Grimoire
  /*!
    This is the total amount of charge of all Scrolls contained in pages when created, decreases with use until 0 when the Grimoire is rendered useless
  */
  unsigned int totalCharge;
};
#endif
