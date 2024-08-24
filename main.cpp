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

// todo --test test.txt
// todo newline блять 
// todo README.md and docs (doxygen)
// todo colourful console with escape sequences

// after rest
// todo universal makefile (/include, /src, Makefile should not depend of actual filenames in a project) - GNU make (docs)

int main(int argc, char *argv[])
{   
    if (argc == 1) {
        printf("%sA solver of equation of the form ax^2 + bx + c = 0\n"
               "Enter a, b, c separated by a space\n%s" , YELLOW_SYMBOLS, CYAN_SYMBOLS);
        struct equation eq1 = {};

        scan_coeff(&eq1.a, &eq1.b, &eq1.c);
        eq1.root_count = solve(&eq1);
        print_roots(eq1.x1, eq1.x2, eq1.root_count);
    
    } else { 

        if (!strcmp(argv[1],"--test") && argc == 3) {
            const char *TESTS_FILE_NAME = argv[2];
            printf("%sLet's test this son of a bitch then!\n\n", YELLOW_SYMBOLS);     
            run_all_tests(TESTS_FILE_NAME);
        
        } else if (!strcmp(argv[1],"-help")) {
            printf("Available argument counters:\n"
                    "<0>   [empty field]              Starting programme\n"
                    "<1>   --test [name.txt]          Testing programme\n");

        } else {
            printf("%sError. Wrong argument counter was given%s\n" 
                    "Enter: \n\n[name.exe] -help\n", RED_SYMBOLS, DEFAULT_COLOR);
        }
    }

    return 0; 
}
