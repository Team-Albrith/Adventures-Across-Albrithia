#include "Effect.hpp"

Effect::Effect(string newTitle, string newDescription, unsigned int duration, float percentChanceOfHit){
  title = newTitle;
  description = newDescription;
  remainingTurns = duration;
  chanceOfHit = percentChanceOfHit;
}
