#include "SolveFile.h"

int is_zero(double x) 
{
    return fabs(x) < EPS; 
}

int solve_equation(struct equation *eq)
{   
    ASSERT(eq != NULL, "Pointer cannot be zero");

    if (!is_zero(eq->a)) 
        eq->root_count = solve_square_equation(eq->a, eq->b, eq->c, &(eq->x1), &eq->x2);
    else
        eq->root_count = solve_linear_equation(eq->b, eq->c, &eq->x1);
    
    return 0;
}

enum N_ROOTS solve_square_equation(double a, double b, double c, double* x1_ptr, double* x2_ptr)
{   
    ASSERT(x1_ptr != NULL, "Pointer cannot be zero"); 
    ASSERT(x2_ptr != NULL, "Pointer cannot be zero"); 
    ASSERT(isfinite(*x1_ptr), "Not a number");
    ASSERT(isfinite(*x2_ptr), "Not a number");
    ASSERT(isfinite(a), "Coefficient cannot be NAN");
    ASSERT(isfinite(b), "Coefficient cannot be NAN");
    ASSERT(isfinite(c), "Coefficient cannot be NAN");

    double discriminant = b*b - 4*a*c;

    if (discriminant < 0) {

        return NO_ROOTS;

    } else if (is_zero(discriminant)) {
        *x1_ptr = -b/(2*a);
        
        return ONE_ROOT;

    } else {
        double square_root = sqrt(discriminant);

        *x1_ptr = (-b - square_root)/(2*a);
        *x2_ptr = (-b + square_root)/(2*a);
      
        return TWO_ROOTS;  
    }
}

enum N_ROOTS solve_linear_equation(double b, double c, double* x1_ptr)
{
    ASSERT(x1_ptr != NULL, "Pointer cannot be zero");
    ASSERT(isfinite(*x1_ptr), "Not a number");
    ASSERT(isfinite(b), "Coefficient cannot be NAN");
    ASSERT(isfinite(c), "Coefficient cannot be NAN");

    if ((!is_zero(b) && is_zero(c)) || (!is_zero(b)  && !is_zero(c))) {
        *x1_ptr = -c/b;

        return ONE_ROOT;

    } else if(is_zero(b) && is_zero(c)) {

        return INFINITE_ROOTS;

    } else if(is_zero(b) && !is_zero(c)) {
        
        return NO_ROOTS;
    }

    return ERROR_ROOTS;
}