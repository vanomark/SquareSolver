#ifndef IN_OUTPUT
#define IN_OUTPUT

#include <windows.h>
#include <assert.h>
#include <stdio.h>

void   scan_coeff            (double *a, double *b, double *c);
void   print_roots           (double x1, double x2, int root_count);
const int INFINITE_ROOTS = -1;
#endif
