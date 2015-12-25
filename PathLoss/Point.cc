// Point class for ECE2036 Pathloss assignment
// Fall 2015

#include "Point.h"

// Point Class implementation

  Point::Point()
  {
    x = 1;
    y = 1;
  }

  Point::Point(int a, int b)
  {
    x = a;
    y = b;
  }

  int Point::getX()
  {
    return x;
  }

  int Point::getY()
  {
    return y;
  }
