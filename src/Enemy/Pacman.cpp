#include "Pacman.h"


Pacman::Pacman(){}

// Pacman::~Pacman(){}

char Pacman::getcharecter() const
{ return charecter; }

void Pacman::setxpos( int x )
{ xpos = x; }

void Pacman::setypos( int y )
{ ypos = y; }

void Pacman::setdirection( char dir )
{ direction = dir; }

void Pacman::setlife( bool state )
{ living = state; }

void Pacman::setdisplay( bool state )
{ display = state; }

void Pacman::seteat( bool state )
{ eat = state; }

void Pacman::setblock( bool state )
{ block = state; }

void Pacman::setdunknow(bool state)
{ dunknow = state; }

void Pacman::setrandomdir()
{
  srand((unsigned) time(0));
  int random = rand() % 2;
  if( random )
  { direction = 'R'; }
  else
  { direction = 'L'; }
}

int Pacman::getxpos() const
{ return xpos; }

int Pacman::getypos() const
{ return ypos; }

char Pacman::getdirection() const
{ return direction; }

int Pacman::getspeed() const
{ return speed; }

bool Pacman::alive() const
{ return living; }

bool Pacman::displayed() const
{ return display; }

bool Pacman::eaten() const
{ return eat; }

int Pacman::money() const
{ return mola; }

bool Pacman::blocked() const
{ return block; }

bool Pacman::yadunknow() const
{ return dunknow; }

void Pacman::resetpos()
{
  xpos = startx;
  ypos = starty;
}

void Pacman::reversedir()
{
  if( direction == 'R')
  { direction = 'L'; }
  else
  { direction = 'R'; }
}

bool Pacman::validate_move( char object, int x, int y )
{
  if( x < 0 || x >= 103 )
  {
    reversedir();
    setblock(true);
    return false;
  }
  if( object == '.' )
  {
    srand((unsigned) time(0));
    int random = rand() % 10;
    int chance;
    // 10% chance
    if( direction == 'R' )
    { chance = 0; }
    else
    { chance = 9; }
    if( random == chance )
    {
      reversedir();
      setblock(true);
      return false;
    }
  }
  if( object == 'W' || object == 'B' )
  {
    reversedir();
    setblock(true);
    return false;
  }
  return true;
}

void Pacman::move()
{
  if( blocked() )
  {
    setblock(false);
    return;
  }
  if( direction == 'R' )
  { xpos++; }
  else
  { xpos--; }
}
