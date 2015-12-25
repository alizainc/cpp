#include <iostream>

 using namespace std; // We will discuss namespaces later

class TwoInt { // Simple class with two integer variables
 public:
TwoInt(int a0, int b0);
 void Print() const; // Print the variables
 int First() const; // Return the first int
 int Second() const; // Return the second int
 int Sum() const; // Get the sum
 // Note the use of "private" here
private:
int a;
 int b;
 };

 // Define a class FourInt that INHERITS from TwoInt
// This means the FourInt class has EVERYTHING that TwoInt has,
 // plus any additional things we might add

 class FourInt : public TwoInt {
 // Inherits from TwoInt the members and functins
 public:
 FourInt(int a0, int b0, int c0, int d0);
 void Print() const; // Print the variables
 int Third() const;
 int Fourth() const;
 double Average() const ;

 private:
 int c;
 int d;
 };

 // Methods for TwoInt
 TwoInt::TwoInt(int a0, int b0)
 : a(a0), b(b0) // Initialize with correct constructors
 { // Nothing else needed
 }

 void TwoInt::Print() const // Print the variables
 {
 cout << "a " << a << ", b " << b << endl;
 }

 int TwoInt::First() const // Return the first int
 {
 return a;
 }
 int TwoInt::Second() const // Return the second int


 {
return b;
 }

 int TwoInt::Sum() const // Return the sum
 {
 return a+b;
 }

 // Methods for FourInt
 // Define the FourInt constructor, with four integers
 FourInt::FourInt(int a0, int b0, int c0, int d0)
 : TwoInt(a0, b0), c(c0), d(d0)
 { // Nothing else needed
 }

void FourInt::Print() const // Print the variables
 {
 // There are two ways to do this; first is to refer to superclass (TwoInt)
 // functions get get member variables. This is NOT the preferred method.
 cout << "a " << First() << ", b " << Second()
 << "c " << c << ", d " << d << endl;

 // Below is a better method.
 TwoInt::Print(); // Let TwoInt "Print Itself"
 cout << "c " << c << ", d " << d << endl;
 }

 int FourInt::Third() const // Get the third int
 {
 return c;
 }

 int FourInt::Fourth() const // Get the fourth int
 {
 return d;
 }

 double FourInt::Average() const // Compute average
 {
 return (Sum() + c + d) / 4.0;
 }

 void Sub1Ref(const TwoInt& ti)
 { // Sub1Ref expects a "TwoInt" reference as a paramenter.
 // We can pass any object of type TwoInt or any subclass of TwoInt
 // We can call any TwoInt function,
 cout << "Hello from Sub1Ref()" << endl;
 ti.Print();
 // But cannot call FourInt functions
 // ti.Average(); // Won’t compile
 }

 void Sub1Ptr(TwoInt* ti)
 { // Sub1Ptr expects a "TwoInt" pointer as a paramenter.
// We can pass any object of type TwoInt or any subclass of TwoInt


 // We can call any TwoInt function,
 cout << "Hello from Sub1Ptr()" << endl;
 ti->Print(); // Note different syntax from Sub1Ref() above
 // But cannot call FourInt functions
 // ti.Average(); // Won’t compile
 }

 void Sub1Value(TwoInt ti)
 { // Sub1Value expects a TwoInt BY VALUE. Although this appears similar
 // to the two examples above, it is quite a bit different. This will
 // become apparent when we discuss virtual functions.
 cout << "Hello from Sub1Value()" << endl;
 ti.Print();
 // But cannot call FourInt functions
 // ti.Average(); // Won’t compile
 };

 int main()
 {
 TwoInt ti1(1, 2);
 TwoInt ti2(2, 4);
 FourInt fi1(10, 11, 12, 13);
 FourInt fi2(fi1);
 // We can call the Sub1 variants passing "TwoInt" objects as parameters
 // either by reference, by pointer, or by value
 cout << "Calling Sub1Ref() passing TwoInt" << endl;
 Sub1Ref(ti1);
 cout << "Calling Sub1Ptr() passing TwoInt" << endl;
 Sub1Ptr(&ti2);
 cout << "Calling Sub1Value() passing TwoInt" << endl;
 Sub1Value(ti1);

 // Note we can pass any subclass of TwoInt to the Sub1’s
 cout << "Calling Sub1Ref() passing FourInt" << endl;
 Sub1Ref(fi1);
 cout << "Calling Sub1Ptr() passing FourInt" << endl;
 Sub1Ptr(&fi2);
 // What happens when we pass a FourInt to Sub1Value?
 cout << "Calling Sub1Value() passing FourInt" << endl;
 Sub1Value(fi1);
 }


/*
 * Calling Sub1Ref() passing TwoInt
 * Hello from Sub1Ref()
 * a 1, b 2
 * Calling Sub1Ptr() passing TwoInt
 * Hello from Sub1Ptr()
 * a 2, b 4
 * Calling Sub1Value() passing TwoInt
 * Hello from Sub1Value()
 * a 1, b 2
 * Calling Sub1Ref() passing FourInt
 * Hello from Sub1Ref()
 * a 10, b 11
 * Calling Sub1Ptr() passing FourInt
 * Hello from Sub1Ptr()
 * a 10, b 11
 * Calling Sub1Value() passing FourInt
 * Hello from Sub1Value()
 * a 10, b 11
 */
