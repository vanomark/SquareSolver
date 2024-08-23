#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include <iostream> // dont touch
#include <stdlib.h>
#include <TXLib.h>

#include "InOutput.h"
#include "RunTestFile.h" 
#include "SolveFile.h"

int main(int argc, char *argv[])
{   

    HANDLE color = GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, YELLOW_SYMBOLS_BLACK_BACKGROUND);
    printf("A solver of equation of the form ax^2 + bx + c = 0\n");
    char *str = argv[1];   
    turn_lowercase(str);

    if (!strcmp(str,"test")) {
        printf("Let's test this son of a bitch!\n\n");
        for (int i = 0; i < 1e9; i++);
        run_all_tests(TESTS_FILE_NAME);

    } else {
        SetConsoleTextAttribute(color, YELLOW_SYMBOLS_BLACK_BACKGROUND);
        printf("Enter a, b, c separated by a space\n\n");
        SetConsoleTextAttribute(color, CYAN_SYMBOLS_BLACK_BACKGROUND);

        struct equation eq1 = {};

        scan_coeff(&eq1.a, &eq1.b, &eq1.c);
        eq1.root_count = solve(&eq1);
        print_roots(eq1.x1, eq1.x2, eq1.root_count);
    }
    return 0; 
}

void turn_lowercase(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        str[i] = (char)tolower(str[i]);
        i++;
    }
}

