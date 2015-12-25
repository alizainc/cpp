#include <iostream>
 using namespace std;
 class Base
 { // Define a base class
 public:
 virtual void Sub1() = 0;
 void Sub2();
virtual void Sub3();
virtual void Sub4();
 };

 class A : public Base
 { // Class A derives from Base
 public:
 void Sub1();
 void Sub2();
 void Sub4();
 };

 class B : public Base
 {// Class B derives from Base
 public:
 void Sub1();
 void Sub2();
 void Sub3();
 };

 // Base Class Methods
 void Base::Sub2(){ cout << "Hello from Base::Sub2()" << endl;}

 void Base::Sub3()
 {
 cout << "Hello from Base::Sub3()" << endl;
 Sub1(); // DON’T MISS THIS CALL IN YOUR ANSWER
 Sub4(); // DON’T MISS THIS CALL IN YOUR ANSWER
 }

 void Base::Sub4(){ cout << "Hello from Base::Sub4()" << endl;}

 // Class A Methods
 void A::Sub1() { cout << "Hello from A:Sub1()" << endl; }
 void A::Sub2() { cout << "Hello from A:Sub2()" << endl; }
 void A::Sub4() { cout << "Hello from A:Sub4()" << endl; }

 // Class B Methods
 void B::Sub1() { cout << "Hello from B:Sub1()" << endl; }
 void B::Sub2() { cout << "Hello from B:Sub2()" << endl; }
 void B::Sub3() { cout << "Hello from B:Sub3()" << endl; }

 // A Helper Subroutine
 void SubP(Base* x)
 {
 x->Sub1();
 x->Sub3();
 x->Sub4();
 } // CONTINUED ON NEXT PAGE

 // Another helper
 void SubR(Base& x)
 {
 x.Sub2();
 x.Sub3();
 x.Sub4();
 }
 // Another Helper
 void SubV(B b0)
 {
 b0.Sub1();
 b0.Sub2();
 }

 int main()
 {
 A a;
 B b;
 SubP(&a);
 SubR(b);
 SubV(b);
 }


/*
 * Hello from A:Sub1()
 * Hello from Base::Sub3()
 * Hello from A:Sub1()
 * Hello from A:Sub4()
 * Hello from A:Sub4()
 * Hello from Base::Sub2()
 * Hello from B:Sub3()
 * Hello from Base::Sub4()
 * Hello from B:Sub1()
 * Hello from B:Sub2()
 */
