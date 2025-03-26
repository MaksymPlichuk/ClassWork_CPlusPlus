
#include <iostream>
using namespace std;

/*3. Створити функції для роботи з динамічним масивом
		- створення  динамічного масиву заданого розміру, розмір приходить як параметр функції
		- заповнення масиву випадковими числами + виконано
		- виведення масиву + виконано
		- доповнення масиву новим елементом(на початок)
		- доповнення масиву новим елементом(у хвіст масиву) + виконано
		- вилучення із  масиву останнього елементу
		- вилучення із  масиву першого елементу*/

void createArr(int size)
{

}


int main()

{
	// Створити динамічні змінні різних числових типів. Знайти середнє арифметичне, результат сер. ар. записати у дробову змінну. Знайти максимальне значення
	cout << "Task1" << endl;
	int* a = new int{ 100 };
	double* b = new double{ 100.89 };
	double* c = new double;
	long long* d = new long long{ 455 };
	*c = (*a + *b+*d) / 3;
	cout << "Avg of " << *a << " and " << *b << " and " << *d << " is " << *c;
	double* max = new double (*a);
	if (*a < *b && *b>*d)
	{
		* max = *b;
	}
	if (*d > *b && *d>*a)
	{
		* max = *d;
	}
	cout << "\nMax number: " << *max << endl;
	delete a;delete b;delete c;delete d;

	cout << "Task2" << endl;
	// 2. Створити динамічний масив. Ввести елементи масиву із клавіатури. Створити новий дин. масив, який буде містити елементи першого масиву, виключаючи останній елемент.
	int size = 5;
	int* arr = new int[size] {};
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	int* arr2 = new int[size - 1] {};
	cout << "Second array"  << endl;
	for (int i = 0; i < size-1; i++)
	{
		arr2[i]= arr[i];
		cout << arr2[i] << "\t";
	}

	cout << "Task3" << endl;
	


}
