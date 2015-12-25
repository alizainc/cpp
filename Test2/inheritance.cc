 #include <iostream>

 using namespace std;

 class Base
 { // Define a base class
 public:
 virtual void Sub1() = 0;
 virtual void Sub2();
 virtual void Sub3();
 void Sub4();
 };
 class A : public Base
 { // Class A derives from Base
 public:
 void Sub2();
 void Sub4();
 };

 class B : public A
 {// Class B derives from A
 public:
 virtual void Sub1();
 void Sub2();
 };

 class C : public Base
 { // Class C derives from Base
 public:
 virtual void Sub1();
 virtual void Sub4();
 };

 // Base Class Methods
 void Base::Sub2(){ cout << "Hello from Base::Sub2()" << endl;}
 void Base::Sub3()
 {
 cout << "Hello from Base::Sub3()" << endl;
 Sub1(); // DON’T MISS THIS CALL IN YOUR ANSWER
 }
 void Base::Sub4(){ cout << "Hello from Base::Sub4()" << endl;}

 // Class A Methods
 void A::Sub2() { cout << "Hello from A:Sub2()" << endl; }
 void A::Sub4() { cout << "Hello from A:Sub4()" << endl; }
 // Class B Methods
 void B::Sub1() { cout << "Hello from B:Sub1()" << endl; }
 void B::Sub2() { cout << "Hello from B:Sub2()" << endl; }
 // Class C Methods
 void C::Sub1() { cout << "Hello from C:Sub1()" << endl; }
 void C::Sub4() { cout << "Hello from C:Sub2()" << endl; }


 // A Helper Subroutine
 void Sub(Base& x)
 {

 x.Sub1();
 x.Sub2();
 x.Sub4();
 }

 void AnotherSub(A& a)
 {
 a.Sub1();
 a.Sub2();
 a.Sub4();
 }

 int main()
 {
 //A a; won’t compile
 B b;
 C c;
 Sub(b);
 Sub(c);
 AnotherSub(b);
 }

