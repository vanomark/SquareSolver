#ifndef SOLVE_FILE
#define SOLVE_FILE

#include <assert.h>
#include <math.h>
#include <stdio.h>

const double EPS = 1e-6;

struct equation {
    double a, b, c, x1, x2;
    int root_count;
};

#ifndef N_ROOTS_ENUM
#define N_ROOTS_ENUM
enum N_ROOTS {
    INFINITE_ROOTS = -1,
    NO_ROOTS       =  0,
    ONE_ROOT       =  1,
    TWO_ROOTS      =  2     
};
#endif

int    solve                 (struct equation *eq);
double abs                   (double x);
int    solve_square_equation (double a, double b, double c, double* x1, double* x2);
int    solve_linear_equation (double b, double c, double* x1);
int    is_zero               (double x);

#endif
