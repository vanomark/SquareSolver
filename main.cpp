#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "InOutput.h"
#include "RunTestFile.h" 
#include "SolveFile.h"

// todo README.md and docs (doxygen)
// after rest
// todo universal makefile (/include, /src, /Makefile should not depend of actual filenames in a project) - GNU make (docs)

int main(const int argc, char* const argv[])
{   
    if (argc == 1) {
        YELLOW_PRINT("A solver of equation of the form ax^2 + bx + c = 0\n"
                     "Enter a, b, c separated by a space\n");

        equation eq = {};

        scan_coeff(&eq.a, &eq.b, &eq.c);
        solve_equation(&eq);
        print_roots(eq.x1, eq.x2, eq.root_count);
    
    } else {
        if (!strcmp(argv[1], "--test") && argc == 3) {

            const char *TESTS_FILE_NAME = argv[2];
            run_all_tests(TESTS_FILE_NAME);       
                                                                        //todo argv 
        } else if (!strcmp(argv[1], "--test") && argc == 2) {

            const char *TESTS_FILE_NAME = "test.txt";
            run_all_tests(TESTS_FILE_NAME);

        } else if (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h")) {
            WHITE_PRINT("Available argument vectors:\n"
                        "<0>   [empty field]              Starting programme\n"
                        "<1>   --test [name.txt]          Testing programme with given test file\n"
                        "<2>   --test [empty field]       Testing programme with default test file\n");

        } else {
            RED_PRINT("Error. Wrong argument vector was given\n"
                     "Enter: \n[name.exe] --help\n");
        }
    }

    return 0; 
}
