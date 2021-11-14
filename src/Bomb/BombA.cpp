#include "BombA.h"

BombA::BombA(){}

// BombA::~BombA(){}

char BombA::getcharecter() const
{ return charecter; }

int BombA::getxpos() const
{ return xpos; }

int BombA::getypos() const
{ return ypos; }

bool BombA::detonated() const
{ return lit; }

time_t BombA::getdroptime() const
{ return droptime; }

int BombA::getcountdown() const
{ return countdown; }

int BombA::getpower() const
{ return power; }

bool BombA::used() const
{ return use; }

void BombA::setxpos( int x )
{ xpos = x; }

void BombA::setypos( int y )
{ ypos = y; }

void BombA::setstart( time_t time )
{ droptime = time; }

void BombA::setpower( int p )
{ power = p; }

void BombA::detonate()
{ lit = true; }

void BombA::bombused()
{ use = true; }
