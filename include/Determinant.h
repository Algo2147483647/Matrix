#ifndef MATRIX_OPERATE_DETERMINANT_H
#define MATRIX_OPERATE_DETERMINANT_H
#include "Mat.h"
#include "Init.h"
#include "BasicAlgebra.h"

namespace Matrix {
/******************************************************************************
* 
*                    行列式
* 
******************************************************************************/
	/*----------------余子式 [ comi ]----------------*/
	template <typename T>
	inline T comi(Mat<T>& a, int i0, int j0) {
		Mat<T> tmp(a.rows - 1, a.cols - 1);
		for (int i = 0; i < a.rows; i++) {
			for (int j = 0; j < a.cols; j++) {
				if (i == i0 || j == j0)
					continue;

				tmp(i < i0 ? i : i - 1, j < j0 ? j : j - 1) = a(i, j);
			}
		}
		return det(a);
	}

	/*---------------- determinant ----------------*/
	template <typename T>
	inline T det(Mat<T>& a) {
		if (a.rows != a.cols)
			exit(-1);

		switch (a.rows) {
		case 0: return 0;
		case 1: return a[0];
		case 2: return a(0, 0) * a(1, 1) - a(0, 1) * a(0, 1);
		case 3: return 
			a(0, 0) * (a(1, 1) * a(2, 2) - a(1, 2) * a(2, 1)) -
			a(0, 1) * (a(1, 0) * a(2, 2) - a(1, 2) * a(2, 0)) +
			a(0, 2) * (a(1, 0) * a(2, 1) - a(1, 1) * a(2, 0));
		default:;
		}

		T res = 0;

		for (int i = 0; i < a.rows; i++)
			res += a(i, 0) * (i % 2 == 0 ? 1 : -1) * comi(a, i, 0);
		return res;
	}

	/*-------------- adjugate matrix ----------------*/
	template <typename T>
	inline Mat<T>& adjugate(Mat<T>& res, Mat<T>& a) {
		Mat<T> resTmp(a.rows, a.cols);
		for (int i = 0; i < a.rows; i++)
			for (int j = 0; j < a.cols; j++)
				resTmp(i, j) = ((i + j) % 2 == 0 ? 1 : -1) * comi(a, i, j);

		res = std::move(resTmp);
		return res;
	}

}

#endif
