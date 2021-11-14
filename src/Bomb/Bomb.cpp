#include "Bomb.h"


Bomb::Bomb(){}

Bomb::~Bomb(){}

void Bomb::setvsmode( int status )
{ vs = status; }

int Bomb::vsmode()
{ return vs; }
