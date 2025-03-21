#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

//1.Вводиться рядок.Яких букв у рядку більше ’а’ чи ’о’ ?
//3.Дано рядок.Замінити у рядку всі великі букви на малі і навпаки.
//4.Написати функцію, яка отримує рядок і повертає довжину рядка.
//Без використання функції strlen()
//5 * **.Дано рядок.Видалити із рядка заданий символ.Результат розмістити у новому рядку.
//6 * **.Розробити програму, яка зчитує з екрану рядок, а потім видає статистику :
//кількість пробільних символів(whitespaces), голосних, приголосних, знаків пунктуації.
//Введення передбачається англомовним.
int main()
{

	/*int countA = 0;
	int countO = 0;
    char arr[255];
    cout << "Enter string: "; cin.getline(arr, 255);
	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] == 'a')
		{
			countA++;
		}
		if (arr[i] == 'o')
		{
			countO++;
		}
	}
	if (countA>countO)
	{
		cout << "letter a is more frequent" << endl;
	}
	else if (countO>countA)
	{
		cout << "letter o is more frequent" << endl;
	}
	else if (countO==countA)
	{
		cout << "letter o and a frequency same" << endl;
	}*/
	//2.Вводиться рядок.Порахувати кількість латинських букв, цифр та пробілів у рядку.
	cout << "Task 2" << endl;
	char arr2[255];
	int letterCount = 0;
	int spaceCount = 0;
	int numCount = 0;
	cout << "Enter string: "; cin.getline(arr2, 255);
	for (int i = 0; i < strlen(arr2); i++)
	{
		if (isalpha(arr2[i]))
		{
			letterCount++;
		}
		if (isspace(arr2[i]))
		{
			spaceCount++;
		}
		if (isdigit(arr2[i]))
		{
			numCount++;
		}
	}
	
	cout << "Number of letters: " << letterCount << endl;
	cout << "Number of numbers: " << numCount << endl;
	cout << "Number of spaces: " << spaceCount << endl;
}
