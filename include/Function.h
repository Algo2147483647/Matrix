#ifndef MATRIX_FUNCTION_H
#define MATRIX_FUNCTION_H
#include "Mat.h"
#include "Init.h"

namespace Matrix {
	/*---------------- function ----------------*/
	template<typename F, typename T>
	Mat<T>& function(Mat<T>& ans, Mat<T>& x, F&& f) {
		ans.alloc(x.rows, x.cols);
		for (int i = 0; i < x.size(); i++)
			ans[i] = f(x[i]);
		return *this;
	}

	template<typename F, typename T>
	Mat<T>& function(Mat<T>& ans, F&& f) {
		for (int i = 0; i < ans.size(); i++)
			ans[i] = f(ans[i]);
		return *this;
	}

	template<typename F, typename T>
	Mat<T>& functionIndex(Mat<T>& ans, Mat<T>& x, F&& f) {
		ans.alloc(x.rows, x.cols);
		for (int i = 0; i < x.size(); i++)
			ans[i] = f(x[i], i);
		return *this;
	}

	template<typename F, typename T>
	Mat<T>& functionIndex(Mat<T>& ans, F&& f) {
		for (int i = 0; i < ans.size(); i++)
			ans[i] = f(ans[i], i);
		return *this;
	}
}

#endif