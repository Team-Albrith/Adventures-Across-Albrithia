#ifndef ENCHANTMENT_HPP
#define ENCHANTMENT_HPP

class Item;

//! Enchantment class
/*! Derived from Magic; Applies bonus stats to weapons and armor. */
class Enchantment {
public:
  Enchantment(); //!< Default Constructor
  Enchantment(string newName, string newDescription);
  //TODO: Constructors for skill, stat increase and effects

  void setName(string newName);
  void setDescription(string description);

  //TODO: getter/setter for skills and effects

private:
    string name;
    string description;

    //Parallel array of skill and its increase
    vector<int*> skill;
    vector<int> statIncrease;

    vector<Effect*> effects;
};

#endif
