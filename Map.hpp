#ifndef MAP_HPP
#define MAP_HPP
#include <string>
#include <vector>
#include "Monster.hpp"

using std::string;
using std::vector;
class Map{
public:
  Map();

  void playerMove(string input);
  int search();
  Monster getSpawn();

protected:
  int id;
  string mod;
  string description;
  vector<Map*> connectedMaps; //maps the player can move too, directly responds too next variable
  vector<char> directions;
  //vector<void> interactables;

  bool searched;
  int searchPass;
  int searchResults;
  vector<Monster> spawns; //possible monster spawns
  vector<Item*> items; //items on ground and dropped by monster



};
#endif

/****
 * Incomplete. Just work from one session. Will complete after further discussion with the group
****/
