#ifndef SOLVE_FILE
#define SOLVE_FILE

#include <assert.h>
#include <stdio.h>
#include <math.h>

const double EPS = 1e-6;

struct equation {
    double a, b, c, x1, x2;
    int root_count;
};

int    solve                 (struct equation *eq);
double abs                   (double x);
int    solve_square_equation (double a, double b, double c, double* x1, double* x2);
int    solve_linear_equation (double b, double c, double* x1);

#endif
