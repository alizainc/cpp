#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>
#include "complex.h"
using namespace std;

class Matrix;
ostream& operator<< (ostream &, const Matrix &);
Matrix operator*(Complex, Matrix &);
Matrix operator*(Matrix &, Complex);
Matrix operator*(Matrix &, Matrix &);

class Matrix {
  public:
    Matrix(); //default ctor
    Matrix(int r, int c); //row/col ctor
    Matrix(const Matrix& rhs); //copy ctor
    Matrix& operator=(const Matrix&); //assignment operator
    ~Matrix();
    Complex& operator()(int r, int c) const;
    Matrix operator+(Matrix m);
    Matrix operator-(Matrix m);
    Matrix operator~();
    friend ostream& operator<< (ostream &, const Matrix &);
    friend Matrix operator*(Complex, Matrix &);
    friend Matrix operator*(Matrix &, Complex);
    friend Matrix operator*(Matrix &, Matrix &);

    void transpose();
    void printMatrix();


    int getRow();
    int getCol();
  private:
    int row;
    int col;
    Complex *cnum;
  
};

#endif
