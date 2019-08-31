
//
//  Matrix.h
//  RayTracer
//
//  Created by Megan Feichtel on 11/11/14.
//
//

#ifndef __RayTracer__Matrix__
#define __RayTracer__Matrix__


class Matrix {
public:
    double m[4][4];
    Matrix( void);
    Matrix(const Matrix& mat);
    ~Matrix(void);
    
    Matrix operator= (const Matrix& rhs);
    Matrix operator* (const Matrix& mat);
    Matrix operator/ (const double c);
    
    void set_identity( void);
    
    
    
    
};
#endif /* defined(__RayTracer__Matrix__) */
