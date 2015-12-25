 #include <iostream>
 using namespace std;

 int Sub2( int arg0, int arg1)
 { // Subroutine with two args; does some manipulation of the arguments
 // and them multiplies the results and returns the product.
 return ++arg0 * arg1++;
 }


 int Sub1( int* pInt0, int* pInt1)
 {
 return (*pInt0++) * (*pInt1++);
 }


 int main()
 {
 // Two arrays for manipulating
 int A[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
 int B[10];

 int* pAzero = A;
 int* pAone = &A[1];
 cout << "*pAzero is " << *pAzero << endl;
 cout << "*pAone is " << *pAone << endl;

 int sub1Return = Sub1(pAzero++, pAone++);
 cout << "Sub1 Return is " << sub1Return << endl;
 cout << "*pAzero is " << *pAzero << endl;
 cout << "*pAone is " << *pAone << endl;
 int sub2Return = Sub2(A[1], A[2]);
 cout << "Sub2 Return is " << sub2Return << endl;
 cout << "A[1] is " << A[1] << endl;
 cout << "A[2] is " << A[2] << endl;
 int* pA = A;
 int* pB = B;
 *pB++ = *pA++;
 *pB++ = pA[2];
 cout << "B[0] is " << B[0] << endl;
 cout << "B[1] is " << B[1] << endl;
}
