#include "SolveFile.h"

double abs(double x)
{
    return  (x > 0) ? x : -x;
}

int solve(struct equation *eq)
{
    assert(eq != NULL);

    if (abs(eq->a) > EPS)
        return solve_square_equation(eq->a, eq->b, eq->c, &(eq->x1), &eq->x2);
    else
        return solve_linear_equation(eq->b, eq->c, &eq->x1);
}

int solve_square_equation(double a, double b, double c, double* x1, double* x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);

    double discriminant = b*b - 4*a*c;

    if (discriminant < 0) {
        return 0;

    } else if (discriminant < EPS) {
        *x1 = -b/(2*a);
        return 1;

    } else {
        double square_root = sqrt(discriminant);

        *x1 = (-b - square_root)/(2*a);
        *x2 = (-b + square_root)/(2*a);
        return 2;
    }
}

int solve_linear_equation(double b, double c, double* x1)
{
    assert(x1 != NULL);

    if ((abs(b) > EPS && abs(c) < EPS) || (abs(b) > EPS && abs(c) > EPS)) {
        *x1 = -c/b;
        return 1;

    } else if(abs(b) < EPS && abs(c) < EPS) {
        return -1;

    } else if(abs(b) < EPS && abs(c) > EPS) {
        return 0;
    }
}
