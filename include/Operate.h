#ifndef MATRIX_OPERATE_H
#define MATRIX_OPERATE_H

#include "LinearAlgebra.h"
#include "Conv.h"
#include "Sum.h"

namespace Matrix {
	/*---------------- ½»»»Êý¾Ý ----------------*/
	template<class T>
	void swap(Mat<T>& a, Mat<T>& b) {
		std::swap(a.data, b.data);
		std::swap(a.rows, b.rows);
		std::swap(a.cols, b.cols);
		return;
	}

	/*
	 * Binarization
	 */
	template <typename T>
	inline Mat<T>& binarization(Mat<T>& ans, Mat<T>& a, double threshold = 0.5) {
		ans.alloc(a.rows, a.cols);

		for (int i = 0; i < a.size(); i++)
			ans(i) = a(i) >= threshold ? 1 : 0;

		return ans;
	}
}

#endif