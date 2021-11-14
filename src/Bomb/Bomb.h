#pragma once
#include "../Object/Object.h"


/// Abstact bomb "Object"
class Bomb : public Object
{
private:
  /// charecter of the bomb
  char charecter;
  /// x coordinate of the bomb
  int xpos;
  /// y coordinate of the bomb
  int ypos;
  /// countdown of bomb detonation
  int countdown;
  /// power range of the bomb
  int power;
  /// game time of the bomb drop
  time_t droptime;
  /// status of the bomb detonation
  bool lit;
  /// status of the bomb remote use
  bool use;
  /// flag for bombs dropped by bombermen enemies in "vs" mode
  int vs = 0;

public:
  Bomb();
  virtual ~Bomb() noexcept(true);
  /// "getter" for the bomb's charecter
  virtual char getcharecter() const = 0;
  /// "getter" for the bomb's x coordinate
  virtual int getxpos() const = 0;
  /// "getter" for the bomb's y coordinate
  virtual int getypos() const = 0;
  /// "getter" for the bomb's countdown
  virtual int getcountdown() const = 0;
  /// "getter" for the bomb's power
  virtual int getpower() const = 0;
  /// "getter" for the bomb's drop time
  virtual time_t getdroptime() const = 0;
  /// "getter" for the bomb's status of detonation
  virtual bool detonated() const = 0;
  /// "getter" for the bomb's status of remote use
  virtual bool used() const = 0;
  /// "getter" for the "vs" mode flag
  int vsmode();

  /// "setter" for the bomb's x coordinate
  virtual void setxpos(int x) = 0;
  /// "setter" for the bomb's y coordinate
  virtual void setypos(int y) = 0;
  /// "setter" for the bomb's drop time
  virtual void setstart(time_t time) = 0;
  /// "setter" for the bomb's range power
  virtual void setpower( int p ) = 0;
  /// "setter" for the bomb's status of detonation
  virtual void detonate() = 0;
  /// "setter" for the bomb's status of remote use
  virtual void bombused() = 0;
  /// "setter" for the "vs" mode flag
  void setvsmode(int status);
};
