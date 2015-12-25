// Wireless path loss assignment
// ECE2036, Georgia Tech, Fall 2015

#include "math.h"

#include <iostream>
#include <fstream>

#include "qdisplay.h"
#include "Point.h"
#include "Line.h"
#include "PrintPixel.h"
#include <math.h>

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
  int ht = d.Height();
  int wt = d.Width();
  int depth = d.Depth();
  QRgb* p = (QRgb*) d.ImageData();

  for (int k = 0; k < 56; k++)
  {
    int index = 0;
    Line l = walls[k];
    int x0 = l.getPF().getX();
    int y0 = l.getPF().getY();
    int x1 = l.getPS().getX();
    int y1 = l.getPS().getY();
    double ln = l.Length();
    QRgb black = QColor(0x0, 0x0, 0x0).rgb();
    for (int j = 0; j < ln; j++)
    {
      if (x0 == x1)
     {
       index = (y0+10 + j) * wt + x0+10;
       p[index] = black;
     }
     else if (y0 == y1)
     {
       index = ((y0+10) * wt) + x0 + j+10;
       p[index] = black;
     }
    }
  }
  QRgb red = QColor(0xff, 0x0, 0x0).rgb();
  QRgb green = QColor(0x0, 0xff, 0x0).rgb();
//  double pr = 20 + 0 + 0 - (10 * log10 ((4 * M_PI * 2.4 * pow(10,9)) / (3 * pow(10,8))));
//  int hi = 2;
//  double hii = 3.25;
//  if (hi < hii)
//  cout << "it is poosible" << endl;

  Point origin(1,1);
  for (int yy = 1; yy < 255; yy++)
  {
    for (int xx = 1; xx < 255; xx++)
    {
      double pr = 20 + 0 + 0 - (10 * log10 ((4 * M_PI * 2.4 * pow(10,9)) / (3 * pow(10,8))));
      QRgb black = QColor(0x0,0x0,0x0).rgb();
      int indexhere = 10 + ((yy+10) * 276) + xx;
      if (p[indexhere] == black)
      {
        continue;
      }
      Point pts(xx, yy);
      Line ls(origin, pts);
      double r = ls.Length();
    //  cout << xx << " " << yy << " " << r << endl;
      if (r > 0)
      pr = pr - (20.0 * log10 (r));
      int count = 0;

      for (int ll = 0; ll < 56; ll++)
      {
        Line eachline = walls[ll];
        bool in = eachline.Intersects(ls);
        if (in)
        {
          count++;
          pr = pr - 5;
        }
      }
      double prprint = pr;
      if (pr >= -20)
      {
        p[indexhere] = green;
        PrintPixel((yy*256)+xx, -20.000, count, 0, 255, 0);
      }
      else if (pr < -20 && pr > -50)
      {
       double mm = 255/30;
       pr = pr + 20;
       unsigned int rcolor = (unsigned int) pr * mm * -1;
       p[indexhere] = QColor(rcolor,  0xff, 0x0).rgb();
       PrintPixel((yy*256)+xx, prprint, count, rcolor, 255, 0);
      }
      else if (pr < -50 && pr > -80)
      {
       double mm = 255/30;
       pr = pr + 50;
       unsigned int gcolor = (unsigned int) 255 - (pr * mm * -1);
       p[indexhere] = QColor(0xff,  gcolor, 0x0).rgb();
       PrintPixel((yy*256)+xx, prprint, count, 255, gcolor, 0);
      }
      else if (pr <= -80)
      {
        p[indexhere] = red;
        PrintPixel((yy*256)+xx, -80.000, count, 255, 0, 0);
      }
      else
      {
        p[indexhere] = QColor(0xff, 0xff, 0x0).rgb();
        PrintPixel((yy*256)+xx, -50.000, count, 255, 255, 0);
      }  
    }
  }

 /* for (int k = 0; k < WALL_COUNT; k++)
  {
    int index = 0;
    Line l = walls[k];
    int x0 = l.getPF().getX();
    int y0 = l.getPF().getY();
    int x1 = l.getPS().getX();
    int y1 = l.getPS().getY();
    double ln = l.Length();
    QRgb black = QColor(0x0, 0x0, 0x0).rgb();
    for (int j = 0; j < ln; j++)
    {
      if (x0 == x1)
     {
       index = (10+y0 + j) * wt + x0+10;
       p[index] = black;
     }
     else if (y0 == y1)
     {
       index = ((y0+10) * wt) + x0 + j+10;
       p[index] = black;
     }
    }
  }*/

  d.Show(); // Make it screen visible
  
  
  // Your code here.  Create 16 threads and compute the signal streangth
  // at each point; Have the threads update the pixel array with the
  // correct color as it is computed.

  d.Update(); // Uncomment as needed
  d.Save("pathloss.png");
  a.exec();
}

      
  
    
