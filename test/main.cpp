#include <iostream> 
#include "Matrix.h"

using namespace std;
using namespace Matrix;

void BasicAlgebraTest() {
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

int main() {
	BasicAlgebraTest();
}