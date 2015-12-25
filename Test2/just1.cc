 #include <iostream>
 #include <iomanip>
 using namespace std;
 int main()
 {
 int intValue; // notice the use of camel style
 float floatValue;
 cout << "Input an integer: ";
 cin >> intValue;
 //now output the number
 cout << "The value you entered in hex is: " << hex << intValue << endl;
 cout << dec; // remove temporarily to show it is sticky
 cout << " The value in decimal is: " << intValue << endl;
 cout << "Input a float number: ";
 cin >> floatValue;
 cout << setprecision(2);
 cout << scientific << "The float value with scientific: " << floatValue << endl;
 cout << fixed << "The float value with fixed is: " << floatValue << endl;
 return 0;
 }
