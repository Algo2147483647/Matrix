#ifndef MATRIX_OPERATE_SUM_H
#define MATRIX_OPERATE_SUM_H

#include <algorithm>
#include "Mat.h"
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
		return *std::max_element(a.begin(), a.end());
	}

	template <typename T>
	inline T min(vector<T>& a) {
		return *std::min_element(a.begin(), a.end());
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

	template <typename Container>
	typename Container::value_type max(const Container& a, int& index) {
		auto it = std::max_element(a.begin(), a.end());
		index = std::distance(a.begin(), it);
		return *it;
	}

	template <typename Container>
	typename Container::value_type min(const Container& a, int& index) {
		auto it = std::min_element(a.begin(), a.end());
		index = std::distance(a.begin(), it);
		return *it;
	}

	// 行/列
	template <typename T>
	inline vector<T>& max(vector<T>& res, Mat<T>& a, int dim) {
		if (dim == 0) {
			res.resize(a.rows);

			for (int x = 0; x < a.rows; x++)
				res[x] = a(x, 0);

			for (int x = 0; x < a.rows; x++)
				for (int y = 0; y < a.cols; y++)
					res[x] = res[x] >= a(x, y) ? res[x] : a(x, y);
		}
		else {
			res.resize(a.cols);

			for (int y = 0; y < a.cols; y++)
				res[y] = a(0, y);

			for (int x = 0; x < a.rows; x++)
				for (int y = 0; y < a.cols; y++)
					res[y] = res[y] >= a(x, y) ? res[y] : a(x, y);
		}

		return res;
	}

	template <typename T>
	inline vector<T>& min(vector<T>& res, Mat<T>& a, int dim) {
		if (dim == 0) {
			res.resize(a.rows);

			for (int x = 0; x < a.rows; x++)
				res[x] = a(x, 0);

			for (int x = 0; x < a.rows; x++)
				for (int y = 0; y < a.cols; y++)
					res[x] = res[x] <= a(x, y) ? res[x] : a(x, y);
		}
		else {
			res.resize(a.cols);

			for (int y = 0; y < a.cols; y++)
				res[y] = a(0, y);

			for (int x = 0; x < a.rows; x++)
				for (int y = 0; y < a.cols; y++)
					res[y] = res[y] <= a(x, y) ? res[y] : a(x, y);
		}

		return res;
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
	inline vector<T>& sum(vector<T>& res, Mat<T>& a, int dim) {
		if (dim == 0) {				//对每一列求和
			res.resize(a.rows);
			fill(res.begin(), res.end(), 0);

			for (int j = 0; j < a.cols; j++)
				for (int i = 0; i < a.rows; i++)
					res[j] += a(i, j);
		}
		else {					//对每一行求和
			res.resize(a.cols);
			fill(res.begin(), res.end(), 0);

			for (int i = 0; i < a.rows; i++)
				for (int j = 0; j < a.cols; j++)
					res[i] += a(i, j);
		}
		
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