// Lab 04
// Task 1 - Mapping from 2-D to 1-D Array

#include "iostream"
#include "cstdio"

using namespace std;

class TwoD_Matrix
{
private:
	int* ptr;
	int rows;
	int columns;

public:

	TwoD_Matrix(int r, int c) // A- Constructor
	{
		ptr = new int[r * c];
		this->rows = r;
		this->columns = c;

		for (int i = 0; i < rows; i++) // Initalizing Matrix with 0
		{
			for (int j = 0; j < columns; j++)
			{
				*(ptr + (i * columns + j)) = 0;
			}
		}
	}

	~TwoD_Matrix() // B- Destructor
	{
		delete[]ptr;
	}

	int get(int i, int j) // C- Getting the Value
	{
		if ((i > rows && i <= 0) || (j > columns && j < 0))
		{
			cout << "ERROR!!! Invalid Row or Column Number";
			return 0;
		}
		else
		{
			return *(ptr + (i * columns + j));
		}
	}

	void set(int i, int j, int v) // D- Setting the Value
	{
		if ((i > rows && i <= 0) || (j > columns && j < 0))
		{
			cout << "ERROR!!! Invalid Row or Column Number";
		}
		else
		{
			*(ptr + (i * columns + j)) = v;
		}
	}

	void print(void) // E- Printing Matrix in 2D Form
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << *(ptr + (i * columns + j)) << "\t";
			}
			cout << "\n";
		}
	}

	void transpose(void) // F- Transpose of Matrix
	{
		int* newData = new int[rows * columns];

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				newData[j * rows + i] = ptr[i * columns + j];
			}
		}

		delete[] ptr;
		ptr = newData;
		swap(rows, columns); // Swap the dimensions
	}

	void printSubMatrix(int r1, int r2, int c1, int c2) // G- Printing Sub-Matrix
	{
		for (int i = r1 - 1; i < r2; i++)
		{
			for (int j = c1 - 1; j < c2; j++)
			{
				cout << *(ptr + (i * columns + j)) << "\t";
			}
			cout << "\n";
		}
	}

	void makeEmpty(int n) // H- Making Matrix Empty
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				*(ptr + (i * columns + j)) = 0;
			}
		}
	}

	void add(TwoD_Matrix& first, TwoD_Matrix& second) // I- Adding Two Matrices
	{
		delete[]ptr;
		ptr = new int[rows * columns];


		if (first.rows == second.rows && first.columns == second.columns && this->rows == first.rows && this->columns == first.columns)
		{
			//this->rows = first.rows;
			//this->columns = first.columns;

			for (int i = 0; i < first.rows; i++)
			{
				for (int j = 0; j < first.columns; j++)
				{
					*(ptr + (i * columns + j)) = first.get(i, j) + second.get(i, j);
				}
			}
		}
		else
		{
			cout << "ERROR!!! Rows or Columns of First and Sexond Matrices are Not Same";
		}
	}
};

int main()
{
	TwoD_Matrix matrix1(5, 3), matrix2(5, 3), matrix3(5, 3);

	matrix1.set(0, 0, 1);
	matrix1.set(0, 1, 2);
	matrix1.set(0, 2, 3);
	matrix1.set(1, 0, 4);
	matrix1.set(1, 1, 5);
	matrix1.set(1, 2, 6);
	matrix1.set(2, 0, 7);
	matrix1.set(2, 1, 8);
	matrix1.set(2, 2, 9);




	matrix2.set(0, 0, 1);
	matrix2.set(0, 1, 2);
	matrix2.set(0, 2, 3);
	matrix2.set(1, 0, 4);
	matrix2.set(1, 1, 5);
	matrix2.set(1, 2, 6);
	matrix2.set(2, 0, 7);
	matrix2.set(2, 1, 8);
	matrix2.set(2, 2, 9);

	matrix1.print();

	cout << "\n\n\n";
	//matrix1.transpose();
	matrix1.print();
	//matrix1.makeEmpty(2);
	cout << "\n\n\n";
	matrix1.printSubMatrix(1, 2, 1, 2);
	
	cout << "\n\n\n";
	matrix3.add(matrix1, matrix2);
	matrix3.print();
	
	//cout<<matrix1.get(4, 4);

	return 0;
}
