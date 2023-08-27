#ifndef MATRIX_OPERATE_CROSSPRODUCT_H
#define MATRIX_OPERATE_CROSSPRODUCT_H
#include "Mat.h"
#include "Init.h"
#include "BasicAlgebra.h"

namespace Matrix {
	/******************************************************************************
	*
	*                    叉乘
	*
	******************************************************************************/

	template <typename T>
	inline Mat<T>& cross(Mat<T>& res, Mat<T>& a, Mat<T>& b) {
		if (a.rows != b.rows)
			exit(-1);

		Mat<T> resTmp(a.rows, a.cols);
		resTmp[0] = a[1] * b[2] - a[2] * b[1];
		resTmp[1] = a[2] * b[0] - a[0] * b[2];
		resTmp[2] = a[0] * b[1] - a[1] * b[0];

		res = std::move(resTmp);
		return res;
	}

	template <typename T>
	inline vector<T>& cross(vector<T>& res, vector<T>& a, vector<T>& b) {
		if (a.size() != b.size())
			exit(-1);

		vector<T> resTmp(a.size());
		resTmp[0] = a[1] * b[2] - a[2] * b[1];
		resTmp[1] = a[2] * b[0] - a[0] * b[2];
		resTmp[2] = a[0] * b[1] - a[1] * b[0];

		res = std::move(resTmp);
		return res;
	}

	template <typename T>
	inline Mat<T>& cross_(Mat<T>& res, Mat<T>& a, Mat<T>& b) {
		if (a.rows != b.rows)
			exit(-1);

		res.alloc(a.rows, a.cols);
		res[0] = a[1] * b[2] - a[2] * b[1];
		res[1] = a[2] * b[0] - a[0] * b[2];
		res[2] = a[0] * b[1] - a[1] * b[0];
		return res;
	}

}

#endif