#pragma once
#include "../Object/Object.h"
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


/// contains hidden upgrades and blocks bomberman & enemies
class Box : public Object
{
private:
  /// charecter of the box
  char charecter = '%';
  /// charecter of an ugprade
  char upgrade = ' ';
  /// x coordinate of the box
  int xpos;
  /// y coordinate of the box
  int ypos;
  /// status of the box blasted
  bool blast = false;
  /// status of the upgrade displayed
  bool display = false;
  /// status of the upgrade use
  bool use = false;
  /// status of a box in the level
  bool dunknow = false;

public:
  Box();
  // virtual ~Box();

  /// "setter" for the box's upgrade
  virtual void setupgrade(char karekter);
  /// "setter" for the box's x coordinate
  virtual void setxpos(int x);
  /// "setter" for the box's y coordinate
  virtual void setypos(int y);
  /// "setter" for the box's blasted state
  virtual void setblast(bool state);
  /// "setter" for the box's upgrade display state
  virtual void setdisplay(bool state);
  /// "setter" for the box's upgrade use state
  virtual void setuse(bool state);
  /// "setter" for the box's state in the level
  virtual void setdunknow(bool state);

  /// "getter" for the box's charecter
  virtual char getcharecter() const override;
  /// "getter" for the box's upgrade
  virtual char getupgrade() const;
  /// "getter" for the box's x coordinate
  virtual int getxpos() const;
  /// "getter" for the box's y coordinate
  virtual int getypos() const;
  /// "getter" for the box's blasted state
  virtual bool blasted() const;
  /// "getter" for the box's upgrade display state
  virtual bool displayed() const;
  /// "getter" for the box's upgrade use state
  virtual bool used() const;
  /// "getter" for the box's state in the level
  virtual bool yadunknow() const;

};
