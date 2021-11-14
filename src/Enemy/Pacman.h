#pragma once
#include "Enemy.h"

/// An enemy with regular speed that moves horizontally and switches directions randomly
class Pacman : public Enemy
{
private:
  /// charecter of the enemy
  char charecter = '<';
  /// speed of the enemy
  int speed = 10000;
  /// x coordinate of the enemy
  int xpos;
  /// y coordinate of the enemy
  int ypos;
  /// money collected from the enemy's death
  int mola = 100;
  /// direction of the enemy's movement
  char direction;
  /// status of the enemy's movement blocking
  bool block = false;
  /// status of the enemy's life
  bool living = true;
  /// status of the enemy's display
  bool display = false;
  /// status of the enemy's money collection
  bool eat = false;
  /// status of enemy in the level
  bool dunknow = false;

public:
  Pacman();
  // virtual ~Pacman();

  /// starting x coordinate of the enemy
  int startx;
  /// starting y coordinate of the enemy
  int starty;

  /// "setter" for the enemy's x coordinate
  virtual void setxpos(int x);
  /// "setter" for the enemy's y coordinate
  virtual void setypos(int y);
  virtual void setdirection(char dir);
  /// "setter" for the enemy's life state
  virtual void setlife(bool state);
  /// "setter" for the enemy's display state
  virtual void setdisplay(bool state);
  /// "setter" for the enemy's eaten state
  virtual void seteat(bool state);
  /// "setter" for the enemy's blocked state
  virtual void setblock(bool state);
  /// "setter" for the enemy's state in the level
  virtual void setdunknow(bool state);

  /// "getter" for the enemy's charecter
  virtual char getcharecter() const override;
  /// "getter" for the enemy's x coordinate
  virtual int getxpos() const override;
  /// "getter" for the enemy's y coordinate
  virtual int getypos() const override;
  /// "getter" for the enemy's direction
  virtual char getdirection() const override;
  /// "getter" for the enemy's speed
  virtual int getspeed() const override;
  /// "getter" for the enemy's life state
  virtual bool alive() const override;
  /// "getter" for the enemy's display state
  virtual bool displayed() const override;
  /// "getter" for the enemy's eaten
  virtual bool eaten() const override;
  /// "getter" for the enemy's money
  virtual int money() const override;
  /// "getter" for the enemy's blocked state
  virtual bool blocked() const override;
  /// "getter" for the enemy's state in the level
  virtual bool yadunknow() const override;

  /// resets the enemy's coordinates to the starting positons
  virtual void resetpos() override;
  /// reverses the enemy's direction of movement
  virtual void reversedir() override;
  /// sets the initial direction randomly
  virtual void setrandomdir();

  /// validates the enemy's move
  virtual bool validate_move(char object, int x, int y) override;
  /// updates the enemies move after its validated
  virtual void move() override;
};
