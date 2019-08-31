//
//  Matrix.cpp
//  RayTracer
//
//  Created by Megan Feichtel on 11/11/14.
//
//

#include "Matrix.h"
#include <stdio.h>


//constructor for image identity matrix
Matrix::Matrix( void){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (i==j)
                m[i][j] = 1.0;
            else
                m[i][j] = 0.0;
        }
    }
}

//copy constructor
Matrix::Matrix(const Matrix& mat){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
                m[i][j] = mat.m[i][j];
        }
    }
}

//destructor
Matrix::~Matrix(void){
    
}

//assignment operator
Matrix Matrix::operator= (const Matrix& rhs){
    if (this == &rhs) {
        return (*this);
    }
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            m[i][j] = rhs.m[i][j];
        }
    }
    return (*this);
}


//matrix multiplication
Matrix Matrix::operator* (const Matrix& mat){
    Matrix 	prod;
    
    for (int col = 0; col < 4; col++)
        for (int row = 0; row < 4; row++) {
            double sum = 0.0;
            
            for (int k = 0; k < 4; k++)
                sum += m[row][k] * mat.m[k][col];
            
            prod.m[row][col] = sum;
        }
    
    return (prod);
}

//division by a double
Matrix Matrix::operator/ (const double c) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            m[i][j] = m[i][j] / c;
    
    return (*this);
}


//make matrix identity
void Matrix::set_identity( void){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (i==j)
                m[i][j] = 1.0;
            else
                m[i][j] = 0.0;
        }
    }
}




