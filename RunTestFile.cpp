#include "RunTestFile.h"

int run_all_tests(const char *name_of_file) 
{   
    ASSERT(name_of_file != NULL, "Pointer cannot be zero");

    YELLOW_PRINT("Let's test this son of a bitch then!\n\n"); 
    
    FILE *test_file = fopen(name_of_file, "r");
    ASSERT(test_file != 0, "Wrong file was given");    

    equation test = {};
    size_t num_test = 0;

    while (fscanf(test_file, "%lf %lf %lf %lf %lf %d", &test.a, &test.b, &test.c,
                                                       &test.x1, &test.x2,
                                                       &test.root_count) != EOF)
        run_test(test, ++num_test);

    fclose(test_file);

    return 0;
}

int run_test(struct equation eq, size_t num_test)
{   
    ASSERT(isfinite(eq.a),          "Not a number");
    ASSERT(isfinite(eq.b),          "Not a number");
    ASSERT(isfinite(eq.c),          "Not a number");
    ASSERT(isfinite(eq.x1),         "Not a number");
    ASSERT(isfinite(eq.x2),         "Not a number");
    ASSERT(isfinite(eq.root_count), "Not a number");
    ASSERT(isfinite(num_test),      "Not a number");

    struct equation test_case = {
        .a = eq.a,
        .b = eq.b,
        .c = eq.c,
    };

    solve_equation(&test_case);

    if (test_case.root_count != eq.root_count
        || !is_zero(test_case.x1 - eq.x1) || !is_zero(test_case.x2 - eq.x2)) {
        
        RED_PRINT_ARG("Test %d: Error \na = %lg, b = %lg, c = %lg,\n", 
            num_test, eq.a, eq.b, eq.c); 
        RED_PRINT_ARG("Programm: x1 = %lg, x2 = %lg, root_count = %d\n", 
            test_case.x1, test_case.x2, test_case.root_count);
        RED_PRINT_ARG("Expected: x1 = %lg, x2 = %lg, root_count = %d\n",
            eq.x1, eq.x2, eq.root_count);

    } else {
        GREEN_PRINT_ARG("Test %d: Success\n", num_test);
    }

    return 0;
}

int SpecAssert(int x, const char *ErrorStr, const char *file, const char *func, int line) {
    
    assert(isfinite(x));
    assert(isfinite(line));
    assert(ErrorStr);
    assert(file);
    assert(func);
    
    if (!x) {
        RED_PRINT_ARG("Error:\n"
                      "File:      %s\n"
                      "Function:  %s\n"
                      "Line:      %d\n"
                      "%s\n", file, func, line, ErrorStr);
        abort();
    }

    return 0;
}