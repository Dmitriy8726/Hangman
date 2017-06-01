#include <ctest.h>
#include <../src/otherfunc.h>

CTEST(Test_one, Language)
{
    int result = Proverka('h');
	
    int expected = 1;
	
    ASSERT_EQUAL(expected, result);
}