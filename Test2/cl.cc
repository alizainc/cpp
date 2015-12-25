 // Code for ECE3090 midterm, QUESTION 3 - Object Cloning
 #include <iostream>
 using namespace std;

 class Base {
 public:
 virtual void Hello() { cout << "Hello from Base" << endl;}
 virtual Base* Clone() { return new Base(*this);}
 };

 // A derives from Base
 class A : public Base {
 public:
 virtual void Hello() { cout << "Hello from A" << endl;}
 virtual Base* Clone() { return new A(*this);}
 };

 // B derives from Base
 class B : public Base {
 public:
 virtual void Hello() { cout << "Hello from B" << endl;}
 };

 // C derives from B
 class C : public B
 {
 public:
 virtual void Hello() { cout << "Hello from C" << endl;}
 virtual Base* Clone() { return new C(*this);}
 };

 void Sub1(Base& p)
 {
 Base* newBase = p.Clone();
 newBase->Hello();
 }

 int main()
 {
 Base base;
 A a;
 B b;
 C c;
 Sub1(base);
 Sub1(a);
 Sub1(b);
 Sub1(c);
 Base d(*a.Clone()); // Copy constructor
 d.Hello();
 }

