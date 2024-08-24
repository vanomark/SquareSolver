#include "InOutput.h"

void scan_coeff(double *a, double *b, double *c)
{
    assert(a);
    assert(b);
    assert(c);

    int result = scanf("%lf %lf %lf", a, b, c);

    while (result != 3) {
        char ch = (char)getchar();        
        
        printf("%sError. Try again\n%s", 
                RED_SYMBOLS, 
                CYAN_SYMBOLS);

        while (ch != '\n' && ch != EOF)
            ch = (char)getchar();
        
        result = scanf("%lf %lf %lf", a, b, c);
    }
}

void print_roots(double x1, double x2, int root_count)
{
    switch(root_count) {
        
        case INFINITE_ROOTS: printf("%sAn infinite number of solutions\n%s", 
                                    LIGHTWHITE_SYMBOLS,
                                    DEFAULT_COLOR);
                    break;

        case NO_ROOTS: printf("%sThere is no solution\n%s", 
                            LIGHTWHITE_SYMBOLS, 
                            DEFAULT_COLOR); 
                    break;

        case ONE_ROOT: printf("%sThe solution %.3lg\n%s",  
                            LIGHTWHITE_SYMBOLS, x1,
                            DEFAULT_COLOR);
                    break;

        case TWO_ROOTS: printf("%sx1 = %.3lg, x2 = %.3lg\n%s", 
                            LIGHTWHITE_SYMBOLS, x1, x2, 
                            DEFAULT_COLOR);
                    break;

        default: printf("%sError. Something's wrong\n%s", 
                        RED_SYMBOLS, 
                        DEFAULT_COLOR);
    }
}
