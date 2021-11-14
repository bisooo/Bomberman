#pragma once
#include "Play.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <ncurses.h>
#include <panel.h>
using namespace std;


/// instance to represent one unique user playing the game
class User
{
private:
  /// "FRONTEND" player instance
  Play player;
  /// current level loaded
  int level;
  /// player's highscore
  int highscore;
  /// player's username
  string username;
  /// loads the player's stats from the file into the "player" instance
  bool loadstats();

public:
  /// default constructor
  User();
  /// constructor - starting a new game
  User( int lvl, int score, string username );
  /// constructor - loading a game
  User( string name );

  /**
  " GAME LOOP "
  @return the status of the game
  */
  bool newgame();
  /// same "game loop" but the game values are set from the loaded file
  bool loadgame();
  /// "game loop" where its Bombermen "VS" BomberMan
  bool vsgame();
};
