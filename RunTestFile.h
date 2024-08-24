#ifndef RUN_TEST_FILE_H
#define RUN_TEST_FILE_H

#include <stdio.h>
#include "SolveFile.h"
#include <windows.h>

const int              BUFFER_SIZE =         40;

#ifndef CONS_COL
#define CONS_COL

#define GREEN_SYMBOLS       "\033[1;32m"
#define RED_SYMBOLS         "\033[1;31m"
#define CYAN_SYMBOLS        "\033[1;36m"
#define YELLOW_SYMBOLS      "\033[1;33m"
#define DEFAULT_COLOR       "\033[0m"
#define LIGHTWHITE_SYMBOLS  "\033[1;37m"

#endif

void   run_test              (struct equation eq);
void   run_all_tests         (const char *NameOfFile);

#endif // RUN_TEST_FILE_H
