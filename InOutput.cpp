#include "InOutput.h"

void scan_coeff(double *a, double *b, double *c)
{
    assert(a);
    assert(b);
    assert(c);

    int result = scanf("%lf %lf %lf", a, b, c);

    while (result != 3) {
        char ch = (char)getchar();
        HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
        
        SetConsoleTextAttribute(color, RED_SYMBOLS_BLACK_BACKGROUND);
        printf("Error. Try again\n");

        while (ch != '\n' && ch != EOF)
            ch = (char)getchar();
        
        SetConsoleTextAttribute(color, 3);
        result = scanf("%lf %lf %lf", a, b, c);
    }
}

void print_roots(double x1, double x2, int root_count)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, LIGHTWHITE_SYMBOLS_BLACK_BACKGROUND); 
    switch(root_count) {
        
        case INFINITE_ROOTS: printf("An infinite number of solutions\n");
                    break;

        case NO_ROOTS: printf("There is no solution\n"); 
                    break;

        case ONE_ROOT: printf("The solution %.3lg\n", x1);
                    break;

        case TWO_ROOTS: printf("x1 = %.3lg, x2 = %.3lg\n", x1, x2);
                    break;

        default: printf("Error. Something's wrong\n");
    }
    SetConsoleTextAttribute(color, DEFAULT_COLOR);
}
