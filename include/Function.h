#ifndef MATRIX_FUNCTION_H
#define MATRIX_FUNCTION_H
#include "Mat.h"
#include "Init.h"

namespace Matrix {
	/*---------------- function ----------------*/
	template<typename F, typename T>
	Mat<T>& function(Mat<T>& res, Mat<T>& x, F&& f) {
		res.alloc(x.rows, x.cols);
		for (int i = 0; i < x.size(); i++)
			res[i] = f(x[i]);
		return *this;
	}

	template<typename F, typename T>
	Mat<T>& function(Mat<T>& res, F&& f) {
		for (int i = 0; i < res.size(); i++)
			res[i] = f(res[i]);
		return *this;
	}

	template<typename F, typename T>
	Mat<T>& functionIndex(Mat<T>& res, Mat<T>& x, F&& f) {
		res.alloc(x.rows, x.cols);
		for (int i = 0; i < x.size(); i++)
			res[i] = f(x[i], i);
		return *this;
	}

	template<typename F, typename T>
	Mat<T>& functionIndex(Mat<T>& res, F&& f) {
		for (int i = 0; i < res.size(); i++)
			res[i] = f(res[i], i);
		return *this;
	}
}

#endif