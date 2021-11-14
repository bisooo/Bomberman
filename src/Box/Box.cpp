#include "Box.h"


Box::Box(){}

// Box::~Box(){}

void Box::setupgrade( char karekter )
{ upgrade = karekter; }

void Box::setxpos( int x )
{ xpos = x; }

void Box::setypos( int y )
{ ypos = y; }

void Box::setblast( bool state )
{ blast = state; }

void Box::setdisplay( bool state )
{ display = state; }

void Box::setuse( bool state )
{ use = state; }

void Box::setdunknow( bool state )
{ dunknow = state; }

char Box::getcharecter() const
{ return charecter; }

char Box::getupgrade() const
{ return upgrade; }

int Box::getxpos() const
{ return xpos; }

int Box::getypos() const
{ return ypos; }

bool Box::blasted() const
{ return blast; }

bool Box::displayed() const
{ return display; }

bool Box::used() const
{ return use; }

bool Box::yadunknow() const
{ return dunknow; }
