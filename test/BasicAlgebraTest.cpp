#include <gtest/gtest.h>
#include "../include/BasicAlgebra.h" // Assuming the Matrix namespace and its methods are defined in this header

using namespace Matrix;

// Test for negative operation
TEST(NegativeTest, NegativeOperation) {
	Mat<int> a({ {1, 2}, {3, 4} });
	Mat<int> res;

	negative(res, a);

	Mat<int> expectedRes({ {-1, -2}, {-3, -4} });
	ASSERT_EQ(res, expectedRes);
}

// Test for unary negation operator
TEST(NegativeTest, UnaryNegationOperator) {
	Mat<int> a({ {1, 2}, {3, 4} });
	Mat<int> res = -a;

	Mat<int> expectedRes({ {-1, -2}, {-3, -4} });
	ASSERT_EQ(res, expectedRes);
}

// Test for transpose operation
TEST(TransposeTest, TransposeOperation) {
	Mat<int> a({ {1, 2, 3}, {4, 5, 6} });
	Mat<int> res;

	transpose(res, a);

	Mat<int> expectedRes({ {1, 4}, {2, 5}, {3, 6} });
	ASSERT_EQ(res, expectedRes);
}

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

// Test for matrix multiplication
TEST(MatrixMultiplicationTest, MatrixMultiplication) {
    Mat<int> a = { {1, 2}, {3, 4} };
    Mat<int> b = { {5, 6}, {7, 8} };
    Mat<int> res;

    mul(res, a, b);

    Mat<int> expectedRes = { {19, 22}, {43, 50} };
    ASSERT_EQ(res, expectedRes);
}

// Test for vector-matrix multiplication
TEST(VectorMatrixMultiplicationTest, VectorMatrixMultiplication) {
    Mat<int> a = { {1, 2}, {3, 4} };
    vector<int> b = { 5, 6 };
    vector<int> res;

    mul(res, a, b);

    vector<int> expectedRes = { 17, 39 };
    ASSERT_EQ(res, expectedRes);
}

// Test for scalar-matrix multiplication
TEST(ScalarMatrixMultiplicationTest, ScalarMatrixMultiplication) {
    Mat<int> b = { {1, 2}, {3, 4} };
    Mat<int> res;

    mul(res, 2.0, b);

    Mat<int> expectedRes = { {2, 4}, {6, 8} };
    ASSERT_EQ(res, expectedRes);
}

// Test for element-wise matrix multiplication
TEST(ElementWiseMatrixMultiplicationTest, ElementWiseMatrixMultiplication) {
    Mat<int> a = { {1, 2}, {3, 4} };
    Mat<int> b = { {5, 6}, {7, 8} };
    Mat<int> res;

    elementMul(res, a, b);

    Mat<int> expectedRes = { {5, 12}, {21, 32} };
    ASSERT_EQ(res, expectedRes);
}

// Test for element-wise vector multiplication
TEST(ElementWiseVectorMultiplicationTest, ElementWiseVectorMultiplication) {
    vector<int> a = { 1, 2, 3 };
    vector<int> b = { 4, 5, 6 };
    vector<int> res;

    elementMul(res, a, b);

    vector<int> expectedRes = { 4, 10, 18 };
    ASSERT_EQ(res, expectedRes);
}

// Test for element-wise matrix division
TEST(ElementWiseMatrixDivisionTest, ElementWiseMatrixDivision) {
    Mat<double> a = { {2.0, 4.0}, {6.0, 8.0} };
    Mat<double> b = { {1.0, 2.0}, {3.0, 4.0} };
    Mat<double> res;

    elementDiv(res, a, b);

    Mat<double> expectedRes = { {2.0, 2.0}, {2.0, 2.0} };
    ASSERT_EQ(res, expectedRes);
}

// Test for element-wise vector division
TEST(ElementWiseVectorDivisionTest, ElementWiseVectorDivision) {
    vector<double> a = { 4.0, 10.0, 18.0 };
    vector<double> b = { 1.0, 2.0, 3.0 };
    vector<double> res;

    elementDiv(res, a, b);

    vector<double> expectedRes = { 4.0, 5.0, 6.0 };
    ASSERT_EQ(res, expectedRes);
}
