#include <assert.h>
#include <math.h>
#include <stdio.h>

void scan_coeff            (double *a, double *b, double *c);
void print_roots           (double a, double b, double c);
int  solve_square_equation (double a, double b, double c, double* x1, double* x2);
int  solve_linear_equation (double b, double c, double* x1);
void print_roots           (double x1, double x2, int root_count);
int  solve                 (struct equation *eq);
void run_test              (struct equation eq);
void all_tests             (void);

const double EPSILON = 1e-6;
const int    INF     = -1;

struct equation {
    double a, b, c, right_x1, right_x2;
    int right_root_count;
};

int main()
{
    all_tests();

    /*
    printf("An equation of the form ax^2 + bx + c = 0\n");
    printf("Enter a, b, c separated by a space\n");
    struct equation eq1 = {};
    scan_coeff(&eq1.a, &eq1.b, &eq1.c);
    eq1.right_root_count = solve(&eq1);
    print_roots(eq1.right_x1, eq1.right_x2, eq1.right_root_count); */
    return 666;
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

int solve(struct equation *eq)
{
    if (eq->a)
        return solve_square_equation(eq->a, eq->b, eq->c, &(eq->right_x1), &eq->right_x2);
    else
        return solve_linear_equation(eq->b, eq->c, &eq->right_x1);
}

int solve_square_equation(double a, double b, double c, double* x1, double* x2)
{

    double discriminant = b*b - 4*a*c;

    if (discriminant < 0) {
        return 0;

    } else if (discriminant < EPSILON) {
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

        case 1: printf("The solution %.3lg", x1);
                    break;

        case 2: printf("Solutions %.3lg %.3lg", x1, x2);
                    break;

        default: printf("Error. Something's wrong");
    }
}

void all_tests()
{
    struct equation test[20]  = {
        {1, 0, -4, -2, 2, 2},      // Test 1
        {0, 0, 0, 0, 0, -1},       // Test 2
        {0, 0, -10, 0, 0, 0},      // Test 3
        {0, 1, -10, 10, 0, 1},     // Test 4
        {10, 0, -10, -1, 1, 2},    // Test 5
        {1, 2, -3, -3, 1, 2},      // Test 6
        {0.5, 1, -1.5, -3, 1, 2},  // Test 7
        {-10, 0, -1, 0, 0, 0},     // Test 8
        {4, 4, 0, -1, 0, 2},       // Test 9
        {4, 4, 1, -0.5, 0, 1},     // Test 10
        {1, 13, -14, -14, 1, 2},   // Test 11
        {1, 1, 1, 0, 0, 0},        // Test 12
        {1, 1, 0, -1, 0, 2},       // Test 13
        {0, -98, 0, 0, 0, 1},      // Test 14
        {2, 2, 2, 0, 0, 0},        // Test 15
        {2, 2, 0.5,-0.5, 0, 1},    // Test 16
        {1, 9, -10, -10, 1, 2},    // Test 17
        {15, 0, 0, 0, 0, 1},       // Test 18
        {3, 0, -3, -1, 1, 2},      // Test 19
        {0, 0, -10, 0, 0, 0}       // Test 20
    } ;

    for (int i = 0; i < 20; i++)
            run_test(test[i]);

}

void run_test(struct equation eq)
{
    static short i = 0;
    i++;
    struct equation test_case = {};
    test_case.a = eq.a;
    test_case.b = eq.b;
    test_case.c = eq.c;
    int root_count = solve(&test_case);

    if (root_count != eq.right_root_count || test_case.right_x1 != eq.right_x1 || test_case.right_x2 != eq.right_x2) {
        printf("Test %d: Error \na = %lg, b = %lg, c = %lg,\nProgramm: x1 = %lg, x2 = %lg, root_count = %d\n"
               "Expected: x1 = %lg, x2 = %lg, root_count = %d\n\n",
                    i, eq.a, eq.b, eq.c, test_case.right_x1, test_case.right_x2, root_count,
                    eq.right_x1, eq.right_x2, eq.right_root_count);
    } else
        printf("Test %d: Success\n\n", i);
}


