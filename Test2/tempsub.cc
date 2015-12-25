 // Define a template subroutine to compute the sort a collection of elements
 // specified by two iterators
 #include <algorithm>
 using namespace std;

 template <class T>
 void Sort(T b, T e)
 { // This sort is inefficient, and used for illustrative purposes only
 while(b != e)
 {
 T i = b;
 while(i != e)
 {
 if (*i < *b)
 { // Need to swap. This iter swap is defined in "algorithm"
 iter_swap(i, b); // Swap the two values
 }
 ++i;
 }
 ++b;
 }
 }

 class A {
 public:
 A() : a(0) {};
 A(int a0) : a(a0) {};
 bool operator<(const A& rhs) { return a < rhs.a; } // Less-than operator
 public:
 int a;
 };

 class B
 {
 public:
 B() : b(0) {};
 B(int b0) : b(b0) {};
 bool operator>(const B& rhs) { return b > rhs.b; } // Greater-than operator
 public:
 int b;
 };

 int main()
 {
 char s[] = "This is a test";
 A a1[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
 B b1[10] = {0, 1, 7, 6, 5, 4, 6, 7, 8, 9};

 // Now call the Sort routine with differing parameters
 Sort(s, s + 14);
 Sort(&a1[0], &a1[10]);
 //Sort(&b1[0], &b1[10]);
 //Sort(&a1[10], &b1[10]);
 }
