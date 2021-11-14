#pragma once
#include "Man.h"
#include "Map.h"
#include "Bomb/BombA.h"
#include "Bomb/BombB.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <ncurses.h>
#include <panel.h>
#include <time.h>
using namespace std;


/// " BACKEND " - all the game logic
class Game
{
public:
  /// default constructor
  Game();
  /// instance of the bomberman in the current game instance
  Man bomberman;
  /// instance of the current level's map
  Map map;
  /// timelimit for the completion of the level 300 seconds
  int timelimit = 300000;
  /// number of enemies left in the current level
  int enemiesleft;
  /// player's score
  int score = 0;
  /// current level's score points
  int lvlpoints = 0;
  /// vector of Enemy objects in the loaded level's map
  vector<Enemy*> enemies;
  /// vector of Bomb objects dropped by the bomberman
  vector<Bomb*> bombs;
  /// vector of Box objects in the loaded level's map
  vector<Box*> boxes;
  /// vector of Bombermen in the "VS" mode map
  vector<Man> mandem;

  /**
  constructs and sets the initial fields of the bomberman
  @param karekter charecter of the bomberman
  @param lvs lives of the bomberman
  @param x horizontal coordinate of the bomberman
  @param y vertical coordinate of the bomberman
  */
  void constructman(char karekter, int lvs, int x, int y);
  /**
  constructs and sets the initial fields of the map
  @param lvl level to be loaded
  @param file filename for the txt map of the level
  */
  void constructmap(int lvl, string file);
  /**
  reads the map from the text file in the 2D char vector
  and constructs the objects in the 2D object vector
  @return the status of the file reading
  */
  bool readmap();
  /**
  calculates & updates the time difference in seconds
  @param start the time when the level was started
  @return the status of the time left
  */
  bool updatetime(time_t start);
  /**
  validates the player's next movement coordinates in the map and updates their coordinates
  @param bomberman instance to move
  @param x current horizontal coordinate of the bomberman
  @param y current vertical coordinate of the bomberman
  @param direction of movement "U" / "D" / "R" / "L"
  */
  void player_move(Man & bomberman, int x, int y, char direction);
  /**
  validates the enemies move and updates their coordinates
  @param enemy instance
  */
  void enemy_move(Enemy * enemy);
  /// checks & updates blasted boxes
  void checkboxes();
  /**
  creates a new Bomb A instance and sets its dropped position
  adds the bomb to the vector of bombs in the map
  @param x horizontal coordinate of the bomb
  @param y vertical coordinate of the bomb
  @param type specifies either Bomb "A" or "B"
  */
  void dropbomb(int x, int y, char type);
  /// checks the current game time and the bomb's countdown to update the detonated
  void checkdetonates();
  /// remotely detonates the placed bombs
  void remotedetonate();
  /**
  sets state of enemy's life
  @param enemy instance
  */
  void enemyblasted(Enemy * enemy);
  /**
  @param x horizontal coordinate of the bomberman
  @param y vertical coordinate of the bomberman
  @return if the player was affected by a bomb
  */
  bool playerblasted(int x, int y);
  /// checks if an enemy was blasted by a bomb and updates their attributes
  void enemiesblasted();
  /// checks if a bomberman was blasted by a bomb and updates their attributes
  void mandemblasted();
  /**
  "AI" movement of the bombermen in "VS" mode
  @param man instance of bomberman in "VS" to move
  @param flag value used so either bombermen follow a path to
              the bomberman or just follow
              normal horizontal / vertical movement
  */
  void AImove(Man & man, int flag);
  /**
  "AI" bomb dropping in "VS" mode
  @param man instance of bomberman in "VS" to drop a bomb
  */
  void AIdropbomb(Man & man);
};
