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

CTEST(Test_3, Language_znak)
{
    int result = Proverka('!');
	
    int expected = 0;
	
    ASSERT_EQUAL(expected, result);
}

CTEST(Test_4, Language_1)
{
    int result = Proverka('1');
	
    int expected = 0;
	
    ASSERT_EQUAL(expected, result);
}

CTEST(Test_Povror1, Letter_a_1)
{
	char A[] ="abc";
	
	int C[] = {1, 1, 1};
	
	int result = Povtor('a', C, 3, A);
	
	int expected = 1;
	
	ASSERT_EQUAL(expected, result);
}

CTEST(Test_Povror2, Letter_a_0)
{
	char A[] ="abc";
	
	int C[] = {0, 1, 1};
	
	int result = Povtor('a', C, 3, A);
	
	int expected = 0;
	
	ASSERT_EQUAL(expected, result);
}

CTEST(Test_Povror3, Letter_d_1)
{
	char A[] ="abc";
	
	int C[] = {1, 1, 1};
	
	int result = Povtor('d', C, 3, A);
	
	int expected = 0;
	
	ASSERT_EQUAL(expected, result);
}

CTEST(Test_Povror4, Letter_d_0)
{
	char A[] ="abc";
	
	int C[] = {0, 0, 0};
	
	int result = Povtor('d', C, 3, A);
	
	int expected = 0;
	
	ASSERT_EQUAL(expected, result);
}