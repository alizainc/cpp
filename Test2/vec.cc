 #include <iostream>
 #include <vector>

 using namespace std;

 int main()
 {
 vector<int> v;
 for (int i = 0; i < 100; ++i)
 {
 v.push_back(i);
 }
 cout << "v.size() " << v.size() << endl;
 cout << "sizeof(v) " << sizeof(v) << endl;
 }

