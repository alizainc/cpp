 #include <stdio.h>
 #include <iostream>

 using namespace std;

 // Define class A with a default constructor, non-default constructor,
 // and a "Copy Constructor".
 class A {
 public:
 A(); // Default constructor
 A(int); // Non-Default Constructor
 A(const A&); // A copy constructor is used by the compile whenever
 // a "copy" of an object is needed.
 ~A(); // And a destructor
 public:
 void operator=(const A& rhs); // Assignment operator
 void Print(); // Member function to print the x variable
 void PrintC() const; // Another print, the "const" keyword is a promise
 // that the PrintC member function will not change
 // any members in the object.
 int x; // Single data member
 public:
 // Demonstrate a function returning a reference
 int& X() { return x; }
 };

 A::A()
 : x(0)
 {
 cout << "Hello from A::A() Default constructor" << endl;
 }

 A::A(int i)
 : x(i)
 {
 cout << "Hello from A::A(int) constructor" << endl;
 }

 A::A(const A& a)
 : x(a.x)
 {
 cout << "Hello from A::A(const A&) constructor" << endl;
 }

 A::~A()
 {
 cout << "Hello from A::A destructor" << endl;
 }

 void A::operator=(const A& rhs)
 {
 x = rhs.x;

 cout << "Hello from A::operator=" << endl;
 }

 void A::Print()
 {
 cout << "A::Print(), x " << x << endl;
 }

 void A::PrintC() const
 {
 cout << "A::PrintC(), x " << x << endl;
 }

 // Define some subroutines to call with variations on A arguments.
 void PassAByValue(A a)
 {
 cout << "PassAByValue, a.x " << a.x << endl;
 a.x++; // Increment the x member of the passed object
 a.Print();
 a.PrintC();
 }

 void PassAByReference(A& a)
 {
 cout << "PassAByReference, a.x " << a.x << endl;
 a.x++; // Increment the x member of the passed object
 a.Print();
 a.PrintC();
 }

 void PassAByConstReference(const A& a)
 {
 cout << "PassAByReference, a.x " << a.x << endl;
 // a.x++; // Increment the x member of the passed object..won’t compile
 a.PrintC(); // Call the "const" print function...works perfectly
 //a.Print(); // Call to "non-const" print function fails!
 // Compiler error from above line. Why?
 // references.cc: In function ’void PassAByConstReference(const A&)’:
 // references.cc:90: error: passing ’const A’ as ’this’ argument of
 // ’void A::Print()’ discards qualifiers
 }

 void PassAByPointer(A* a)
 {
 cout << "PassAByPointer, a->x " << a->x << endl;
 a->x++;
 a->Print();
 a->PrintC();
 }


 int main()
 {
 cout << "Creating a0"; getchar();
 A a0; // Default constructor called



 cout << "Creating a1"; getchar();
 A a1(1); // Constructor with integer argument

 cout << "Creating a2"; getchar();
 A a2(a0); // Copy constructor

 cout << "Creating a3"; getchar();
 A a3 = a0; // Which constructor?

 cout << "Assigning a3 = a1"; getchar();
    a3  = a1; // Which constructor, if any?

 // Call some of the "A" subroutines
 cout << "PassAByValue(a1)"; getchar();
 PassAByValue(a1); // Which constructor, if any?
 cout << "After PassAByValue(a1)" << endl;
 a1.Print();

 cout << "PassAByReference(a1)"; getchar();
 PassAByReference(a1); // Which constructor, if any?
 cout << "After PassAByReference(a1)" << endl;
 a1.Print();

 cout << "PassAByConst(a1)"; getchar();
 PassAByConstReference(a1); // Which constructor, if any?
 cout << "After PassAByConstReference(a1)" << endl;
 a1.Print();

 cout << "PassAByPointer(&a1)"; getchar();
 PassAByPointer(&a1); // Which constructor, if any?
 cout << "After PassAByPointer(a1)" << endl;
 a1.Print();

 // Use the X() member function to get a reference to x
 cout << "a1.X() = 10"; getchar();
 a1.X() = 10;
 a1.Print();

 cout << "PassAByConstReference"; getchar();
 PassAByConstReference(20);
 // Why does the above compile? What does it do?
 return 0;
 }

