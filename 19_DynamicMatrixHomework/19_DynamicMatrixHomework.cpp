
#include <iostream>
using namespace std;
// 1. Знайти суму та добуток трьох числових даних. Виконати через вказівники на вкаазівники.
// 2. Написати функцію створення динамічної матриці за двома розмірами.
//void printMatrix(int m, int r, int c)
//{
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			cout << m[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//
//}
int main()
{
 //   cout << "Task 2" << endl;
	//int rows;
	//int cols;
	//cout << "Enter number of rows :";
	//cin >> rows;
	//cout << "Enter number of columns :";
	//cin >> cols;

	//int** matrix = new int* [rows]; // vkazinvuk na dynamic (int *[rows]) return vkazinvuk matrix, strvor masiv vkazivnukiv na maybitni rows

	//for (int i = 0; i < rows; i++)
	//{
	//	matrix[i] = new int[cols] {};// row dovzhini cols
	//}
	//printMatrix(**matrix, rows, cols);
	int* pa = new int{ 25 };
	int* pb = new int{ 50 };
	int* pc = new int{ 75 };
	int** pa2 = &pa;
	int** pb2 = &pb;
	int** pc2 = &pc;
	int sum;
	int dob;
	sum = **pa2 + **pb2 + **pc2;
	dob = **pa2 * **pb2 * **pc2;
	cout << "Dobutok " << dob << endl;
	cout << "Suma  " << sum << endl;
}
