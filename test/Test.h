#include <iostream>
#include <iomanip>
#include <cmath>
#include "../include/Matrix.h" 

using namespace std;
using namespace Matrix;

namespace MatrixTest {

    // Helper function to compare two matrices
    template <typename T>
    bool areMatricesEqual(Mat<T>& mat1, Mat<T>& mat2, double tolerance = 1E-4) {
        if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
            return false;
        }

        for (int i = 0; i < mat1.rows; i++) {
            for (int j = 0; j < mat1.cols; j++) {
                if (fabs(mat1(i, j) - mat2(i, j)) > tolerance) {
                    return false;
                }
            }
        }

        return true;
    }

    template <typename T>
    void printMat(Mat<T>& A) {

        for (int i = 0; i < A.rows; i++) {
            for (int j = 0; j < A.cols; j++) {
                cout << A(i, j) << ' ';
            } cout << '\n';
        } cout << '\n';
    }

	void BasicAlgebraTest();
	void EigTest();
}
