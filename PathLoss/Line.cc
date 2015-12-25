// Line class for ECE2036 Pathloss assignment
// Fall 2015

#include "Line.h"
#include "math.h"

// Class implementation here

  Line::Line()
  {
    point1 = Point(0,0);
    point2 = Point(0,0);
  }

  Line::Line(Point& p1, Point& p2)
  {
    point1 = p1;
    point2 = p2;
  }

  Point Line::getPF()
  {
    return point1;
  }

  Point Line::getPS()
  {
    return point2;
  }

  double Line::Length()
  {
    double out = pow((point2.getX()*1.0 - point1.getX()*1.0),2) + pow((point2.getY()*1.0 - point1.getY()*1.0),2);
    out = sqrt(out);
    return out;
  }

  bool Line::Intersects(Line& rhs)
  {
    if (point1.getX() == point2.getX())//vertical line(wall)
    {
      if (rhs.point1.getX() == rhs.point2.getX())//other line also vertical
      {
        return false;//parallel return false
      }
      else
     {
       if (rhs.point1.getY() == rhs.point2.getY())//other line horizontal
       {
         int xhere = point1.getX();//wall x-value
         if (rhs.point1.getX() <= xhere && xhere <= rhs.point2.getX() && point1.getY() <= rhs.point1.getY() && rhs.point1.getY() < point2.getY())
         {
           return true;
         }
         else
         {
           return false;
         }
       }
       double m = (((rhs.point2.getY() - rhs.point1.getY())) * 1.0) / (((rhs.point2.getX() - rhs.point1.getX())) *1.0);
       double c = (rhs.point1.getY()) - (m * rhs.point1.getX());
       double y = (m * point1.getX()) + c;
       if (((point1.getY() <= y) && (y < point2.getY())) && ((rhs.point1.getY() <= y) && (y <= rhs.point2.getY())))
       {
         return true;
       }
       else
       {
         return false;
       }
     }
    }
    else if (point1.getY() == point2.getY())//horizontal line(wall)
    {
      if (rhs.point1.getY() == rhs.point2.getY())//other line horizontal
      {
        return false;//parallel lines return false
      }
      else
     {
       if (rhs.point1.getX() == rhs.point2.getX())//other line vertical
       {
         int yhere = point1.getY();
         if (rhs.point1.getY() <= yhere && yhere <= rhs.point2.getY() && point1.getX() <= rhs.point1.getX() && rhs.point1.getX() < point2.getX())
         {
           return true;
         }
         else
         {
           return false;
         }  
       }
       double m = (((rhs.point2.getY() - rhs.point1.getY())) * 1.0) / (((rhs.point2.getX() - rhs.point1.getX())) *1.0);
       double c = (rhs.point1.getY()) - (m * rhs.point1.getX());
       double x = (point1.getY() - c) / m;
       if (((point1.getX() <= x) && (x < point2.getX())) && ((rhs.point1.getX() <= x) && (x <= rhs.point2.getX())))
       {
         return true;
       }
       else
       {
         return false;
       }
     }
    }
    return false;
  }
