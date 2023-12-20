#pragma once

#include<iostream>
#include<sstream>

// ����� �������
class Matrix
{
private:
	int lines;        // ���������� ����� �������
	int columns;      // ���������� �������� �������
	double** matrix;  // ������ �������
public:
	// ����������� �� ���������
	Matrix();
	// �����������, �������������� ���������� �������
	Matrix(int num);
	// �����������, �������������� �������, � ������� lines - ���������� �����, columns - ��������
	Matrix(int lines, int columns);
	// ����������� �����������
	Matrix(const Matrix& other);
	// setters & getters
	int get_lin() { return lines; }
	int get_col() { return columns; }
	double& Elem(int ind_lin, int ind_col);

	// �������� ������������� ������
	bool compatibility_matrix(Matrix& other);
	// �������� ���������� �� �������
	bool square_matrix();

	// ����� ���������� �������
	void input(int min, int max); 
	
	// ������ ������ �������
	void print(); 
	std::string to_string();

	// �������� � ���������
	Matrix sum(const Matrix& other);   // �������� ���� ������
	Matrix sub(const Matrix& other);   // �������� ���� ������
	Matrix mult(const Matrix& other);  // ��������� ���� ������
	Matrix div(const Matrix& other);   // ������� ���� ������

	Matrix invert();                   // ����� �������� ���� �������	
	Matrix mult(double number);        // ��������� ������� �� �����

	void increment();       // ���������
	Matrix prefix_inc();    // ���������� ���������
	Matrix postfix_inc();   // ����������� ���������
	void decrement();       // ���������
	Matrix prefix_dec();    // ���������� ���������
	Matrix postfix_dec();   // ����������� ���������

	// ����������� ���������� ������������
	void get_matr(Matrix& p, int i, int j);
	double determinant(int lines);

	// ��������� ������ �����������
	bool equals(const Matrix& other);
	int compare(Matrix& other);

	// ��������������� ���������� ��������
	Matrix operator=(const Matrix& other);

	Matrix operator+(Matrix& other);
	Matrix operator-(Matrix& other);
	Matrix operator*(Matrix& other);
	Matrix operator*(double number);
	Matrix operator/(Matrix& other);
	Matrix operator++();				// ���������� ���������
	Matrix operator++(int);			    // ����������� ���������
	Matrix operator--();                // ���������� ���������
	Matrix operator--(int);	            // ����������� ���������
	
	bool operator==(const Matrix& other);
	bool operator!=(const Matrix& other);
	bool operator<(Matrix& other);
	bool operator>(Matrix& other);
	bool operator<=(Matrix& other);
	bool operator>=(Matrix& other);

	// ����������
	~Matrix();
};

