#include "Matrix.h"

Matrix::Matrix()
	: Matrix(0, 0)
{
}

Matrix::Matrix(int num)
	: Matrix(num, num)
{
}

Matrix::Matrix(int lines, int columns)
	: lines{ lines }, columns{ columns }
{
	matrix = new double*[lines];
	for (int i = 0; i < lines; i++)
		matrix[i] = new double[columns];
}

double& Matrix::Elem(int ind_lin, int ind_col)
{
	return matrix[ind_lin][ind_col];
}

bool Matrix::compatibility_matrix(Matrix& other)
{
	return lines == other.lines && columns == other.columns;
}

bool Matrix::square_matrix()
{
	return lines == columns;
}

void Matrix::input(int min, int max)
{
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] = rand() % max - min;
}

void Matrix::print()
{
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}	
	std::cout << std::endl;
}

std::string Matrix::to_string()
{
	std::ostringstream out;
	for (int i = 0; i < lines; i++) {		
		for (int j = 0; j < columns; j++) {
			out << matrix[i][j] << "\t";
		}		
	}
	return out.str();
}

Matrix Matrix::sum(const Matrix& other)
{
	Matrix mat(lines, columns);
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) {
			mat.Elem(i, j) = matrix[i][j] + other.matrix[i][j];
		}
	}
	return mat;
}

Matrix Matrix::sub(const Matrix& other)
{
	Matrix mat(lines, columns);
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) {
			mat.Elem(i, j) = matrix[i][j] - other.matrix[i][j];
		}
	}
	return mat;
}

Matrix Matrix::mult(const Matrix& other)
{
	Matrix mat(lines, columns);
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) {
			mat.Elem(i, j) = matrix[i][j] * other.matrix[i][j];
		}
	}
	return mat;
}

Matrix Matrix::div(const Matrix& other)
{
	Matrix mat(lines, columns);
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) {
			mat.Elem(i, j) = matrix[i][j] / other.matrix[i][j];
		}
	}
	return mat;
}

Matrix Matrix::invert()
{
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] *= -1;
	return *this;
}

Matrix Matrix::mult(double number)
{
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] *= number;
	return *this;
}

void Matrix::increment()
{	
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) {
			matrix[i][j]++;
		}
	}
}

Matrix Matrix::prefix_inc()
{
	increment();
	return *this;
}

Matrix Matrix::postfix_inc()
{
	Matrix old = *this;
	increment();
	return old;
}

void Matrix::decrement()
{
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) {
			matrix[i][j]--;
		}
	}
}

Matrix Matrix::prefix_dec()
{
	decrement();
	return *this;
}

Matrix Matrix::postfix_dec()
{
	Matrix old = *this;
	decrement();
	return old;
}

void Matrix::get_matr(Matrix& p, int i, int j)
{
	int di = 0, dj = 0;
	for (int ki = 0; ki < lines - 1; ki++) {      // проверка индекса строки
		if (ki == i) {
			di = 1;
		}
		for (int kj = 0; kj < lines - 1; kj++) {  // проверка индекса столбца
			if (kj == j) {
				dj = 1;
			}
			p.Elem(ki, kj) = matrix[ki + di][kj + dj];
		}
	}
}

double Matrix::determinant(int lines)
{
	int d = 0, k = 1, n;	
	Matrix p(lines);	
	n = lines - 1;	
	if (lines == 1) {
		d = Elem(0, 0);
		return(d);
	}
	if (lines == 2) {
		d = Elem(0, 0) * Elem(01, 1) - (Elem(1, 0) * Elem(0, 1));
		return(d);
	}
	if (lines > 2) {
		for (int i = 0; i < lines; i++) {
			get_matr(p, i, 0);
			d = d + k * Elem(i, 0) * p.determinant(n);
			k = -k;
		}
	}
	return(d);
}

bool Matrix::equals(const Matrix& other)
{
	int f = 0;
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) {
			if (matrix[i][j] == other.matrix[i][j]) {
				f++;
			}
		}
	}
	if (f == lines * columns) {
		return true;
	}
	return false;
}

int Matrix::compare(Matrix& other)
{
	double d1 = determinant(lines);
	double d2 = other.determinant(other.lines);
	if (d1 == d2) {
		return 0;
	}
	if (d1 > d2) {
		return 1;
	}
	if (d1 < d2) {
		return -1;
	}
}

Matrix Matrix::operator=(const Matrix& other)
{
	return Matrix(other);
}

Matrix Matrix::operator+(Matrix& other)
{
	return sum(other);
}

Matrix Matrix::operator-(Matrix& other)
{
	return sub(other);
}

Matrix Matrix::operator*(Matrix& other)
{
	return mult(other);
}

Matrix Matrix::operator*(double number)
{
	return mult(number);
}

Matrix Matrix::operator/(Matrix& other)
{
	return div(other);
}

Matrix Matrix::operator++()
{
	return prefix_inc();
}

Matrix Matrix::operator++(int)
{
	return postfix_inc();
}

Matrix Matrix::operator--()
{
	return prefix_dec();
}

Matrix Matrix::operator--(int)
{
	return postfix_dec();
}

bool Matrix::operator==(const Matrix& other)
{
	return equals(other);
}

bool Matrix::operator!=(const Matrix& other)
{
	return !equals(other);
}

bool Matrix::operator<(Matrix& other)
{
	return compare(other) < 0;
}

bool Matrix::operator>(Matrix& other)
{
	return compare(other) > 0;
}

bool Matrix::operator<=(Matrix& other)
{
	return compare(other) <= 0;
}

bool Matrix::operator>=(Matrix& other)
{
	return compare(other) >= 0;
}

Matrix::Matrix(const Matrix& other)
	: lines{ other.lines }, columns{ other.columns }
{
	matrix = new double* [lines];
	for (int i = 0; i < lines; i++)
		matrix[i] = new double[columns];
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] = other.matrix[i][j];
}



Matrix::~Matrix()
{
	for (int i = 0; i < lines; i++)
		delete[] matrix[i];
	delete[] matrix;
}
