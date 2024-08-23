#include "SolveFile.h"

int is_zero(double x) 
{
    return  (fabs(x) < EPS) ? 1 : 0;
}

int solve(struct equation *eq)
{
    assert(eq);

    if (!is_zero(eq->a)) 
        return solve_square_equation(eq->a, eq->b, eq->c, &(eq->x1), &eq->x2);
    else
        return solve_linear_equation(eq->b, eq->c, &eq->x1);
}

int solve_square_equation(double a, double b, double c, double* x1, double* x2)
{
    assert(x1); 
    assert(x2);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    double discriminant = b*b - 4*a*c;

    if (discriminant < 0) {
        return NO_ROOTS;

    } else if (is_zero(discriminant)) {
        *x1 = -b/(2*a);
        return ONE_ROOT;

    } else {
        double square_root = sqrt(discriminant);

        *x1 = (-b - square_root)/(2*a);
        *x2 = (-b + square_root)/(2*a);
        return TWO_ROOTS;
    }
}

int solve_linear_equation(double b, double c, double* x1)
{
    assert(x1);
    assert(isfinite(b));
    assert(isfinite(c));

    if ((!is_zero(b) && is_zero(c)) || (!is_zero(b)  && !is_zero(c))) {
        *x1 = -c/b;
        return ONE_ROOT;

    } else if(is_zero(b) && is_zero(c)) {
        return INFINITE_ROOTS;

    } else if(is_zero(b) && !is_zero(c)) {
        return NO_ROOTS;
    }
    return 666;
}