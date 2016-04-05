#ifndef Matrix_hpp
#define Matrix_hpp

#include <iostream>

class Matrix {
public:
	Matrix() : lines(0), columns(0), nom(nullptr) {};
	Matrix(int _lines, int _columns);
	Matrix(const Matrix &a);
	~Matrix();

	void read_matrix(const string s);
	void print_matrix() const;
	int get_cout_columns();
	int get_cout_lines();
	void reset();

	Matrix& operator = (Matrix &a);
	Matrix operator + (Matrix &array) const;
	Matrix operator * (Matrix &array) const;
	int* operator [](int i);

private:
	int lines;
	int columns;
	int **nom;
};

Matrix::~Matrix() {
	if (nom) {
		for (int i = 0; i < lines; i++) {
			delete[] nom[i];
		}
		delete[] nom;
	}
}

Matrix::Matrix(const Matrix &copy) : lines(copy.lines), columns(copy.columns) {
	nom = new int*[lines];
	for (int i = 0; i < lines; i++) {
		nom[i] = new int[columns];
	}
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) {
			nom[i][j] = copy.nom[i][j];
		}
	}

}


Matrix::Matrix(int _lines, int _columns) : lines(_lines), columns(_columns) {
	nom = new int*[lines];
	for (int i = 0; i < lines; i++) {
		nom[i] = new int[columns];
	}

}

void Matrix::read_matrix(string s) {
	ifstream fin(s);
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) {
			fin >> nom[i][j];
		}
	}

	fin.close();

}
void Matrix::print_matrix() const {
	for (int i = 0; i < lines; i++) {

		for (int j = 0; j < columns; j++) {
			cout.width(5);
			cout << nom[i][j] << " ";
		}
		cout << endl;
	}
}
Matrix &Matrix::operator = (Matrix &a) {
	for (int i = 0; i < lines; i++)

	{
		delete[] nom[i];
	}
	delete[] nom;
	lines = a.lines;
	columns = a.columns;
	nom = new int*[lines];

	for (int i = 0; i < lines; i++) {
		nom[i] = new int[columns];
		for (int j = 0; j < columns; j++) {
			nom[i][j] = a.nom[i][j];
		}
	}
	return *this;
}


Matrix Matrix::operator + (Matrix &array) const {

	Matrix result(*this);
	for (int i = 0; i < result.lines; i++)
		for (int j = 0; j < result.columns; j++) {
			result.nom[i][j] += array.nom[i][j];
		}
	return result;
}

Matrix Matrix::operator * (Matrix &array) const {

	Matrix result(lines, array.get_cout_columns());
	result.reset();
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < array.get_cout_lines(); j++)
			for (int t = 0; t < columns; t++) {
				result.nom[i][j] += nom[i][t] * array.nom[t][j];
			}
	return result;
}

int* Matrix::operator [] (int i) {
	int *temp = new int[columns];
	for (int j = 0; j < columns; j++) {
		temp[j] = nom[i - 1][j];
	}
	return(temp);

}
int Matrix::get_cout_columns() {
	return(columns);
}

int Matrix::get_cout_lines() {
	return(lines);
}
void Matrix::reset() {
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++) {
			nom[i][j] = 0;
		}
}

#endif
