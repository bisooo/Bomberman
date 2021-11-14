#pragma once
#include "Bomb.h"


/// A regular bomb that detonates after a countdown
class BombA : public Bomb
{
private:
  /// charecter of the bomb
  char charecter = '!';
  /// x coordinate of the bomb
  int xpos;
  /// y coordinate of the bomb
  int ypos;
  /// countdown of bomb detonation
  int countdown = 3;
  /// power range of the bomb
  int power = 2;
  /// game time of the bomb drop
  time_t droptime;
  /// status of the bomb detonation
  bool lit = false;
  /// status of the bomb remote use
  bool use = false;

public:
  BombA();
  // virtual ~BombA();
  /// "getter" for the bomb's charecter
  virtual char getcharecter() const override;
  /// "getter" for the bomb's x coordinate
  virtual int getxpos() const override;
  /// "getter" for the bomb's y coordinate
  virtual int getypos() const override;
  /// "getter" for the bomb's countdown
  virtual int getcountdown() const override;
  /// "getter" for the bomb's power
  virtual int getpower() const override;
  /// "getter" for the bomb's drop time
  virtual time_t getdroptime() const override;
  /// "getter" for the bomb's status of detonation
  virtual bool detonated() const override;
  /// "getter" for the bomb's status of remote use
  virtual bool used() const override;

  /// "setter" for the bomb's x coordinate
  virtual void setxpos(int x);
  /// "setter" for the bomb's y coordinate
  virtual void setypos(int y);
  /// "setter" for the bomb's drop time
  virtual void setstart(time_t time);
  /// "setter" for the bomb's range power
  virtual void setpower(int p);
  /// "setter" for the bomb's status of detonation
  virtual void detonate();
  /// "setter" for the bomb's status of remote use
  virtual void bombused();
};
