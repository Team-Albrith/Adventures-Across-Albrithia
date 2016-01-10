#ifndef MAGIC_HPP
#define MAGIC_HPP

#include "Entity.hpp"
#include <string>
#include <vector>

using std::string;

//! Magic class
/*! The base class for all magic in the game. */
class Magic {

public:
  Magic(); //!< Default Constructor
};

  //! Spell class
  /*! Derived from Magic; User-performed magics. */
  class Spell : public Magic {

  public:
    Spell(); //!< Default Constructor
  };

    //! Buff class
    /*! Derived from Spell; Applies effects such as regen, poison, etc. */
    class Buff : public Spell {

    public:
      Buff(); //!< Default Constructor
    }

  //! Enchantment class
  /*! Derived from Magic; Applies bonus stats to weapons and armor. */
  class Enchantment : public Magic {

  public:
    Enchantment(); //!< Default Constructor
  };

#endif
