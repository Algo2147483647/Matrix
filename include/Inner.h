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
		T ans = 0;

		for (int i = 0; i < a.size(); i++)
			ans += a[i] * b[i];
		return ans;
	}

	template <typename T>
	inline T dot(vector<T>& a, vector<T>& b) {
		if (a.size() != b.size())
			exit(-1);
		T ans = 0;

		for (int i = 0; i < a.size(); i++)
			ans += a[i] * b[i];
		return ans;
	}

	/*---------------- norm ----------------*/
	template <typename T>
	inline T norm(Mat<T>& a) {
		return sqrt(dot(a, a));
	}

	template <typename T>
	inline T norm(Mat<T>& a, const char ctrl) {
		return sqrt(dot(a, a)); //####
	}

	template <typename T>
	inline T norm(vector<T>& a) {
		return sqrt(dot(a, a));
	}

	template <typename T>
	inline T norm(vector<T>& a, const int n) {
		return sqrt(dot(a, a)); //####
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