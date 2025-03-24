#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	const int SIZE = 200;
	char str[SIZE] = "C style string Standard function strcpy()...";
	cout << "Str = " << str << endl;
	//cout << str + 1 << endl;
	//cout << str + 2<< endl;
	////cout << str+3 << endl;
	//char copyStr[SIZE]{}; //
	//strcpy(copyStr, str); // to from
	//cout << "Copy of Str=" << copyStr << endl;
	////strcat_s concantination
	//// strcat_s(copyStr,"!!!!","***") adds "!!!" to tge end
	//// int result = strcmp(one, two) //compare apple > APPLE, "A" code < than "a" code
	//// int result = strcmp(one +1, two +2 )
	//// int result = strcmp(one  two, 4 )порівн не бліьше 4 букв
	//// int result = _stricmp(one  two) ignore case
	//const int size = 200;
	//char str[size] = " style string Standard function strcpy()...";
	//cout << "Str = " << str << endl;
	//// search func
	//char symbol = 't';
	//char* p = strchr(str, symbol);
	//if (p != nullptr) // nullptr not found
	//{
	//	cout << "Found symbol" << symbol << " in index " << p-str << endl; // -str дає index
	//	*p = '$'; //replace t(index 3) with $
	//	cout << "Replace symbol with $" << str;
	//}
	//else
	//{
	//	cout << "Symbol not found"; //cntl+rr; cntr+shift+v
	//}

	//const int LEN = 20;//вертає вказівник на першу бувку слова
	//char word[LEN];
	//cout << " Enter word: ";
	//cin >> word;
	//p = strstr(myStr, word);
	//if (p != nullptr)
	//{
	//	cout << "Found word ;", < word << "in index" << p - myStr << ednl;
	//	}
	cout << "Task 1" << endl;
	/*ВВести кількість слів.Потім ввести самі слова, обєднати  слова у новий рядок, розділити слова комою(чи іншим символом)
		strcat*/
	int n;
	cout << "Enter number of words to enter: ";
	cin >> n;
	char word[25];
	char text[400]{};
	for (int i = 0; i < n; i++)
	{
		cin >> word;
		strcat_s(text, word);
		if (i+1!=n)
		{
			strcat_s(text, ", ");
		}
		else
		{
			strcat_s(text, ". ");
		}
	}
	cout << text;

	/*Завдання 2. Дано текст та символ(ввести з клавіатури).Порахувати кількість входжень цього символа у рядку. (strchr)*/
	cout << "Task 2" << endl;
	int symb;
	cout << "Enter type of symbol to enter: ";
	cin >> symb;
	char text2[400]="Lorem ipsum dolor sit amet, consectetur adipiscing elit. Cras tempor sagittis erat, lacinia tristique ex commodo id. In efficitur ante nec ligula pellentesque mattis. Cras quis dictum erat. Fusce a semper mi. Sed vitae sapien quam. Etiam mollis blandit porttitor. Sed euismod, nibh eu commodo blandit, justo augue aliquet dui, a maximus ante enim at metus. Pellentesque rutrum fa";
	char* p = strchr(text2, symb);
	if (p != nullptr)
	{
		cout << "Found symbol: " << symb << " in index " << p-text2 << endl;
		*p = '$';
		cout << "Replace symbol with $ " << text2;
	}
	else
	{
		cout << "Symbol not found";
	}// TO DO

}
