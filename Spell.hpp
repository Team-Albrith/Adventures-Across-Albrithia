#ifndef SPELL_HPP
#define SPELL_HPP

#include <string>
#include <vector>

#include "Entity.hpp"

using std::string;

  //! Spell class
  /*! Derived from Magic; User-performed magics. */
  class Spell {

  public:
    Spell(); //!< Default Constructor
  };

    //! Buff class
    /*! Derived from Spell; Applies effects such as regen, poison, etc. */
    class Buff : public Spell {

    public:
      Buff(); //!< Default Constructor
    };

#endif
