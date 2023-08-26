#ifndef MATRIX_BASIC_ALGEBRA_H
#define MATRIX_BASIC_ALGEBRA_H
#include "Mat.h"
#include "Init.h"

#include <vector>

using namespace std;

namespace Matrix {
/*
 * Basic operations of matrix
 */

	/*---------------- negative ----------------*/
	template <typename T>
	inline Mat<T>& negative(Mat<T>& ans, Mat<T>& a) {
		ans.alloc(a.rows, a.cols);

		for (int i = 0; i < a.size(); i++)
			ans[i] = -a[i];
		return ans;
	}

	template <typename T>
	inline Mat<T>& operator-(Mat<T>& a) {
		Mat<T> ans;
		ans.alloc(a.rows, a.cols);

		for (int i = 0; i < a.size(); i++)
			ans[i] = -a[i];
		return ans;
	}

	/*---------------- transpose ----------------*/
	template <typename T>
	inline Mat<T>& transpose(Mat<T>& ans, Mat<T>& a) {
		Mat<T> ansTmp(a.cols, a.rows);

		for (int i = 0; i < a.rows; i++)
			for (int j = 0; j < a.cols; j++)
				ansTmp(j, i) = a(i, j);

		ans = std::move(ansTmp);
		return ans;
	}

	/*---------------- addition ----------------*/
	template <typename T>
	inline Mat<T>& add(Mat<T>& ans, Mat<T>& a, Mat<T>& b) {
		if (a.rows != b.rows || a.cols != b.cols)
			exit(-1);

		ans.alloc(a.rows, a.cols);

		for (int i = 0; i < a.size(); i++)
			ans[i] = a[i] + b[i];
		return ans;
	}

	template <typename T>
	inline vector<T>& add(vector<T>& ans, vector<T>& a, vector<T>& b) {
		if (a.size() != b.size() || a.size() != ans.size())
			exit(-1);

		for (int i = 0; i < a.size(); i++)
			ans[i] = a[i] + b[i];
		return ans;
	}

	/*---------------- subtraction ----------------*/
	template <typename T>
	inline Mat<T>& sub(Mat<T>& ans, Mat<T>& a, Mat<T>& b) {
		if (a.rows != b.rows || a.cols != b.cols)
			exit(-1);
		ans.alloc(a.rows, a.cols);

		for (int i = 0; i < a.size(); i++)
			ans[i] = a[i] - b[i];
		return ans;
	}

	template <typename T>
	inline vector<T>& sub(vector<T>& ans, vector<T>& a, vector<T>& b) {
		if (a.size() != b.size() || a.size() != ans.size())
			exit(-1);

		for (int i = 0; i < a.size(); i++)
			ans[i] = a[i] - b[i];
		return ans;
	}

	/*---------------- multiplication ----------------*/
	template <typename T>
	inline Mat<T>& mul(Mat<T>& ans, Mat<T>& a, Mat<T>& b) {
		if (a.cols != b.rows)
			exit(-1);
		Mat<T> ansTmp(a.rows, b.cols);

		for (int i = 0; i < a.rows; i++)
			for (int j = 0; j < b.cols; j++)
				for (int k = 0; k < a.cols; k++)
					ansTmp(i, j) += a(i, k) * b(k, j);

		ans = std::move(ansTmp);
		return ans;
	}

	template <typename T>
	inline vector<T>& mul(vector<T>& ans, Mat<T>& a, vector<T>& b) {
		if (a.cols != b.size())
			exit(-1);
		vector<T> ansTmp(a.rows, 0);

		for (int i = 0; i < a.rows; i++)
			for (int j = 0; j < a.cols; j++)
				ansTmp[i] += a(i, j) * b[j];

		ans = std::move(ansTmp);
		return ans;
	}

	// scalar multiplication
	template <typename T>
	inline Mat<T>& mul(Mat<T>& ans, const double a, Mat<T>& b) {
		ans.alloc(b.rows, b.cols);

		for (int i = 0; i < ans.size(); i++)
			ans[i] = a * b[i];
		return ans;
	}

	template <typename T>
	inline vector<T>& mul(vector<T>& ans, const double a, vector<T>& b) {
		for (int i = 0; i < ans.size(); i++)
			ans[i] = a * b[i];
		return ans;
	}

	/*---------------- multiplication of elements, Hadamard product ----------------*/
	template <typename T>
	inline Mat<T>& elementMul(Mat<T>& ans, Mat<T>& a, Mat<T>& b) {
		if (a.rows != b.rows || a.cols != b.cols)
			exit(-1);
		ans.alloc(a.rows, a.cols);

		for (int i = 0; i < ans.size(); i++)
			ans[i] = a[i] * b[i];
		return ans;
	}

	template <typename T>
	inline vector<T>& elementMul(vector<T>& ans, vector<T>& a, vector<T>& b) {
		if (a.size() != b.size())
			exit(-1);

		for (int i = 0; i < ans.size(); i++)
			ans[i] = a[i] * b[i];
		return ans;
	}

	/*---------------- division of elements ----------------*/
	template <typename T>
	inline Mat<T>& elementDiv(Mat<T>& ans, Mat<T>& a, Mat<T>& b) {
		if (a.rows != b.rows || a.cols != b.cols)
			exit(-1);
		ans.alloc(a.rows, a.cols);

		for (int i = 0; i < ans.size(); i++)
			ans[i] = a[i] / b[i];
		return ans;
	}

	template <typename T>
	inline vector<T>& elementDiv(vector<T>& ans, vector<T>& a, vector<T>& b) {
		if (a.size() != b.size())
			exit(-1);

		for (int i = 0; i < ans.size(); i++)
			ans[i] = a[i] / b[i];
		return ans;
	}

}
#endif