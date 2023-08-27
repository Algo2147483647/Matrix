#ifndef LINEAR_ALGEBRA
#define LINEAR_ALGEBRA

#include "BasicAlgebra.h"
#include "Inner.h"
#include "Determinant.h"
#include "Inv.h"
#include "CrossProduct.h"

namespace Matrix {
    // �������ļ�
    template<typename T>
    inline double trace(const Mat<T>& mat) {
        T tr = 0;
        for (size_t i = 0; i < mat.rows; ++i) {
            tr += mat[i][i];
        }
        return tr;
    }

    // �жϾ����Ƿ��ǶԳƵ�
    template<typename T>
    inline bool isSymmetric(const Mat<T>& mat) {
        for (size_t i = 0; i < mat.rows; ++i) {
            for (size_t j = i + 1; j < mat.cols; ++j) {
                if (mat(i, j) != mat(j, i)) {
                    return false;
                }
            }
        }
        return true;
    }

    // �жϾ����Ƿ��������ģ�Cholesky�ֽⷽ����
    template<typename T>
    inline bool isPositiveDefinite(const Mat<T>& mat) {
        Mat<T> L(mat.rows, mat.cols);

        for (size_t i = 0; i < mat.rows; ++i) {
            for (size_t j = 0; j <= i; ++j) {
                T sum = 0;

                for (size_t k = 0; k < j; ++k) {
                    sum += L(i, k) * L(j, k);
                }

                if (i == j) {
                    L(i, j) = std::sqrt(mat(i, i) - sum);
                    if (L(i, j) <= 0) return false; // ����Խ������з��������������������
                }
                else {
                    L(i, j) = (1.0 / L(j, j) * (mat(i, j) - sum));
                }
            }
        }
        return true;
    }

    // ����������
    template<typename T>
    inline int rank(const Mat<T>& mat) {
        int r = 0;

        ;
        return r;
    }
}

#endif // !LINEAR_ALGEBRA
