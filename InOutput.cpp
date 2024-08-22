#include "InOutput.h"

void scan_coeff(double *a, double *b, double *c)
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    int result = scanf("%lf %lf %lf", a, b, c);

    while (result != 3) {
        char ch = getchar();

        HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(color, 4);

        printf("Error. Try again\n");


        while (ch != '\n' && ch != EOF)
            ch = getchar();
        SetConsoleTextAttribute(color, 6);
        result = scanf("%lf %lf %lf", a, b, c);
    }
}

void print_roots(double x1, double x2, int root_count)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 15);
    switch(root_count) {

        case INFINITE_ROOTS: printf("An infinite number of solutions\n");
                    break;

        case 0: printf("There is no solution\n");
                    break;

        case 1: printf("The solution %.3lg\n", x1);
                    break;

        case 2: printf("Solutions %.3lg %.3lg\n", x1, x2);
                    break;

        default: printf("Error. Something's wrong\n");
    }
    SetConsoleTextAttribute(color, 7);
}
