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

int main()
{
    HANDLE color = GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, YELLOW_SYMBOLS_BLACK_BACKGROUND);
    printf("A solver of equation of the form ax^2 + bx + c = 0\n\n");
    printf("%14s %8s %20s\nto start solving  %30s",
           "Enter \"Start\"", "or", "Enter \"Test\"",
           "to start testing\n\n");
    SetConsoleTextAttribute(color, CYAN_SYMBOLS_BLACK_BACKGROUND);

    char str[BUFFER_SIZE] = "";
    do {
        scanf("%s",str);
        turn_lowercase(str);

        if (!strcmp(str,"test"))
        {
            run_all_tests(TESTS_FILE_NAME);

        } else if (!strcmp(str,"start")) {
            SetConsoleTextAttribute(color, YELLOW_SYMBOLS_BLACK_BACKGROUND);
            printf("\nEnter a, b, c separated by a space\n");
            SetConsoleTextAttribute(color, CYAN_SYMBOLS_BLACK_BACKGROUND);

            struct equation eq1 = {};

            scan_coeff(&eq1.a, &eq1.b, &eq1.c);
            eq1.root_count = solve(&eq1);
            print_roots(eq1.x1, eq1.x2, eq1.root_count);
        }
    } while (strcmp(str,"test") && strcmp(str,"start"));

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

