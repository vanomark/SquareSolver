#ifndef SOLVE_FILE
#define SOLVE_FILE

#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "AssertFile.h"
#include "ColorPrintFile.h"

const double EPS = 1e-6;

enum N_ROOTS {
    INFINITE_ROOTS = -1, ///< infinite number of solutions
    NO_ROOTS       =  0, ///< no roots (D < 0 or bad equation)
    ONE_ROOT       =  1, ///< one root (D == 0 or linear case)
    TWO_ROOTS      =  2, ///< two roots (D > 0)
    ERROR_ROOTS    =  666, ///< happens if unknown equation type
};

struct equation {
    double a, b, c, x1, x2;
    enum N_ROOTS root_count;
};

int               solve_equation        (struct equation *eq);
enum   N_ROOTS    solve_square_equation (double a, double b, double c, double* x1, double* x2);
enum   N_ROOTS    solve_linear_equation (double b, double c, double* x1);
int               is_zero               (double x);

#endif //SOLVE_FILE
