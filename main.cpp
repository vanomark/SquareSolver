#include <stdio.h>
#include <math.h>
#define NOSOLUTION printf("There is no solution\n")
#define INFSOLUTION printf("An infinite number of solutions\n")

void beginning(void);
void calculation(float a, float b, float c);

int main() {
    float a = 0.0, b = 0.0, c = 0.0;

    beginning();

    scanf("%f %f %f", &a, &b, &c);

    calculation(a, b, c);
}


void beginning(void) {
    printf("An equation of the form ax^2 + bx + c = 0\n");
    printf("Enter a, b, c separated by a space\n");
}


void calculation(float a, float b, float c) {
    if (a && b) {
        float discriminant;
        discriminant = b*b - 4*a*c;
        if (discriminant < 0)
            NOSOLUTION;

        if (discriminant == 0)
            printf("The solution %.3f\n", -b/(2*a));

        else printf("Solutions %.3f, %.3f\n", (-b - sqrt(discriminant))/2, (-b + sqrt(discriminant))/2);
    }
    else if(!a && b)
        printf("The solution %.3f\n", -c/b);

    else if(!a && !b && !c)
        INFSOLUTION;

    else if(!a && !b && c)
        NOSOLUTION;

    else if(a*c>0)
        NOSOLUTION;

    else
        printf("Solutions %.3f, %.3f", -sqrt(-c/a), sqrt(-c/a));
}
