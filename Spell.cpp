#include "Spell.hpp"

Spell::Spell(){

}

Spell::~Spell() {
    for (const Effect* spell : effects) {
        delete spell;
    }
}
