/* 
 * auteur : Ella van der Sanden
 * myProgramTest
 */

#include "mySecondFile.h"
#include "otherFile.h"
#include "unity.h"


void setUp(void)
{
    // This is run before EACH test
}

void tearDown(void)
{
    // This is run after EACH test
}

void test_to_see_if_our_compiler_can_add_2_integers(void)
{
    int result = 2;
    TEST_ASSERT_EQUAL(result, 1+1);
}

void testmyFunctions (void)
{
	TEST_ASSERT_EQUAL(8,someFunction(3,5));
	TEST_ASSERT_EQUAL(7,otherFunction(3,5));
}

int main (int argc, char * argv[])
{
    UnityBegin();
    
    RUN_TEST(test_to_see_if_our_compiler_can_add_2_integers,1);
    RUN_TEST(testmyFunctions,2);

    
    return UnityEnd();
}
