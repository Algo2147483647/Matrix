#include <gtest/gtest.h>
#include "../include/BasicAlgebra.h" // Assuming the Matrix namespace and its methods are defined in this header

using namespace Matrix;

TEST(AddTest, MatricesAddition) {
	Mat<int> a(2, 2);
	a[0] = 1; a[1] = 2;
	a[2] = 3; a[3] = 4;

	Mat<int> b(2, 2);
	b[0] = 5; b[1] = 6;
	b[2] = 7; b[3] = 8;

	Mat<int> expected_result(2, 2);
	expected_result[0] = 6; expected_result[1] = 8;
	expected_result[2] = 10; expected_result[3] = 12;

	Mat<int> result(2, 2);
	add(result, a, b);

	EXPECT_EQ(result, expected_result);
}

TEST(AddTest, DifferentMatrixSizes) {
	Mat<int> a(2, 2);
	Mat<int> b(3, 3);
	Mat<int> result(3, 3);

	// 这里期望 add 函数会调用 exit(-1)
	EXPECT_EXIT(add(result, a, b), ::testing::ExitedWithCode(-1), ".*");
}
