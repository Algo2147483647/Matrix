#include "Test.h"
#include "../include/BasicAlgebra.h" // Assuming the Matrix namespace and its methods are defined in this header

namespace MatrixTest {
	void BasicAlgebraTest() {
		std::cout << "\n******** Basic Algebra Test ********\n";

		Mat<float> A(10);
		Mat<float> B(1, 10);

		A = 1;
		for (size_t i = 0; i < 10; i++)
		{
			B[i] = i;
		}

		mul(A, A, B);

		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				printf("%.1f ", A(i, j));
			}
			printf("\n");
		}

		printf("%.1f ", Matrix::sum(A));
	}
}