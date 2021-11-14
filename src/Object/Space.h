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

/// An "Object" that represent a path coordinate for the bomberman
class Space : public Object
{
private:
  /// charecter of a space
  char charecter = ' ';

public:
  Space();
  /// "getter" for the space's charecter
  virtual char getcharecter() const override;
};
