#include <iomanip>
#include <iostream>

using namespace std;


void findLength(char arr[]) 
{
	int len = 0;
	while (arr[len] != '\0') 
	{
		len++;
	}
	cout << "Length of the string : " << len << endl;;
}

void chrRemove(char arr[], char symb)
{
	char newsymb = ' ';
	for (int i = 0; arr[i]!='\0'; i++)
	{
		if (arr[i] == symb)
		{
			arr[i] = newsymb;
		}
	}
}


int main()
{
	//1.Вводиться рядок.Яких букв у рядку більше ’а’ чи ’о’ ?
	cout << "Task 1" << endl;
	cout << "Enter sentence" << endl;
	int countA = 0, countO = 0;
	char arr[255];
	cin.getline(arr, 255);
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
	if (countA > countO)
	{
		cout << "letter a is more frequent" << endl;
	}
	else if (countO > countA)
	{
		cout << "letter o is more frequent" << endl;
	}
	else if (countO == countA)
	{
		cout << "letter o and a frequency same" << endl;
	}


	//2.Вводиться рядок.Порахувати кількість латинських букв, цифр та пробілів у рядку.
	cout << "Task 2" << endl;
	int countLetters = 0, countNum = 0, countSpace = 0;
	cout << "Enter sentence" << endl;
	char arr2[255];
	cin.getline(arr2, 255);
	for (int i = 0; i < strlen(arr2); i++)
	{

		if (isalpha(arr2[i]))
		{
			countLetters++;
		}
		if (isdigit(arr2[i]))
		{
			countNum++;
		}
		if (isspace(arr2[i]))
		{
			countSpace++;
		}
	}

	cout << "Number of letters : " << countLetters << endl;
	cout << "Number of numbers : " << countNum << endl;
	cout << "Number of spaces : " << countSpace << endl;


	//3.Дано рядок.Замінити у рядку всі великі букви на малі і навпаки.
	cout << "Task 3" << endl;
	char arr3[255];
	cout << "Enter sentence" << endl;
	cin.getline(arr3, 255);
	for (int i = 0; i < strlen(arr3); i++)
	{
		if (islower(arr3[i]))
		{
			arr3[i] = toupper(arr3[i]);
		}	
		else if (isupper(arr3[i]))
		{
			arr3[i] = tolower(arr3[i]);
		}
	}
	for (int i = 0; i < strlen(arr3); i++)
	{
		cout << arr3[i];
	}

	/*4.Написати функцію, яка отримує рядок і повертає довжину рядка.
		Без використання функції strlen()*/
	cout << "\nTask 4" << endl;
	char arr4[255];
	cout << "Enter sentence" << endl;
	cin.getline(arr4, 255);
	findLength(arr4);

	//5 * **.Дано рядок.Видалити із рядка заданий символ.Результат розмістити у новому рядку.
	cout << "\nTask 5" << endl;
	char arr5[255];
	cout << "Enter sentence" << endl;
	cin.getline(arr5, 255);
	char symb;
	cout << "Enter symbol to remove: "; cin >> symb;
	chrRemove(arr5, symb);
	for (int i = 0; i < strlen(arr5); i++)
	{
		cout << arr5[i];
	}

	/*
	6 * **.Розробити програму, яка зчитує з екрану рядок, а потім видає статистику :
	кількість пробільних символів(whitespaces), голосних, приголосних, знаків пунктуації.
	Введення передбачається англомовним.
	Hello
	Helo*/
}
