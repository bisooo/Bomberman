#include "User.h"

User::User(){}

User::User( int lvl, int score, string name )
: level(lvl), highscore(score), username(name) {}

User::User( string name )
: username(name) {}

bool User::loadstats()
{
  string filename = "src/users/";
  filename.append(username);
  filename.append(".txt");

  string scr, lvl, lvs, bpow, maxb, rpow, maxr;
  int score, lives, bpower, bmax, rpower, rmax;
  ifstream load;
  load.open(filename);
  getline(load,scr);
  getline(load,lvl);
  getline(load,lvs);
  getline(load,bpow);
  getline(load,maxb);
  getline(load,rpow);
  getline(load,maxr);
  load.close();
  score  = stoi(scr);
  level  = stoi(lvl);
  lives  = stoi(lvs);
  bpower  = stoi(bpow);
  bmax  = stoi(maxb);
  rpower  = stoi(rpow);
  rmax  = stoi(maxr);

  char levelno = lvl[0];
  string maptoload = "src/Maps/lvl";
  maptoload += levelno;
  maptoload.append(".txt");

  bool loading = player.loadwindows(level, maptoload, lives);
  if( !loading )
  { return false; }
  player.setscore(score);
  player.setbombpower(bpower);
  player.setbombsmax(bmax);
  player.setremotepower(rpower);
  player.setremotesmax(rmax);
  return true;
}

bool User::newgame()
{
  bool loading = player.loadwindows(1, "src/Maps/lvl1.txt", 3);
  if( !loading )
  { return false; }
  while( 1 )
  {
    // returns the status of the time countdown of a level
    bool time = player.countdown();
    if( time )
    {
      // checks if there's user input & updates the player's move / drops bomb
      bool playing = player.userinput();
      // user chooses to exit the game
      if( !playing )
      { break; }
      // updates the enemies moves
      player.enemymove();
      // displays the dropped bombs
      player.displaybombs();
      // updates the detonated bombs and displays their effects
      bool bombed = player.bombsupdate();
      if( bombed )
      { break; }
      // checks if the player was caught
      bool caught = player.caught();
      if( caught )
      {
        // deduces a life from the player
        player.lostlife();
        // checks if the player's lives didn't run out
        bool alive = player.alive();
        if( !alive )
        { break; }
        // "restart" the current level
        else
        {
          player.restartlevel();
          continue;
        }
      }
      else
      {
        bool complete = player.completed();
        if( complete )
        {
          // clear the current level
          player.clearlevel();
          level++;
          // load the next level
          bool gamecomplete = player.loadnextlevel(level);
          if( gamecomplete )
          { break; }
          else
          { continue; }
        }
      }
    }
    else
    {
      player.lostlife();
      bool alive = player.alive();
      if( !alive )
      { break; }
      else
      {
        player.restartlevel();
        continue;
      }
    }
  }
  highscore = player.getscore();
  wattron(stdscr, A_BOLD|COLOR_PAIR(2));
  mvwprintw(stdscr, 0, 0, "SAVING YOUR GAME PROGRESS %s ...", username.c_str());
  wattroff(stdscr, A_BOLD|COLOR_PAIR(2));
  wrefresh(stdscr);
  string filename = "src/users/";
  filename.append(username);
  filename.append(".txt");
  ofstream save;
  save.open(filename);
  save << highscore << endl;
  save << level << endl;
  save << player.getlives() << endl;
  save << player.getbombpower() << endl;
  save << player.getbombsmax() << endl;
  save << player.getremotepower() << endl;
  save << player.getremotesmax() << endl;
  save.close();
  sleep(3);
  return loading;
}

bool User::loadgame()
{
  bool loading = loadstats();
  if( !loading )
  { return false; }
  while( 1 )
  {
    bool time = player.countdown();
    if( time )
    {
      bool playing = player.userinput();
      if( !playing )
      { break; }
      player.enemymove();
      player.displaybombs();
      bool bombed = player.bombsupdate();
      if( bombed )
      { break; }
      bool caught = player.caught();
      if( caught )
      {
        player.lostlife();
        bool alive = player.alive();
        if( !alive )
        { break; }
        else
        {
          player.restartlevel();
          continue;
        }
      }
      else
      {
        bool complete = player.completed();
        if( complete )
        {
          player.clearlevel();
          level++;
          bool gamecomplete = player.loadnextlevel(level);
          if( gamecomplete )
          { break; }
          else
          { continue; }
        }
      }
    }
    else
    {
      player.lostlife();
      bool alive = player.alive();
      if( !alive )
      { break; }
      else
      {
        player.restartlevel();
        continue;
      }
    }
  }
  highscore = player.getscore();
  wattron(stdscr, A_BOLD|COLOR_PAIR(2));
  mvwprintw(stdscr, 0, 0, "SAVING YOUR GAME PROGRESS %s ...", username.c_str());
  wattroff(stdscr, A_BOLD|COLOR_PAIR(2));
  wrefresh(stdscr);

  string filename = "src/users/";
  filename.append(username);
  filename.append(".txt");
  ofstream save;
  save.open(filename);
  save << highscore << endl;
  save << level << endl;
  save << player.getlives() << endl;
  save << player.getbombpower() << endl;
  save << player.getbombsmax() << endl;
  save << player.getremotepower() << endl;
  save << player.getremotesmax() << endl;
  save.close();
  sleep(3);
  return loading;
}

bool User::vsgame()
{
  bool loading = player.loadwindows(1, "src/Maps/vs.txt", 1);
  if( !loading )
  { return false; }
  player.vsmode = true;
  while( 1 )
  {
    bool time = player.countdown();
    if( time )
    {
      // AI movement / bomb dropping
      player.AImandem();
      bool playing = player.userinput();
      if( !playing )
      { break; }
      player.displaybombs();
      bool bombed = player.bombsupdate();
      if( bombed )
      { break; }
      bool complete = player.completed();
      if( complete )
      { break; }
    }
    else
    { break; }
  }
  player.vsmode = false;
  return loading;
}
