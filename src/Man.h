#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <map>
#include <vector>
#include <ncurses.h>
#include <panel.h>
using namespace std;


/// Bomberman instance of a user
class Man
{
private:
  /// charecter of the bomberman
  char charecter;
  /// number of lives of the bomberman
  int lives;
  /// movement speed of the bomberman
  int speed = 30000;
  /// horizontal coordinate of the bomberman
  int xpos;
  /// vertical coordinate of the bomberman
  int ypos;
  /// power range of a regular bomb
  int bombpower = 2;
  /// power range of a remote bomb
  int remotepower = 1;
  /// maximum number of normal bombs to be dropped
  int bombmax = 3;
  /// maximum number of remote bombs to be dropped
  int remotemax = 2;
  /// number of normal bombs dropped
  int bombsused = 0;
  /// number of remote bombs dropped
  int remotesused = 0;
  /// flag to move away after bomb drop in "vs" mode
  int dropped = 0;

public:
    Man();

    /// "setter" for the bomberman's charecter
    void setcharecter(char karekter);
    /// "setter" for the bomberman's lives
    void setlives(int lvs);
    /// "setter" for the bomberman's x coordinate
    void setxpos(int startx);
    /// "setter" for the bomberman's y coordinate
    void setypos(int starty);
    /// "setter" for the bomberman's maximum number of normal bombs
    void setbombmax(int no);
    /// "setter" for the bomberman's maximum number of remote bombs
    void setremotemax(int no);
    /// "setter" for the bomberman's number of used normal bombs
    void setbombsused(int no);
    /// "setter" for the bomberman's number of used remote bombs
    void setremotesused(int no);
    /// "setter" for the power of a normal bomb
    void setbombpower(int power);
    /// "setter" for the power of a remote bomb
    void setremotepower(int power);
    /// "setter" for the bomb dropping flag
    void setdrop(int status);

    ///"getter" for the bomberman's charecter
    char getcharecter();
    /// "getter" for the bomberman's lives
    int getlives();
    /// "getter" for the bomberman's x coordinate
    int getxpos();
    /// "getter" for the bomberman's y coordinate
    int getypos();
    /// "setter" for the bomberman's speed
    int getspeed();
    /// "getter" for the bomberman's maximum number of normal bombs
    int getbombsmax();
    /// "getter" for the bomberman's maximum number of remote bombs
    int getremotesmax();
    /// "getter" for the bomberman's number of used normal bombs
    int getbombsused();
    /// "getter" for the bomberman's number of used remote bombs
    int getremotesused();
    /// "getter" for the power of a normal bomb
    int getbombpower();
    /// "getter" for the power of a remote bomb
    int getremotepower();
    /// "getter" for bomb dropping flag
    int getdrop();

    /**
    @param object at the position the player wants to move to
    @return if the player's move is valid
    */
    bool validate_move(char object);
    /// updates the bomberman's coordinates after the move is validated
    void move(char direction);
    /**
     "AI" of the bombermen's movement in "VS" mode
     @param x coordinate of the bomberman to follow
     @param y coordinate of the bomerman to follow
     @param uf flag representing if up movement is valid
     @param df flag representing if down movement is valid
     @param rf flag representing if right movement is valid
     @param lf flag representing if left movement is valid
    */
    void AImove(int x, int y, int uf, int df, int rf, int lf);
};
