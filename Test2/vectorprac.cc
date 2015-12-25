#include <iostream>
#include <vector>

using namespace std;

int main()
{
  typedef vector<int> a0;
  a0 avec;
  avec.push_back(100);
  avec.push_back(10);
  avec.reserve(10);
  avec.push_back(5);
  cout << avec.size() << endl;

}
