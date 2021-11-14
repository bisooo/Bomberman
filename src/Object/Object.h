#pragma once
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

/// Abstract "Object" - base class to all the instances in a map
class Object
{
private:

public:
  Object();
  virtual ~Object() noexcept(true);
  /// "getter" for the object's charecter
  virtual char getcharecter() const = 0;
};
