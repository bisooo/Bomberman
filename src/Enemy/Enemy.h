#pragma once
#include "../Object/Object.h"

/// Abstract enemy "Object"
class Enemy : public Object
{
private:
  /// speed of the enemy
  int speed;
  /// starting x coordinate of the enemy
  int startx;
  /// starting y coordinate of the enemy
  int starty;
  /// x coordinate of the enemy
  int xpos;
  /// y coordinate of the enemy
  int ypos;
  /// money collected from the enemy's death
  int mola;
  /// direction of the enemy's movement
  char direction;
  /// status of the enemy's movement blocking
  bool block;
  /// status of the enemy's life
  bool living;
  /// status of the enemy's display
  bool display;
  /// status of the enemy's money collection
  bool eat;
  /// status of enemy in the level
  bool dunknow;

public:
  Enemy();
  virtual ~Enemy() noexcept(true);
  /// "setter" for the enemy's x coordinate
  virtual void setxpos(int x) = 0;
  /// "setter" for the enemy's y coordinate
  virtual void setypos(int y) = 0;
  /// "setter" for the enemy's direction
  virtual void setdirection(char dir) = 0;
  /// "setter" for the enemy's life state
  virtual void setlife(bool state) = 0;
  /// "setter" for the enemy's display state
  virtual void setdisplay(bool state) = 0;
  /// "setter" for the enemy's eaten state
  virtual void seteat(bool state) = 0;
  /// "setter" for the enemy's blocked state
  virtual void setblock(bool state) = 0;
  /// "setter" for the enemy's state in the level
  virtual void setdunknow(bool state) = 0;

  /// "getter" for the enemy's charecter
  virtual char getcharecter() const = 0;
  /// "getter" for the enemy's x coordinate
  virtual int getxpos() const = 0;
  /// "getter" for the enemy's y coordinate
  virtual int getypos() const = 0;
  /// "getter" for the enemy's direction
  virtual char getdirection() const = 0;
  /// "getter" for the enemy's speed
  virtual int getspeed() const = 0;
  /// "getter" for the enemy's life state
  virtual bool alive() const = 0;
  /// "getter" for the enemy's display state
  virtual bool displayed() const = 0;
  /// "getter" for the enemy's eaten state
  virtual bool eaten() const = 0;
  /// "getter" for the enemy's money
  virtual int money() const = 0;
  /// "getter" for the enemy's blocked state
  virtual bool blocked() const = 0;
  /// "getter" for the enemy's state in the level
  virtual bool yadunknow() const = 0;

  /// resets the enemy's coordinates to the starting positons
  virtual void resetpos() = 0;
  /// reverses the enemy's direction of movement
  virtual void reversedir() = 0;
  /// sets the initial direction randomly
  virtual void setrandomdir() = 0;

  /**
  @param object at the position the enemy wants to move to
  @param x coordinate positon of the enemy
  @param y coordinate position of the enemy
  @return if the enemy's move is valid
  */
  virtual bool validate_move(char object, int x, int y ) = 0;
  /// updates the enemies move after its validated
  virtual void move() = 0;
};
