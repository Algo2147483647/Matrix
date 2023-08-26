#ifndef MATRIX_TRANSFORM_H
#define MATRIX_TRANSFORM_H
#include "Mat.h"
#include "Init.h"
#include "BasicAlgebra.h"
#include "Inner.h"

/****************************************************************
* 
* Construction of linear transformation matrix
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
    res(i, i) = res(j, j) = cos(theta);
    res(i, j) = sin(theta);
    res(j, i) =-sin(theta);
    return res;
}

template <typename T>
inline Mat<T>& rotate(Mat<T>& theta, Mat<T>& res) {
    E(res.alloc(theta.rows, theta.cols));
    Mat<T> rotateMat = res;

    for (int i = 0; i < theta.rows; i++) {
        for (int j = i + 1; j < theta.cols; j++) {
            mul(res, rotate(i, j, theta(i, j), rotateMat), res);
        }
    }
    return res;
}

//3D·四元数
template <typename T>
inline Mat<T>& rotate(Mat<T>& rotateAxis, double theta, Mat<T>& res) {
    E(res.alloc(4, 4));
    
    normalize(rotateAxis);
    static Mat<T> q(4), tmp;				//四元数
    q = {
        cos(theta / 2),
        sin(theta / 2) * rotateAxis[0],
        sin(theta / 2) * rotateAxis[1],
        sin(theta / 2) * rotateAxis[2]
    };

    // rotate mats
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            res(i, j) = q[((j % 2 == 0 ? 1 : -1) * i + j + 4) % 4];

    for (int i = 1; i < 4; i++)
        res(i, i % 3 + 1) *= -1;

    tmp = T;
    for (int i = 1; i < 4; i++) {
        res(0, i) *= -1;
        tmp(i, 0) *= -1;
    }

    mul(res, res, tmp);
    return res;
}

/****************************************************************
* 反射变换
****************************************************************/
template <typename T>
inline Mat<T>& reflect(Mat<T>& e, Mat<T>& res) {
    Mat<T> tmp;

    transpose(tmp, e);
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
    transpose(tmp, X);
    mul(res, tmp, X);

    //# inv(res, res);
    mul(res, X, res);

    transpose(tmp, X);
    mul(res, res, tmp);
    return res;
}

/****************************************************************
* 正交化
****************************************************************/
/*
void orthogonalize (Mat<T>& A) {
    Mat<T> q;
    q[0].normalize();
    q[1] -= t1.mul(q[1].dot(q[0]), q[0]);   //施密特正交化
    q[1].normalize();
    q[2] -= t1.mul(q[2].dot(q[0]), q[0]);
    q[2] -= t1.mul(q[2].dot(q[1]), q[1]);
    q[2].normalize();
    q[3] -= t1.mul(q[3].dot(q[0]), q[0]);
    q[3] -= t1.mul(q[3].dot(q[1]), q[1]);
    q[3] -= t1.mul(q[3].dot(q[2]), q[2]);
    q[3].normalize();
}*/

}

#endif