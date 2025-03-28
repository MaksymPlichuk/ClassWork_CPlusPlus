
#include <iostream>
using namespace std;
//Дан двовимірний масив розмірністю 3×4.Необхідно знайти кількість елементів, значення яких дорівнює нулю.
int main()
{
    srand(time(0));

	cout << "Task 1" << endl;
	int counter = 0;
    int matrix1[3][4]{};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrix1[i][j] = rand() % 21 -10;
			cout << matrix1[i][j] << " ";
			if (matrix1[i][j]==0)
			{
				counter++;
			}
		}
		cout <<endl;
	}
	cout << "\nNumber of numbers that are 0 in matrix is " << counter << endl;

}
