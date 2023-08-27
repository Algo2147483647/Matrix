#ifndef MATRIX_OPERATE_INNER_H
#define MATRIX_OPERATE_INNER_H
#include "Mat.h"
#include "Init.h"
#include "BasicAlgebra.h"

namespace Matrix {
/******************************************************************************
* 
*                    内积空间
* 
******************************************************************************/

	/*---------------- inner product  ----------------*/
	template <typename T>
	inline T dot(Mat<T>& a, Mat<T>& b) {
		if (a.rows != b.rows || a.cols != b.cols)
			exit(-1);
		T res = 0;

		for (int i = 0; i < a.size(); i++)
			res += a[i] * b[i];
		return res;
	}

	template <typename T>
	inline T dot(vector<T>& a, vector<T>& b) {
		if (a.size() != b.size())
			exit(-1);
		T res = 0;

		for (int i = 0; i < a.size(); i++)
			res += a[i] * b[i];
		return res;
	}

	/*---------------- norm ----------------*/
	template <typename T>
	inline T norm(Mat<T>& a) {
		return sqrt(dot(a, a));
	}

	template <typename T>
	inline T norm(Mat<T>& a, const char ctrl) {
		switch (ctrl)
		{
		case 'F': // Frobenius范数
			T res = 0;

			for (int i = 0; i < a.rows(); ++i) {
				for (int j = 0; j < a.cols(); ++j) {
					res += a(i, j) * a(i, j);
				}
			}
			return sqrt(res);
		case '1': // 1范数 (列和的最大值)
		{
			T maxSum = 0;
			for (int j = 0; j < a.cols(); ++j) {
				T colSum = 0;
				for (int i = 0; i < a.rows(); ++i) {
					colSum += std::abs(a(i, j));
				}
				maxSum = std::max(maxSum, colSum);
			}
			return maxSum;
		}
		case 'I': // 无穷范数 (行和的最大值)
		{
			T maxSum = 0;
			for (int i = 0; i < a.rows(); ++i) {
				T rowSum = 0;
				for (int j = 0; j < a.cols(); ++j) {
					rowSum += std::abs(a(i, j));
				}
				maxSum = std::max(maxSum, rowSum);
			}
			return maxSum;
		}
		case '2': return sqrt(dot(a, a));
		default:
			break;
		}
		return 0;
	}

	template <typename T>
	inline T norm(vector<T>& a) {
		return sqrt(dot(a, a));
	}

	template <typename T>
	inline T norm(vector<T>& a, int p) {
		switch (p)
		{
		case 1:  // L1范数
			T ret = 0;
			for (const auto& val : a) {
				ret += std::abs(val);
			}
			return ret;
		case 2: return sqrt(dot(a, a)); // L2范数
		case -1:
			T ret = *std::max_element(a.begin(), a.end(), [](const T& x, const T& y) {
				return std::abs(x) < std::abs(y);
			});
			return std::abs(ret);

		default:
			break;
		}
		return 0;
	}

	/*---------------- normalize -----------------*/
	template <typename T>
	inline Mat<T>& normalize(Mat<T>& a) {
		T t = norm(a);
		if (t == 0)
			return a;

		for (int i = 0; i < a.size(); i++)
			a[i] /= t;

		return a;
	}

	template <typename T>
	inline vector<T>& normalize(vector<T>& a) {
		T t = norm(a);
		if (t == 0)
			return a;

		for (int i = 0; i < a.size(); i++)
			a[i] /= t;

		return a;
	}
}

#endif