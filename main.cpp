#include <TXLib.h>
#include <stdio.h>
#include <math.h>

int main(void){
float a, b, c, discriminant;
printf("An equation of the form ax^2 + bx + c = 0\n");
printf("Enter a, b, c separated by a space\n");
scanf("%f %f %f",&a,&b,&c);
if (a && b){
discriminant = b*b-4*a*c;
if (discriminant < 0) printf("There is no real solution");
if (discriminant == 0) printf("The solution %.3f", (-b)/(2*a));
else printf("Solutions %.3f, %.3f",(-b-sqrt(discriminant))/2,(-b+sqrt(discriminant))/2);}
else if(!a && b) printf("The solution %.3f", (-c)/b);
else if(!a && !b && !c) printf("An infinite number of solutions");
else printf("There is no solution");
return 0;}
