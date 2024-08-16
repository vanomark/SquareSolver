#include <stdio.h>
#include <math.h>
#define NOSOLUTION printf("There is no solution\n")
#define INFSOLUTION printf("An infinite number of solutions\n")

void introduction(void);
void scan(double *a, double *b, double *c);
void calculation(double *a, double *b, double *c);


int main() {
    double a = 0, b = 0, c = 0;
    introduction();
    scan(&a, &b, &c);
    calculation(a, b, c);
}


void introduction(void) {
    printf("An equation of the form ax^2 + bx + c = 0\n");
    printf("Enter a, b, c separated by a space\n");
}


void scan(double *a, double *b, double *c) {

    int result = scanf("%g %g %g", a, b, c);

    if (result != 3) {
        printf("Error. Try again\n");
        scan(a, b, c);
    }
}


void calculation(double a, double b, double c) {

    printf("%g %g %g\n", a, b, c);
    if (a && b) {
        double discriminant = b*b - 4*a*c;
        double epsilon = 1.0e-6;

        if (discriminant < 0)
            NOSOLUTION;

        else if (discriminant < epsilon)
            printf("The solution %g\n", -b/(2*a));

        else {
            double square_root_1 = sqrt(discriminant);
            printf("Solutions %g, %g\n", (-b - square_root_1)/2, (-b + square_root_1)/2);
        }
    }
    else if(!a && b)
        printf("The solution %g\n", -c/b);

    else if(!a && !b && !c)
        INFSOLUTION;

    else if(!a && !b && c)
        NOSOLUTION;

    else if(a*c>0)
        NOSOLUTION;

    else {
        double square_root_2 = sqrt(-c/a);
        printf("Solutions %g, %g", -square_root_2, square_root_2);
    }
}
