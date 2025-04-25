
#include <iostream>
using namespace std;
 /*1. Знайти суму та добуток трьох числових даних. Виконати через вказівники на вкаазівники.
 2. Написати функцію створення динамічної матриці за двома розмірами.
void printMatrix(int m, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}


}*/
/*
* 1. Завершити класну роботу та доповнити задачу новими  функціями

		Написати функції для роботи з динамічною матрицею :
	•	Функція створення динамічної матриці розміром row x col, де row та col - аргументи функції.Функція повертає адресу створеної матриці(або адреса матриці передається по ссилці).
		•	Функція заповнення матриці
		•	Функція виводу матриці +
		•	Функція доповнення матриці новим рядком(новий рядок додається як перший у матрицю)(класна робота)
		•	Функція видалення з матриці рядка за вказаним індексом
		•	Функція вставки нового рядка за вказаним індексом

		Перевірити роботу функцій
_____________________________________________________________________________________________

2. 	Виконати на вибір
2.1.Створити функції  для роботи з  трикутною матрицею
1) int** createTrianMatrix(int rows) - функція отримує  число рядків та повертає  динамічну матрицю,
у якій 1 - рядок містить 1 елемент, 2 - й - два елементи і т.д.

2) void printTrianMatrix(int** m, int rows) виведення на екран

3) void fillRandTrianMatrix(int** m, int rows, int left = 0, int right = 100) - заповнення   випадковими числами у вказаному користувачем діапазоні


2.2.Транспонування матриці — це операція, після
якої стовпці колишньої матриці стають рядками, а рядки
стовпцями.Напишіть функцію транспонування матриці.Функція отримує  динамічні матрицю, повертає  транспоновану для неї.
*/

int** createMatrix(int rows, int cols) 
{
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		int* row = new int[cols] {};
		matrix[i] = row;

	}

	return matrix;
}

void randMatrix(int**& matrix, int row, int cols) 
{
	for (int i = 0; i < row; i++) 
	{
		for (int j = 0; j < cols; j++) 
		{
			matrix[i][j] = rand() % 100;
		}
	}
}

void printMatrix(int** m, int r, int c)
{
	if (m == nullptr)
	{
		cout << "Empty matrix!\n";
		return;
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << m[i][j] << "\t";
		}
		cout << endl;
	}
}

void addFirstRow(int**& m, int& r, int c, int value) 
{
	int** tmp = new int* [r + 1];

	tmp[0] = new int[c];

	for (int j = 0; j < c; j++) 
	{
		tmp[0][j] = value;
	}
	for (int i = 0; i < r; i++) 
	{
		tmp[i + 1] = m[i];
	}

	delete[] m;
	m = tmp;
	r++;
}

void removeRowByIndex(int**& matrix, int& rows, int index) 
{
	if (index < 0 || index >= rows) return;
	delete[] matrix[index];

	for (int i = index; i < rows - 1; i++) 
	{
		matrix[i] = matrix[i + 1];
	}
	rows--;
}

void addRowByIndex(int**& matrix, int& rows, int cols, int index, int value) 
{
	if (index < 0 || index > rows) return;
	int** tmp = new int* [rows + 1];

	for (int i = 0; i < index; i++) 
	{
		tmp[i] = matrix[i];
	}

	tmp[index] = new int[cols];

	for (int j = 0; j < cols; j++) 
	{
		tmp[index][j] = value;
	}

	for (int i = index; i < rows; i++) {
		tmp[i + 1] = matrix[i];
	}

	delete[] matrix;
	matrix = tmp;
	rows++;
}

int main()
{
	srand(time(0));
  /*cout << "Task 2" << endl;
	int rows;
	int cols;
	cout << "Enter number of rows :";
	cin >> rows;
	cout << "Enter number of columns :";
	cin >> cols;

	int** matrix = new int* [rows]; // vkazinvuk na dynamic (int *[rows]) return vkazinvuk matrix, strvor masiv vkazivnukiv na maybitni rows

	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols] {};// row dovzhini cols
	}
	printMatrix(**matrix, rows, cols);
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
	cout << "Suma  " << sum << endl;*/

	int rows, cols,index;
	cout << "Enter number of rows : "; cin >> rows;
	cout << "\nEnter number of cols : "; cin >> cols;
	
	int** matrix = createMatrix(rows, cols);
	randMatrix(matrix, rows, cols);
	printMatrix(matrix, rows, cols);

	cout << "\nNew row added to the front\n";
	addFirstRow(matrix, rows, cols, 0);
	printMatrix(matrix, rows, cols);

	cout << "\nEnter index of the row to delete from matrix : ";
	cin >> index;
	removeRowByIndex(matrix, rows, index);
	printMatrix(matrix, rows, cols);

	cout << "\nEnter index to insert a new row : ";
	cin >> index;
	addRowByIndex(matrix, rows, cols, index, 0);
	printMatrix(matrix, rows, cols);

	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

}
