
#include <iostream>
#include <cstring>
using namespace std;
/*Завдання 1.
Дано текст та символ(ввести з клавіатури).
Порахувати кількість входжень цього символа у рядку. (strchr)*/

int main()
{
	cout << "Task 1" << endl;
	const int SIZE = 255;
	char arr[SIZE]{};
	char symb;
	cout << "Enter text : "; cin.getline(arr, SIZE); cout << endl;
	cout << "Enter symbol to find : "; cin >> (symb); cout << endl;
	char* p = strchr(arr, symb);
	while (p != nullptr)
	{
		cout << "Found symbol : " << symb<<" in index " << p - arr << endl;
		p = strchr(p + +1, symb);
	}


	/*Завдання 2.
Дано текст та два символи(ввести з клавіатури).
Замінити у тексті один символ на інший. (strchr)
* *Зробити це не більше чим N разів*/
	cout << "\nTask 2" << endl;
	cin.ignore();
	char arr2[SIZE]{};
	char symb1, replaceSymb;
	int numOfReplace, count = 0;
	cout << "Enter text : "; cin.getline(arr2, SIZE); cout << endl;
	cout << "Enter symbol to find : "; cin >> (symb1); cout << endl;
	cout << "Enter symbol to replace with : "; cin >> (replaceSymb); cout << endl;
	cout << "Enter max replacements: "; cin >> numOfReplace; cout << endl;
	char* p1 = strchr(arr2, symb1);
	while (p1 && count < numOfReplace) 
	{
		*p1 = replaceSymb;
		count++;
		p1 = strchr(p1 + 1, symb1);
	}

	cout << "Replaced text : " << arr2 << endl;


	/*Завдання 3.
	Вводиться послідовність N слів(N вводиться з клавіатури).Об'єднати у окремий рядок слова, що  починаються та закінчуються на однакову букву.
	strcat, strlen()*/
	cin.ignore();
	cout << "\nTask 3" << endl;
	const int WORD_SIZE = 25;
	int n;

	cout << "Enter number of words to input: "; cin >> n;

	char word[WORD_SIZE];
	char result[SIZE] = "";

	for (int i = 0; i < n; ++i) {
		cout << "Enter word: ";
		cin.getline(word, WORD_SIZE);

		int len = strlen(word);
		if (len > 0 && word[0] == word[len - 1]) {
			if (strlen(result) > 0) {
				strcat_s(result, " ");
			}
			strcat_s(result, word);
		}
	}
	cout << "\nResult: " << result << endl;



/*Завдання 4.
Ввести  послідовність слів до зустрічі слова "stop". Порахувати число введених  слів.
Записати у окремий рядок слова, що починаються із певного сполучення букв.
Наприклад, вводиться сполучення букв "for" та вводяться слова
	for
	fear
	forget
	forgive
	rfor
	stop
Число слів  = 5
Рядок із  словами, що починаються на  'for' = 'for forget forgive' 

strcmp(), strcat(), strstr()*/
	cout << "\nTask 4" << endl;

	char word2[WORD_SIZE];
	char result2[SIZE] = "";

	char startWith[WORD_SIZE];
	int wordCount = 0;

	cin.ignore();
	cout << "Enter starting letters : ";
	cin.getline(startWith, WORD_SIZE);

	while (true)
	{
		cout << "Enter word: ";
		cin.getline(word2, WORD_SIZE);

		if (strcmp(word2, "stop") == 0) break;
		wordCount++;

		if (strstr(word2, startWith) == word2) 
		{
			if (strlen(result2) > 0) 
			{
				strcat_s(result2, " ");
			}
			strcat_s(result2, word2);
		} 
		
	}
	cout << "\nNumber of words : " << wordCount;
	cout << "\nString with letters that start on " << startWith << " : " << result2<< endl;
/*________________________________________________________________________________

Додаткові завдання.
Завдання 5.
Дано текст та два слова (фрагменти) однакової довжини.
Замінити у тексті одне слово на інше. (strstr, strncpy)
Порахувати число виконаних замін.

Завдання 6.
Порахуйте скільки разів цифри зустрічаються в тексті. 
strchr або strpbrk(рядок, набір цифр)*/


}
