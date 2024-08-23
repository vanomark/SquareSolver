#ifndef RUN_TEST_FILE_H
#define RUN_TEST_FILE_H

#include <stdio.h>
#include "SolveFile.h"
#include <windows.h>

const char * const TESTS_FILE_NAME = "test.txt";
const int              BUFFER_SIZE =         40;

#ifndef CONS_COL
#define CONS_COL

enum CONSOLE_COLORS {
    RED_SYMBOLS_BLACK_BACKGROUND        = 4,
    DEFAULT_COLOR                       = 7,
    LIGHTWHITE_SYMBOLS_BLACK_BACKGROUND = 15,
    GREEN_SYMBOLS_BLACK_BACKGROUND      = 10
};
#endif

void   run_test              (struct equation eq);
void   run_all_tests         (const char *NameOfFile);

#endif // RUN_TEST_FILE_H
