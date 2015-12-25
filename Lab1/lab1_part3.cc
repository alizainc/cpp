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



//beginning of the LeibnizWheel class:
class LeibnizWheel
{
    //private variables initialized:
    private:
        int register1;
        int register2;
        int registerResult;
    //public functions and constructor initialized:
    public:
        LeibnizWheel();

        void setRegister1(int r1);
        void setRegister2(int r2);
        void setRegisterResult(int rr);
        int getRegister1();
        int getRegister2();
        int getRegisterResult();
        void clearRegisters();
        void multiplyRegisters();
        void getInputValues();
        void displayOutputValue(); 
};//end of the class variable


//Constructor implementation here
LeibnizWheel::LeibnizWheel()
{
    register1 = 0;
    register2 = 0;
    registerResult = 0;
}

//member function to set register1
void LeibnizWheel::setRegister1( int reg1)
{
    register1 = reg1;
}

//member function to set register2
void LeibnizWheel::setRegister2( int reg2)
{
    register2 = reg2;
}

//member function to set registerResult
void LeibnizWheel::setRegisterResult( int regr)
{
    registerResult = regr;
}

//member function to get the register1 value 
int LeibnizWheel::getRegister1()
{
    return register1;
}

//member function to get the register2 value 
int LeibnizWheel::getRegister2()
{
    return(register2);
}

//member function to get the resultRegister value
int LeibnizWheel::getRegisterResult()
{
    return registerResult;
}

//Implements clearRegisters() here
//It sets the value of all the registers equal to zero
void LeibnizWheel::clearRegisters()
{
    register1 = 0;
    register2 = 0;
    registerResult = 0;
}

//Implement addRegisters() here
//It will add register1 and register2 and put result in registerResult
void LeibnizWheel::multiplyRegisters()
{
    registerResult = register1 * register2;
}

//Implement getInputValues() here
//It will get the input data from the user
void LeibnizWheel::getInputValues()
{
    cout << "Please input the value of register1: ";
    cin >> register1;
    cout << "Please input the value of register2: ";
    cin >> register2;
}

//Implement displayOutputValue() here
// It will display the output register and computation to the user
void LeibnizWheel::displayOutputValue()
{
    cout << "***Leibniz Wheel Result: " << register1 << " * " << register2 << " = " << registerResult << endl;
}

int main()
{
    char letter;
    char input;
    do {
        cout << "Would you like to use the Leibniz Wheel (enter 'L') or the Pascaline (enter 'P')?";
        cin >> letter;
        if (letter == 'P')
        {
            //Instantiated main object here
            Pascaline myPascaline;
            //Now called the public member functions to use the object
            
            myPascaline.getInputValues();
            myPascaline.addRegisters();
            myPascaline.displayOutputValue();
            myPascaline.clearRegisters();
        }
        else if(letter == 'L')
        {
            //Instantiated main object here
            LeibnizWheel myLeibnizWheel;
            //Now called the public member functions to use the object
            myLeibnizWheel.getInputValues();
            myLeibnizWheel.multiplyRegisters();
            myLeibnizWheel.displayOutputValue();
            myLeibnizWheel.clearRegisters();
        }
        else
        {
            cout << "I am not sure what you want!" << endl;
        }
         cout << endl;
         cout << "Would you like to calculate again (Y or N)? ";
         cin >> input;
    } while (input == 'Y');
    return 0;
}
