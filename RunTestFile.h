#ifndef RUN_TEST_FILE_H
#define RUN_TEST_FILE_H

#include <stdio.h>
#include "SolveFile.h"

void   run_test              (struct equation eq);
void   run_all_tests         (const char *NameOfFile);
const char * const TESTS_FILE_NAME = "test.txt";

#endif // RUN_TEST_FILE_H
