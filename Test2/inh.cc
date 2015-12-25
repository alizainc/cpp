 // Inheritance program for ECE2036 final exam
 //ECE2036, Fall 2012
 #include <iostream>
 class Base {
 public:
 virtual void Func1() const = 0;
 void Func2() const;
 virtual void Func3() const;
 };

 class Sub1 : public Base {
 public:
 void Func1() const;
 void Func2() const;
 };


 class Sub2 : public Base {
 public:
 void Func2() const;
 void Func3() const;
 };

 class Sub3 : public Sub1 {
 public:
 void Func1() const;
 void Func2() const;
 };

 class Sub4 : public Sub2 {
 public:
 void Func1() const;
 };
 // Implementations
 // Base
 void Base::Func2() const
 {
 std::cout << "Hello from Base::Func2()" << std::endl;
 };
 void Base::Func3() const
 {
 std::cout << "Hello from Base::Func3()" << std::endl;
 };
 // Sub1
 void Sub1::Func1() const
 {
 std::cout << "Hello from Sub1::Func1()" << std::endl;
 };
 void Sub1::Func2() const
 {
 std::cout << "Hello from Sub1::Func2()" << std::endl;
 };
 // Sub2
 void Sub2::Func2() const
 {
 std::cout << "Hello from Sub2::Func2()" << std::endl;
 };
 void Sub2::Func3() const
 {
 std::cout << "Hello from Sub2::Func3()" << std::endl;
 };
 // Sub3
 void Sub3::Func1() const
 {
 std::cout << "Hello from Sub3::Func1()" << std::endl;
 };
 void Sub3::Func2() const
 {
 std::cout << "Hello from Sub3::Func2()" << std::endl;
 };
 // Sub4
 void Sub4::Func1() const
 {
 std::cout << "Hello from Sub4::Func1()" << std::endl;
 };
// Functions for testing
 void BaseRef(const Base& b)
 {
 b.Func2();
 b.Func1();
 }

 void Sub1Val(Sub1 s1)
 {
 s1.Func1();
 s1.Func2();
 s1.Func3();
 }

 void Sub2Ref(const Sub2& s2)
 {
 s2.Func1();
 s2.Func2();
 s2.Func3();
 }


 int main()
 {
 Sub1 s1;
 Sub3 s3;
 Sub4 s4;
 BaseRef(s1);
 BaseRef(s3);
 Sub1Val(s3);
 Sub2Ref(s4);
 }

