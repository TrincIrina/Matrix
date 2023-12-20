#include<iostream>
#include"Matrix.h"
using namespace std;

// тестирование операций над матрицами
void test_matrix(Matrix& matrix) {
	matrix.print();
	matrix.invert().print();
	matrix++.print();
	matrix--.print();
	matrix.mult(2).print();
	if (matrix.square_matrix()) {
		cout << "D = " << matrix.determinant(matrix.get_lin()) << endl << endl;
	}
	else {
		cout << "ћатрица не €вл€етс€ квадратной, нельз€ вычислить определитель матрицы." << endl << endl;
	}
}

// тестирование операций над матрицами
void test_operation(Matrix& A, Matrix& B) {
	cout << "Matrix A:" << endl;
	A.print();
	cout << "Matrix B:" << endl;
	B.print();
	if (!A.compatibility_matrix(B)) {
		cout << "ћатрицы не совместимы, операции над ними невозможны." << endl;
		return;
	}
	cout << "A + B" << endl;
	A.sum(B).print();
	cout << "A - B" << endl;
	A.sub(B).print();
	cout << "A * B" << endl;
	A.mult(B).print();
	cout << "A / B" << endl;
	A.div(B).print();
	if (A == B) {
		cout << "ћатрицы равны." << endl;
	}
	else {
		cout << "ћатрицы не равны." << endl;
	}
	if (A > B) {
		cout << "D(A) > D(B)" << endl << endl;
	}
	else if (A < B) {
		cout << "D(A) < D(B)" << endl << endl;
	}
	else if (A <= B) {
		cout << "D(A) <= D(B)" << endl << endl;
	}
	else if (A >= B) {
		cout << "D(A) >= D(B)" << endl << endl;
	}
}

void main() {
	setlocale(0, "");
	srand(time(NULL));

	Matrix A(3);
	A.input(-25, 15);
	test_matrix(A);
	Matrix B(4, 5);
	B.input(-50, 25);
	test_matrix(B);
	Matrix C(A);
	test_operation(A, B);
	test_operation(A, C);
}