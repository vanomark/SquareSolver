#include "InOutput.h"

int scan_coeff(double *a_ptr, double *b_ptr, double *c_ptr)
{   
    ASSERT(a_ptr != NULL, "Pointer cannot be zero");
    ASSERT(b_ptr != NULL, "Pointer cannot be zero");
    ASSERT(c_ptr != NULL, "Pointer cannot be zero");

    int result = scanf("%lf %lf %lf", a_ptr, b_ptr, c_ptr);

    while (result != 3) {
        RED_PRINT("Error. Try again\n");

        clean_buffer();
        
        result = scanf("%lf %lf %lf", a_ptr, b_ptr, c_ptr);
    }

    return 0;
}

int clean_buffer(void) 
{
    char ch = (char) getchar();        
    while (ch != '\n' && ch != EOF) 
        ch = (char) getchar();
    
    return 0;
}

int print_roots(double x1, double x2, int root_count)
{   
    ASSERT(isfinite(x1),         "Not a number");
    ASSERT(isfinite(x2),         "Not a number");
    ASSERT(isfinite(root_count), "Not a number");

    switch(root_count) {
        
        case INFINITE_ROOTS: WHITE_PRINT("An infinite number of solutions\n");
                    break;      

        case NO_ROOTS:       WHITE_PRINT("There is no solution\n"); 
                    break;

        case ONE_ROOT:       WHITE_PRINT_ARG("The solution %.3lg\n", x1);
                    break;

        case TWO_ROOTS:      WHITE_PRINT_ARG("x1 = %.3lg, x2 = %.3lg\n", x1, x2);
                    break;

        default:             RED_PRINT("Error. Something's wrong\n");
    }

    return 0;
}
