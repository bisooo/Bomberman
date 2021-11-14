#pragma once
#include "Object/Object.h"
#include "Object/Wall.h"
#include "Object/Space.h"
#include "Box/Box.h"
#include "Enemy/Pacman.h"
#include "Enemy/Dollar.h"
#include "Man.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <map>
#include <vector>
#include <ncurses.h>
#include <panel.h>
#include <fstream>
using namespace std;


/// instance of a level
class Map
{
private:
  /// 2D vector of objects
  vector< vector < Object* > > map;
  /// 2D vector of charecters
  vector< vector < char > > file;
  /// vector of enemy instances in the map
  vector< Enemy* > enemies;
  /// vector of box instances in the map
  vector< Box* > boxes;
  /// vector of bombermen in "VS" map
  vector< Man > mandem;
  /// level of the map loaded
  int level;
  /// filename of the level's txt map
  string filename;
  /// number of enemies in the loaded map
  int enemiesleft = 0;


public:
  Map();
  /**
  "setter" for the level and filename
  @param lvl level number
  */
  void setlevel(int lvl);
  /**
  "setter" for the level and filename
  @param file txt filename of the map
  */
  void setfile(string file);
  /**
  modifies the 2D charecter vector at a specified coordinate
  @param x horizontal coordinate
  @param y vertical coordinate
  @param charecter value to be set
  */
  void setfilexy(const size_t & x, const size_t & y, char charecter);
  /// resets the number of enemies to 0 zero between levels
  void resetenemiesleft();
  /**
  @return the number of enemies in the map
  */
  int getenemiesleft();
  /**
  "getter" for the 2D charecter vector at a specified coordinate
  @param x horizontal coordinate
  @param y vertical coordinate
  @return charecter value at the specified coordinate
  */
  char getfilexy(const size_t & x, const size_t & y);
  /**
  "getter" for the 2D Object vector at a specified coordinate
  @param x horizontal coordinate
  @param y vertical coordinate
  @return Object instance at the specified coordinate
  */
  Object * getmapxy(const size_t & x, const size_t & y);
  /// "getter" for the vector of enemies in the map
  vector<Enemy*> getenemies();
  /// "getter" for the vector of boxes in the map
  vector<Box*> getboxes();
  /// "getter" for the vector of bombermen in the map
  vector<Man> getmandem();

  /// reads the txt file into the vector of chars
  bool readlevel();
  /// initialises the objects into the 2D vector of objects
  void loadobjects();
  /// clears both map vectors
  void clearmap();
};
