#include <iostream>
using namespace std;

void arrFill(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = rand() %21 -10;
	}
}
void showArr(int* arr,int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
}
void nullReplacer(int* arr,int size)
{
	for (int i = 0; i < size; i++)
	{
		if (*(arr + i) < 0)
		{
			*(arr+i) = 0;
		}
	}
}

void randomMatrix(int matrix[][4], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = (rand() % 10);
		}
		
	}
}

void showMatrix(int matrix[][4], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Swap(int& a, int& b)
{
	int temp = b;
	b = a;
	a = temp;
}

void swapColumns(int matrix[][4], int row) 
{
	for (int i = 0; i < row; i++) 
	{
		int& a = matrix[i][2];
		int& b = matrix[i][3];
		Swap(a, b);
	}
}

int main()
{
	srand(time(0));
	/*1.Дано три числа.Оголосити ссилки на ці числа.
		Отримати добуток трьох заданих чисел, середє арифметичне, найменше з них,
		користуючись непрямим доступом до чисел(через ссилку)*/
   cout << "\tTask 1" << endl;
   int a,b,c;
   cout << "Enter numbers: ";
   cin >> a >> b >> c;
   int& la = a;
   int& lb = b;
   int& lc = c;
   int dob = la * lb * lc;
   int avg = (la + lb + lc) / 3;
   int min = la;
   if (la<lb && la<lc)
   {
	   min = la;
   }
   if (lb<la && lb<lc)
   {
	   min = lb;
   }
   if (lc<lb && lc<la)
   {
	   min = lc;
   }
   cout << "Product of numbers : " << dob << endl;  
   cout << "Average of numbers : " << avg << endl;  
   cout << "Minimum of numbers : " << min << endl;

   cout << "\n\tTask 2" << endl;
   //2.Написати функцію, яка замінює всі від’ємні елементи переданого масиву нулями.
   const int SIZE = 5;
   int arr[SIZE]{};
   arrFill(arr, SIZE);
   cout << "Before update : ";
   showArr(arr, SIZE);
   cout << "\nAfter update : ";
   nullReplacer(arr, SIZE);
   showArr(arr, SIZE);

   cout << "\n\tTask 3" << endl;
/*3.Написать функцію(або шаблон), яка приймає дві ссилки на змінні і
виконує обмін значень.За допомогою написаної функції поміняти місцями
у матриці перший та другий стовпці.*/
   const int row = 3;
   const int col = 4;
   int matrix[row][col];
   cout << "Before update : " << endl;
   randomMatrix(matrix, row, col);
   showMatrix(matrix, row, col);
   cout << "\nAfter update : " << endl;
   swapColumns(matrix, row);
   showMatrix(matrix, row, col);


}

