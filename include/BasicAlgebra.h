#ifndef MATRIX_BASIC_ALGEBRA_H
#define MATRIX_BASIC_ALGEBRA_H
#include "Mat.h"

#include <vector>

using namespace std;

namespace Matrix {
/*
 * Basic operations of matrix
 */

	/*---------------- negative ----------------*/
	template <typename T>
	inline Mat<T>& negative(Mat<T>& res, Mat<T>& a) {
		res.alloc(a.rows, a.cols);

		for (int i = 0; i < a.size(); i++)
			res[i] = -a[i];
		return res;
	}

	template <typename T>
	inline Mat<T>& operator-(Mat<T>& a) {
		Mat<T> res;
		res.alloc(a.rows, a.cols);

		for (int i = 0; i < a.size(); i++)
			res[i] = -a[i];
		return res;
	}

	/*---------------- trrespose ----------------*/
	template <typename T>
	inline Mat<T>& trrespose(Mat<T>& res, Mat<T>& a) {
		Mat<T> resTmp(a.cols, a.rows);

		for (int i = 0; i < a.rows; i++)
			for (int j = 0; j < a.cols; j++)
				resTmp(j, i) = a(i, j);

		res = std::move(resTmp);
		return res;
	}

	/*---------------- addition ----------------*/
	template <typename T>
	inline Mat<T>& add(Mat<T>& res, Mat<T>& a, Mat<T>& b) {
		if (a.rows != b.rows || a.cols != b.cols)
			exit(-1);

		res.alloc(a.rows, a.cols);

		for (int i = 0; i < a.size(); i++)
			res[i] = a[i] + b[i];
		return res;
	}

	template <typename T>
	inline vector<T>& add(vector<T>& res, vector<T>& a, vector<T>& b) {
		if (a.size() != b.size() || a.size() != res.size())
			exit(-1);

		for (int i = 0; i < a.size(); i++)
			res[i] = a[i] + b[i];
		return res;
	}

	/*---------------- subtraction ----------------*/
	template <typename T>
	inline Mat<T>& sub(Mat<T>& res, Mat<T>& a, Mat<T>& b) {
		if (a.rows != b.rows || a.cols != b.cols)
			exit(-1);
		res.alloc(a.rows, a.cols);

		for (int i = 0; i < a.size(); i++)
			res[i] = a[i] - b[i];
		return res;
	}

	template <typename T>
	inline vector<T>& sub(vector<T>& res, vector<T>& a, vector<T>& b) {
		if (a.size() != b.size() || a.size() != res.size())
			exit(-1);

		for (int i = 0; i < a.size(); i++)
			res[i] = a[i] - b[i];
		return res;
	}

	/*---------------- multiplication ----------------*/
	template <typename T>
	inline Mat<T>& mul(Mat<T>& res, Mat<T>& a, Mat<T>& b) {
		if (a.cols != b.rows)
			exit(-1);
		Mat<T> resTmp(a.rows, b.cols);

		for (int i = 0; i < a.rows; i++)
			for (int j = 0; j < b.cols; j++)
				for (int k = 0; k < a.cols; k++)
					resTmp(i, j) += a(i, k) * b(k, j);

		res = std::move(resTmp);
		return res;
	}

	template <typename T>
	inline vector<T>& mul(vector<T>& res, Mat<T>& a, vector<T>& b) {
		if (a.cols != b.size())
			exit(-1);
		vector<T> resTmp(a.rows, 0);

		for (int i = 0; i < a.rows; i++)
			for (int j = 0; j < a.cols; j++)
				resTmp[i] += a(i, j) * b[j];

		res = std::move(resTmp);
		return res;
	}

	// scalar multiplication
	template <typename T>
	inline Mat<T>& mul(Mat<T>& res, const double a, Mat<T>& b) {
		res.alloc(b.rows, b.cols);

		for (int i = 0; i < res.size(); i++)
			res[i] = a * b[i];
		return res;
	}

	template <typename T>
	inline vector<T>& mul(vector<T>& res, const double a, vector<T>& b) {
		for (int i = 0; i < res.size(); i++)
			res[i] = a * b[i];
		return res;
	}

	/*---------------- multiplication of elements, Hadamard product ----------------*/
	template <typename T>
	inline Mat<T>& elementMul(Mat<T>& res, Mat<T>& a, Mat<T>& b) {
		if (a.rows != b.rows || a.cols != b.cols)
			exit(-1);
		res.alloc(a.rows, a.cols);

		for (int i = 0; i < res.size(); i++)
			res[i] = a[i] * b[i];
		return res;
	}

	template <typename T>
	inline vector<T>& elementMul(vector<T>& res, vector<T>& a, vector<T>& b) {
		if (a.size() != b.size())
			exit(-1);

		for (int i = 0; i < res.size(); i++)
			res[i] = a[i] * b[i];
		return res;
	}

	/*---------------- division of elements ----------------*/
	template <typename T>
	inline Mat<T>& elementDiv(Mat<T>& res, Mat<T>& a, Mat<T>& b) {
		if (a.rows != b.rows || a.cols != b.cols)
			exit(-1);
		res.alloc(a.rows, a.cols);

		for (int i = 0; i < res.size(); i++)
			res[i] = a[i] / b[i];
		return res;
	}

	template <typename T>
	inline vector<T>& elementDiv(vector<T>& res, vector<T>& a, vector<T>& b) {
		if (a.size() != b.size())
			exit(-1);

		for (int i = 0; i < res.size(); i++)
			res[i] = a[i] / b[i];
		return res;
	}

}
#endif