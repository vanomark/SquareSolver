#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void   scan_coeff            (double *a, double *b, double *c);
void   print_roots           (double a, double b, double c);
int    solve_square_equation (double a, double b, double c, double* x1, double* x2);
int    solve_linear_equation (double b, double c, double* x1);
void   print_roots           (double x1, double x2, int root_count);
int    solve                 (struct equation *eq);
void   run_test              (struct equation eq);
void   run_all_tests         (void);
void   turn_lowercase        (char *str);
double abs                   (double x);

const double EPS         = 1e-8;
const int    INFINITE    =   -1;
const int    BUFFER_SIZE =   40;

struct equation {
    double a, b, c, x1, x2;
    int root_count;
};

int main()
{
    printf("A solver of equation of the form ax^2 + bx + c = 0\n\n");
    printf("%14s %8s %20s\nto start solving  %30s",
           "Enter \"Start\"", "or", "Enter \"Test\"",
           "to start testing\n\n" );

    char str[BUFFER_SIZE] = "";
    do {
        scanf("%s",str);
        turn_lowercase(str);

        if (!strcmp(str,"test"))
        {
            run_all_tests();

        } else if (!strcmp(str,"start")) {
            printf("\nEnter a, b, c separated by a space\n");
            struct equation eq1 = {};

            scan_coeff(&eq1.a, &eq1.b, &eq1.c);
            eq1.root_count = solve(&eq1);
            print_roots(eq1.x1, eq1.x2, eq1.root_count);
        }
    } while (strcmp(str,"test") && strcmp(str,"start"));

return 666;
}

void turn_lowercase(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
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

double abs(double x)
{
return x = (x > 0)? x : -x;
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

void print_roots(double x1, double x2, int root_count)
{
    switch(root_count) {

        case INFINITE: printf("An infinite number of solutions\n");
                    break;

        case 0: printf("There is no solution\n");
                    break;

        case 1: printf("The solution %.3lg\n", x1);
                    break;

        case 2: printf("Solutions %.3lg %.3lg\n", x1, x2);
                    break;

        default: printf("Error. Something's wrong\n");
    }
}

void run_all_tests()
{
    struct equation test = {};
    FILE *fp = fopen("test.txt","r");

    while (fscanf(fp, "%lf %lf %lf %lf %lf %d", &test.a, &test.b, &test.c, &test.x1, &test.x2, &test.root_count) != EOF)
        run_test(test);

    fclose(fp);
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

    if (root_count != eq.root_count || test_case.x1 != eq.x1 || test_case.x2 != eq.x2) {
        printf("\nTest %d: Error \na = %lg, b = %lg, c = %lg,\n"
               "Programm: x1 = %lg, x2 = %lg, root_count = %d\n"
               "Expected: x1 = %lg, x2 = %lg, root_count = %d\n",
                    i, eq.a, eq.b, eq.c, test_case.x1, test_case.x2, root_count,
                    eq.x1, eq.x2, eq.root_count);
    } else {
        printf("Test %d: Success\n\n", i);
    }
}
