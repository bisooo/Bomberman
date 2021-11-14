#include "Play.h"


Play::Play(){}

int Play::getscore()
{ return score; }
int Play::getlives()
{ return bomberman.getlives(); }
int Play::getbombpower()
{ return bomberman.getbombpower(); }
int Play::getbombsmax()
{ return bomberman.getbombsmax(); }
int Play::getremotepower()
{ return bomberman.getremotepower(); }
int Play::getremotesmax()
{ return bomberman.getremotesmax(); }

void Play::setscore( int scr )
{ score = scr; }
void Play::setbombpower( int bpow )
{ bomberman.setbombpower(bpow); }
void Play::setbombsmax( int maxb )
{ bomberman.setbombmax(maxb); }
void Play::setremotepower( int rpow )
{ bomberman.setremotepower(rpow); }
void Play::setremotesmax( int maxr )
{ bomberman.setremotemax(maxr); }

bool Play::countdown()
{
  // update the time limit depending on the time diffrence
  bool status = updatetime(start);
  if( !status )
  {
    werase(messagewindow);
    wrefresh(messagewindow);
    wattron(mapwindow,A_BOLD|COLOR_PAIR(1));
    int center = (105 - strlen(" !!! TIME'S UP !!! "))/2;
    mvwprintw(mapwindow, 0, center, " !!! TIME'S UP !!! ");
    wattroff(mapwindow,A_BOLD|COLOR_PAIR(1));
    wrefresh(mapwindow);
    score -= lvlpoints;
    return status;
  }
  int startx = 3;
  int starty = 1;
  // 100 seconds remaining
  if( timelimit <= 100000 )
  {
    for( auto & exit : boxes )
    {
      if( exit->getupgrade() == 'E' && !exit->yadunknow() )
      {
        werase(messagewindow);
        int center = (105 - strlen("DOOR @ XX , XX"))/2;
        wattron(messagewindow, A_BOLD|COLOR_PAIR(15));
        mvwprintw(messagewindow, 1, center, "DOOR @ %d , %d", exit->getxpos(), exit->getypos());
        wattroff(messagewindow, A_BOLD|COLOR_PAIR(15));
        wrefresh(messagewindow);
        break;
      }
    }
  }
  // 30 seconds remaining
  if( timelimit <= 30000 )
  {
    wattron(infowindow,A_BOLD|COLOR_PAIR(1));
    mvwprintw(infowindow, starty, startx, "TIME LEFT = %.2f ", (double) timelimit/1000);
    wattroff(infowindow,A_BOLD|COLOR_PAIR(1));
  }
  else
  {
    wattron(infowindow,A_BOLD);
    mvwprintw(infowindow, starty, startx, "TIME LEFT = %.2f ", (double) timelimit/1000);
    wattroff(infowindow,A_BOLD);
  }
  wrefresh(infowindow);
  return status;
}

void Play::loadname()
{
  int startx = 1;
  int starty = 6;
  int width = 102;
  int height = 9;
  namewindow = newwin(height, width, starty, startx);
  curs_set(0);
  mvwprintw(stdscr, 1, 1, "LOADING NEXT LEVEL ...");
  wrefresh(stdscr);
  wattron(namewindow,A_BOLD|COLOR_PAIR(2));
  mvwprintw(namewindow, 1, 6,
  "\" 8888888.                          888                       8888     8888\n");
  mvwprintw(namewindow, 2, 6,
  "   888   888                        888                       88888   88888\n");
  mvwprintw(namewindow, 3, 6,
  "  888  .888                         888                       888888.888888\n");
  mvwprintw(namewindow, 4, 6,
  "  88888888.   .8888.  888888.8888.  888888.   .8888.  8888888 8888888888888  88888.  888888.\n");
  mvwprintw(namewindow, 5, 6,
  "  888   8888 888  888 888  888  888 888  888 888 888  888 888 888 88888 888      888 888  888\n");
  mvwprintw(namewindow, 6, 6,
  "  888    888 888  888 888  888  888 888  888 88888888 888     888  888  888 .8888888 888  888\n");
  mvwprintw(namewindow, 7, 6,
  "  888   8888 888..888 888  888  888 888  888 888.     888     888       888 888  888 888  888\n");
  mvwprintw(namewindow, 8, 6,
  "  88888888     8888   888  888  888 888888    88888   888     888       888  8888888 888  888\n");
  mvwprintw(namewindow, 1, 97, "  \" ®");
  wattroff(namewindow,A_BOLD|COLOR_PAIR(2));
  wrefresh(namewindow);
}

void Play::loadmessage()
{
  // create a window for the message updates
  int startx = 3;
  int starty = 25;
  int width = 105;
  int height = 3;
  messagewindow = newwin(height, width, starty, startx);
  curs_set(0);
}

void Play::loadinfo()
{
  // create a window to display the game's stats
  int startx = 3;
  int starty = 1;
  int width = 105;
  int height = 3;
  infowindow = newwin(height, width, starty, startx);
  box(infowindow, 0 , 0);
  curs_set(0);
  double timeleft = timelimit / 1000;
  wattron(infowindow,A_BOLD);
  mvwprintw(infowindow, starty, startx, "TIME LEFT = %ld", (int) timeleft);
  wattroff(infowindow,A_BOLD);
  wattron(infowindow,A_BOLD|COLOR_PAIR(1));
  mvwprintw(infowindow, starty, startx+21, "ENEMIES LEFT = %d", enemiesleft);
  wattroff(infowindow,A_BOLD|COLOR_PAIR(1));
  if( !vsmode )
  {
    wattron(infowindow,A_BOLD);
    wattron(infowindow,A_BOLD|COLOR_PAIR(2));
    mvwprintw(infowindow, starty, startx+40, "BOMB^%d = %d / %d", bomberman.getbombpower(), bomberman.getbombsused(), bomberman.getbombsmax());
    wattroff(infowindow,A_BOLD);
    wattron(infowindow,A_BOLD);
    mvwprintw(infowindow, starty, startx+57, "REMOTE^%d = %d / %d", bomberman.getremotepower(), bomberman.getremotesused(), bomberman.getremotesmax());
    wattroff(infowindow,A_BOLD);
    wattroff(infowindow,A_BOLD|COLOR_PAIR(2));
  }
  wattron(infowindow,A_ITALIC|COLOR_PAIR(2));
  mvwprintw(infowindow, starty, startx+76, "LIVES = %d", bomberman.getlives());
  wattroff(infowindow,A_ITALIC|COLOR_PAIR(2));
  wattroff(infowindow,A_BOLD);
  wattron(infowindow,A_BOLD|COLOR_PAIR(4));
  mvwprintw(infowindow, starty, startx+87, "SCORE = %d", score);
  wattroff(infowindow,A_BOLD|COLOR_PAIR(4));
}

void Play::loadmap()
{
  // create a window for the level's map
  int startx = 3;
  int starty = 4;
  int width = 105;
  int height = 21;
  mapwindow = newwin(height, width, starty, startx);
  box(mapwindow, 0 ,'=');
  keypad(mapwindow, TRUE);
  curs_set(0);

  // render the map charecters inside the window
  for( int y = 0 ; y < height-1 ; y++ )
  {
    for( int x = 0 ; x < width-1 ; x++ )
    {
      if( map.getfilexy(x,y) == '.' )
      {
        wattron(mapwindow,A_ITALIC|COLOR_PAIR(16));
        mvwaddch(mapwindow, y+1, x+1, map.getmapxy(x,y)->getcharecter());
        wattroff(mapwindow,A_ITALIC|COLOR_PAIR(16));
      }
      else if( map.getfilexy(x,y) == 'W' )
      {
        wattron(mapwindow,COLOR_PAIR(5));
        mvwaddch(mapwindow, y+1, x+1, map.getmapxy(x,y)->getcharecter());
        wattroff(mapwindow,COLOR_PAIR(5));
      }
      else if( map.getfilexy(x,y) == 'P' )
      {
        wattron(mapwindow,COLOR_PAIR(8));
        mvwaddch(mapwindow, y+1, x+1, bomberman.getcharecter());
        wattroff(mapwindow,COLOR_PAIR(8));
      }
      else if( map.getfilexy(x,y) == 'B' )
      {
        wattron(mapwindow,COLOR_PAIR(3));
        mvwaddch(mapwindow, y+1, x+1, map.getmapxy(x,y)->getcharecter());
        wattroff(mapwindow,COLOR_PAIR(3));
      }
      else if( map.getfilexy(x,y) == '<' )
      {
        wattron(mapwindow,COLOR_PAIR(17));
        mvwaddch(mapwindow, y+1, x+1, map.getmapxy(x,y)->getcharecter());
        wattroff(mapwindow,COLOR_PAIR(17));
      }
      else if( map.getfilexy(x,y) == '$' )
      {
        wattron(mapwindow,COLOR_PAIR(18));
        mvwaddch(mapwindow, y+1, x+1, map.getmapxy(x,y)->getcharecter());
        wattroff(mapwindow,COLOR_PAIR(18));
      }
      else if( map.getfilexy(x,y) == 'X' )
      {
        wattron(mapwindow,COLOR_PAIR(20));
        mvwaddch(mapwindow, y+1, x+1, '<');
        wattroff(mapwindow,COLOR_PAIR(20));
      }
    }
  }
}

bool Play::loadobjects( int level, string filename, int lives )
{
  // construct a Bomberman object
  constructman('@', lives, 1, 1);
  if( vsmode )
  { bomberman.setbombmax(5); }
  // construct a Map object
  constructmap(level, filename);
  bool status = readmap();
  return status;
}

bool Play::loadwindows( int level, string filename, int lives)
{
  if( level > 3 )
  { return false; }
  bool status = loadobjects(level, filename, lives);

  loadmessage();
  wrefresh(messagewindow);
  loadinfo();
  wrefresh(infowindow);
  loadmap();
  wrefresh(mapwindow);
  // get the border coordinates of the level's map
  getmaxyx(mapwindow, ymax, xmax);
  // hide upgrades and the exit door in the boxes
  fillboxes();
  displayplayer();

  // start time of the game
  start = time(NULL);
  return status;
}

void Play::fillboxes()
{
  // TESTIN' - adds an upgrade in the box @ 1,2 in level 1
  // for( auto box : boxes )
  // {
  //   if( box->getxpos() == 1 && box->getypos() == 2 )
  //   {
  //     box->setupgrade('E');
  //   }
  // }
  int number = boxes.size();
  int random;
  // add 4 exit doors
  for( int doors = 0 ; doors < 4 ; doors++ )
  {
    random = rand() % number;
    Box * exit = boxes.at(random);
    exit->setblast(false);
    exit->setdisplay(false);
    exit->setuse(false);
    exit->setdunknow(false);
    exit->setupgrade('E');
  }

  // random number of hidden upgrades up to 7
  int upgrades = rand() % 6 + 2;
  int center = (105 - strlen("THERE ARE X HIDDEN UPGRADES IN THE MAP ! EXPLORE THE MAP & BLAST BOXES TO FIND THEM"))/2;
  wattron(messagewindow, A_BOLD|COLOR_PAIR(2));
  mvwprintw(messagewindow, 1, center, "THERE ARE %d HIDDEN UPGRADES IN THE MAP ! EXPLORE THE MAP & BLAST BOXES TO FIND THEM", upgrades);
  wattroff(messagewindow, A_BOLD|COLOR_PAIR(2));
  wrefresh(messagewindow);
  for( int upgrade = 0 ; upgrade <= upgrades ; upgrade++ )
  {
    random = rand() % number;
    if( boxes.at(random)->getupgrade() == ' ' )
    {
      Box * hidden = boxes.at(random);
      hidden->setblast(false);
      hidden->setdisplay(false);
      hidden->setuse(false);
      hidden->setdunknow(false);
      switch( upgrade )
      {
        case 0:
        {
          // score++
          hidden->setupgrade('S');
          break;
        }
        case 1:
        {
          // time++
          hidden->setupgrade('T');
          break;
        }
        case 2:
        {
          // life++
          hidden->setupgrade('L');
          break;
        }
        case 3:
        {
          // bombmax++
          hidden->setupgrade('a');
          break;
        }
        case 4:
        {
          // remotemax++
          hidden->setupgrade('b');
          break;
        }
        case 5:
        {
          // bombpower++
          hidden->setupgrade('A');
          break;
        }
        case 6:
        {
          // remotepower++
          hidden->setupgrade('B');
          break;
        }
        case 7:
        {
          // exit door
          hidden->setupgrade('E');
          break;
        }
        default:
          break;
      }
    }
  }
}

bool Play::caught()
{
  for( auto & enemy : enemies )
  {
    if( enemy->alive() && enemy->getxpos() == bomberman.getxpos() && enemy->getypos() == bomberman.getypos() )
    { return true; }
    else if( !enemy->eaten() && !enemy->alive() && enemy->getxpos() == bomberman.getxpos() && enemy->getypos() == bomberman.getypos() )
    {
      srand((unsigned) time(0));
      int mola = (rand() % enemy->money() ) + (enemy->money()/2);
      score += mola;
      lvlpoints += mola;
      enemy->seteat(true);
      enemy->setdisplay(true);
      werase(messagewindow);
      int center = (105 - strlen("!!! COLLECTED XXX POINTS FROM THE ENEMY !!!"))/2;
      wattron(messagewindow, A_BOLD|COLOR_PAIR(4));
      mvwprintw(messagewindow, 1, center, "!!! COLLECTED %d POINTS FROM THE ENEMY !!!", mola);
      wattroff(messagewindow, A_BOLD|COLOR_PAIR(4));
      wrefresh(messagewindow);
    }
  }
  return false;
}

void Play::lostlife()
{
  int livesleft = bomberman.getlives();
  livesleft--;
  bomberman.setlives(livesleft);
  loadinfo();
}

bool Play::alive()
{
  if(bomberman.getlives() >= 0)
  { return true; }
  // GAME OVER
  else
  {
    werase(messagewindow);
    wrefresh(messagewindow);
    wattron(mapwindow,A_BOLD|COLOR_PAIR(9));
    mvwprintw(mapwindow, bomberman.getypos(), bomberman.getxpos(), "X");
    wattroff(mapwindow,A_BOLD|COLOR_PAIR(9));
    napms(1000);
    werase(mapwindow);
    wattron(mapwindow,A_BOLD|COLOR_PAIR(1));
    int center = (105 - strlen(" !!! GAME OVER !!! "))/2;
    mvwprintw(mapwindow, 9, center, " !!! GAME OVER !!! ");
    wattroff(mapwindow,A_BOLD|COLOR_PAIR(1));
    wrefresh(mapwindow);
    napms(3000);
    return false;
  }
}

void Play::restartlevel()
{
  werase(messagewindow);
  wrefresh(messagewindow);
  wattron(mapwindow,A_BOLD|COLOR_PAIR(9));
  mvwprintw(mapwindow, bomberman.getypos(), bomberman.getxpos(), "X");
  wattroff(mapwindow,A_BOLD|COLOR_PAIR(9));
  wrefresh(mapwindow);
  napms(1000);
  wclear(mapwindow);
  wattron(mapwindow,A_BOLD|COLOR_PAIR(4));
  int center = (105 - strlen(" !!! TRY AGAIN !!! "))/2;
  mvwprintw(mapwindow, 9, center, " !!! TRY AGAIN !!! ");
  wattroff(mapwindow,A_BOLD|COLOR_PAIR(4));
  wrefresh(mapwindow);
  napms(3000);
  werase(mapwindow);

  // clear the bombs dropped
  bombs.clear();
  // reset the number of enemies
  enemiesleft = map.getenemiesleft();
  // reset the bomberman to the starting position
  bomberman.setxpos(1);
  bomberman.setypos(1);
  // reset the number of bombs used
  bomberman.setbombsused(0);
  bomberman.setremotesused(0);
  // reset all the enemy's attributes and their starting positions
  for( auto & enemy : enemies )
  {
    if( !enemy->yadunknow() )
    {
      enemy->resetpos();
      enemy->setlife(true);
      enemy->setdisplay(false);
      enemy->seteat(false);
    }
  }
  // reset all the box's attributes
  for( auto & box : boxes )
  {
    if( !box->yadunknow() )
    {
      box->setblast(false);
      box->setdisplay(true);
      box->setuse(true);
      box->setdunknow(true);
    }
  }
  // reset all the blasted boxes
  for( int y = 0 ; y < 20 ; y++ )
  {
    for( int x = 0 ; x < 104 ; x++ )
    {
      if( map.getfilexy(x,y) == '!' )
      {
        map.setfilexy(x, y, 'B');
      }
    }
  }
  fillboxes();
  // reset the time countdown
  timelimit = 300000;
  // reset the level's score
  score -= lvlpoints;
  lvlpoints = 0;
  loadinfo();
  wrefresh(infowindow);
  loadmap();
  wrefresh(mapwindow);

  start = time(NULL);
  // clear the key buffer
  flushinp();
}

void Play::displayplayer()
{
  wattron(mapwindow, COLOR_PAIR(8));
  mvwaddch(mapwindow, bomberman.getypos(), bomberman.getxpos(), bomberman.getcharecter());
  wattroff(mapwindow, COLOR_PAIR(8));
  wrefresh(mapwindow);
  wattron(messagewindow, A_ITALIC|COLOR_PAIR(2));
  mvwprintw(messagewindow, 0, 1, "@  %d  ,  %d ", bomberman.getxpos(), bomberman.getypos());
  wattroff(messagewindow, A_ITALIC|COLOR_PAIR(2));
  wrefresh(messagewindow);
}

bool Play::userinput()
{
  noecho();
  nodelay(mapwindow,TRUE);
  // used to adjust the "FPS" of the player's movement
  if( enemiesleft > 0 )
  { usleep(bomberman.getspeed()); }

  int move = wgetch(mapwindow);
  int bombcheck = 1;
  int bombsdropped, remotesdropped;
  int xman = bomberman.getxpos();
  int yman = bomberman.getypos();
  switch( move )
  {
    // if the time out is reached and no key is pressed
    case ERR:
      break;
    // ESC key - exit the game
    case 27:
    {
      clearlevel();
      return false;
      break;
    }
    case KEY_UP:
    {
      // used to block buffered repeats of a certain move key
      if( move != ERR )
      { while( wgetch(mapwindow) == move ); }
      for( auto & bomb : bombs )
      {
        if( !bomb->detonated() && bomb->getxpos() == xman && bomb->getypos() == yman )
        {
          bombcheck = 0;
          break;
        }
      }
      // erases the trails of player's charecter
      if( bombcheck )
      {
        wattron(mapwindow,A_ITALIC|COLOR_PAIR(16));
        mvwaddch(mapwindow, yman, xman, ' ');
        wattroff(mapwindow,A_ITALIC|COLOR_PAIR(16));
      }
      player_move(bomberman, xman, yman, 'U');
      displayplayer();
      break;
    }
    case KEY_DOWN:
    {
      if( move != ERR )
      { while( wgetch(mapwindow) == move ); }
      for( auto & bomb : bombs )
      {
        if( !bomb->detonated() && bomb->getxpos() == xman && bomb->getypos() == yman )
        {
          bombcheck = 0;
          break;
        }
      }
      if( bombcheck )
      {
        wattron(mapwindow,A_ITALIC|COLOR_PAIR(16));
        mvwaddch(mapwindow, yman, xman, ' ');
        wattroff(mapwindow,A_ITALIC|COLOR_PAIR(16));
      }
      player_move(bomberman, xman, yman, 'D');
      displayplayer();
      break;
    }
    case KEY_RIGHT:
    {
      if( move != ERR )
      { while( wgetch(mapwindow) == move ); }
      for( auto & bomb : bombs )
      {
        if( !bomb->detonated() && bomb->getxpos() == xman && bomb->getypos() == yman )
        {
          bombcheck = 0;
          break;
        }
      }
      if( bombcheck )
      {
        wattron(mapwindow,A_ITALIC|COLOR_PAIR(16));
        mvwaddch(mapwindow, yman, xman, ' ');
        wattroff(mapwindow,A_ITALIC|COLOR_PAIR(16));
      }
      player_move(bomberman, xman, yman, 'R');
      displayplayer();
      break;
    }
    case KEY_LEFT:
    {
      if( move != ERR )
      { while( wgetch(mapwindow) == move ); }
      for( auto & bomb : bombs )
      {
        if( !bomb->detonated() && bomb->getxpos() == xman && bomb->getypos() == yman )
        {
          bombcheck = 0;
          break;
        }
      }
      if( bombcheck )
      {
        wattron(mapwindow,A_ITALIC|COLOR_PAIR(16));
        mvwaddch(mapwindow, yman, xman, ' ');
        wattroff(mapwindow,A_ITALIC|COLOR_PAIR(16));
      }
      player_move(bomberman, xman, yman, 'L');
      displayplayer();
      break;
    }
    // z - DROP BOMB "A"
    case 'z':
    {
      if( move != ERR )
      { while( wgetch(mapwindow) == move ); }
      // validates if an "active" bomb is already been dropped at the current position
      for( auto & bomb : bombs )
      {
        if( bomb->getcharecter() == '!' && !bomb->detonated() )
        {
          if( bomb->getxpos() == xman && bomb->getypos() == yman )
          {
            bombcheck = 0;
            break;
          }
        }
      }
      if( !bombcheck )
      { break; }
      if( bomberman.getbombsused() < bomberman.getbombsmax() )
      {
        dropbomb(xman, yman, 'A');
        displaybombs();
        bombsdropped = bomberman.getbombsused();
        bombsdropped++;
        bomberman.setbombsused(bombsdropped);
      }
      break;
    }
    // x - DROP BOMB "B"
    case 'x':
    {
      if( move != ERR )
      { while( wgetch(mapwindow) == move ); }
      for( auto & bomb : bombs )
      {
        if( bomb->getcharecter() == '?' && !bomb->detonated() )
        {
          if( bomb->getxpos() == xman && bomb->getypos() == yman )
          {
            bombcheck = 0;
            break;
          }
        }
      }
      if( !bombcheck )
      { break; }
      if( bomberman.getremotesused() < bomberman.getremotesmax() )
      {
        dropbomb(xman, yman, 'B');
        displaybombs();
        remotesdropped = bomberman.getremotesused();
        remotesdropped++;
        bomberman.setremotesused(remotesdropped);
      }
      break;
    }
    // SPACE - DETONATE BOMB "B"
    case ' ':
    {
      if( move != ERR )
      { while( wgetch(mapwindow) == move ); }
      remotedetonate();
      break;
    }
    default:
      break;
  }
  return true;
}

void Play::displayenemy( Enemy * enemy )
{
  char charecter = enemy->getcharecter();
  int xenemy = enemy->getxpos();
  int yenemy = enemy->getypos();
  if( charecter == '<' )
  {
    wattron(mapwindow,COLOR_PAIR(17));
    mvwaddch(mapwindow, yenemy, xenemy, charecter);
    wattroff(mapwindow,COLOR_PAIR(17));
  }
  else
  {
    wattron(mapwindow,COLOR_PAIR(18));
    mvwaddch(mapwindow, yenemy, xenemy, charecter);
    wattroff(mapwindow,COLOR_PAIR(18));
  }
  wrefresh(mapwindow);
}

void Play::enemymove()
{
  // used to adjust the "FPS" of the enemy's movement
  usleep(60000);
  for( auto & enemy : enemies )
  {
    if( enemy->alive() && !enemy->yadunknow() )
    {
      wattron(mapwindow,A_ITALIC|COLOR_PAIR(16));
      mvwaddch(mapwindow, enemy->getypos(), enemy->getxpos(), ' ');
      wattroff(mapwindow,A_ITALIC|COLOR_PAIR(16));
      enemy_move(enemy);
      displayenemy(enemy);
    }
  }
}

void Play::displaybombs()
{
  for( auto & bomb : bombs )
  {
    // if the bomb has not detonated yet
    if( !bomb->detonated() && !bomb->used() )
    {
      wattron(mapwindow,COLOR_PAIR(9));
      mvwaddch(mapwindow, bomb->getypos(), bomb->getxpos(), bomb->getcharecter());
      wattroff(mapwindow,COLOR_PAIR(9));
    }
    if( !bomb->detonated() && !bomb->used() && bomb->vsmode() )
    {
      wattron(mapwindow,COLOR_PAIR(21));
      mvwaddch(mapwindow, bomb->getypos(), bomb->getxpos(), bomb->getcharecter());
      wattroff(mapwindow,COLOR_PAIR(21));
    }
  }
  wrefresh(mapwindow);
}

bool Play::bombsupdate()
{
  // check Bomb "A" detonates
  checkdetonates();
  // check if the player was blasted
  bool blasted = playerblasted(bomberman.getxpos(), bomberman.getypos());
  if( blasted )
  {
    lostlife();
    bool live = alive();
    if( !live )
    { return true; }
    else
    { restartlevel(); }
  }
  // check and update the blasted enemies
  if( !vsmode )
  { enemiesblasted(); }
  // check and update the blasted bombermen
  else
  { mandemblasted(); }
  // display bomb blast effect
  displaylitness();
  // check & display upgrades in blasted boxes
  checkboxes();
  displayupgrades();
  // update bomberman's stats after picking up an upgrade
  checkupgrades();
  if( !vsmode )
  {
    for( auto & enemy : enemies )
    {
      if( !enemy->alive() && !enemy->displayed() )
      {
        char charecter = enemy->getcharecter();
        int xenemy = enemy->getxpos();
        int yenemy = enemy->getypos();
        wattron(mapwindow,COLOR_PAIR(19));
        mvwaddch(mapwindow, yenemy, xenemy, charecter);
        wattroff(mapwindow,COLOR_PAIR(19));
        if( enemy->getcharecter() == '<' )
        {
          werase(messagewindow);
          int center = (105 - strlen("PACMAN (<) ENEMY BLASETED @ X , Y !!!"))/2;
          wattron(messagewindow, A_BOLD|COLOR_PAIR(4));
          mvwprintw(messagewindow, 1, center, "PACMAN (<) ENEMY BLASETED @ %d , %d !!!", xenemy, yenemy);
          wattroff(messagewindow, A_BOLD|COLOR_PAIR(4));
          wrefresh(messagewindow);
        }
        else
        {
          werase(messagewindow);
          int center = (105 - strlen("DOLLAR ($) ENEMY BLASETED @ X , Y !!!"))/2;
          wattron(messagewindow, A_BOLD|COLOR_PAIR(4));
          mvwprintw(messagewindow, 1, center, "DOLLAR ($) ENEMY BLASETED @ %d , %d !!!", xenemy, yenemy);
          wattroff(messagewindow, A_BOLD|COLOR_PAIR(4));
          wrefresh(messagewindow);
        }
      }
    }
  }
  wrefresh(mapwindow);
  loadinfo();
  wrefresh(infowindow);
  return false;
}

void Play::displaylitness()
{
  int upflag, downflag, rightflag, leftflag;
  for( auto & bomb : bombs )
  {
    upflag = 0;
    downflag = 0;
    rightflag = 0;
    leftflag = 0;
    if( bomb->detonated() && !bomb->used() )
    {
      int charecter = bomb->getcharecter();
      int power = bomb->getpower();
      int x = bomb->getxpos();
      int y = bomb->getypos();
      wattron(mapwindow,COLOR_PAIR(10));
      mvwaddch(mapwindow, y, x, charecter);
      for( int range = 0 ; range <= power ; range++ )
      {
        // UP
        if( map.getfilexy(x-1, y-range-1) == 'W' || y-range <= 0 )
        { upflag = 1; }
        if( !upflag && map.getfilexy(x-1, y-range-1) == 'B' )
        {
          map.setfilexy(x-1, y-range-1, '!');
          upflag = 1;
        }
        else if ( !upflag )
        { mvwaddch(mapwindow, y-range, x, charecter); }
        // DOWN
        if( map.getfilexy(x-1, y+range-1) == 'W' || y+range > 19 )
        { downflag = 1; }
        if( !downflag && map.getfilexy(x-1, y+range-1) == 'B' )
        {
          map.setfilexy(x-1, y+range-1, '!');
          downflag = 1;
        }
        else if ( !downflag )
        { mvwaddch(mapwindow, y+range, x, charecter); }
        // RIGHT
        if( map.getfilexy(x+range-1, y-1) == 'W' || x+range > 103 )
        { rightflag = 1; }
        if( !rightflag && map.getfilexy(x+range-1, y-1) == 'B' )
        {
          map.setfilexy(x+range-1, y-1, '!');
          rightflag = 1;
        }
        else if ( !rightflag )
        { mvwaddch(mapwindow, y, x+range, charecter); }
        // LEFT
        if( map.getfilexy(x-range-1, y-1) == 'W' || x-range <= 0 )
        { leftflag = 1; }
        if( !leftflag && map.getfilexy(x-range-1, y-1) == 'B' )
        {
          map.setfilexy(x-range-1, y-1, '!');
          leftflag = 1;
        }
        else if ( !leftflag )
        { mvwaddch(mapwindow, y, x-range, charecter); }
      }
      wattroff(mapwindow,COLOR_PAIR(10));
      wrefresh(mapwindow);
      usleep(30000);
      eraselitness();
      wrefresh(mapwindow);
      bomb->bombused();
    }
  }
}

void Play::eraselitness()
{
  int upflag, downflag, rightflag, leftflag;
  for( auto & bomb : bombs )
  {
    upflag = 0;
    downflag = 0;
    rightflag = 0;
    leftflag = 0;
    if( bomb->detonated() && !bomb->used() )
    {
      int power = bomb->getpower();
      int x = bomb->getxpos();
      int y = bomb->getypos();
      wattron(mapwindow,A_ITALIC|COLOR_PAIR(16));
      mvwaddch(mapwindow, y, x, ' ');
      wattroff(mapwindow,A_ITALIC|COLOR_PAIR(16));
      for( int range = 0 ; range <= power ; range++ )
      {
        wattron(mapwindow,A_ITALIC|COLOR_PAIR(16));
        // UP
        if( !upflag && (map.getfilexy(x-1, y-range-1) != 'W' || map.getfilexy(x-1, y-range-1) == '!') )
        {
          if( map.getfilexy(x-1, y-range-1) != 'B' && x > 0 && y-range > 0 )
          {
            mvwaddch(mapwindow, y-range, x, ' ');
          }
        }
        if( map.getfilexy(x-1, y-range-1) == 'W' )
        { upflag = 1; }
        // DOWN
        if( !downflag && (map.getfilexy(x-1, y+range-1) != 'W' || map.getfilexy(x-1, y+range-1) == '!') )
        {
          if( map.getfilexy(x-1, y+range-1) != 'B' && x > 0 && y+range <= 19 )
          {
            mvwaddch(mapwindow, y+range, x, ' ');
          }
        }
        if( map.getfilexy(x-1, y+range-1) == 'W' )
        { downflag = 1; }
        // RIGHT
        if( !rightflag && (map.getfilexy(x+range-1, y-1) != 'W' || map.getfilexy(x+range-1, y-1) == '!') )
        {
          if( map.getfilexy(x+range-1, y-1) != 'B' && x+range <= 103 && y > 0 )
          {
            mvwaddch(mapwindow, y, x+range, ' ');
          }
        }
        if( map.getfilexy(x+range-1, y-1) == 'W' )
        { rightflag = 1; }
        // LEFT
        if( !leftflag && (map.getfilexy(x-range-1, y-1) != 'W' || map.getfilexy(x-range-1, y-1) == '!') )
        {
          if( map.getfilexy(x-range-1, y-1) != 'B' && x-range > 0 && y > 0 )
          {
            mvwaddch(mapwindow, y, x-range, ' ');
          }
        }
        if( map.getfilexy(x-range-1, y-1) == 'W' )
        { leftflag = 1; }
        wattroff(mapwindow,A_ITALIC|COLOR_PAIR(16));
      }
    }
  }
}

void Play::displayupgrades()
{
  for( auto box : boxes )
  {
    if( box->blasted() && !box->displayed() && !box->used() && !box->yadunknow() )
    {
      char upgrade = box->getupgrade();
      char xbox = box->getxpos();
      char ybox = box->getypos();
      switch( upgrade )
      {
        case 'E':
        {
          wattron(mapwindow,COLOR_PAIR(11));
          mvwaddch(mapwindow, ybox, xbox, upgrade);
          wattroff(mapwindow,COLOR_PAIR(11));
          werase(messagewindow);
          break;
        }
        case 'S':
        {
          wattron(mapwindow,COLOR_PAIR(12));
          mvwaddch(mapwindow, ybox, xbox, upgrade);
          wattroff(mapwindow,COLOR_PAIR(12));
          werase(messagewindow);
          int center = (105 - strlen("XTRA SCORE POINTS LOCATED @ X , Y"))/2;
          wattron(messagewindow, A_BOLD|COLOR_PAIR(4));
          mvwprintw(messagewindow, 1, center, "XTRA SCORE POINTS LOCATED @ %d , %d", xbox, ybox);
          wattroff(messagewindow, A_BOLD|COLOR_PAIR(4));
          wrefresh(messagewindow);
          break;
        }
        case 'T':
        {
          wattron(mapwindow,COLOR_PAIR(13));
          mvwaddch(mapwindow, ybox, xbox, upgrade);
          wattroff(mapwindow,COLOR_PAIR(13));
          werase(messagewindow);
          int center = (105 - strlen("XTRA TIME LOCATED @ X , Y"))/2;
          wattron(messagewindow, A_BOLD|COLOR_PAIR(4));
          mvwprintw(messagewindow, 1, center, "XTRA TIME LOCATED @ %d , %d", xbox, ybox);
          wattroff(messagewindow, A_BOLD|COLOR_PAIR(4));
          wrefresh(messagewindow);
          break;
        }
        case 'L':
        {
          wattron(mapwindow,COLOR_PAIR(12));
          mvwaddch(mapwindow, ybox, xbox, upgrade);
          wattroff(mapwindow,COLOR_PAIR(12));
          werase(messagewindow);
          int center = (105 - strlen("XTRA LIFE LOCATED @ X , Y"))/2;
          wattron(messagewindow, A_BOLD|COLOR_PAIR(4));
          mvwprintw(messagewindow, 1, center, "XTRA LIFE LOCATED @ %d , %d", xbox, ybox);
          wattroff(messagewindow, A_BOLD|COLOR_PAIR(4));
          wrefresh(messagewindow);
          break;
        }
        case 'A':
        {
          wattron(mapwindow,COLOR_PAIR(14));
          mvwaddch(mapwindow, ybox, xbox, '!');
          wattroff(mapwindow,COLOR_PAIR(14));
          werase(messagewindow);
          int center = (105 - strlen("BOMB POWER UPGRADE LOCATED @ X , Y"))/2;
          wattron(messagewindow, A_BOLD|COLOR_PAIR(4));
          mvwprintw(messagewindow, 1, center, "BOMB POWER UPGRADE LOCATED @ %d , %d", xbox, ybox);
          wattroff(messagewindow, A_BOLD|COLOR_PAIR(4));
          wrefresh(messagewindow);
          break;
        }
        case 'a':
        {
          wattron(mapwindow,COLOR_PAIR(14));
          mvwaddch(mapwindow, ybox, xbox, '!');
          wattroff(mapwindow,COLOR_PAIR(14));
          werase(messagewindow);
          int center = (105 - strlen("XTRA BOMB UPGRADE LOCATED @ X , Y"))/2;
          wattron(messagewindow, A_BOLD|COLOR_PAIR(4));
          mvwprintw(messagewindow, 1, center, "XTRA BOMB UPGRADE LOCATED @ %d , %d", xbox, ybox);
          wattroff(messagewindow, A_BOLD|COLOR_PAIR(4));
          wrefresh(messagewindow);
          break;
        }
        case 'B':
        {
          wattron(mapwindow,COLOR_PAIR(14));
          mvwaddch(mapwindow, ybox, xbox, '?');
          wattroff(mapwindow,COLOR_PAIR(14));
          werase(messagewindow);
          int center = (105 - strlen("REMOTE POWER UPGRADE LOCATED @ X , Y"))/2;
          wattron(messagewindow, A_BOLD|COLOR_PAIR(4));
          mvwprintw(messagewindow, 1, center, "REMOTE POWER UPGRADE LOCATED @ %d , %d", xbox, ybox);
          wattroff(messagewindow, A_BOLD|COLOR_PAIR(4));
          wrefresh(messagewindow);
          break;
        }
        case 'b':
        {
          wattron(mapwindow,COLOR_PAIR(14));
          mvwaddch(mapwindow, ybox,xbox, '?');
          wattroff(mapwindow,COLOR_PAIR(14));
          werase(messagewindow);
          int center = (105 - strlen("XTRA REMOTE UPGRADE LOCATED @ X , Y"))/2;
          wattron(messagewindow, A_BOLD|COLOR_PAIR(4));
          mvwprintw(messagewindow, 1, center, "XTRA REMOTE UPGRADE LOCATED @ %d , %d", xbox, ybox);
          wattroff(messagewindow, A_BOLD|COLOR_PAIR(4));
          wrefresh(messagewindow);
          break;
        }
        default:
          break;
      }
    }
  }
  wrefresh(mapwindow);
}

void Play::checkupgrades()
{
  for( auto box : boxes )
  {
    if( box->blasted() && !box->displayed() && !box->used() && !box->yadunknow() )
    {
      if( bomberman.getxpos() == box->getxpos() && bomberman.getypos() == box->getypos() )
      {
        box->setdisplay(true);
        box->setuse(true);
        char upgrade = box->getupgrade();
        switch( upgrade )
        {
          // exit door
          case 'E':
          {
            if( enemiesleft != 0 )
            {
              box->setdisplay(false);
              box->setuse(false);
            }
            break;
          }
          // score++
          case 'S':
          {
            werase(messagewindow);
            wrefresh(messagewindow);
            score += ( rand() % 200 ) + 50;
            break;
          }
          // time++
          case 'T':
          {
            werase(messagewindow);
            wrefresh(messagewindow);
            timelimit += 50000;
            break;
          }
          // life++
          case 'L':
          {
            werase(messagewindow);
            wrefresh(messagewindow);
            int lives = bomberman.getlives();
            lives++;
            bomberman.setlives(lives);
            break;
          }
          // bombpower++
          case 'A':
          {
            int power = bomberman.getbombpower();
            power++;
            bomberman.setbombpower(power);
            werase(messagewindow);
            int center = (105 - strlen("BOMB POWER IS NOW X"))/2;
            wattron(messagewindow, A_BOLD|COLOR_PAIR(4));
            mvwprintw(messagewindow, 1, center, "BOMB POWER IS NOW %d", power);
            wattroff(messagewindow, A_BOLD|COLOR_PAIR(4));
            wrefresh(messagewindow);
            break;
          }
          // bombmax++
          case 'a':
          {
            int max = bomberman.getbombsmax();
            max++;
            bomberman.setbombmax(max);
            werase(messagewindow);
            int center = (105 - strlen("YOU CAN NOW CARRY X BOMBS"))/2;
            wattron(messagewindow, A_BOLD|COLOR_PAIR(4));
            mvwprintw(messagewindow, 1, center, "YOU CAN NOW CARRY %d BOMBS", max);
            wattroff(messagewindow, A_BOLD|COLOR_PAIR(4));
            wrefresh(messagewindow);
            break;
          }
          // remotepower++
          case 'B':
          {
            int power = bomberman.getremotepower();
            power++;
            bomberman.setremotepower(power);
            werase(messagewindow);
            int center = (105 - strlen("REMOTE POWER IS NOW X"))/2;
            wattron(messagewindow, A_BOLD|COLOR_PAIR(4));
            mvwprintw(messagewindow, 1, center, "REMOTE POWER IS NOW %d", power);
            wattroff(messagewindow, A_BOLD|COLOR_PAIR(4));
            wrefresh(messagewindow);
            break;
          }
          // remotemax++
          case 'b':
          {
            int max = bomberman.getremotesmax();
            max++;
            bomberman.setremotemax(max);
            werase(messagewindow);
            int center = (105 - strlen("YOU CAN NOW CARRY X REMOTES"))/2;
            wattron(messagewindow, A_BOLD|COLOR_PAIR(4));
            mvwprintw(messagewindow, 1, center, "YOU CAN NOW CARRY %d REMOTES", max);
            wattroff(messagewindow, A_BOLD|COLOR_PAIR(4));
            wrefresh(messagewindow);
            break;
          }
          default:
            break;
      }
    }
  }
}
}

bool Play::completed()
{
  for( auto box : boxes )
  {
    if( box->blasted() && box->displayed() && box->used() && !box->yadunknow())
    {
      if( bomberman.getxpos() == box->getxpos() && bomberman.getypos() == box->getypos() )
      {
        char completed = box->getupgrade();
        if( completed == 'E' )
        {
          werase(messagewindow);
          wrefresh(messagewindow);
          werase(mapwindow);
          werase(infowindow);
          wrefresh(infowindow);
          wattron(mapwindow,A_BOLD|COLOR_PAIR(4));
          int center = (105 - strlen(" !!! LEVEL COMPLETE !!! "))/2;
          mvwprintw(mapwindow, 9, center, " !!! LEVEL COMPLETE !!! ");
          wattroff(mapwindow,A_BOLD|COLOR_PAIR(4));
          wrefresh(mapwindow);
          napms(2000);
          loadname();
          napms(2000);
          werase(namewindow);
          werase(stdscr);
          wrefresh(stdscr);
          lvlpoints = 0;
          return true;
        }
      }
    }
  }
  return false;
}

void Play::clearlevel()
{
  werase(messagewindow);
  werase(infowindow);
  werase(mapwindow);
  wrefresh(messagewindow);
  wrefresh(infowindow);
  wrefresh(mapwindow);
}

bool Play::loadnextlevel( int level )
{
  werase(messagewindow);
  wrefresh(messagewindow);
  if( level > 3 )
  {
    werase(mapwindow);
    wattron(mapwindow,A_BOLD|COLOR_PAIR(4));
    int center = (105 - strlen("!!! CONGRATS YOU FINISHED THE GAME !!!"))/2;
    mvwprintw(mapwindow, 9, center, "!!! CONGRATS YOU FINISHED THE GAME !!!");
    wattroff(mapwindow,A_BOLD|COLOR_PAIR(4));
    wrefresh(mapwindow);
    napms(3000);
    return true;
  }
  map.clearmap();
  for( auto & bomb : bombs )
  {
    bomb->detonated();
    bomb->used();
  }
  for( auto & enemy : enemies )
  {
    enemy->setlife(false);
    enemy->setdisplay(true);
    enemy->seteat(true);
    enemy->setdunknow(true);
  }
  for( auto & box : boxes )
  {
    box->setblast(false);
    box->setdisplay(true);
    box->setuse(true);
    box->setdunknow(true);
  }
  map.resetenemiesleft();
  string filename ="src/Maps/lvl";
  filename += to_string(level);
  filename += ".txt";
  loadwindows(2, filename, bomberman.getlives());
  bomberman.setxpos(1);
  bomberman.setypos(1);
  bomberman.setbombsused(0);
  bomberman.setremotesused(0);
  timelimit = 300000;
  return false;
}

void Play::AImandem()
{
  // used to control the "FPS" of the bombermen movement in "VS" mode
  usleep(60000);
  enemiesleft = mandem.size();
  int random;
  for( auto & man : mandem )
  {
    int x = man.getxpos();
    int y = man.getypos();
    int absxdiff = abs( x - bomberman.getxpos() );
    int absydiff = abs( y - bomberman.getypos() );
    random = rand() % 10 + 1;
    if( man.getlives() > 0 )
    {
      // drop a bomb within bombing range
      if( !man.getdrop() && ( (absxdiff == 1 && absydiff == 1 ) || (absxdiff <= 2 && absydiff == 0) ) )
      {
        AIdropbomb(man);
        wattron(mapwindow,COLOR_PAIR(20));
        mvwaddch(mapwindow, man.getypos(), man.getxpos(), man.getcharecter());
        wattroff(mapwindow,COLOR_PAIR(20));
        wrefresh(mapwindow);
        man.setdrop(1);
        return;
      }
      // 70% chance of following the bomberman
      if( random <= 7 || absxdiff > 40 || absydiff > 5 )
      {
        wattron(mapwindow,A_ITALIC|COLOR_PAIR(16));
        mvwaddch(mapwindow, man.getypos(), man.getxpos(), ' ');
        wattroff(mapwindow,A_ITALIC|COLOR_PAIR(16));
        AImove(man, 0);
      }
      // move horizontally / vertically & avoid obstacles
      else
      {
        wattron(mapwindow,A_ITALIC|COLOR_PAIR(16));
        mvwaddch(mapwindow, man.getypos(), man.getxpos(), ' ');
        wattroff(mapwindow,A_ITALIC|COLOR_PAIR(16));
        AImove(man,1);
      }
      wattron(mapwindow,COLOR_PAIR(20));
      mvwaddch(mapwindow, man.getypos(), man.getxpos(), man.getcharecter());
      wattroff(mapwindow,COLOR_PAIR(20));
      wrefresh(mapwindow);
    }
    else
    { enemiesleft--; }
  }
}
