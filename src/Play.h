#pragma once
#include "Game.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include <ncurses.h>
#include <panel.h>
#include <time.h>
using namespace std;


/// " FRONTEND " - all the render functions to draw & update the console using ncurses
class Play : public Game
{
private:
    /// window for the level's map
    WINDOW * mapwindow;
    /// window for the live status of the time / score / bomberman attributes
    WINDOW * infowindow;
    /// window for the message updates
    WINDOW * messagewindow;
    /// window for the logo
    WINDOW * namewindow;
    /// max "width" of the map window
    int xmax = 0;
    /// max "height" of the map window
    int ymax = 0;
    /// stores the start time when starting a level
    time_t start;
    /// renders the map charecters into the map window
    void loadmap();
    /// renders the live status into the info window
    void loadinfo();
    /// renders the message window
    void loadmessage();
    /// renders the logo into the name window
    void loadname();

public:
    /// default constructor
    Play();
    /// flag stores "vs" mode game state
    bool vsmode;
    /// "getter" for the player's score - saving player's progress
    int getscore();
    /// "getter" for the player's lives - saving player's progress
    int getlives();
    /// "getter" for the player's bomb power - saving player's progress
    int getbombpower();
    /// "getter" for the player's max no of bombs - saving player's progress
    int getbombsmax();
    /// "getter" for the player's remote power - saving player's progress
    int getremotepower();
    /// "getter" for the player's max no of remotes - saving player's progress
    int getremotesmax();

    /// "setter" for the player's score - loading player's progress
    void setscore(int scr);
    /// "setter" for the player's bomb power - loading player's progress
    void setbombpower(int bpow);
    /// "setter" for the player's max no of bombs - loading player's progress
    void setbombsmax(int maxb);
    /// "setter" for the player's remote power - loading player's progress
    void setremotepower(int rpow);
    /// "setter" for the player's max no of remotes - loading player's progress
    void setremotesmax(int maxr);

    /**
    initialises the 3 main windows - logo, info & map then renders them to the screen
    @param level of map
    @param filename of the txt map file
    @param lives of the bomberman
    @return if the initalisation was successful or not
    */
    bool loadwindows(int level, string filename, int lives);
    /**
    constructs a Man & Map object then loads the level into the Map object
    @param level of map
    @param filename of the txt map file
    @param lives of the bomberman
    @return if reading the map from the file was successful or not
    */
    bool loadobjects(int level, string filename, int lives);
    /// adds a hidden "exit door" & randomly fills some of the boxes in the map with upgrades
    void fillboxes();
    /**
    checks the status of the time left & updates the time displayed
    @return if the time ran out or not
    */
    bool countdown();
    /**
    handles all the user user input
    - moving the bomberman
    - dropping a normal bomb
    - dropping a remote bomb
    - detonating the remote bomb
    - exiting the game
    @return if the user wants to exit the game
    */
    bool userinput();
    /**
    updates the detonated bombs & upgrades of blasted boxes
    @return if the player was affected by the bomb
    */
    bool bombsupdate();
    /// renders the bomberman to the screen at their current coordinates
    void displayplayer();
    /// renders the bombermen in "vs" mode at their current coordinates
    void AImandem();
    /// renders the bombs at their dropped coordinates
    void displaybombs();
    /// renders the detonation effect in the range of a bomb
    void displaylitness();
    /// erases the detonation effect in the range of a bomb
    void eraselitness();
    /// renders the upgrades of the blasted boxes
    void displayupgrades();
    /// checks if an upgrade is picked up & updates the bomberman's stats
    void checkupgrades();
    /// updates the movement of the enemies
    void enemymove();
    /**
    renders the enemy to the screen at their current coordinates
    @param enemy to be displayed
    */
    void displayenemy(Enemy * enemy);
    /**
    updates the score if a dead enemy is eaten or if the bomberman was caught
    @return if the player was caught by an enemy
    */
    bool caught();
    /// updates the bomberman's lives
    void lostlife();
    /**
    @return whether the bomberman ran out of lives
    */
    bool alive();
    /// resets the time / bomberman / enemies / boxes & map attributes
    void restartlevel();
    /**
    @return if the bomberman completed the level
    */
    bool completed();
    /// clears the map and objects of the current level
    void clearlevel();
    /**
    loads the map of the new level and sets the attributes of the objects
    @param level of the map
    @return if the player completed the game
    */
    bool loadnextlevel(int level);
};
