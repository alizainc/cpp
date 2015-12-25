// Point class for ECE2036 Pathloss assignment
// Fall 2015

// Class declaration

#ifndef __POINT_H__
#define __POINT_H__

// A point object consists of two integers denoting the x and y
// position of a point.  Two-D, not 3-D.
class Point 
{
public:
  Point();  // Default constructor
  Point(int, int);  // Construct with x,y

  int getX();
  int getY();
  // Add needed member variables here
private:
  int x;
  int y;
};
#endif

