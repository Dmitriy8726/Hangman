#include <ctest.h>
#include <../test/otherfunc2.h>

CTEST(Test_1, Language_h)
{
    int result = Proverka('h');
	
    int expected = 1;
	
    ASSERT_EQUAL(expected, result);
}

CTEST(Test_2, Language_H)
{
    int result = Proverka('H');
	
    int expected = 1;
	
    ASSERT_EQUAL(expected, result);
}

CTEST(Test_3, Language_p)
{
    int result = Proverka('р');
	
    int expected = 1;
	
    ASSERT_EQUAL(expected, result);
}

CTEST(Test_4, Language_P)
{
    int result = Proverka('Р');
	
    int expected = 1;
	
    ASSERT_EQUAL(expected, result);
}