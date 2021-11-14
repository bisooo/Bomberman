#include "Man.h"

Man::Man(){}

void Man::setcharecter(char karekter)
{ charecter = karekter; }

void Man::setlives(int lvs)
{ lives = lvs; }

void Man::setxpos(int startx)
{ xpos = startx; }

void Man::setypos(int starty)
{ ypos = starty; }

void Man::setbombmax(int no)
{ bombmax = no; }

void Man::setremotemax(int no)
{ remotemax = no; }

void Man::setbombsused(int no)
{ bombsused = no; }

void Man::setremotesused(int no)
{ remotesused = no; }

void Man::setbombpower(int power)
{ bombpower = power; }

void Man::setremotepower(int power)
{ remotepower = power; }

void Man::setdrop(int status)
{ dropped = status; }

char Man::getcharecter()
{ return charecter; }

int Man::getxpos()
{ return xpos; }

int Man::getypos()
{ return ypos; }

int Man::getlives()
{ return lives; }

int Man::getspeed()
{ return speed; }

int Man::getbombsmax()
{ return bombmax; }

int Man::getremotesmax()
{ return remotemax; }

int Man::getbombsused()
{ return bombsused; }

int Man::getremotesused()
{ return remotesused; }

int Man::getbombpower()
{ return bombpower; }

int Man::getremotepower()
{ return remotepower; }

int Man::getdrop()
{ return dropped; }

bool Man::validate_move( char object )
{
  if( object == 'W' || object == 'B' )
  { return false; }
  return true;
}

void Man::move( char direction )
{
  switch( direction )
  {
    case 'U':
    {
      ypos--;
      break;
    }
    case 'D':
    {
      ypos++;
      break;
    }
    case 'R':
    {
      xpos++;
      break;
    }
    case 'L':
    {
      xpos--;
      break;
    }
    default:
      break;
  }
}

void Man::AImove( int x, int y, int uf, int df, int rf, int lf )
{
  int absxdiff = abs( xpos - x );
  int absydiff = abs( ypos - y );
  int xdiff = xpos - x;
  int ydiff = ypos - y;
  if( absxdiff > (absydiff * 5) )
  {
    // horizontal movement - RIGHT / LEFT while avoiding obstacles
    if( xdiff < 0 && !rf )
    {
      move('R');
      return;
    }
    if( xdiff < 0 && rf && !uf )
    {
      move('U');
      return;
    }
    if( xdiff < 0 && rf && !df )
    {
      move('D');
      return;
    }
    if( xdiff > 0 && !lf )
    {
      move('L');
      return;
    }
    if( xdiff > 0 && lf && !uf )
    {
      move('U');
      return;
    }
    if( xdiff > 0 && lf && !df )
    {
      move('D');
      return;
    }
  }
  else
  {
    // vertical movement - UP / DOWN while avoiding obstacles
    if( ydiff < 0 && !df )
    {
      move('D');
      return;
    }
    if( ydiff < 0 && df && !rf )
    {
      move('R');
      return;
    }
    if( ydiff < 0 && df && !lf )
    {
      move('L');
      return;
    }
    if( ydiff > 0 && !uf )
    {
      move('U');
      return;
    }
    if( ydiff > 0 && uf && !rf )
    {
      move('R');
      return;
    }
    if( ydiff > 0 && uf && !lf )
    {
      move('L');
      return;
    }
  }
}
