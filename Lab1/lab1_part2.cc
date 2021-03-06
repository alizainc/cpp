#include <iostream>
#include <math.h>
using namespace std;

//beginning of the Pascaline class:
class Pascaline
{
    //private variables initialized:
    private:
        int register1;
        int register2;
        int registerResult;
    //public functions and constructor initialized:
    public:
        Pascaline();

        void setRegister1(int r1);
        void setRegister2(int r2);
        void setRegisterResult(int rr);
        int getRegister1();
        int getRegister2();
        int getRegisterResult();
        void clearRegisters();
        void addRegisters();
        void getInputValues();
        void displayOutputValue(); 
};//end of the class variable


//Constructor implementation here
Pascaline::Pascaline()
{
    register1 = 0;
    register2 = 0;
    registerResult = 0;
}

//member function to set register1
void Pascaline::setRegister1( int reg1)
{
    register1 = reg1;
}

//member function to set register2
void Pascaline::setRegister2( int reg2)
{
    register2 = reg2;
}

//member function to set registerResult
void Pascaline::setRegisterResult( int regr)
{
    registerResult = regr;
}

//member function to get the register1 value 
int Pascaline::getRegister1()
{
    return register1;
}

//member function to get the register2 value 
int Pascaline::getRegister2()
{
    return(register2);
}

//member function to get the resultRegister value
int Pascaline::getRegisterResult()
{
    return registerResult;
}

//Implements clearRegisters() here
//It sets the value of all the registers equal to zero
void Pascaline::clearRegisters()
{
    register1 = 0;
    register2 = 0;
    registerResult = 0;
}

//Implement addRegisters() here
//It will add register1 and register2 and put result in registerResult
void Pascaline::addRegisters()
{
    registerResult = register1 + register2;
}

//Implement getInputValues() here
//It will get the input data from the user
void Pascaline::getInputValues()
{
    cout << "Please input the value of register1: ";
    cin >> register1;
    cout << "Please input the value of register2: ";
    cin >> register2;
}

//Implement displayOutputValue() here
// It will display the output register and computation to the user
void Pascaline::displayOutputValue()
{
    cout << "***Pascaline Result: " << register1 << " + " << register2 << " = " << registerResult << endl;
}


int main()
{
    //Instantiated main object here
    Pascaline myPascaline;
    char input;
    //Now called the public member functions to use the object
    do {
        myPascaline.getInputValues();
        myPascaline.addRegisters();
        myPascaline.displayOutputValue();
        myPascaline.clearRegisters();

        cout << endl;
        cout << "Would you like to calculate again (Y or N)? ";
        cin >> input;
    } while (input == 'Y');
    return 0;
}
