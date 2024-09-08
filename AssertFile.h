#ifndef ASSERT_CUSTOM
#define ASSERT_CUSTOM

#define ASSERT(TestFile, ErrorStr) SpecAssert(TestFile, ErrorStr, __FILE__, __PRETTY_FUNCTION__, __LINE__)

int SpecAssert    (int x, const char *ErrorStr, const char *file, const char *func, int line);

#endif // ASSERT_CUSTOM