#include <gtest/gtest.h>
#include "../include/Eig.h" // Assuming the Matrix namespace and its methods are defined in this header

using namespace Matrix;

// Test the eig function
TEST(EigTest, BasicTest) {
    // Create a sample matrix
    Mat<double> inputMatrix(3, 3);
    inputMatrix(0, 0) = 4.0; inputMatrix(0, 1) = 2.0; inputMatrix(0, 2) = 1.0;
    inputMatrix(1, 0) = 2.0; inputMatrix(1, 1) = 5.0; inputMatrix(1, 2) = 3.0;
    inputMatrix(2, 0) = 1.0; inputMatrix(2, 1) = 3.0; inputMatrix(2, 2) = 6.0;

    // Calculate eigenvalues and eigenvectors
    Mat<double> eigenvectors, eigenvalues;
    eig(inputMatrix, eigenvectors, eigenvalues);

    // Check if the eigenvalue calculation is correct
    EXPECT_NEAR(eigenvalues(0, 0), 10.1622, 1e-4);
    EXPECT_NEAR(eigenvalues(1, 1), 4.6056, 1e-4);
    EXPECT_NEAR(eigenvalues(2, 2), 0.2322, 1e-4);

    // Check if the eigenvector calculation is correct
    // (Note: You may need to adjust these values based on the specific results expected)
    EXPECT_NEAR(eigenvectors(0, 0), 0.3972, 1e-4);
    EXPECT_NEAR(eigenvectors(1, 1), 0.5662, 1e-4);
    EXPECT_NEAR(eigenvectors(2, 2), 0.7236, 1e-4);
}
