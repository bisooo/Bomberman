#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include <ncurses.h>
#include <panel.h>
#include "User.h"
using namespace std;

void loadimg()
{
  int x = 1;
  int y = 8;
  int wide = 30;
  int high = 30;
  WINDOW * console = newwin(high, wide, y, x);
  curs_set(0);
  wattron(console,A_BOLD|COLOR_PAIR(2));
  mvwprintw(console,1,1,
    " __________________________");
    mvwprintw(console,2,1,
   "|o OFF  o ON               |");
   mvwprintw(console,3,1,
   "| .----------------------. |");
   mvwprintw(console,4,1,
   "| |  .----------------.  | |");
   mvwprintw(console,5,1,
   "| |  |                |  | |");
   mvwprintw(console,6,1,
   "| |  |                |  | |");
   mvwprintw(console,7,1,
   "| |  |                |  | |");
   mvwprintw(console,8,1,
   "| |  |                |  | |");
   mvwprintw(console,9,1,
   "| |  |                |  | |");
   mvwprintw(console,10,1,
   "| |  |                |  | |");
   mvwprintw(console,11,1,
   "| |  |                |  | |");
   mvwprintw(console,12,1,
   "| |  '----------------'  | |");
   mvwprintw(console,13,1,
   "| |__GAME BOY____________/ |");
   mvwprintw(console,14,1,
   "|          ________        |");
   mvwprintw(console,15,1,
   "|    _    (Nintendo)       |");
   mvwprintw(console,16,1,
   "|  _| |_              .-.  |");
   mvwprintw(console,17,1,
   "|-[_   _]-       .-. (   ) |");
   mvwprintw(console,18,1,
   "|   |_|         (   ) '-'  |");
   mvwprintw(console,19,1,
   "|    '           '-'   A   |");
   mvwprintw(console,20,1,
   "|                 B        |");
   mvwprintw(console,21,1,
   "|          ___   ___       |");
   mvwprintw(console,22,1,
   "|         (___) (___)   ,.,|");
   mvwprintw(console,23,1,
   "|        select start  ;:;:|");
   mvwprintw(console,24,1,
   "|                     ,;:;'/");
   mvwprintw(console,25,1,
   "|                   ,:;:'.'");
   mvwprintw(console,26,1,
   "'-----------------------`");
   wattroff(console,A_BOLD|COLOR_PAIR(2));
   wrefresh(console);
  int strtx = 1;
  int strty = 0;
  int w = 140;
  int h = 9;
  WINDOW * title = newwin(h, w, strty, strtx);
  curs_set(0);
  wattron(title,A_BOLD|COLOR_PAIR(2));
  mvwprintw(title, 1, 8,
  "\" 8888888.                          888                       8888     8888\n");
  mvwprintw(title, 2, 8,
  "  888   888                         888                       88888   88888\n");
  mvwprintw(title, 3, 8,
  "  888  .888                         888                       888888.888888\n");
  mvwprintw(title, 4, 8,
  "  88888888.   .8888.  888888.8888.  888888.   .8888.  8888888 8888888888888  88888.  888888.\n");
  mvwprintw(title, 5, 8,
  "  888   8888 888  888 888  888  888 888  888 888 888  888 888 888 88888 888      888 888  888\n");
  mvwprintw(title, 6, 8,
  "  888    888 888  888 888  888  888 888  888 88888888 888     888  888  888 .8888888 888  888\n");
  mvwprintw(title, 7, 8,
  "  888   8888 888..888 888  888  888 888  888 888.     888     888       888 888  888 888  888\n");
  mvwprintw(title, 8, 8,
  "  88888888     8888   888  888  888 888888    88888   888     888       888  8888888 888  888\n");
  mvwprintw(title, 1, 100, " \" ®");
  wattroff(title,A_BOLD|COLOR_PAIR(2));
  wrefresh(title);
  int height = 30;
  int width = 50;
  int startx = 75;
  int starty = 9;
  WINDOW * art = newwin(height, width, starty, startx);
  wattron(art,A_BOLD|COLOR_PAIR(2));
  mvwprintw(art, 1, 1,
  "                        .-.\n");
  mvwprintw(art, 2, 1,
  "                        '-'\n");
  mvwprintw(art, 3, 1,
  "                       //\n");
  mvwprintw(art, 4, 1,
  "              _..---._//\n");
  mvwprintw(art, 5, 1,
  "           . '  .\"     '-.\n");
  mvwprintw(art, 6, 1,
  "          /__/           \\      *\n");
  mvwprintw(art, 7, 1,
  "         ====_____     __ |   .:\n");
  mvwprintw(art, 8, 1,
  "       /#    #\"\"\" |   /()\\    :\n");
  mvwprintw(art, 9, 1,
  "       |#    #    |   \\__/    :\n");
  mvwprintw(art, 10, 1,
  "       \\#___ #____|      /   :::\n");
  mvwprintw(art, 11, 1,
  "        \\______________ |_...:_:\n");
  mvwprintw(art, 12, 1,
  "  ()    // /\\||||)))))))      \\\n");
  mvwprintw(art, 13, 1,
  " .( \\_  \\\\_\\//       _-'.'/    |\n");
  mvwprintw(art, 14, 1,
  "( )  |^|^|^|ooo/_#\\.//\"\"\"_     |\n");
  mvwprintw(art, 15, 1,
  "(_)_.|v|v|v|   / \\#  \\__/ '_  _'\n");
  mvwprintw(art, 16, 1,
  "         | _ _/_/      /_./_\"|\n");
  mvwprintw(art, 17, 1,
  "         /#_#__\"\"\"-._ /#  \\__)\n");
  mvwprintw(art, 18, 1,
  "         |__   \"\"-._ |##\n");
  mvwprintw(art, 19, 1,
  "         |  \"\"|-\"\"\"-_/##\n");
  mvwprintw(art, 20, 1,
  "         /\"\"--\\__.-|\n");
  mvwprintw(art, 21, 1,
  "         \\-_.-<__ /\n");
  mvwprintw(art, 22, 1,
  "         /-_| /  \\\n");
  mvwprintw(art, 23, 1,
  "         \\-_| \\_-<.\n");
  mvwprintw(art, 24, 1,
  "         <_-/ <_.-\\\n");
  mvwprintw(art, 25, 1,
  "         <_-|  |_.-|\n");
  mvwprintw(art, 26, 1,
  "    .----|   \\__\\  |\n");
  mvwprintw(art, 27, 1,
  "   |     .\"\"\"   '.  |\n");
  mvwprintw(art, 28, 1,
  "    .___|        |__|");
  mvwprintw(art, 29, 1,
  "        '.__...\"\"\"\n");
  wattroff(art,A_BOLD|COLOR_PAIR(2));
  wrefresh(art);
}

string getstring()
{
  string input;
  int ch;
  while ( (ch = getch()) != 10 )
  {
      input.push_back(ch);
      if ( ch == 127 )
      { return "INVALID"; }
  }
  return input;
}

void newgame()
{
  int width,height,startX,startY;
  width = 40;
  height = 5;
  startX = (COLS - width)/2;
  startY = (LINES - height)/2;
  WINDOW * newuser = newwin(height ,width ,startY , startX);
  echo();
  curs_set(1);
  keypad(newuser, true);
  box(newuser, '?', '~');
  string name;

  while( 1 )
  {
      wattron(newuser, A_BOLD);
      mvwprintw(newuser, 2, 3, "ENTER A USERNAME - ");
      move(startY+2, startX+23);
      wattroff(newuser, A_BOLD);
      wattron(newuser, A_BOLD|COLOR_PAIR(5));
      mvwprintw(newuser, 4, 2, "PRESS BACKSPACE TO RE-ENTER USERNAME");
      wattroff(newuser, A_BOLD|COLOR_PAIR(5));
      wrefresh(newuser);
      name = getstring();
      string filename = "src/users/";
      filename.append(name);
      filename.append(".txt");
      ifstream check;
      check.open(filename);
      if( !check.fail() )
      {
        move(startY+2,startX+25);
        werase(newuser);
        wrefresh(newuser);
        box(newuser,0,0);
        wattron(stdscr,COLOR_PAIR(1));
        mvwprintw(stdscr,17,44,"USERNAME ALREADY EXISTS!");
        wattroff(stdscr,COLOR_PAIR(1));
        wrefresh(stdscr);
        continue;
      }
      if( name == "INVALID" || name.empty() || name.find_first_not_of(' ') == string::npos)
      {
          move(startY+2, startX+25);
          wclear(newuser);
          box(newuser, '?', '~');
      }
      else
      { break; }
  }
  delwin(newuser);
  refresh();

  wattron(stdscr, A_BOLD|COLOR_PAIR(2));
  mvwprintw(stdscr, 0, 0, "STARTING NEW GAME...");
  wattroff(stdscr, A_BOLD|COLOR_PAIR(2));
  wrefresh(stdscr);
  napms(500);
  wclear(stdscr);
  wrefresh(stdscr);

  // create a new instance of a User
  User user(1, 0, name);
  // load the main game loop
  bool loading = user.newgame();
  if( !loading )
  {
    cout << "LOADING GAME FAILED..." << endl;
    napms(500);
    return;
  }
  werase(stdscr);
  wattron(stdscr, A_BOLD|COLOR_PAIR(2));
  mvwprintw(stdscr, 1, 1, "EXITING GAME ...");
  wattroff(stdscr, A_BOLD|COLOR_PAIR(2));
  wrefresh(stdscr);
  napms(1000);
}

void loadgame()
{
  int width,height,startX,startY;
  width = 40;
  height = 5;
  startX = (COLS - width)/2;
  startY = (LINES - height)/2;
  WINDOW * loaduser = newwin(height ,width ,startY , startX);
  echo();
  curs_set(1);
  keypad(loaduser, true);
  box(loaduser, '?', '~');
  string name;

  while( 1 )
  {
      wattron(loaduser, A_BOLD);
      mvwprintw(loaduser, 2, 3, "ENTER YOUR USERNAME - ");
      move(startY+2, startX+25);
      wattroff(loaduser, A_BOLD);
      wattron(loaduser, A_BOLD|COLOR_PAIR(5));
      mvwprintw(loaduser, 4, 2, "PRESS BACKSPACE TO RE-ENTER USERNAME");
      wattroff(loaduser, A_BOLD|COLOR_PAIR(5));
      wrefresh(loaduser);
      name = getstring();
      string filename = "src/users/";
      filename.append(name);
      filename.append(".txt");
      ifstream input;
      input.open(filename);
      if ( input.fail() )
      {
          move(startY+2,startX+25);
          werase(loaduser);
          wrefresh(loaduser);
          box(loaduser,0,0);
          wattron(stdscr,COLOR_PAIR(1));
          mvwprintw(stdscr,17,44,"USERNAME DOSEN'T EXIST!");
          wattroff(stdscr,COLOR_PAIR(1));
          wrefresh(stdscr);
      }
      else
      { break; }
  }
  delwin(loaduser);
  werase(stdscr);
  wrefresh(stdscr);
  refresh();

  wattron(stdscr, A_BOLD|COLOR_PAIR(2));
  mvwprintw(stdscr, 0, 0, "LOADING GAME...");
  wattroff(stdscr, A_BOLD|COLOR_PAIR(2));
  wrefresh(stdscr);
  napms(1000);
  wclear(stdscr);
  wrefresh(stdscr);

  User user(name);
  bool loading = user.loadgame();
  if( !loading )
  {
    wattron(stdscr, A_BOLD|COLOR_PAIR(1));
    mvwprintw(stdscr, 0, 0, "LOADING GAME FAILED ...");
    wattroff(stdscr, A_BOLD|COLOR_PAIR(1));
    wrefresh(stdscr);
    napms(500);
    return;
  }
  werase(stdscr);
  wattron(stdscr, A_BOLD|COLOR_PAIR(2));
  mvwprintw(stdscr, 0, 0, "EXITING GAME ...");
  wattroff(stdscr, A_BOLD|COLOR_PAIR(2));
  wrefresh(stdscr);
  napms(1000);
}

void info()
{
  int width,height,startx,starty;
  width = 107;
  height = 26;
  startx = 30;
  starty = 9;
  while(1)
  {
    loadimg();
    WINDOW * guide = newwin(height ,width ,starty , startx);
    noecho();
    curs_set(0);
    keypad(guide, true);
    wrefresh(guide);
    wattron(guide, A_BOLD|COLOR_PAIR(2));
    mvwprintw(guide, 1, 1, "THE AIM OF THE GAME IS TO ELIMINATE ALL THE ENEMIES WHILE EXPLORING THE MAP IN");
    mvwprintw(guide, 2, 1, "THE GIVEN TIME TO FIND THE HIDDEN DOOR AND UPGRADE YOUR BOMBERMAN ALONG THE WAY");
    wattroff(guide, A_BOLD|COLOR_PAIR(2));
    wattron(guide, A_BOLD|COLOR_PAIR(1));
    mvwprintw(guide, 4, 28, "<");
    wattroff(guide, A_BOLD|COLOR_PAIR(1));
    mvwprintw(guide, 4, 30, "-- ENEMIES --");
    wattron(guide, A_BOLD|COLOR_PAIR(6));
    mvwprintw(guide, 4, 44, "$");
    wattroff(guide, A_BOLD|COLOR_PAIR(6));
    wattron(guide, A_BOLD|COLOR_PAIR(6));
    mvwprintw(guide, 5, 1, "DOLLAR ($) ARE FAST AND MOVE VERTICALLY");
    wattroff(guide, A_BOLD|COLOR_PAIR(6));
    wattron(guide, A_BOLD|COLOR_PAIR(1));
    mvwprintw(guide, 6, 1, "PACMAN (<) ARE SLOWER & MOVE HORIZONTALLY, THEY ALSO SWITCH DIRECTIONS RANDOMLY ");
    wattroff(guide, A_BOLD|COLOR_PAIR(1));
    mvwprintw(guide, 7, 30, "-- UPGRADES --");
    wattron(guide, A_BOLD|COLOR_PAIR(3));
    mvwaddch(guide, 7, 28, '%');
    mvwaddch(guide, 7, 45, '%');
    wattroff(guide, A_BOLD|COLOR_PAIR(3));
    wattron(guide, A_BOLD|COLOR_PAIR(11));
    mvwprintw(guide, 8, 1, " ");
    wattroff(guide, A_BOLD|COLOR_PAIR(11));
    wattron(guide, A_BOLD|COLOR_PAIR(4));
    mvwprintw(guide, 8, 3, "YOU CAN LEVEL UP THROUGH THE EXIT DOOR ONCE ALL THE ENEMIES ARE CLEARED ");
    wattron(guide, A_BOLD|COLOR_PAIR(14));
    mvwprintw(guide, 9, 1, "!");
    wattroff(guide, A_BOLD|COLOR_PAIR(14));
    mvwprintw(guide, 9, 3, "OR");
    wattron(guide, A_BOLD|COLOR_PAIR(14));
    mvwprintw(guide, 9, 6, "?");
    wattroff(guide, A_BOLD|COLOR_PAIR(14));
    wattron(guide, A_BOLD|COLOR_PAIR(4));
    mvwprintw(guide, 9, 8, "ARE BOMB UPGRADES THAT CAN INCREASE YOUR BOMB/REMOTES'S RANGE POWER OR");
    mvwprintw(guide, 10, 8, "HOW MANY BOMBS/REMOTES YOU CAN CARRY/DROP AT A TIME");
    wattroff(guide, A_BOLD|COLOR_PAIR(4));
    wattron(guide, A_BOLD|COLOR_PAIR(12));
    mvwprintw(guide, 11, 1, "L");
    wattroff(guide, A_BOLD|COLOR_PAIR(12));
    mvwprintw(guide, 11, 3, "&");
    wattron(guide, A_BOLD|COLOR_PAIR(13));
    mvwprintw(guide, 11, 5, "S");
    wattroff(guide, A_BOLD|COLOR_PAIR(13));
    mvwprintw(guide, 11, 7, "&");
    wattron(guide, A_BOLD|COLOR_PAIR(13));
    mvwprintw(guide, 11, 9, "T");
    wattroff(guide, A_BOLD|COLOR_PAIR(13));
    wattron(guide, A_BOLD|COLOR_PAIR(4));
    mvwprintw(guide, 11, 11, "GIVE YOU AN EXTRA LIFE / XTRA POINTS OR AN EXTRA 30 SECONDS");
    wattroff(guide, A_BOLD|COLOR_PAIR(4));
    mvwprintw(guide, 12, 30, "-- CONTROLS --");
    wattron(guide, A_BOLD|COLOR_PAIR(5));
    mvwaddch(guide, 12, 28, ' ');
    mvwaddch(guide, 12, 45, ' ');
    mvwprintw(guide, 13, 1, "<= ^v =>");
    wattroff(guide, A_BOLD|COLOR_PAIR(5));
    mvwprintw(guide, 13, 9, " - ARROW KEYS TO NAVIGATE THE MAP");
    wattron(guide, A_BOLD|COLOR_PAIR(7));
    mvwprintw(guide, 13, 43, "@");
    wattroff(guide, A_BOLD|COLOR_PAIR(7));
    wattron(guide, A_BOLD|COLOR_PAIR(5));
    mvwprintw(guide, 14, 1, "Z");
    mvwprintw(guide, 15, 1, "X");
    mvwprintw(guide, 16, 1, "SPACE");
    wattroff(guide, A_BOLD|COLOR_PAIR(5));
    mvwprintw(guide, 14, 2, " - TO DROP A NORMAL BOMB THAT DETONATES AFTER 2 SECONDS");
    wattron(guide, A_BOLD|COLOR_PAIR(9));
    mvwprintw(guide, 14, 58, "!");
    wattroff(guide, A_BOLD|COLOR_PAIR(9));
    wattron(guide, A_BOLD|COLOR_PAIR(10));
    mvwprintw(guide, 14, 60, "! ! !");
    wattroff(guide, A_BOLD|COLOR_PAIR(10));
    mvwprintw(guide, 15, 2, " - TO DROP A REMOTE BOMB");
    wattron(guide, A_BOLD|COLOR_PAIR(9));
    mvwprintw(guide, 15, 27, "?");
    wattroff(guide, A_BOLD|COLOR_PAIR(9));
    mvwprintw(guide, 16, 6, " - TO DETONATE ALL THE REMOTE BOMBS");
    wattron(guide, A_BOLD|COLOR_PAIR(10));
    mvwprintw(guide, 16, 42, "? ? ?");
    wattroff(guide, A_BOLD|COLOR_PAIR(10));
    wattron(guide, A_BOLD|COLOR_PAIR(2));
    mvwprintw(guide, 17, 5, "PRESS 1 TO START A NEW GAME | PRESS 2 TO LOAD A GAME | PRESS ESC TO EXIT");
    wattron(guide, A_BOLD|COLOR_PAIR(2));

    int key = wgetch(guide);
    if( key == 49 )
    {
      werase(guide);
      wrefresh(guide);
      refresh();
      newgame();
    }
    else if( key == 50 )
    {
      werase(guide);
      wrefresh(guide);
      refresh();
      loadgame();
    }
    else if( key == 27 )
    {
      werase(guide);
      wrefresh(guide);
      refresh();
      werase(stdscr);
      wattron(stdscr, A_BOLD|COLOR_PAIR(2));
      mvwprintw(stdscr, 0, 0, "EXITING GAME ...");
      wattroff(stdscr, A_BOLD|COLOR_PAIR(2));
      wrefresh(stdscr);
      napms(1000);
      break;
    }
    else
    { continue; }
    wrefresh(guide);
  }
}

void vsgame()
{
  wattron(stdscr, A_BOLD|COLOR_PAIR(2));
  mvwprintw(stdscr, 0, 0, "LOADING VS MODE ...");
  wattroff(stdscr, A_BOLD|COLOR_PAIR(2));
  wrefresh(stdscr);
  napms(1000);
  wclear(stdscr);
  wrefresh(stdscr);

  User user;
  bool loading = user.vsgame();
  if( !loading )
  {
    wattron(stdscr, A_BOLD|COLOR_PAIR(1));
    mvwprintw(stdscr, 0, 0, "LOADING GAME FAILED ...");
    wattroff(stdscr, A_BOLD|COLOR_PAIR(1));
    wrefresh(stdscr);
    napms(500);
    return;
  }
  werase(stdscr);
  wattron(stdscr, A_BOLD|COLOR_PAIR(2));
  mvwprintw(stdscr, 0, 0, "EXITING GAME ...");
  wattroff(stdscr, A_BOLD|COLOR_PAIR(2));
  wrefresh(stdscr);
  napms(1000);
  info();
}

int main()
{
  // initialises ncurses and some color pairs (fg/bg)
  initscr();
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_CYAN, 0);
  init_pair(3, COLOR_GREEN, COLOR_YELLOW);
  init_pair(4, COLOR_GREEN, 0);
  init_pair(5, 0, COLOR_WHITE);
  init_pair(6, COLOR_MAGENTA, 0);
  init_pair(7, COLOR_CYAN, COLOR_BLACK);
  init_pair(8, COLOR_WHITE, COLOR_BLUE);
  init_pair(9, COLOR_RED, COLOR_BLUE);
  init_pair(10, COLOR_WHITE, COLOR_RED);
  init_pair(11, COLOR_BLUE, COLOR_BLUE);
  init_pair(12, COLOR_BLUE, COLOR_GREEN);
  init_pair(13, COLOR_WHITE, COLOR_GREEN);
  init_pair(14, COLOR_RED, COLOR_GREEN);
  init_pair(15, COLOR_BLUE, 0);
  init_pair(16, COLOR_CYAN, COLOR_CYAN);
  init_pair(17, COLOR_RED, COLOR_MAGENTA);
  init_pair(18, COLOR_MAGENTA, COLOR_RED);
  init_pair(19, COLOR_GREEN, COLOR_BLUE);
  init_pair(20, COLOR_BLUE, COLOR_RED);
  init_pair(21, COLOR_BLUE, COLOR_MAGENTA);

  int width,height,startX,startY;
  int key;
  int choice = 0;
  int flag = 0;
  // width and height of the main menu screen
  width = 25;
  height = 10;
  // starting (x,y) coordinate depending on the screen size( COLS, LINES )
  startX = (COLS - width)/2;
  startY = (LINES - height)/2 + 3;
  // displays ASCII art windows
  loadimg();
  // creating the main menu window with the dimensions and starting coordinates
  WINDOW * mainmenu = newwin(height, width, startY, startX);
  // enabling the keyboard input for the mainmenu window
  keypad(mainmenu, true);
  // disable key echo && the cursor
  noecho();
  curs_set(0);
  // outline of the mainmenu window
  box(mainmenu, 0 ,'=');
  string choices[4] = {" NEW GAME ", " LOAD ", "\" VS \"", "= INFO ="};
  wattron(mainmenu, COLOR_PAIR(1));
  mvwprintw(mainmenu, 9, 6, "!ESC TO EXIT!");
  wattroff(mainmenu, COLOR_PAIR(1));
  clearok(mainmenu, true);
  wrefresh(mainmenu);
  while( 1 )
  {
      for( int i = 0 ; i < 4 ; i++ )
      {
        // print the menu choices and highlight the currently indexed one
        if ( i == choice )
        { wattron(mainmenu, A_REVERSE); }
        wattron(mainmenu, A_BOLD);
        if( i == 0 )
        { mvwprintw(mainmenu, i+3, 8, "%s", choices[i].c_str()); }
        else if( i == 1 )
        { mvwprintw(mainmenu, i+3, 10, "%s", choices[i].c_str()); }
        else if( i == 2 )
        { mvwprintw(mainmenu, i+3, 10, "%s", choices[i].c_str()); }
        else
        { mvwprintw(mainmenu, i+3, 9, "%s", choices[i].c_str()); }
        wattroff(mainmenu, A_REVERSE);
        wattroff(mainmenu, A_BOLD);
      }
      // keyboard listener to get the key pressed
      key = wgetch(mainmenu);
      // ESC key
      if( key == 27 )
      {
          flag = 1;
          break;
      }
      // ENTER key
      if( key == 10 )
      {
          delwin(mainmenu);
          refresh();
          break;
      }
      switch( key )
      {
        // Navigation Keypad keys
        case KEY_UP:
        {
          choice--;
          if( choice == -1 )
          { choice = 0; }
          break;
        }
        case KEY_DOWN:
        {
          choice++;
          if( choice == 4 )
          { choice = 3; }
          break;
        }
        default:
            break;
      }
  }
  if( flag )
  {
    mvwprintw(stdscr, 1, 1, "EXITING GAME ...");
    wattroff(stdscr, A_BOLD);
    wrefresh(stdscr);
    napms(1000);
    endwin();
    return 0;
  }

  switch( choice )
  {
      case 0:
          newgame();
          break;
      case 1:
          loadgame();
          break;
      case 2:
          vsgame();
          break;
      case 3:
          info();
          break;
      default:
        break;
  }
  endwin();
  return 0;
}
