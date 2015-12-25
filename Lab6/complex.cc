//
// ECE2036 Program 6- Complex Number Class implementation
// ALIZAI CHARANIA
//

#include <iostream>
#include <string>
#include <iomanip>

#include <math.h>

#include "complex.h"
//#include "string-parse.h"

using namespace std;

// Implement your constructors here
// Constructors

  Complex::Complex()
  {
    real = 0;
    imag = 0;
    isNum = true;
  }
  Complex::Complex(double r, double i)
  {
    real = r;
    imag = i;
    isNum = true;
  }
 /* Complex::Complex(const string& rhs)
  {
    if(rhs[0] == '(')
    {
    if(rhs.find(",") != string::npos)
    {
      string rhs1 = RemoveParens(rhs);
      string r = rhs1.substr(0, rhs1.find(","));
      string i = rhs1.substr(rhs1.find(",")+1, rhs1.length()-r.length()-1);
      real = ToDouble(r);
      imag = ToDouble(i);
      isNum = true;
    }
    if(rhs.find(">") != string::npos)
    {
      string rhs1 = RemoveParens(rhs);
      string r = rhs1.substr(0, rhs1.find(">"));
      string i = rhs1.substr(rhs1.find(">")+1, rhs1.length()-r.length()-1);
      double r1 = ToDouble(r);
      double i1 = ToDouble(i);
      real = r1*cos(i1*M_PI/180);
      imag = r1*sin(i1*M_PI/180);
      isNum = true;
    }
    }
    else
    {
      real = ToDouble(rhs);
      imag = 0;
      isNum = true;
    }
  }*/

double Complex::getReal() {
  return real;
}

double Complex::getImag() {
  return imag;
}

bool Complex::getIsNum() {
  return isNum;
}
// Implement your other member functions here
// Member functions

  double Complex::magnitude()
  {
    return sqrt(real*real + imag*imag);
  }

  double Complex::angle()
  {
    double a = atan2(imag, real);
    return a;
  }

  Complex Complex::conjugate()
  {
    Complex result(real, -imag);
    return result;
  }

  void Complex::Print()
  {
   if(isNum)
    {
    if(imag != 0 && real!= 0)
    {
    cout << setw(5) << real << " +" << setw(2) << imag << "j";
    }
    else if (imag == 0)
    {
    cout << setw(10) << real;
    }
    else if (real == 0)
    {
    cout << setw(10) << imag << "j";
    }
    }
   else
     {
       cout << setw(10) << "NaN";
     }
  }

/*  ostream& operator<<(ostream& os, Complex const& c) {
    
  }*/

// Implement your operators here
// Operators

  Complex Complex::operator+(Complex rhs)
  {
    if(isNum && rhs.isNum)
    {
      Complex result(real+rhs.real, imag+rhs.imag);
      return result;
    }
    else
    {
      rhs.isNum = false;
      return rhs;
    }
  }

  Complex Complex::operator-(Complex rhs)
  {
    if(isNum && rhs.isNum)
    {
      Complex result(real-rhs.real, imag-rhs.imag);
      return result;
    }
    else
    {
      rhs.isNum = false;
      return rhs;
    }
  }

  Complex operator*(Complex lhs, Complex rhs)
  {
    if (lhs.isNum && rhs.isNum)
    {
    Complex r((lhs.real*rhs.real) - (lhs.imag*rhs.imag), (lhs.imag*rhs.real) + (rhs.imag*lhs.real));
    return r;
    }
    else
    {
    lhs.isNum = false;
    return lhs;
    }
  }

  Complex operator/(Complex lhs, Complex rhs)
  {
    if (lhs.isNum && rhs.isNum)
    {
      if(rhs.magnitude() == 0)
    {
      rhs.isNum = false;
      return rhs;
    }
    else
    {
      Complex c = lhs * rhs.conjugate();
      double m = rhs.magnitude() *rhs.magnitude();
      Complex result(c.real/m, c.imag/m);
      return result;
    }
    }
    else
    {
      lhs.isNum = false;
      return lhs;
    }
  }
