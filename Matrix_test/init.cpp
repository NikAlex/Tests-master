#include "matrix.h"
#include <catch.hpp>
#include <fstream>
SCENARIO("Matrix init", "[init]") 
{
	GIVEN("The number of rows and columns") 
	{
		auto rows = 3;
		auto columns = 4;
		WHEN("Create instansce of Matrix") 
		{
			Matrix A(rows, columns);
			Matrix B(rows*2+columns,columns*2+rows);
			Matrix C;
			THEN("The number of rows and columns must be preserved") 
			{
				REQUIRE(A.Rows() == rows);
				REQUIRE(A.Columns() == columns);
				REQUIRE(B.Rows() == 2*rows+columns);
				REQUIRE(B.Columns() == 2*columns+rows);
				REQUIRE(C.Rows() == 0);
				REQUIRE(C.Columns() == 0);
			}
		}
	}
}

SCENARIO("Matrix operator >>", "[Fill]") 
{
	std::ifstream input("A.txt");
	Matrix A = Matrix(2, 2);
	REQUIRE( input >> A );
	REQUIRE( A[0][0] == 2 );
	REQUIRE( A[0][1] == 3 );
	REQUIRE( A[1][0] == 2 );
	REQUIRE( A[1][1] == 1 );
}
SCENARIO("Matrix operator <<", "[out]") 
{
	Matrix A(2,2);
	Matrix B(2,2);
	std::ifstream("A.txt") >> A;
	fstream out; 
	out.open("out.txt");
	REQUIRE(out << A);
	std::ifstream("out.txt") >> B;
	out.close();
	REQUIRE(A==B);
}
SCENARIO("Matrix operator +", "[addition]") 
{
	Matrix A(2,2);
	Matrix B(2,2);
	Matrix expected(2,2);
	Matrix result(2,2);
	std::ifstream("A.txt") >> A;
	std::ifstream("B.txt") >> B;
	std::ifstream("A+B.txt") >> result;
	expected=A+B;
	REQUIRE(expected==result);
}
SCENARIO("Matrix operator -", "[subtraction]") 
{
	Matrix A(2,2);
	Matrix B(2,2);
	Matrix expected(2,2);
	Matrix result(2,2);
	std::ifstream("A.txt") >> A;
	std::ifstream("B.txt") >> B;
	std::ifstream("A-B.txt") >> result;
	expected=A-B;
	REQUIRE(expected==result);
}
SCENARIO("Matrix operator *", "[multiplication]") 
{
	Matrix A(2,2);
	Matrix B(2,2);
	Matrix expected(2,2);
	Matrix result(2,2);
	std::ifstream("A.txt") >> A;
	std::ifstream("B.txt") >> B;
	std::ifstream("AxB.txt") >> result;
	expected=A*B;
	REQUIRE(expected==result);
}
SCENARIO("Matrix operator [](int)", "[row]") 
{
	Matrix A(2,2);
	std::ifstream("A.txt") >> A;
	int* row = A[1];
	REQUIRE(row[0]==2);
	REQUIRE(row[1]==1);
}
SCENARIO("Matrix operator ==", "[comparison]") 
{
	Matrix A(2,2);
	Matrix B(2,2);
	std::ifstream("A.txt") >> A;
	std::ifstream("A.txt") >> B;
	REQUIRE(A==B);
}
