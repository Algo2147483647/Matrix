#ifndef MATRIX_OPERATE_SUM_H
#define MATRIX_OPERATE_SUM_H
#include "Mat.h"
#include "Init.h"
#include "BasicAlgebra.h"

namespace Matrix {
	/******************************************************************************
	*
	*                    求和
	*
	******************************************************************************/

	/*---------------- max/min ----------------*/
	template <typename T>
	inline T max(Mat<T>& a) {
		T res = a[0];
		for (int i = 1; i < a.size(); i++)
			res = res >= a[i] ? res : a[i];
		return res;
	}

	template <typename T>
	inline T min(Mat<T>& a) {
		T res = a[0];
		for (int i = 1; i < a.size(); i++)
			res = res <= a[i] ? res : a[i];
		return res;
	}

	template <typename T>
	inline T max(vector<T>& a) {
		T res = a[0];
		for (int i = 1; i < a.size(); i++)
			res = res >= a[i] ? res : a[i];
		return res;
	}

	template <typename T>
	inline T min(vector<T>& a) {
		T res = a[0];
		for (int i = 1; i < a.size(); i++)
			res = res <= a[i] ? res : a[i];
		return res;
	}

	template <typename T>
	inline T max(Mat<T>& a, int& index) {
		T res = a[0];
		index = 0;

		for (int i = 1; i < a.size(); i++)
			if (res < a[i]) {
				res = a[i];
				index = i;
			}
		return res;
	}

	template <typename T>
	inline T min(Mat<T>& a, int& index) {
		T res = a[0];
		index = 0;

		for (int i = 1; i < a.size(); i++)
			if (res > a[i]) {
				res = a[i];
				index = i;
			}
		return res;
	}

	// 行/列
	template <typename T>
	inline Mat<T>& max(Mat<T>& res, Mat<T>& a, int index) {
		if (index == 0) {
			res.alloc(a.rows);

			for (int x = 0; x < a.rows; x++)
				res[x] = a(x, 0);

			for (int x = 0; x < a.rows; x++)
				for (int y = 0; y < a.cols; y++)
					res(x) = res(x) >= a(x, y) ? res(x) : a(x, y);
			return res;
		}
		else {
			res.alloc(1, a.cols);

			for (int y = 0; y < a.cols; y++)
				res[y] = a(0, y);

			for (int x = 0; x < a.rows; x++)
				for (int y = 0; y < a.cols; y++)
					res(y) = res(y) >= a(x, y) ? res(y) : a(x, y);
			return res;
		}
	}

	template <typename T>
	inline Mat<T>& min(Mat<T>& res, Mat<T>& a, int index) {
		if (index == 0) {
			res.alloc(a.rows);

			for (int x = 0; x < a.rows; x++)
				res[x] = a(x, 0);

			for (int x = 0; x < a.rows; x++)
				for (int y = 0; y < a.cols; y++)
					res(x) = res(x) <= a(x, y) ? res(x) : a(x, y);
			return res;
		}
		else {
			res.alloc(1, a.cols);

			for (int y = 0; y < a.cols; y++)
				res[y] = a(0, y);

			for (int x = 0; x < a.rows; x++)
				for (int y = 0; y < a.cols; y++)
					res(y) = res(y) <= a(x, y) ? res(y) : a(x, y);
			return res;
		}
	}

	/*---------------- 求和 ----------------*/
	template <typename T>
	inline T sum(Mat<T>& a) {
		T res = 0;
		for (int i = 1; i < a.size(); i++)
			res += a[i];
		return res;
	}

	template <typename T>
	inline Mat<T>& sum(Mat<T>& res, Mat<T>& a, int dim) {
		if (dim == 0) {				//对每一列求和
			Mat<T> resTmp(1, a.cols);

			for (int j = 0; j < a.cols; j++)
				for (int i = 0; i < a.rows; i++)
					resTmp[j] += a(i, j);

			res = std::move(resTmp);
			return res;
		}

		if (dim == 1) {				//对每一行求和
			Mat<T> resTmp(a.rows);
			for (int i = 0; i < a.rows; i++)
				for (int j = 0; j < a.cols; j++)
					resTmp[i] += a(i, j);

			res = std::move(resTmp);
			return res;
		}
		exit(-1);
		return res;
	}

	/*---------------- 求积 ----------------*/
	template <typename T>
	inline T product(Mat<T>& a) {
		T res = 0;
		for (int i = 1; i < a.size(); i++)
			res *= a[i];
		return res;
	}

}

#endif