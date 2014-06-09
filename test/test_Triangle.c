#include "unity.h"
#include "Triangle.h"
#include "CException.h"

char *getTriangleName(int side1, int side2, int side3);


void setUp(void){}

void tearDown(void){}

void test_getTriangleName_given_2_2_3_should_return_isoscales(void)
{
	char *name;
	name = getTriangleName(2,2,3);
	TEST_ASSERT_EQUAL_STRING("isosceles",name);
}

void test_getTriangleName_given_2_3_3_should_return_isoscales(void)
{
	char *name;
	name = getTriangleName(2,3,3);
	TEST_ASSERT_EQUAL_STRING("isosceles",name);
}

void test_getTriangleName_given_3_2_3_should_return_isoscales(void)
{
	char *name;
	name = getTriangleName(3,2,3);
	TEST_ASSERT_EQUAL_STRING("isosceles",name);
}


void test_getTriangleName_given_1_2_3_should_return_scalene(void)
{
	char *name;
	name = getTriangleName(1,2,3);
	TEST_ASSERT_EQUAL_STRING("scalene",name);
}

void test_getTriangleName_given_3_3_3_should_return_equilateral(void)
{
	char *name;
	name = getTriangleName(3,3,3);
	TEST_ASSERT_EQUAL_STRING("equilateral",name);
}

void test_getTriangleName_given_0_3_3_should_return_invalid(void)
{
	char *name;
	name = getTriangleName(0,3,3);
	TEST_ASSERT_EQUAL_STRING("invalid",name);
}

void test_getTriangleName_given_3_0_3_should_return_invalid(void)
{
	char *name;
	name = getTriangleName(3,0,3);
	TEST_ASSERT_EQUAL_STRING("invalid",name);
}

void test_getTriangleName_given_3_3_0_should_return_invalid(void)
{
	char *name;
	name = getTriangleName(3,3,0);
	TEST_ASSERT_EQUAL_STRING("invalid",name);
}

void test_getTriangleName_given_neg2_3_3_should_return_invalid(void)
{
	char *name;
	name = getTriangleName(-2,3,3);
	TEST_ASSERT_EQUAL_STRING("invalid",name);
}

void test_getTriangleName_given_3_neg2_3_should_return_invalid(void)
{
	char *name;
	name = getTriangleName(3,-2,3);
	TEST_ASSERT_EQUAL_STRING("invalid",name);
}

void test_getTriangleName_given_3_3_neg2_should_return_invalid(void)
{
	char *name;
	name = getTriangleName(3,3,-2);
	TEST_ASSERT_EQUAL_STRING("invalid",name);
}

void test_getTriangleName_given_1_1_3_should_return_invalid(void)
{
	char *name;
	name = getTriangleName(1,1,3);
	TEST_ASSERT_EQUAL_STRING("invalid",name);
}

void test_getTriangleName_given_1_3_1_should_return_invalid(void)
{
	char *name;
	name = getTriangleName(1,3,1);
	TEST_ASSERT_EQUAL_STRING("invalid",name);
}

void test_getTriangleName_given_3_1_1_should_return_invalid(void)
{
	char *name;
	name = getTriangleName(3,1,1);
	TEST_ASSERT_EQUAL_STRING("invalid",name);
}

void test_areLengthsAllStrictlyPositive_given_all_positive_side_should_not_throw_an_exception(void)
{	CEXCEPTION_T err;
	Try
	{	areLengthsAllStrictlyPositive(3,3,3);
		printf("Success: No Exception generated.It is a valid triangle!!");
	}	Catch(err) 
	{
		TEST_FAIL_MESSAGE("Do not expect exception to be generated");
	}
}

void test_areLengthsAllStrictlyPositive_given_neg_side1_should_throw_an_exception(void)
{	CEXCEPTION_T err;
	Try
	{	areLengthsAllStrictlyPositive(-3,3,3);
		TEST_FAIL_MESSAGE("Should generated an exception with all positive sides");
	}	Catch(err) 
	{
		TEST_ASSERT_EQUAL(ERR_LENGTH_IS_NOT_STRICTLY_POSITIVE, err);
		printf("Success: Exception generated.The error code is %d\n",err);
	}
}

void test_areLengthsAllStrictlyPositive_given_neg_side2_should_throw_an_exception(void)
{	CEXCEPTION_T err;
	Try
	{	areLengthsAllStrictlyPositive(3,-3,3);
		TEST_FAIL_MESSAGE("Should generated an exception with all positive sides");
	}	Catch(err) 
	{
		TEST_ASSERT_EQUAL(ERR_LENGTH_IS_NOT_STRICTLY_POSITIVE, err);
		printf("Success: Exception generated.The error code is %d\n",err);
	}
}

void test_areLengthsAllStrictlyPositive_given_neg_side3_should_throw_an_exception(void)
{	CEXCEPTION_T err;
	Try
	{	areLengthsAllStrictlyPositive(3,3,-3);
		TEST_FAIL_MESSAGE("Should generated an exception with all positive sides");
	}	Catch(err) 
	{
		TEST_ASSERT_EQUAL(ERR_LENGTH_IS_NOT_STRICTLY_POSITIVE, err);
		printf("Success: Exception generated.The error code is %d\n",err);
	}
}
void test_isTriangle_given_side1_1_side2_1_side3_3_should_throw_an_exception(void)
{	CEXCEPTION_T err;
	Try
	{	isTriangle(1,1,3);
		TEST_FAIL_MESSAGE("Should generated an exception with sum of 2 sides must larger than side3");
	}	Catch(err) 
	{
		TEST_ASSERT_EQUAL(ERR_NOT_TRIANGLE, err);
		printf("Success: Exception generated.The error code is %d\n",err);
	}
}

void test_isTriangle_given_side1_5_side2_1_side3_3_should_throw_an_exception(void)
{	CEXCEPTION_T err;
	Try
	{	isTriangle(5,1,3);
		TEST_FAIL_MESSAGE("Should generated an exception with sum of 2 sides must larger than side3");
	}	Catch(err) 
	{
		TEST_ASSERT_EQUAL(ERR_NOT_TRIANGLE, err);
		printf("Success: Exception generated.The error code is %d\n",err);
	}
}

void test_isTriangle_given_side1_2_side2_8_side3_3_should_throw_an_exception(void)
{	CEXCEPTION_T err;
	Try
	{	isTriangle(2,8,3);
		TEST_FAIL_MESSAGE("Should generated an exception with sum of 2 sides must larger than side3");
	}	Catch(err) 
	{
		TEST_ASSERT_EQUAL(ERR_NOT_TRIANGLE, err);
		printf("Success: Exception generated.The error code is %d\n",err);
	}
}

void test_isTriangle_given_side1_neg_5_side2_1_side3_3_should_throw_an_exception(void)
{	CEXCEPTION_T err;
	Try
	{	isTriangle(-5,1,3);
		TEST_FAIL_MESSAGE("Should generated an exception with sum of 2 sides must larger than side3");
	}	Catch(err) 
	{
		TEST_ASSERT_EQUAL(ERR_NOT_TRIANGLE, err);
		printf("Success: Exception generated.The error code is %d\n",err);
	}
}


