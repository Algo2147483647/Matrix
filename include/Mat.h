#ifndef MATRIX_MAT_H
#define MATRIX_MAT_H

#include <algorithm>
#include <vector>
#include <initializer_list>

template <class T = double>
class Mat {
public:
	/*
	 * Element (Data Stacking - Row First)
	 */
	T* data = NULL;
	size_t rows = 0;
	size_t cols = 0;

	/*---------------- constructor, destructor ----------------*/
	Mat() { 
		; 
	}

	Mat(const int _rows) { 
		zero(_rows, 1); 
	}

	Mat(const int _rows, const int _cols) { 
		zero(_rows, _cols); 
	}

	Mat(const int _rows, const int _cols, T* _data) { 
		set(_rows, _cols, _data); 
	}

	Mat(const Mat& a) {			//copy constructor
		*this = a;
	}

	~Mat() { 
		delete[] data;
	}

	/*---------------- memory ----------------*/
	// alloc memory space
	Mat& alloc(const int _rows, const int _cols = 1) {
		if (_rows != rows || _cols != cols) {
			if (data != NULL)
				delete data;

			data = (T*)malloc(_rows * _cols * sizeof(T));
			rows = _rows;
			cols = _cols;
		}
		return *this;
	}

	/*---------------- property ----------------*/
	// size of elements
	inline int size() const {
		return rows * cols;
	}

	inline bool empty() {
		return size() == 0 ? true : false;
	}

	/*---------------- index (先纵再横)----------------*/
	inline void i2rc(int i, int& r, int& c) {
		r = i / cols;
		c = i % cols;
	}

	inline int  i2r(int i) {
		return i / cols;
	}

	inline int  i2c(int i) {
		return i % cols;
	}

	inline int rc2i(int r, int c) {
		return r * cols + c;
	}

	inline T& operator[](int i) { 
		return data[i];
	}

	inline T& operator()(int x) { 
		return data[x]; 
	}

	inline T& operator()(int x, int y) { 
		return data[x * cols + y]; 
	}

	inline std::vector<T> getRow(size_t r) {
		if (r >= rows) {
			throw std::out_of_range("Row index out of range");
		}

		std::vector<T> row_data(cols);
		for (size_t j = 0; j < cols; ++j) {
			row_data[j] = this->operator()(r, j);
		}

		return row_data;
	}

	inline std::vector<T> getCol(size_t c) {
		if (c >= cols) {
			throw std::out_of_range("Column index out of range");
		}

		std::vector<T> col_data(rows);
		for (size_t i = 0; i < rows; ++i) {
			col_data[i] = this->operator()(i, c);
		}

		return col_data;
	}

	inline Mat<T>& setRow(size_t r, const std::vector<T>& row_data) {
		if (r >= rows || row_data.size() != cols) {
			throw std::invalid_argument("Invalid row data or index");
		}

		for (size_t j = 0; j < cols; ++j) {
			this->operator()(r, j) = row_data[j];
		}

		return *this;
	}

	inline Mat<T>& setCol(size_t c, const std::vector<T>& col_data) {
		if (c >= cols || col_data.size() != rows) {
			throw std::invalid_argument("Invalid column data or index");
		}

		for (size_t i = 0; i < rows; ++i) {
			this->operator()(i, c) = col_data[i];
		}

		return *this;
	}

	inline Mat<T>& getSubmatrix(Mat<T>& res, int rowSt, int rowEd, int colSt, int colEd) {
		if (rowSt < 0 || rowEd >= res.rows ||
			colSt < 0 || colEd >= res.cols) {
			throw std::out_of_range("Invalid matrix indices");
		}
		
		Mat<T> resTmp(rowEd - rowSt + 1, colEd - colSt + 1);

		for (int i = rowSt; i <= rowEd; i++)
			for (int j = colSt; j <= colEd; j++)
				resTmp(i - rowSt, j - colSt) = this->operator()(i, j);

		res = std::move(resTmp);
		return res;
	}

	inline Mat<>& setSubmatrix(Mat<>& subMatrix, int rowSt, int colSt, int rowEd = -1, int colEd = -1) {
		if (rowSt < 0 || rowEd >= subMatrix.rows ||
			colSt < 0 || colEd >= subMatrix.cols) {
			throw std::out_of_range("Invalid matrix indices");
		}

		int maxRow = (rowEd == -1) ? subMatrix.rows : rowEd;
		int maxCol = (colEd == -1) ? subMatrix.cols : colEd;

		for (int i = rowSt; i <= maxRow; i++)
			for (int j = colSt; j <= maxCol; j++)
				this->operator()(i, j) = subMatrix(i - rowSt, j - colSt);

		return *this;
	}

	/*---------------- initial ----------------*/
	// clear the data
	inline Mat& zero() {
		memset(data, 0, sizeof(T) * size());
		return *this;
	}

	Mat& zero(const int _rows, const int _cols = 1) {
		alloc(_rows, _cols);
		zero();
		return *this;
	}

	// set the parameters with data existed 
	Mat& set(const int _rows, const int _cols, T* _data) {
		zero(_rows, _cols);
		memcpy(data, _data, sizeof(T) * size());
		return *this;
	}

	Mat& set_(const int _rows, const int _cols, T* _data) {
		rows = _rows;
		cols = _cols;
		data = _data;
		return *this;
	}

	/*---------------- assignment ----------------*/ //不能赋值自己
	Mat& operator=(const Mat& a) {
		if (a.data == NULL)
			return *this;

		alloc(a.rows, a.cols);
		memcpy(data, a.data, sizeof(T) * size());
		return *this;
	}

	// Modified function to accept an rvalue reference
	Mat& operator=(Mat&& other) {
		if (this != &other) {
			if (data != NULL)
				delete data;

			data = other.data;
			other.data = NULL;

			rows = other.rows;
			cols = other.cols;
			other.rows = other.cols = 0;
		}
		return *this;
	}

	Mat& operator=(std::initializer_list<T> list) {
		int i = 0;
		for (auto& item : list)
			data[i++] = item;
		return *this;
	}

	Mat& operator=(const std::vector<T>& x) {
		int n = x.size();
		alloc(n);

		for (int i = 0; i < n; i++) {
			data[i] = x[i];
		}

		return *this;
	}

	Mat& operator=(T x) {
		return fill(x);
	}

	inline Mat& fill(const T& a) {
		for (int i = 0; i < size(); i++)
			data[i] = a;
		return *this;
	}

	/*---------------- basic operation ----------------*/
	// 改变矩阵形状
	Mat& reshape(int _rows, int _cols = 1) {
		if(_rows * _cols != size())
			exit(-1);
		
		rows = _rows;
		cols = _cols;

		return *this;
	}

	// compare
	bool operator==(const Mat& a) {
		if (rows != a.rows || cols != a.cols)
			return false;
		return memcmp(data, a.data, size() * sizeof(T)) == 0 ? true : false;
	}

	// judge whether cross the border
	inline bool isOut(int _rows, int _cols) {
		if (_rows < 0 || _rows >= rows) return true;
		if (_cols < 0 || _cols >= cols) return true;
		return false;
	}


};


#endif