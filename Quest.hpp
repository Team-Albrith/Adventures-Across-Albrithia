#ifndef QUEST_HPP
#define QUEST_HPP
#include <string>
#include <vector>
#include "Item.hpp"

using std::string;
using std::vector;

class Quest{
public:
  Quest();

protected:
  vector<string> story;
  int id;
  string mod;
  vector<Item *> rewards;


};
#endif

//Incomplete
