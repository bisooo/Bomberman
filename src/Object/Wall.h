#pragma once
#include "../Object/Object.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <map>
#include <vector>
#include <ncurses.h>
#include <panel.h>
using namespace std;

/// An "Object" that represents a wall that blocks enemies & the bomberman
class Wall : public Object
{
private:
  /// charecter of the wall
  char charecter = '#';

public:
  Wall();
  /// "getter" for the wall's charecter
  virtual char getcharecter() const override;
};
