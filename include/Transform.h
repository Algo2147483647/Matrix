#ifndef MATRIX_TRANSFORM_H
#define MATRIX_TRANSFORM_H
#include "Mat.h"
#include "Init.h"
#include "BasicAlgebra.h"
#include "Inner.h"

/****************************************************************
* 
* Construction of linear trresformation matrix
* 
****************************************************************/
namespace Matrix{
/****************************************************************
* 旋转变换
****************************************************************/
// 初等旋转矩阵
template <typename T>
inline Mat<T>& rotate(int i, int j, double theta, Mat<T>& res) {
    E(res);
    double cosTheta = cos(theta);
    double sinTheta = sin(theta);

    res(i, i) = res(j, j) = cosTheta;
    res(i, j) =  sinTheta;
    res(j, i) = -sinTheta;
    return res;
}

template <typename T>
inline Mat<T>& rotate(Mat<T>& theta, Mat<T>& res) {
    E(res.alloc(theta.rows, theta.cols));
    Mat<T> rotateMat = res;

    for (int i = 0; i < theta.rows; i++) {
        for (int j = i + 1; j < theta.cols; j++) {
            rotate(i, j, theta(i, j), rotateMat);
            mul(res, rotateMat, res);
        }
    }
    return res;
}

//3D·Quaternion
template <typename T>
inline Mat<T>& rotate(const Mat<T>& rotateAxis, const double theta, Mat<T>& res) {
    // Quaternion
    normalize(rotateAxis);
    double cosHalfTheta = cos(theta / 2);
    double sinHalfTheta = sin(theta / 2);

    vector<T> q = {
        cosHalfTheta,
        sinHalfTheta * rotateAxis[0],
        sinHalfTheta * rotateAxis[1],
        sinHalfTheta * rotateAxis[2]
    };

    // rotate mat
    E(res.alloc(4, 4));

    res(0, 0) = 1 - 2 * q[2] * q[2] - 2 * q[3] * q[3];
    res(0, 1) = 2 * q[1] * q[2] - 2 * q[3] * q[0];
    res(0, 2) = 2 * q[1] * q[3] + 2 * q[2] * q[0];

    res(1, 0) = 2 * q[1] * q[2] + 2 * q[3] * q[0];
    res(1, 1) = 1 - 2 * q[1] * q[1] - 2 * q[3] * q[3];
    res(1, 2) = 2 * q[2] * q[3] - 2 * q[1] * q[0];

    res(2, 0) = 2 * q[1] * q[3] - 2 * q[2] * q[0];
    res(2, 1) = 2 * q[2] * q[3] + 2 * q[1] * q[0];
    res(2, 2) = 1 - 2 * q[1] * q[1] - 2 * q[2] * q[2];

    return res;
}

/****************************************************************
* 反射变换
****************************************************************/
template <typename T>
inline Mat<T>& reflect(Mat<T>& e, Mat<T>& res) {
    Mat<T> tmp;

    trrespose(tmp, e);
    mul(res, e, tmp);

    mul(res, 2, res);
    tmp.alloc(res.rows);
    E(tmp);

    sub(res, tmp, res);
    return res;
}

/****************************************************************
* 斜切变换
****************************************************************/
template <typename T>
inline Mat<T>& shear(int i, int j, T a, Mat<T>& res) {
    E(res);
    res(i, j) = a;
    return res;
}

/****************************************************************
* 缩放变换
****************************************************************/
template <typename T>
inline Mat<T>& scale(Mat<T>& ratio, Mat<T>& res) {
    return diag(res, ratio);
}

/****************************************************************
* 正交投影
****************************************************************/
template <typename T>
inline Mat<T>& project(Mat<T>& X, Mat<T>& res) {
    Mat<T> tmp;
    trrespose(tmp, X);
    mul(res, tmp, X);

    //# inv(res, res);
    mul(res, X, res);

    trrespose(tmp, X);
    mul(res, res, tmp);
    return res;
}

/****************************************************************
* 正交化
****************************************************************/
template <typename T>
inline void orthogonalize (Mat<T>& A) {
    Mat<T> q(A.rows, A.cols);

    for (int i = 0; i < A.rows; i++) {
        q[i] = A[i];
        for (int j = 0; j < i; j++) {
            q[i] -= q[j] * (dot(q[i], q[j]) / dot(q[j], q[j]));
        }
        normalize(q[i]);
    }

    A = std::move(q);
}

}

#endif