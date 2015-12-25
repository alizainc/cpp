//
// EC20360 Program 2 - Complex Number Calculator
// Alizain Charania
//

#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "complex.h"
#include "string-parse.h"

using namespace std;

int main()
{
  // Add any variables you might need here
  Complex result;
  Complex a;
  Complex b;
  while(true)
    {
      string st = GetStringFromKeyboard(); // Get the  next input line
      // The types StringArray_t and CharArray_t are defined in string-parse.h
      // They are fixed length arrays of 3 elements.
      // The StringParse function returns an integer indicating how many
      // of the three are actually used.
      StringArray_t operands; // array of operands
      CharArray_t   delims;   // array of delimiters
      int count = StringParse(st, "+-*/", operands, delims);
      if (count == 0) break; // All done

      if (count == 1)
      {
        result = Complex(operands[0]);
        result.Print();
      }
      if (count == 2)
     {
      if (operands[0].empty())
      {
        a = Complex(operands[1]);
        if(delims[0] == '+')
        result = result + a;
        else if(delims[0] == '-')
        result = result - a;
        else if(delims[0] == '*')
        result = result * a;
        else if(delims[0] =='/')
        result = result / a;

        result.Print();
      }
      else
      {
        a = Complex(operands[1]);
        result = Complex(operands[0]);
        if(delims[0] == '+')
        result = result + a;
        else if(delims[0] == '-')
        result = result-a;
        else if(delims[0] == '*')
        result =  result*a;
        else if(delims[0] =='/')
        result = result/a;

        result.Print();
      }
     }

      // Debug code follows.  Remove this after testing
/*     for (int i = 0; i < count; ++i)
        {
          cout << "op[" << i << "] ";

          // Note use of the "empty()" method.  You will need this in your code
          // Also note we can index the strings with the indexing operator []
          // For example, st[0] would be the zeroth character of the string st
          if (operands[i].empty())
            {
              cout << "(Empty string)";
            }
          else
            {
              cout << operands[i];
            }
          cout << " delims[" << i << "] ";
          if (delims[i] == 0)
            {
              cout << "(zero character)" << endl;
            }
          else
            {
              cout << delims[i] << endl;
            }
        }*/
      // End of debug code.  Remove all the above debug

      // Now perform the calculation
      // YOUR CODE HERE

  }
  return 0;  // Successful completion of main()
}

