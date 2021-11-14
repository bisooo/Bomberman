#include "BombB.h"

BombB::BombB(){}

// BombB::~BombB(){}

char BombB::getcharecter() const
{ return charecter; }

int BombB::getxpos() const
{ return xpos; }

int BombB::getypos() const
{ return ypos; }

bool BombB::detonated() const
{ return lit; }

time_t BombB::getdroptime() const
{ return droptime; }

int BombB::getcountdown() const
{ return countdown; }

int BombB::getpower() const
{ return power; }

bool BombB::used() const
{ return use; }

void BombB::setxpos( int x )
{ xpos = x; }

void BombB::setypos( int y )
{ ypos = y; }

void BombB::setstart( time_t time )
{ droptime = time; }

void BombB::setpower( int p )
{ power = p; }

void BombB::detonate()
{ lit = true; }

void BombB::bombused()
{ use = true; }
