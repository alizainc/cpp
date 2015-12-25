//
// ECE20360 Program 2 - Complex Number Class decaration
// ALIZAIN CHARANIA>
//

// Class declaration for Complex number class
// ECE2035 Project 2

#include <iostream>
#include <string>

class Complex {
public:
  // Define your constructors here
  // Constructors
  Complex();
  Complex(double r, double i);
//  Complex(const std::string& rhs);

  // Define the other required member functions here
  // Member Functions
  double magnitude();
  double angle();
  Complex conjugate();
  void Print();
  double getReal();
  double getImag();
  bool getIsNum();

  // Define your operator overloads here if using member function overloads
  Complex operator+(Complex rhs);
  Complex operator-(Complex rhs);

  // Define your Data Members here
  // Data Members
public:
  double real;
  double imag;
  bool isNum;
};

// Define your operator overloads here if using non-member function
// operator overloads.
  
  Complex operator*(Complex lhs, Complex rhs);
  Complex operator/(Complex lhs, Complex rhs);
