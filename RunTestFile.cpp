#include "RunTestFile.h"

void run_all_tests(const char *NameOfFile)
{
    struct equation test = {};
    FILE *fp = fopen(NameOfFile,"r");

    while (fscanf(fp, "%lf %lf %lf %lf %lf %d", &test.a, &test.b, &test.c,
                                                &test.x1, &test.x2,
                                                &test.root_count) != EOF)
        run_test(test);

    fclose(fp);
}

void run_test(struct equation eq)
{
    static short i = 0;
    i++;
    struct equation test_case = {};
    test_case.a = eq.a;
    test_case.b = eq.b;
    test_case.c = eq.c;
    int root_count = solve(&test_case);

    if (root_count != eq.root_count || test_case.x1 != eq.x1 || test_case.x2 != eq.x2) {
        printf("\nTest %d: Error \na = %lg, b = %lg, c = %lg,\n"
               "Programm: x1 = %lg, x2 = %lg, root_count = %d\n"
               "Expected: x1 = %lg, x2 = %lg, root_count = %d\n",
                    i, eq.a, eq.b, eq.c, test_case.x1, test_case.x2, root_count,
                    eq.x1, eq.x2, eq.root_count);
    } else {
        printf("Test %d: Success\n\n", i);
    }
}
