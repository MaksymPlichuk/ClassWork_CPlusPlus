// 19_DynamicMatirxClasswork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;    
#include "dyn_matrix.h"



int main()
{
    /*int const rows = 3;
    int* matrix[rows];
	int cols;
	cout << "Enter number of columns :";
	cin >> cols;
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols] {};
	}
	matrix[0][0] = 5;
	matrix[1][2] = 7;
	printMatrix(matrix, rows, cols);

	//remove matrix
	for (int i = 0; i < rows; i++)
	{
		delete [] matrix[i];
	} */

	//full dynamic
	int rows;
	int cols;
	cout << "Enter number of rows :";
	cin >> rows;
	cout << "Enter number of columns :";
	cin >> cols;

	int** matrix = new int *[rows]; // vkazinvuk na dynamic (int *[rows]) return vkazinvuk matrix, strvor masiv vkazivnukiv na maybitni rows

	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols] {};// row dovzhini cols
	}
	matrix[0][0] = 5;
	matrix[1][2] = 7;
	printMatrix(matrix, rows, cols);

	//remove matrix
	//removeMatrix(int**& m, int r);
	//for (int i = 0; i < rows; i++)
	//{
	//	delete[] matrix[i]; // delete every row
	//}
	//delete[] matrix; // delete masiv vkazivnukiv

}
