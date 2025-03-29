#include <iostream>
#include "dyn_matrix.h"
using namespace std;

void printMatrix(int** m, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << m[i][j] << "\t";
		}
		cout << endl;
	}

}

void removeMatrix(int**& m, int r)
{
	for (int i = 0; i < r; i++)
	{
		delete[] m[i]; // delete every row
	}
	delete[] m; // delete masiv vkazivnukiv
	m = nullptr;
}

void addRow(int**& m, int& r, int c, int* value)
{
	++r;
	int** tmp = new int* [r];
	for (int i = 0; i < r-1; i++)
	{
		tmp[i] = m[i]; // added old rows in new array
	}
}
