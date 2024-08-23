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
enum CONSOLE_COLORS {
    CYAN_SYMBOLS_BLACK_BACKGROUND       = 3,
    RED_SYMBOLS_BLACK_BACKGROUND        = 4,
    YELLOW_SYMBOLS_BLACK_BACKGROUND     = 6,
    DEFAULT_COLOR                       = 7,
    LIGHTWHITE_SYMBOLS_BLACK_BACKGROUND = 15,
    GREEN_SYMBOLS_BLACK_BACKGROUND      = 10,

};
#endif

void   turn_lowercase        (char *str);
void   scan_coeff            (double *a, double *b, double *c);
void   print_roots           (double x1, double x2, int root_count);


#endif