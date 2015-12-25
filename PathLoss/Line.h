// Line class for ECE2036 Pathloss assignment
// Fall 2015

// Class declaration

#ifndef __LINE_H__
#define __LINE_H__

// Note that we are really referring to Line Segments here,
// not Lines in the classical geometrical sense.  We just called
// it "Line" to save some typing

#include "Point.h"

class Line
{
public:
  Line();  // Default constructor
  Line(Point&, Point&);  // Construct with two endpoints

  Point getPF();
  Point getPS();
  // Add member function for Length()
  // returns the length of the line segment
  double Length();

  // Add Intersects(const Line&); which returns true
  // if the current line intersects the specified line
  bool Intersects(Line&);

  // Add needed member variables here
private:
   Point point1;
   Point point2;
};
#endif

