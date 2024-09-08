#ifndef RUN_TEST_FILE_H
#define RUN_TEST_FILE_H

#include <stdio.h>
#include <stdlib.h>

#include "AssertFile.h"
#include "ColorPrintFile.h"
#include "SolveFile.h"

int run_test      (struct equation eq, size_t num_test);
int run_all_tests (const char *NameOfFile);

#endif // RUN_TEST_FILE_H
