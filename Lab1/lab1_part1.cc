#include <iostream>
using namespace std;

long int fact(int n)
{
    if(n==0)
    return 1;
    else
    {
        long int prod = 1;
        for (int i = 1; i <= n; i++)
        {
            prod = prod * i;
        }
    return prod;
    }
}
int main()
{
    int num;
    cout << "Please input the size of the triangle: ";
    cin >> num;
    
    for(int i = 0;  i <= num;  i++)
    {
        cout << "n= " << i << ": ";
        for(int j = 0; j <= i; j++)
        {
            long int calc = fact(i)/ (fact(j)*fact(i-j));
            cout << calc << "  ";
        }
    cout << endl;
    }
}
