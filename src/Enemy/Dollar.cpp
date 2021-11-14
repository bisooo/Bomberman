#include "Dollar.h"

Dollar::Dollar(){}

// Dollar::~Dollar(){}

char Dollar::getcharecter() const
{ return charecter; }

void Dollar::setxpos( int x )
{ xpos = x; }

void Dollar::setypos( int y )
{ ypos = y; }

void Dollar::setdirection( char dir )
{ direction = dir; }

void Dollar::setlife( bool state )
{ living = state; }

void Dollar::setdisplay( bool state )
{ display = state; }

void Dollar::seteat( bool state )
{ eat = state; }

void Dollar::setblock( bool state )
{ block = state; }

void Dollar::setdunknow(bool state)
{ dunknow = state; }

void Dollar::setrandomdir()
{
  srand((unsigned) time(0));
  int random = (rand() % 2) + 1;
  if( random )
  { direction = 'U'; }
  else
  { direction = 'D'; }
}

int Dollar::getxpos() const
{ return xpos; }

int Dollar::getypos() const
{ return ypos; }

char Dollar::getdirection() const
{ return direction; }

int Dollar::getspeed() const
{ return speed; }

bool Dollar::alive() const
{ return living; }

bool Dollar::displayed() const
{ return display; }

bool Dollar::eaten() const
{ return eat; }

int Dollar::money() const
{ return mola; }

bool Dollar::blocked() const
{ return block; }

bool Dollar::yadunknow() const
{ return dunknow; }


void Dollar::resetpos()
{
  xpos = startx;
  ypos = starty;
}

void Dollar::reversedir()
{
  if( direction == 'U' )
  { direction = 'D'; }
  else
  { direction = 'U'; }
}

bool Dollar::validate_move( char object, int x, int y )
{
  if( y < 0 || y >= 19 )
  {
    reversedir();
    setblock(true);
    return false;
  }
  if( object == 'W' || object == 'B' )
  {
    reversedir();
    setblock(true);
    return false;
  }
  return true;
}

void Dollar::move()
{
  if( blocked() )
  {
    setblock(false);
    return;
  }
  if( direction == 'D' )
  { ypos++; }
  else
  { ypos--; }
}
