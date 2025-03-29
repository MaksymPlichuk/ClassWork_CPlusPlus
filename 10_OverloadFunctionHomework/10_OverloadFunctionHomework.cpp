using namespace std;
#include <iostream>
//На додаткові 12 балів:
//Завдання 1. Написати функції, що визначають кількість
//додатних, від'ємних і нульових елементів переданого їй
//масиву.
//Завдання 2. Написати перевантажені функції(int, double,
//    char) для виконання таких завдань :
//■ Ініціалізація квадратної матриці;
//■ Вивід матриці на екран;
//■ Визначення максимального й мінімального елемента
//на головній діагоналі матриці;
//■ Сортування елементів за зростанням окремо для
//кожного рядка матриці.******
//
//Завдання 3 * **.Написати функцію, яка приймає дві дати
//(тобто функція приймає шість параметрів) та обчислює
//різницю в днях між цими датами.Для виконання цього
//завдання необхідно також написати функцію, яка визна -
//чає, чи є рік високосним.
void numDetector(int arr[], int size) {
    int positive = 0, negative = 0, zeros = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            positive++;
        }
        else if (arr[i] < 0) {
            negative++;
        }
        else {
            zeros++;
        }
    }
    cout << "Number of postivie numbers : " << positive << endl;
    cout << "Number of negative numbers : " << negative << endl;
    cout << "Number of 0 : " << zeros << endl;
}

int main()
{
	srand(time(0));
    int const SIZE = 10;
    int arr[SIZE] = {};
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 21 - 10;
		cout << arr[i] << " ";
	}
	cout << endl;
    numDetector(arr, SIZE);

}
