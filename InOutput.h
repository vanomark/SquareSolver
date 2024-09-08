#ifndef IN_OUTPUT 
#define IN_OUTPUT

#include <assert.h>
#include <stdio.h>
#include <windows.h>

#include "AssertFile.h"
#include "ColorPrintFile.h"
#include "SolveFile.h"

int   scan_coeff            (double *a, double *b, double *c);
int   clean_buffer          (void);
int   print_roots           (double x1, double x2, int root_count);

#endif // IN_OUTPUT