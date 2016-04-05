// matrix.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//
#include "stdafx.h"
#include "matrix.h"
#include <iostream>
#include <fstream>
#include <string>
//jlksdahgkjhasdkljghlkjasdg

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}
int max(int a, int b)
{
	return a > b ? a : b;
}

Matrix::Matrix(int rows, int columns) :n(rows), m(columns)
{
	matrix = new int*[n];
	for (int i = 0; i<n; i++)
	{
		matrix[i] = new int[m];
		for (int j = 0; j<m; j++)
		{
			matrix[i][j] = 0;
		}
	}
}
Matrix::Matrix(const Matrix& copy) :n(copy.n), m(copy.m)
{
	matrix = new int*[n];
	for (int i = 0; i<n; i++)
	{
		matrix[i] = new int[m];
		for (int j = 0; j<m; j++)
		{
			matrix[i][j] = copy.matrix[i][j];
		}
	}
}
Matrix::~Matrix()
{
	if (matrix != nullptr)
	{
		for (int i = 0; i<n; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}
}

Matrix Matrix::operator + (const Matrix &matr)
{
	Matrix result(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			result.matrix[i][j] = matrix[i][j] + matr.matrix[i][j];
		}
	}
	return result;
}
Matrix Matrix::operator - (const Matrix &matr)
{
	Matrix result(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			result.matrix[i][j] = matrix[i][j] - matr.matrix[i][j];
		}
	}
	return result;
}
Matrix Matrix::operator * (const Matrix &matr)
{
	Matrix result(n, matr.m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < matr.m; j++)
		{
			int value = 0;
			for (int k = 0; k < m; k++)
			{
				value += matrix[i][k] * matr.matrix[k][j];
			}
			result.matrix[i][j] = value;
		}
	}
	return result;
}
Matrix &Matrix::operator = (const Matrix &matr)
{
	if (this != &matr)
	{
		if (matrix != nullptr)
		{
			for (int i = 0; i<n; i++)
			{
				delete[] matrix[i];
			}
			delete[] matrix;
		}
		n = matr.n;
		m = matr.m;
		matrix = new int*[n];
		for (int i = 0; i<n; i++)
		{
			matrix[i] = new int[m];
			for (int j = 0; j<m; j++)
			{
				matrix[i][j] = matr.matrix[i][j];
			}
		}
	}
	return *this;
}
bool Matrix::operator == (const Matrix &matr) 
{
	if (n!=matr.n || m!=matr.m) 
	{
		return false;
	}

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			if (matrix[i][j] != matr.matrix[i][j]) 
			{
				return false;
			}
		}
	}
	return true;
}
int* Matrix::operator [] (int index)
{
	if (index <= this->n)
	{
		return this->matrix[index];
	}
	else
	{
		return nullptr;
	}
}
int Matrix::Rows() const
{
	return n;
}
int Matrix::Columns() const
{
	return m;
}
ostream &operator << (ostream &os, const Matrix &temp)
{
	for (int i = 0; i < temp.n; i++)
	{
		for (int j = 0; j < temp.m; j++)
		{
			os << temp.matrix[i][j] << " ";
		}
		os << endl;
	}
	return os;
}
istream &operator >> (istream &input, Matrix &matr)
{
    for (int i = 0; i < matr.n; i++) 
    {
        for (int j = 0; j < matr.m; j++) 
        {
            if (!(input >> matr.matrix[i][j]))
            {
                throw "exception in fill matrix";
            }
        }
    }
    return input;
}
