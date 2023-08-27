#ifndef MATRIX_OPERATE_CONV_H
#define MATRIX_OPERATE_CONV_H
#include "Mat.h"

namespace Matrix {
/******************************************************************************
* 
*                    卷积
* 
******************************************************************************/
	/* 卷积 */
	template <typename T>
	inline Mat<T>& conv(Mat<T>& res, const Mat<T>& a, const Mat<T>& b, int padding = 0, int stride = 1) {
		Mat<T> resTmp(
			(a.rows - b.rows + 2 * padding) / stride + 1,
			(a.cols - b.cols + 2 * padding) / stride + 1
		);

		// for each element of output
		for (int y = 0; y < resTmp.cols; y++) {
			for (int x = 0; x < resTmp.rows; x++) {

				// for each element of b
				for (int ky = 0; ky < b.cols; ky++) {
					for (int kx = 0; kx < b.rows; kx++) {

						// get the corresponding element of a
						int xt = -padding + x * stride + kx,
							yt = -padding + y * stride + ky;
						resTmp(x, y) += (xt < 0 || xt >= a.rows || yt < 0 || yt >= a.cols) ? 0 : a(xt, yt) * b(kx, ky);
					}
				}
			}
		}
		res = std::move(resTmp);
		return res;
	}
}

#endif