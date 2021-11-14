#include "Map.h"


Map::Map(){}

void Map::setlevel(int lvl)
{ level = lvl; }

void Map::setfile(string file)
{ filename = file; }

int Map::getenemiesleft()
{ return enemiesleft; }

vector<Enemy*> Map::getenemies()
{ return enemies; }

vector<Box*> Map::getboxes()
{ return boxes; }

vector<Man> Map::getmandem()
{ return mandem; }

bool Map::readlevel()
{
  ifstream input(this->filename);
  if( !input.is_open() )
  { return false; }
  string in;
  while( getline(input,in) )
  {
    vector< char > row;
    for( char & c : in )
    {
      row.push_back(c);
    }
    file.push_back(row);
  }
  return true;
}

void Map::setfilexy( const size_t & x, const size_t & y, char charecter )
{
  if( x < 103 && y < 19 )
  {
    file.at(y).at(x) = charecter;
  }
}

void Map::resetenemiesleft()
{ enemiesleft = 0; }

void Map::loadobjects()
{
  map.resize(20, vector<Object*> (103));
  for( int y = 0 ; y < 20 ; y++ )
  {
    for( int x = 0 ; x < 103 ; x++ )
    {
      if( getfilexy(x,y) == 'W' )
      {
        Wall * w = new Wall;
        map.at(y).at(x) = w;
      }
      else if( getfilexy(x,y) == '.' )
      {
        Space * s = new Space;
        map.at(y).at(x) = s;
      }
      else if( getfilexy(x,y) == 'B' )
      {
        Box * b = new Box;
        b->setxpos(x+1);
        b->setypos(y+1);
        map.at(y).at(x) = b;
        boxes.push_back(b);
      }
      else if( getfilexy(x,y) == '<' )
      {
        enemiesleft++;
        Pacman * p = new Pacman;
        p->startx = x+1;
        p->starty = y+1;
        p->setxpos(x+1);
        p->setypos(y+1);
        p->setrandomdir();
        map.at(y).at(x) = p;
        enemies.push_back(p);
      }
      else if( getfilexy(x,y) == '$' )
      {
        enemiesleft++;
        // initialising enemy object pointer
        Dollar * d = new Dollar;
        // setting coordinates of enemy locally
        d->startx = x+1;
        d->starty = y+1;
        d->setxpos(x+1);
        d->setypos(y+1);
        d->setrandomdir();
        // adding enemy pointer to the 2D vector of map "objects"
        map.at(y).at(x) = d;
        // adding object pointer to the vector of "enemies" in the map
        enemies.push_back(d);
      }
      else if ( getfilexy(x,y) == 'X' )
      {
        // Bombermen in "VS" mode;
        Man bomberman;
        bomberman.setxpos(x+1);
        bomberman.setypos(y+1);
        bomberman.setcharecter('<');
        bomberman.setlives(1);
        mandem.push_back(bomberman);
      }
    }
  }
}

char Map::getfilexy(const size_t & x, const size_t & y)
{
  if( x < 103 && y < 19 )
  {
    return file.at(y).at(x);
  }
  else
  { return '?'; }
}

Object * Map::getmapxy(const size_t & x, const size_t & y)
{
  if( x < 103 && y < 19 )
  {
    return map.at(y).at(x);
  }
  else
  {
    Space * err = new Space;
    return err;
  }
}

void Map::clearmap()
{
  file.clear();
  map.clear();
}
