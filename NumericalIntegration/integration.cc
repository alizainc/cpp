// Parallel Numerical Integration
// ECE2893 Assignment 7, Spring 2011
// Alizain Charania

#include <stdio.h>
#include <math.h>
#include "gthread.h"
#include <iostream>

using namespace std;

// The typedef below defines whether we are using 32-bit float
// or 64-bit double for all of the floating point values.  Your program
// should use this type (MyFloat_t) for all variables that use floating
// point.
typedef MYFLOAT  MyFloat_t;
double correct = 1.8850380210460e+11;

// The below is the "correct" value, determined by evaluating the
// integral and computing the area.  This is used when computing
// the "error" for the numerical integration calculations.
// Also, this is the only place in the program where the type "double"
// is to be used.  Everywhere else, you should use type MyFloat_t.
//double correct = 1.8850380185600e+11;

// The below global variable is used by the threads to update the
// total area of the integral.  You will need mutex protection before
// updating this variable.
MyFloat_t totalArea;
gthread_mutex_t m;

MyFloat_t funct(MyFloat_t x)
{
  
  MyFloat_t y = (47.124*x*x*x*x) - (23.864*x*x*x) + (5.7*x*x) - (173.1*x) + 10.523;
  return y;
}
void riemannSum(MyFloat_t start, MyFloat_t length, MyFloat_t dx)
{
  MyFloat_t rectArea = 0;
  MyFloat_t sumArea = 0;
  MyFloat_t loopLength = length/dx;
  MyFloat_t start1 = start;
  for (int i = 0; i < loopLength; i++)
  {
    MyFloat_t height = (funct(start)/2.0) + (funct(start + dx)/2.0);
    rectArea = height * dx;
    sumArea += rectArea;
    start += dx;
  }
  LockMutex(m);
  totalArea += sumArea;
  UnlockMutex(m);
  EndThread();
}

int main()
{
  // Print out whether using float or double
  if (sizeof(MyFloat_t) == 4)
    {
      printf("Using float\n");
    }
  else
    {
      printf("Using double\n");
    }
  // Your code here.  You need to loop 7 times with 7 different
  // deltaX values, as described in the assignment.  For each of
  // the 7 iterations, create 10 threads and compute the integral
  // numerically using the Riemann sum metthod.  After all 10 threads
  // have completed, print out the deltaX value, the computed integral
  // and the error.
  MyFloat_t dx = 10.0;
  MyFloat_t start = -100.0;
  MyFloat_t end = 100.0;
  MyFloat_t length = (end - start) / 10.0;
  for (int i = 0; i < 7; i++)
  {
    totalArea = 0;
    dx = dx/10;
    for (int j = 0; j < 10; j++)
    {
      CreateThread(riemannSum, start, length, dx);
      start += length;
    }
    WaitAllThreads();
    MyFloat_t error = fabs(totalArea - correct);
    printf("DeltaX %3.6f, Area %15.13e, error %15.13e\n", dx, totalArea, error);
    totalArea = 0;
    start = -100;
  }
}
