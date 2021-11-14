#include "Game.h"


Game::Game(){}

bool Game::updatetime( time_t start )
{
  int diff = difftime(time(NULL), start);
  timelimit -= diff;
  if( timelimit <= 0 )
  {
    timelimit = 0;
    return false;
  }
  return true;
}

void Game::constructman( char karekter, int lvs, int x, int y )
{
  bomberman.setcharecter(karekter);
  bomberman.setlives(lvs);
  bomberman.setxpos(x);
  bomberman.setypos(y);
}

void Game::constructmap( int lvl, string filename )
{
  map.setlevel(lvl);
  map.setfile(filename);
}

bool Game::readmap()
{
  bool status = map.readlevel();
  if( status )
  { map.loadobjects(); }
  enemiesleft = map.getenemiesleft();
  enemies = map.getenemies();
  boxes = map.getboxes();
  mandem = map.getmandem();
  return status;
}

void Game::player_move( Man & bomberman, int x, int y, char direction )
{
  switch( direction )
  {
    // UP
    case 'U':
    {
      for( auto & bomb : bombs )
      {
        if( !bomb->detonated() )
        {
          if( bomb->getxpos() == x && bomb->getypos() == y-1 )
          { return; }
        }
      }
      if( !bomberman.validate_move( map.getfilexy(x-1, y-2) ) || y-2 < 0 )
      { return; }
      else
      { bomberman.move('U'); }
      break;
    }
    // DOWN
    case 'D':
    {
      for( auto & bomb : bombs )
      {
        if( !bomb->detonated() )
        {
          if( bomb->getxpos() == x && bomb->getypos() == y+1 )
          { return; }
        }
      }
      if( !bomberman.validate_move( map.getfilexy(x-1, y) ) || y >= 19 )
      { return; }
      else
      { bomberman.move('D'); }
      break;
    }
    // RIGHT
    case 'R':
    {
      for( auto & bomb : bombs )
      {
        if( !bomb->detonated() )
        {
          if( bomb->getxpos() == x+1 && bomb->getypos() == y )
          { return; }
        }
      }
      if( !bomberman.validate_move( map.getfilexy(x, y-1) ) || x >= 103 )
      { return; }
      else
      { bomberman.move('R'); }
      break;
    }
    // LEFT
    case 'L':
    {
      for( auto & bomb : bombs )
      {
        if( !bomb->detonated() )
        {
          if( bomb->getxpos() == x-1 && bomb->getypos() == y )
          { return; }
        }
      }
      if( !bomberman.validate_move( map.getfilexy(x-2, y-1) ) || x-2 < 0 )
      { return; }
      else
      { bomberman.move('L'); }
      break;
    }
    default:
      break;
  }
  return;
}

void Game::enemy_move( Enemy * enemy )
{
  int x = enemy->getxpos();
  int y = enemy->getypos();
  char direction = enemy->getdirection();
  switch( direction )
  {
    // RIGHT
    case 'R':
    {
      for( auto & bomb : bombs )
      {
        if( !bomb->detonated() )
        {
          if( bomb->getxpos() == x+1 && bomb->getypos() == y )
          {
            enemy->reversedir();
            return;
          }
        }
      }
      if( !enemy->validate_move( map.getfilexy(x, y-1), x, y ) )
      { return; }
      else
      { enemy->move(); }
      break;
    }
    // LEFT
    case 'L':
    {
      for( auto & bomb : bombs )
      {
        if( !bomb->detonated() )
        {
          if( bomb->getxpos() == x-1 && bomb->getypos() == y )
          {
            enemy->reversedir();
            return;
          }
        }
      }
      if( !enemy->validate_move( map.getfilexy(x-2, y-1), x-2, y ) )
      { return; }
      else
      { enemy->move(); }
      break;
    }
    // UP
    case 'U':
    {
      for( auto & bomb : bombs )
      {
        if( !bomb->detonated() )
        {
          if( bomb->getxpos() == x && bomb->getypos() == y-1 )
          {
            enemy->reversedir();
            return;
          }
        }
      }
      if( !enemy->validate_move( map.getfilexy(x-1, y-2), x, y-2 ) )
      { return; }
      else
      { enemy->move(); }
      break;
    }
    // DOWN
    case 'D':
    {
      for( auto & bomb : bombs )
      {
        if( !bomb->detonated() )
        {
          if( bomb->getxpos() == x && bomb->getypos() == y+1 )
          {
            enemy->reversedir();
            return;
          }
        }
      }
      if( !enemy->validate_move( map.getfilexy(x-1, y), x, y ) )
      { return; }
      else
      { enemy->move(); }
      break;
    }
    default:
      break;
  }
  return;
}

void Game::checkboxes()
{
  for( auto box : boxes )
  {
    if( box->getupgrade() != ' ' && !box->blasted() )
    {
      if( map.getfilexy(box->getxpos()-1, box->getypos()-1) == '!' )
      { box->setblast(true); }
    }
  }
}

void Game::dropbomb( int x, int y, char type )
{
  switch( type )
  {
    // normal bomb
    case 'A':
    {
      BombA * bomb = new BombA;
      bomb->setxpos(x);
      bomb->setypos(y);
      bomb->setpower(bomberman.getbombpower());
      // game time when the bomb was dropped
      bomb->setstart(time(NULL));
      bombs.push_back(bomb);
      break;
    }
    // remote bomb
    case 'B':
    {
      BombB * bomb = new BombB;
      bomb->setxpos(x);
      bomb->setypos(y);
      bomb->setpower(bomberman.getremotepower());
      bombs.push_back(bomb);
      break;
    }
    default:
      break;
  }
}

void Game::checkdetonates()
{
  for( auto & bomb : bombs )
  {
    if( !bomb->detonated() )
    {
      // BOMB A
      if( bomb->getcharecter() == '!' && bomb->getcountdown() == difftime(time(NULL), bomb->getdroptime()) )
      {
        bomb->detonate();
        int bombsused = bomberman.getbombsused();
        bombsused--;
        bomberman.setbombsused(bombsused);
      }
    }
  }
}

void Game::remotedetonate()
{
  for( auto & bomb : bombs )
  {
    if( !bomb->detonated() )
    {
      // BOMB B
      if( bomb->getcharecter() == '?' )
      {
        bomb->detonate();
        int remotesused = bomberman.getremotesused();
        remotesused--;
        bomberman.setremotesused(remotesused);
      }
    }
  }
}

bool Game::playerblasted( int x, int y )
{
  int upflag, downflag, rightflag, leftflag;
  for( auto & bomb : bombs )
  {
    upflag = 0;
    downflag = 0;
    rightflag = 0;
    leftflag = 0;
    int bombx = bomb->getxpos();
    int bomby = bomb->getypos();
    // player is standing at a detonated bomb
    if( bomb->detonated() && !bomb->used() && bomb->getxpos() == x && bomb->getypos() == y )
    { return true; }
    // loops through the "range" power of a bomb
    for( int range = 0 ; range <= bomb->getpower() ; range++ )
    {
      if( bomb->detonated() && !bomb->used() )
      {
        // boxes and walls block a bombs effect
        if( map.getfilexy(bombx-1, bomby-range-1) == 'B' || map.getfilexy(bombx-1, bomby-range-1) == 'W' )
        { upflag = 1; }
        if( map.getfilexy(bombx-1, bomby+range-1) == 'B' ||  map.getfilexy(bombx-1, bomby+range-1) == 'W' )
        { downflag = 1; }
        if( map.getfilexy(bombx+range-1, bomby-1) == 'B' || map.getfilexy(bombx+range-1, bomby-1) == 'W' )
        { rightflag = 1; }
        if( map.getfilexy(bombx-range-1, bomby-1) == 'B' || map.getfilexy(bombx-range-1, bomby-1) == 'W' )
        { leftflag = 1; }

        // UP "range"
        if( !upflag && bombx == x && bomby-range == y )
        { return true; }
        // DOWN "range"
        if( !downflag && bombx == x && bomby+range == y )
        { return true; }
        // RIGHT "range"
        if( !rightflag && bombx+range == x && bomby == y )
        { return true; }
        // LEFT "range"
        if( !leftflag && bombx-range == x && bomby == y )
        { return true; }
      }
    }
  }
  return false;
}

void Game::enemiesblasted()
{
  int upflag, downflag, rightflag, leftflag;
  for( auto & enemy : enemies )
  {
    upflag = 0;
    downflag = 0;
    rightflag = 0;
    leftflag = 0;
    for( auto & bomb : bombs )
    {
      int power = bomb->getpower();
      int x = bomb->getxpos();
      int y = bomb->getypos();
      if( bomb->detonated() && !bomb->used() )
      {
        for( int range = 0 ; range <= power ; range++ )
        {
          // walls and boxes protect the enemy
          if( map.getfilexy(x-1, y-range-1) == 'B' || map.getfilexy(x-1, y-range-1) == 'W' )
          { upflag = 1; }
          if( map.getfilexy(x-1, y+range-1) == 'B' || map.getfilexy(x-1, y+range-1) == 'W')
          { downflag = 1; }
          if( map.getfilexy(x+range-1, y-1) == 'B' || map.getfilexy(x+range-1, y-1) == 'W')
          { rightflag = 1; }
          if( map.getfilexy(x-range-1, y-1) == 'B' || map.getfilexy(x-range-1, y-1) == 'W' )
          { leftflag = 1; }

          // UP "range"
          if( !upflag && enemy->alive() && enemy->getxpos() == x && enemy->getypos() == y-range  )
          { enemyblasted(enemy);  }
          // DOWN "range"
          if( !downflag && enemy->alive() && enemy->getxpos() == x && enemy->getypos() == y+range )
          { enemyblasted(enemy); }
          // RIGHT "range"
          if( !rightflag && enemy->alive() && enemy->getxpos() == x+range && enemy->getypos() == y )
          { enemyblasted(enemy); }
          // LEFT "range"
          if( !leftflag && enemy->alive() && enemy->getxpos() == x-range && enemy->getypos() == y )
          { enemyblasted(enemy); }
        }
      }
    }
  }
}

void Game::enemyblasted( Enemy * enemy )
{
  enemy->setlife(false);
  enemiesleft--;
}

void Game::mandemblasted()
{
  int upflag, downflag, rightflag, leftflag;
  for( auto & man : mandem )
  {
    upflag = 0;
    downflag = 0;
    rightflag = 0;
    leftflag = 0;
    for( auto & bomb : bombs )
    {
      int power = bomb->getpower();
      int x = bomb->getxpos();
      int y = bomb->getypos();
      if( bomb->detonated() && !bomb->used() )
      {
        for( int range = 0 ; range <= power ; range++ )
        {
          // walls and boxes protect the enemy
          if( map.getfilexy(x-1, y-range-1) == 'B' || map.getfilexy(x-1, y-range-1) == 'W' )
          { upflag = 1; }
          if( map.getfilexy(x-1, y+range-1) == 'B' || map.getfilexy(x-1, y+range-1) == 'W')
          { downflag = 1; }
          if( map.getfilexy(x+range-1, y-1) == 'B' || map.getfilexy(x+range-1, y-1) == 'W')
          { rightflag = 1; }
          if( map.getfilexy(x-range-1, y-1) == 'B' || map.getfilexy(x-range-1, y-1) == 'W' )
          { leftflag = 1; }

          // UP "range"
          if( !upflag && man.getlives() > 0 && man.getxpos() == x && man.getypos() == y-range  )
          { man.setlives(0); }
          // DOWN "range"
          if( !downflag && man.getlives() > 0 && man.getxpos() == x && man.getypos() == y+range )
          { man.setlives(0); }
          // RIGHT "range"
          if( !rightflag && man.getlives() > 0 && man.getxpos() == x+range && man.getypos() == y )
          { man.setlives(0); }
          // LEFT "range"
          if( !leftflag && man.getlives() > 0 && man.getxpos() == x-range && man.getypos() == y )
          { man.setlives(0); }
        }
      }
    }
  }
}

void Game::AImove( Man & man, int flag )
{
  int upflag = 0;
  int downflag = 0;
  int rightflag = 0;
  int leftflag = 0;
  int x = man.getxpos();
  int y = man.getypos();
  for( auto & bomb : bombs )
  {
    if( !bomb->detonated() )
    {
      if( bomb->getxpos() == x && bomb->getypos() == y )
      { flag = 1; }
      if( bomb->getxpos() == x && bomb->getypos() == y-1 )
      { upflag = 1; }
      if( bomb->getxpos() == x && bomb->getypos() == y+1 )
      { downflag = 1; }
      if( bomb->getxpos() == x+1 && bomb->getypos() == y )
      { rightflag = 1; }
      if( bomb->getxpos() == x-1 && bomb->getypos() == y )
      { leftflag = 1; }
    }
  }
  if( !man.validate_move( map.getfilexy(x-1, y-2) ) || y-2 < 0 )
  { upflag = 1; }
  if( !man.validate_move( map.getfilexy(x-1, y) ) || y >= 19 )
  { downflag = 1; }
  if( !man.validate_move( map.getfilexy(x, y-1) ) || x >= 103 )
  { rightflag = 1; }
  if( !man.validate_move( map.getfilexy(x-2, y-1) ) || x-2 < 0 )
  { leftflag = 1; }

  int random = rand() % 10 + 1;
  if( random >= 5 )
  { return; }
  // just dropped a bomb
  if( man.getdrop() || man.getdrop() == 2 )
  {
    man.setdrop(2);
    if( !rightflag && x < 51 )
    {
      player_move(man, x, y, 'R');
      return;
    }
    else if ( rightflag && y <= 10 && !downflag )
    {
      player_move(man, x, y, 'D');
      return;
    }
    else if ( !upflag )
    {
      player_move(man, x, y, 'U');
      return;
    }
    if( !leftflag && x > 51 )
    {
      player_move(man, x, y, 'L');
      return;
    }
    else if ( leftflag && y <= 10 && !downflag )
    {
      player_move(man, x, y, 'D');
      return;
    }
    else if ( !upflag )
    {
      player_move(man, x, y, 'U');
      return;
    }
  }
  // constant horizontal / vertical movement
  if( flag || man.getdrop() == 2 )
  {
    man.setdrop(0);
    if( y % 3 != 0 && x > 51 )
    {
      player_move(man, x, y, 'R');
      return;
    }
    else if( y % 3 != 0 && x > 51 )
    {
      if( y > 10 )
      {
        player_move(man, x, y, 'U');
        return;
      }
      else
      {
        player_move(man, x, y, 'D');
        return;
      }
    }

    if( y % 3 != 0 && x < 51 )
    {
      player_move(man, x, y, 'L');
      return;
    }
    else if( y % 3 != 0 && x < 51 )
    {
      if( y >= 10 )
      {
        player_move(man, x, y, 'U');
        return;
      }
      else
      {
        player_move(man, x, y, 'D');
        return;
      }
    }
    if( y % 3 == 0 && y < 10 )
    {
      player_move(man, x, y, 'D');
      return;
    }
    else if( y % 3 == 0 && y > 10 )
    {
      player_move(man, x, y, 'U');
      return;
    }
  }
  // avoid obstacles & move towards the bomberman
  else
  { man.AImove(bomberman.getxpos(), bomberman.getypos(), upflag, downflag, rightflag, leftflag); }
}

void Game::AIdropbomb( Man & man )
{
  int random = rand() % 10 + 1;
  if( random >= 9 )
  { return; }
  int x = man.getxpos();
  int y = man.getypos();
  BombA * bomb = new BombA;
  bomb->setxpos(x);
  bomb->setypos(y);
  bomb->setpower(bomberman.getbombpower());
  bomb->setstart(time(NULL));
  bomb->setvsmode(1);
  bombs.push_back(bomb);
}
