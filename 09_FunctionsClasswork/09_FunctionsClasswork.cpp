/*Завдання 1. Написати функцію, що виводить на екран
прямокутник з висотою N і шириною K.

Завдання 2. Написати функцію, яка обчислює факторіал

переданого їй числа.

Завдання 3. Написати функцію, яка перевіряє, чи є пере -

дане їй число простим.Число називається простим, якщо

воно ділиться без залишку тільки на себе та на одиницю.

Завдання 4. Написати функцію, яка повертає куб числа.

Завдання 5. Написати функцію для знаходження най -

більшого з двох чисел.

Завдання 6. Написати функцію, яка повертає істину, якщо

передане значення додатне, та брехню, якщо від’ємне*/
#include <iostream>
using namespace std;

void rectangle(int n, int k)
{
	for (int h = 0; h < n; h++)
	{
		for (int w = 0; w < k; w++)
		{
			cout << "*" << " ";
		}
		cout << endl;
	}
}

int factorial(int num)
{
	int Factorial = 1;
	for (int i = 1; i <= num; i++)
	{
		Factorial *= i;
	}
	return Factorial;
}

int primeNumbers(int a)
{
	for (int i = 2; i <= a/2; i++)
	{
		if (a % i == 0)
		{
			return false;
		}
	}
		return true;
}

int main()
{

    rectangle(4,5);
	cout << factorial(5) << endl;
	cout << primeNumbers(9) << endl;
}
