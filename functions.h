#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>

double f(double *x);

double fA(double *x, double *h, double A);

double dfdx1(double *x);

double dfdx2(double *x);

double ScalarProduct(double *a, double *b, int n);

double Stop1(double *x, double *X, int n);

double Stop2(double *X, int n);

double Alpha(double *x, double *h); 

void DeltaA(double *delta_x, double *delta_y, double **A_matrix, double **delta_A, int n);

void GradientMethod(double *X, double *x, int n, double E);

void DFPMethod(double *X, double *x, int n, double E);

#endif