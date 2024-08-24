#ifndef IN_OUTPUT 
#define IN_OUTPUT

#include <assert.h>
#include <stdio.h>
#include <windows.h>

#ifndef N_ROOTS_ENUM
#define N_ROOTS_ENUM
enum N_ROOTS {
    INFINITE_ROOTS = -1,
    NO_ROOTS       =  0,
    ONE_ROOT       =  1,
    TWO_ROOTS      =  2     
};
#endif

#ifndef CONS_COL
#define CONS_COL

#define GREEN_SYMBOLS       "\033[1;32m"
#define RED_SYMBOLS         "\033[1;31m"
#define CYAN_SYMBOLS        "\033[1;36m"
#define YELLOW_SYMBOLS      "\033[1;33m"
#define DEFAULT_COLOR       "\033[0m"
#define LIGHTWHITE_SYMBOLS  "\033[1;37m"

#endif

void   turn_lowercase        (char *str);
void   scan_coeff            (double *a, double *b, double *c);
void   print_roots           (double x1, double x2, int root_count);


#endif