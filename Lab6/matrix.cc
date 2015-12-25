#include <iostream>
#include <string>
#include <iomanip>

#include <math.h>

#include "matrix.h"
//#include "complex.h"
//#include "string-parse.h"

using namespace std;

// Default ctor

Matrix::Matrix() {
  row = 0;
  col = 0;
  cnum = NULL;
}

// row/column ctor

Matrix::Matrix(int r, int c) {
  row = r;
  col = c;
  cnum = new Complex[row*col];
}

//copy ctor

Matrix::Matrix(const Matrix& rhs) {
  row = rhs.row;
  col = rhs.col;
  cnum = new Complex[row*col];
  for (int i = 1; i <= row; i++) {
    for (int j = 1; j <= col; j++) {
      (*this)(i,j) = rhs(i,j);
//(*this)(i,j).Print();
//rhs(i,j).Print();
      //cnum[(i-1)*row+(j-1)] =  rhs.cnum[(i-1)*row+(j-1)];
//      this(i,j) rhs(i,j);
    }
  }
}

// Destructor

Matrix::~Matrix() {
  delete [] cnum;
}

//assignment operator

Matrix& Matrix::operator=(const Matrix& rhs) {
  if (this == &rhs) {
    return *this;
  }
  delete [] cnum;
  row = rhs.row;
  col = rhs.col;
  cnum = new Complex[row*col];
  for (int i = 1; i <= row; i++) {
    for (int j = 1; j <= col; j++) {
      cnum[(i-1)*row+(j-1)] =  rhs.cnum[(i-1)*row+(j-1)];
    }
  }
  return *this;
}

int Matrix::getRow() {
  return row;
}

int Matrix::getCol() {
  return col;
}

Complex& Matrix::operator()(int x, int y) const {
  int realx = x-1;
  int realy = y-1;
  return cnum[(realx*row) + realy];
}


void Matrix::transpose() {
/*  for (int i = 1; i <= row; i++) {
    for(int j = 1; j <= col; j++) {
      Complex z = (*this)(i,j);
      (*this)(i,j) = (*this)(j,i);
      (*this)(j,i) = z;
//(*this)(i,j).Print();
//(*this)(j,i).Print();
    }
  }*/
  Matrix newarr((*this));
  //delete [] cnum;
  //cnum = new Complex[row*col];
  for (int i = 1; i <= row; i++) {
    for(int j = 1; j<= col; j++) {
      //cnum[(j-1)*row+(i-1)] =  newarr.cnum[(i-1)*row+(j-1)];
      (*this)(i,j) = newarr(j,i);
    }
  }
  int temp = row;
  row = col;
  col = temp;
  //delete [] newarr.cnum;
}

void Matrix::printMatrix() {
  if (cnum == NULL || row == 0 || col == 0) {
    cout << "Matrix Mismatch Error!" << endl;
    cout << "This matrix has zero elements" << endl;
  }
  else {
  for (int i = 1; i <= row; i++) {
    for (int j = 1; j <= col; j++) {
      (*this)(i,j).Print();
    }
    cout << endl;
  } //end of for (i)
  } // end of else
} // end of printMatrix()

Matrix Matrix::operator+(Matrix m) {
  if (row != m.row || col != m.col) {
    Matrix mm;
    return mm;
  }
  Complex z;
  Matrix finalmat(row, col);
  if ((row == m.row) && (col == m.col)) {
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        z = cnum[i*row+j] + m.cnum[i*row+j];
        finalmat(i+1,j+1) = z;
      }
    }
    return finalmat;
  }
  return finalmat;
}

Matrix Matrix::operator-(Matrix m) {
  if (row != m.row || col != m.col) {
    Matrix mm1;
    return mm1;
  }
  Complex z;
  Matrix finalmat1(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      z = cnum[i*row+j] - m.cnum[i*row+j];
      finalmat1(i+1, j+1) = z;
    }
  }
  return finalmat1;
}

Matrix Matrix::operator~() {
  Matrix newmat(col, row);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      newmat.cnum[(j*row)+i] = cnum[(i*row)+j];
    }
  }
  return newmat;
}

ostream& operator<< (ostream & io, const Matrix & m) {
  if (m.cnum == NULL || m.row == 0 || m.col == 0) {
    io << "Matrix Mismatch Error!" << endl;
    io << "This matrix has zero elements" << endl;
  }
  else {
  for (int i = 1; i <= m.row; i++) {
    for (int j = 1; j <= m.col; j++) {
   if(m(i,j).getIsNum())
    {
    if(m(i,j).getImag() != 0 && m(i,j).getReal()!= 0)
    {
    io << setw(5) << m(i,j).getReal() << " +" << setw(2) << m(i,j).getImag() << "j";
    }
    else if (m(i,j).getImag() == 0)
    {
    io << setw(10) << m(i,j).getReal();
    }
    else if (m(i,j).getReal() == 0)
    {
    io << setw(10) << m(i,j).getImag() << "j";
    }
    }
   else
     {
       io << setw(10) << "NaN";
     }

    } //end of for (j)
    io << endl;
  } //end of for (i)
  } // end of else
  return io;
}

Matrix operator*(Complex c, Matrix & m) {
  Matrix finalmat(m.row, m.col);
  for (int i = 1; i <= m.row; i++) {
    for (int j = 1; j <= m.col; j++) {
      Complex z = c*m(i,j);
      finalmat(i,j) = z;
    }
  }
  return finalmat;
}

Matrix operator*(Matrix & m, Complex c) {
  Matrix finalmat;
  finalmat = c*m;
  return finalmat;
}

Matrix operator*(Matrix & m1, Matrix & m2) {
  Matrix res;
  if (m1.col != m2.row) {
    return res;
  }
  else {
    res = Matrix(m1.row, m2.col);
    for (int i = 1; i <= m1.row; i++) {
    for (int j = 1; j <= m1.col; j++) {
      Complex z;
      for(int k = 1; k <= m1.col; k++) {
        z = z + (m1(i,k) * m2(k,j));
      }//end of for(k)
      res(i,j) = z;
    }//end of for(j)
    }//end of for(i)

  }//end of else

  return res;
}//end of function
