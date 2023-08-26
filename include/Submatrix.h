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
	inline Mat<>& assign(Mat<>& ans, initializer_list<vector<double>> list) {
		ans.alloc(list.begin()->size(), list.size());
		int cur = 0;

		for (auto e = list.begin(); e != list.end(); ++e) {
			for (int i = 0; i < e->size(); i++) {
				ans(i, cur) = (*e)[i];
			}
			cur++;
		}

		return ans;
	}

	inline Mat<>& rowStack(Mat<>& ans, Mat<>& a, Mat<>& b) {
		if (a.cols != b.cols)
			exit(-1);

		Mat<> ansTmp(a.rows + b.rows, a.cols);

		for (int i = 0; i < ansTmp.rows; i++)
			for (int j = 0; j < ansTmp.cols; j++)
				ansTmp(i, j) = i < a.rows ? a(i, j) : b(i - a.rows, j);

		ans = std::move(ansTmp);
		return ans;
	}

	inline Mat<>& rowStack(Mat<>& ans, initializer_list<Mat<>> list) {
		return ans;
	}

	inline Mat<>& colStack(Mat<>& ans, Mat<>& a, Mat<>& b) {
		if (a.rows != b.rows) 
			exit(-1);

		Mat<> ansTmp(a.rows, a.cols + b.cols);

		for (int i = 0; i < ansTmp.rows; i++)
			for (int j = 0; j < ansTmp.cols; j++)
				ansTmp(i, j) = j < a.cols ? a(i, j) : b(i, j - a.cols);

		ans = std::move(ansTmp);
		return ans;
	}

	inline Mat<>& colStack(Mat<>& ans, initializer_list<Mat<>> list) {
		return ans;
	}

	/*----------------复制拓展----------------*/
	inline Mat<>& colRepeat(Mat<>& ans, Mat<>& a, int repeatNum) {
		if (a.cols != 1) 
			exit(-1);

		Mat<> ansTmp(a.rows, repeatNum);

		for (int i = 0; i < a.rows; i++)
			for (int j = 0; j < repeatNum; j++)
				ansTmp(i, j) = a[i];
		return ans = std::move(ansTmp);
	}

}
#endif