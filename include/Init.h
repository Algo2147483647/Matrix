#ifndef MATRIX_INIT_H
#define MATRIX_INIT_H
#include "Mat.h"

using namespace std;

namespace Matrix {
/*---------------- Identity matrix ----------------*/
template <typename T>
	inline Mat<T>& E(Mat<T>& a) {
	a.zero();
	for (int i = 0; i < a.rows; i++)
		a(i, i) = 1;
	return a;
}

/*---------------- All 1 matrix ----------------*/
template <typename T>
	inline Mat<T>& ones(Mat<T>& a) {
	a.fill(1);
	return a;
}

/*---------------- random matrix ----------------*/
template <typename T>
	inline Mat<T>& rands(Mat<T>& a, T st, T ed) {
	for (int i = 0; i < a.size(); i++)
		a[i] = rand() / T(RAND_MAX) * (ed - st) + st;	//[st,ed)
	return a;
}

/*---------------- Linear spacing vector ----------------*/
template <typename T>
	inline Mat<T>& linspace(Mat<T>& a, T xs, T xe, int n = 2) {
	T dx = (xe - xs) / (n - 1);
	a.alloc(n);

	for (int i = 0; i < n; i++)
		a[i] = xs + dx * i;
	a[n - 1] = xe;

	return a;
}

template <typename T>
	inline vector<T>& linspace(vector<T>& a, T xs, T xe, int n = 2) {
	T dx = (xe - xs) / (n - 1);
	a.resize(n);

	for (int i = 0; i < n - 1; i++)
		a[i] = xs + dx * i;
	a[n - 1] = xe;

	return a;
}

/*---------------- Diagonal matrix ----------------*/
template <typename T>
	inline Mat<T>& diag(Mat<T>& a, Mat<T>& b) {
	if (b.rows == b.cols) {
		a.alloc(a.rows);

		for (int i = 0; i < a.rows; i++)
			a[i] = b(i, i);
	}
	else if (b.rows == 1 || b.cols == 1) {
		int n = b.rows > b.cols ? b.rows : b.cols;
		a.alloc(n, n);

		for (int i = 0; i < n; i++)
			a(i, i) = b[i];
	}
	else
		exit(-1);
	return a;
}

}
#endif