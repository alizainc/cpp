 // Code for ECE3090 midterm, Constructors and Destructors question

 class A {
 public:
 A(); // Default constructor
 A(int); // int Constructor
 A(const A&); // Copy constructor
 ~A(); // Destructor
 A operator+(A rhs) const; // Addition operator
 public:
 int x; // Single data member
 };

 A A::operator+(A rhs) const
 {
 A r(x + rhs.x);
 return r;
 }

 class B {
 public:
 B(); // Default Constructor
 B(int); // int Constructor
 B(const B&); // Copy constructor
 ~B(); // Destructor
 B operator+(const B& rhs) const; // Addition operator
 public:
 int x; // Single data member
 };

 B B::operator+(const B& rhs) const
 {
 return B(x + rhs.x);
 }

 void Sub1(const A& a)
 {
 A a2(a + a);
 }

 void Sub2(B b)
 {
 B b2(b + b);
 }

 int main()
 {
 A a(1);
 B b(2);

 Sub1(a);
 Sub2(b);
 }
