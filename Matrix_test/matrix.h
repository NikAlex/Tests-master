class Matrix {
public:
	Matrix() : lines(0), columns(0), nom(nullptr) {};
	Matrix(int _lines, int _columns);
	Matrix(const Matrix &a);
	~Matrix();

	void read_matrix(string s);
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

#endif
