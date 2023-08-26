#ifndef MATRIX_OPERATE_CROSSPRODUCT_H
#define MATRIX_OPERATE_CROSSPRODUCT_H
#include "Mat.h"
#include "Init.h"
#include "BasicOperate.h"

namespace Matrix {
	/******************************************************************************
	*
	*                    叉乘
	*
	******************************************************************************/

	template <typename T>
	inline Mat<T>& cross(Mat<T>& ans, Mat<T>& a, Mat<T>& b) {
		if (a.rows != b.rows)
			exit(-1);

		Mat<T> ansTmp(a.rows, a.cols);
		ansTmp[0] = a[1] * b[2] - a[2] * b[1];
		ansTmp[1] = a[2] * b[0] - a[0] * b[2];
		ansTmp[2] = a[0] * b[1] - a[1] * b[0];

		ans = std::move(ansTmp);
		return ans;
	}

	template <typename T>
	inline vector<T>& cross(vector<T>& ans, vector<T>& a, vector<T>& b) {
		if (a.size() != b.size())
			exit(-1);

		vector<T> ansTmp(a.size());
		ansTmp[0] = a[1] * b[2] - a[2] * b[1];
		ansTmp[1] = a[2] * b[0] - a[0] * b[2];
		ansTmp[2] = a[0] * b[1] - a[1] * b[0];

		ans = ansTmp;
		return ans;
	}

	template <typename T>
	inline Mat<T>& cross_(Mat<T>& ans, Mat<T>& a, Mat<T>& b) {
		if (a.rows != b.rows)
			exit(-1);

		ans.alloc(a.rows, a.cols);
		ans[0] = a[1] * b[2] - a[2] * b[1];
		ans[1] = a[2] * b[0] - a[0] * b[2];
		ans[2] = a[0] * b[1] - a[1] * b[0];
		return ans;
	}

}

#endif