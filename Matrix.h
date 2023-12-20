#pragma once

#include<iostream>
#include<sstream>

// Класс Матрица
class Matrix
{
private:
	int lines;        // количество строк матрицы
	int columns;      // количество столбцов матрицы
	double** matrix;  // данные матрицы
public:
	// Конструктор по умолчанию
	Matrix();
	// Конструктор, инициализирует квадратную матрицу
	Matrix(int num);
	// Конструктор, инициализирует матрицу, в которой lines - количество строк, columns - столбцов
	Matrix(int lines, int columns);
	// Конструктор копирования
	Matrix(const Matrix& other);
	// setters & getters
	int get_lin() { return lines; }
	int get_col() { return columns; }
	double& Elem(int ind_lin, int ind_col);

	// Критерий совместимости матриц
	bool compatibility_matrix(Matrix& other);
	// Проверка квадратная ли матрица
	bool square_matrix();

	// Метод заполнения матрицы
	void input(int min, int max); 
	
	// Методы вывода матрицы
	void print(); 
	std::string to_string();

	// Операции с матрицами
	Matrix sum(const Matrix& other);   // Сложение двух матриц
	Matrix sub(const Matrix& other);   // Разность двух матриц
	Matrix mult(const Matrix& other);  // Умножение двух матриц
	Matrix div(const Matrix& other);   // Деление двух матриц

	Matrix invert();                   // Метод меняющий знак матрицы	
	Matrix mult(double number);        // Умножение матрицы на число

	void increment();       // инкремент
	Matrix prefix_inc();    // префиксный инкремент
	Matrix postfix_inc();   // постфиксный инкремент
	void decrement();       // декремент
	Matrix prefix_dec();    // префиксный декремент
	Matrix postfix_dec();   // постфиксный декремент

	// Рекурсивное вычисление определителя
	void get_matr(Matrix& p, int i, int j);
	double determinant(int lines);

	// Сравнение матриц поэлементно
	bool equals(const Matrix& other);
	int compare(Matrix& other);

	// соответствующие перегрузки операций
	Matrix operator=(const Matrix& other);

	Matrix operator+(Matrix& other);
	Matrix operator-(Matrix& other);
	Matrix operator*(Matrix& other);
	Matrix operator*(double number);
	Matrix operator/(Matrix& other);
	Matrix operator++();				// префиксный инкремент
	Matrix operator++(int);			    // постфиксный инкремент
	Matrix operator--();                // префиксный декремент
	Matrix operator--(int);	            // постфиксный декремент
	
	bool operator==(const Matrix& other);
	bool operator!=(const Matrix& other);
	bool operator<(Matrix& other);
	bool operator>(Matrix& other);
	bool operator<=(Matrix& other);
	bool operator>=(Matrix& other);

	// Деструктор
	~Matrix();
};

