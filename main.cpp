#include <TXLib.h>
#include <stdio.h>
#include <math.h>

int main(void){
float a, b, c, discriminant;
printf("Вычисление корней уравнения типа ax^2 + bx + c = 0\n");
printf("Через пробел введите а, b, c\n");
scanf("%f %f %f",&a,&b,&c);
if (a && b){
discriminant = b*b-4*a*c;
if (discriminant < 0) printf("Нет действительных корней");
if (discriminant == 0) printf("Единственный корень %.3f", (-b)/(2*a));
else printf("Корни %.3f, %.3f",(-b-sqrt(discriminant))/2,(-b+sqrt(discriminant))/2);}
else if(!a && b) printf("Единственный корень %.3f", (-c)/b);
else if(!a && !b && !c) printf("Бесконечное количество решений");
else printf("Нет решений");
return 0;}
