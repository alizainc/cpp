// Wireless path loss assignment
// ECE2036, Georgia Tech, Fall 2015

#include "math.h"

#include <iostream>
#include <fstream>

#include "qdisplay.h"
#include "Point.h"
#include "Line.h"
#include "PrintPixel.h"

using namespace std;

#define WALL_COUNT 56

Line walls[WALL_COUNT];  // Each wall stored here

int main(int argc, char** argv)
{

  QApplication a(argc, argv);
  ifstream w("walls.txt");
  if (!w)
    {
      cout << "OOps, no walls.txt file" << endl;
      return(1);
    }
  
  // Read the walls file
  int ind = 0;
  while(w)
    {
      int x0 = -1;
      int y0 = -1;
      int x1 = -1;
      int y1 = -1;
      w >> x0 >> y0 >> x1 >> y1;
      if (x0 < 0) break; // done
      // Your code here.  Save wall info in the walls array

      if (x0 == x1)
      {
        if (y1 < y0)
        {
          int temp = y0;
          y0 = y1;
          y1 = temp;
        }
      }
      else if (y0 == y1)
      {
        if (x1 < x0)
        {
          int temp = x0;
          x0 = x1;
          x1 = temp;
        }
      }
      Point p1(x0, y0);
      Point p2(x1, y1);
      Line l1(p1, p2);
      walls[ind] = l1;
      ind++;
    }
  w.close();

  // Create the display object
  QDisplay d(a);
  d.BlankImage(276, 276, 32); // 256x256 plus 10 pixel border (32 bit colors)
  int h = 256;
  int w = 256;
  int depth = 32;
  ORgb* p = (QRgb*) d.ImageData();

  for (int k = 0; k < 56; k++)
  {
    int index = 0;
    Line l = walls[k];
    int x0 = l.getPF().getX();
    int y0 = l.getPF().getY();
    int x1 = l.getPS().getX();
    int y1 = l.getPS().getY();
    double ln = l.Length();
    for (int j = 0; j < ln; j++)
    {
      if (x0 == x1)
     {
       index = (y0 + j) * w + x0;
     }
    }
  }
  d.Show(); // Make it screen visible
  
  // Your code here.  Create 16 threads and compute the signal streangth
  // at each point; Have the threads update the pixel array with the
  // correct color as it is computed.

  // d.Update(); // Uncomment as needed
  d.Save("pathloss.png");
  a.exec();
  cout << "Done" << endl;
}

      
  
    
