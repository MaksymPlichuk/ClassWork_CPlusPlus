#include <iostream>
using namespace std;
/*Завдання 1
Написати функцію або шаблон функції, яка сортує масив за зростанням або за спаданням методом вибору(Selection Sort),
залежно від третього параметра функції.
Якщо він дорівнює true, сортування йде за зростанням, якщо false — за спаданням.
Перші 2 параметри функції — це масив і його розмір, третій параметр за замовчуванням дорівнює true.*/
void ShowArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void selectionSort(int arr[], int size, bool condition)
{
	if (condition == true) {
		for (int i = 0; i < size - 1; i++)
		{
			int minIndex = i;

			for (int j = i + 1; j < size; j++)
			{
				if (arr[j] < arr[minIndex])
				{
					minIndex = j;
				}
			}

			if (minIndex != i)
			{
				swap(arr[i], arr[minIndex]);
			}
		}
	}
	else if (condition == false) {
		for (int i = 0; i < size - 1; i++)
		{
			int maxIndex = i;

			for (int j = i + 1; j < size; j++)
			{
				if (arr[j] > arr[maxIndex])
				{
					maxIndex = j;
				}
			}

			if (maxIndex != i)
			{
				swap(arr[i], arr[maxIndex]);
			}
		}
	}
}

/*Завдання 2
Написати функцію або шаблон функції, яка сортує першу половину масиву за спаданням, а другу — за зростанням,
використовуючи алгоритм бульбашки або камінця.*/
void bubbleSort(int arr[], int size)
{
	int mid = size / 2;

	for (int i = 0; i < mid - 1; i++)
	{
		for (int j = 0; j < mid - i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}

	for (int i = 0; i < size - mid - 1; i++)
	{
		for (int j = mid; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}


/*Завдання 3
У функцію передається масив випадкових чисел у діапазоні від - 20 до + 20.
Необхідно знайти позиції крайніх від'ємних елементів (найлівішого від'ємного елемента і найправішого від'ємного елемента)
і відсортувати елементи, що знаходяться між ними.*/
int leftNegative(int arr[], int size) {
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] < 0)
		{
			return i;
		}
	}
	return -1;
}

int rightNegative(int arr[], int size)
{
	for (int i = size - 1; i >= 0; --i)
	{
		if (arr[i] < 0) {
			return i;
		}
	}
	return -1;
}

void sortBetween(int arr[],int size)
{
	int left = 1, right = size - 1;
	for (int i = left; i < right; ++i) 
	{
		for (int j = i + 1; j <= right; j++) 
		{
			if (arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
			}
		}
	}
}


/*Додаткове завдання.
	Завдання 4
	Переписати функцію бінарного пошуку
	int binarySearch(int key, const int arr[], int size)
{
	int left = 0, right = size - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == key)
			return mid;
		if (key > arr[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

Додати у функцію третій параметр логічного типу, який буде вказувати на порядок сортування.
Якщо він дорівнює true, то у функцію передано масив впорядкований за зростанням, якщо false — за спаданням.*/

int binarySearch(int key, const int arr[], int size, bool condition)
{
	int left = 0, right = size - 1;
	int mid = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (arr[mid] == key)
			return mid;

		if (condition == true)
		{
			if (key > arr[mid])
				left = mid + 1;
			else
				right = mid - 1;
		}
		else 
		{
			if (key < arr[mid])
				left = mid + 1;
			else
				right = mid - 1;
		}
	}
	return -1;
}




int main()
{
	srand(time(0));
	cout << "Task 1" << endl;

	const int SIZE = 10;
	int arr1[SIZE]{5,6,9,95,2,11,-9,7,4,-9};
	cout << "Before selection sort : ";
	ShowArray(arr1, SIZE);
	cout << endl;
	cout << "After selection sort(from min to max) : ";
	selectionSort(arr1, SIZE, true);
	ShowArray(arr1, SIZE);
	cout << "After selection sort(from max to min) : ";
	selectionSort(arr1, SIZE, false);
	ShowArray(arr1, SIZE);

	cout << "\nTask 2" << endl;

	int arr2[SIZE]{ 5,6,9,95,2,11,-9,7,4,-9 };

	cout << "Before bubble sort : ";
	ShowArray(arr1, SIZE);

	bubbleSort(arr1, SIZE);
	cout << "After bubble sort(from max to min to min to max) : ";
	ShowArray(arr1, SIZE);

	cout << "\nTask 3" << endl;

	int arr3[SIZE]{};
	for (int i = 0; i < SIZE; i++)
	{
		arr3[i] = rand() % 41 - 20;
	}

	int left = leftNegative(arr3, SIZE);
	int right = rightNegative(arr3, SIZE);
	ShowArray(arr3, SIZE);

	cout << "Index of left negative : " << left << endl;
	cout << "Index of right negative : " << right << endl;
	cout << "\nAfter sort in between : ";
	sortBetween(arr3, SIZE);
	ShowArray(arr3, SIZE);

	cout << "\nTask 4" << endl;
	int arr4[SIZE]{ -9, -9, 2, 4, 5, 6, 7, 9, 11, 95 };
	ShowArray(arr4, SIZE);
	int result = binarySearch(7, arr4, SIZE, true);
	if (result != -1)
		cout << "Element found on index : " << result << endl;
	else
		cout << "Element not found" << endl;

	int arr5[SIZE]{ 95,11,9,7,6,5,4,2,-9,-9 };
	ShowArray(arr5, SIZE);
	result = binarySearch(7, arr5, SIZE, false);
	if (result != -1)
		cout << "Element found on index : " << result << endl;
	else
		cout << "Element not found" << endl;

}




