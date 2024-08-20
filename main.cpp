#include <stdio.h>
#include <math.h>

void scan_coeff(double *a, double *b, double *c);
void print_roots(double a, double b, double c);
int solve_square_equation(double a, double b, double c, double* x1, double* x2);
int solve_linear_equation(double b, double c, double* x1);
void print_roots(double x1, double x2, int root_count);

const double epsilon = 1e-6;
const int INF = -1;

int main()
{
    printf("An equation of the form ax^2 + bx + c = 0\n");
    printf("Enter a, b, c separated by a space\n");

    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int root_count = 0;

    scan_coeff(&a, &b, &c);
    if (a)
        root_count = solve_square_equation(a, b, c, &x1, &x2);
    else
        root_count = solve_linear_equation(b, c, &x1);
    print_roots(x1, x2, root_count);
}


void scan_coeff(double *a, double *b, double *c)
{
    int result = scanf("%lf %lf %lf", a, b, c);

    while (result != 3) {
        char ch = getchar();

        printf("Error. Try again\n");

        while (ch != '\n' && ch != EOF)
            ch = getchar();

        result = scanf("%lf %lf %lf", a, b, c);
    }
}


int solve_square_equation(double a, double b, double c, double* x1, double* x2)
{
    double discriminant = b*b - 4*a*c;

    if (discriminant < 0) {
        return 0;

    } else if (discriminant < epsilon) {
        *x1 = -b/(2*a);
        return 1;

    } else {
        double square_root = sqrt(discriminant);
        *x1 = (-b - square_root)/2;
        *x2 = (-b + square_root)/2;
        return 2;
    }
}

int solve_linear_equation(double b, double c, double* x1)
{
    if (b && c || b && !c) {
        *x1 = -c/b;
        return 1;

    } else if(!b && !c) {
        return -1;

    } else if(!b && c) {
        return 0;
    }
}

void print_roots(double x1, double x2, int root_count)
{
    switch(root_count) {

        case INF: printf("An infinite number of solutions");
                    break;

        case 0: printf("There is no solution");
                    break;

        case 1: printf("The solution %lg", x1);
                    break;

        case 2: printf("Solutions %lg %lg", x1, x2);
                    break;

        default: printf("Error. Something's wrong");
    }
}
