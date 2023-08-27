#include "Test.h" 
#include "../include/Eig.h"

namespace MatrixTest {
    void EigTest() {
        std::cout << "\n******** Eig Test ********\n";

        Mat<double> A(5, 5);
        A = {
            4, 1, 0, 0, 2,
            1, 3, 1, 0, 0,
            0, 1, 5, 1, 0,
            0, 0, 1, 4, 1,
            2, 0, 0, 1, 6
        };

        Mat<double> expectedEigVec(5, 5);
        expectedEigVec = {
            -2.008, 2.333, -0.694, -0.142, 1,
            -0.835, -0.917, 1.107, -1.625, 1,
            -2.324, -2.407, -0.505, 2.824, 1,
            0.556, -1.044, -3.395, -1.394, 1,
            0.612, 0.178, 0.201, 0.337, 1
        };

        Mat<double> expectedEigVal(5);
        expectedEigVal  = { 1.842, 2.704, 4.175, 5.718, 7.561 };

        Mat<double> computedEigVec, computedEigVal;
        Matrix::eig(A, computedEigVec, computedEigVal);

        if (areMatricesEqual(expectedEigVec, computedEigVec) && areMatricesEqual(expectedEigVal, computedEigVal)) {
            std::cout << "Test passed!" << std::endl;
        }
        else {
            std::cout << "Test failed!" << std::endl;

            printMat(expectedEigVal);
            printMat(computedEigVal);
            printMat(expectedEigVec);
            printMat(computedEigVec);
        }
    }

} // namespace MatrixTest
