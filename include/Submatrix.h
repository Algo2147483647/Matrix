#ifndef MATRIX_SUBMATRIX_H
#define MATRIX_SUBMATRIX_H
#include "Mat.h"

namespace Matrix {
/******************************************************************************
* 
*                    子矩阵
* 
******************************************************************************/
	/*----------------拼接----------------*/
	template <typename T>
	inline Mat<T>& assign(Mat<T>& res, initializer_list<vector<T>> list) {
		res.alloc(list.begin()->size(), list.size());
		int cur = 0;

		for (auto e = list.begin(); e != list.end(); ++e) {
			for (int i = 0; i < e->size(); i++) {
				res(i, cur) = (*e)[i];
			}
			cur++;
		}

		return res;
	}

	template <typename T>
	inline Mat<T>& rowStack(Mat<T>& res, Mat<T>& a, Mat<T>& b) {
		if (a.cols != b.cols)
			exit(-1);

		Mat<T> resTmp(a.rows + b.rows, a.cols);

		for (int i = 0; i < resTmp.rows; i++)
			for (int j = 0; j < resTmp.cols; j++)
				resTmp(i, j) = i < a.rows ? a(i, j) : b(i - a.rows, j);

		res = std::move(resTmp);
		return res;
	}

	template <typename T>
	inline Mat<T>& rowStack(Mat<T>& res, initializer_list<Mat<T>> list) {
		return res;
	}

	template <typename T>
	inline Mat<T>& colStack(Mat<T>& res, Mat<T>& a, Mat<T>& b) {
		if (a.rows != b.rows) 
			exit(-1);

		Mat<T> resTmp(a.rows, a.cols + b.cols);

		for (int i = 0; i < resTmp.rows; i++)
			for (int j = 0; j < resTmp.cols; j++)
				resTmp(i, j) = j < a.cols ? a(i, j) : b(i, j - a.cols);

		res = std::move(resTmp);
		return res;
	}

	template <typename T>
	inline Mat<T>& colStack(Mat<T>& res, initializer_list<Mat<T>> list) {
		return res;
	}

	/*----------------复制拓展----------------*/
	template <typename T>
	inline Mat<T>& colRepeat(Mat<T>& res, Mat<T>& a, int repeatNum) {
		if (a.cols != 1) 
			exit(-1);

		Mat<T> resTmp(a.rows, repeatNum);

		for (int i = 0; i < a.rows; i++)
			for (int j = 0; j < repeatNum; j++)
				resTmp(i, j) = a[i];
		return res = std::move(resTmp);
	}

}
#endif