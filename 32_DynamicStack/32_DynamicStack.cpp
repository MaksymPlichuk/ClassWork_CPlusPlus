
#include <iostream>
using namespace std;

/*Тема: Динамічні структури даних — стек
Завдання N1
Реалізуйте клас стек для роботи з символами (символь-
ний стек). Стек повинен мати фіксований розмір. Також
реалізуйте набір операцій для роботи зі стеком: внесення
символу в стек, видалення символу зі стеку, підрахунок
кількості символів в стеці, перевірку, чи стек порожній,
перевірку, чи стек повний, очищення стеку, отримання
без видалення верхнього символу в стеці.

Завдання N2
Змініть стек з першого завдання зі статичного типу на
динамічний (за нестачі вільного місця потрібно змінити
розмір внутрішнього масиву без втрати даних).
 */

class Stack {
    int size;
    char *arr;
    int topIndex;
	enum{EMPTY=-1};
public:
	Stack() = delete;

	Stack(int size) :size(size)//100
	{
		arr = new char[size];
		topIndex = EMPTY;
	}
	bool IsFull()const
	{
		return topIndex == size - 1;
	}
	bool Push(char elem)
	{
		if (!IsFull())
		{
			arr[++topIndex] = elem;
			return true;
		}
		return false;
	}
	bool IsEmpty()const
	{
		return topIndex == EMPTY;
	}
	char Pop()
	{
		if (!IsEmpty())
		{
			return arr[topIndex--];
		}
	}
	int Peek()
	{
		if (!IsEmpty())
		{
			return arr[topIndex];
		}
	}
	int GetCount()const
	{
		return topIndex + 1;
	}
	void Clear()
	{
		topIndex = EMPTY;
	}
	void Print()const
	{
		for (int i = 0; i < GetCount(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	~Stack()
	{
		if (arr != nullptr)
			delete[]arr;
	}
};
char symb;
int main()
{
	Stack st(5);
	
	while (!st.IsFull())
	{
		cout << "Enter symbol: " << endl;
		cin >> symb;
		st.Push(symb);
	}
	st.Print();
	cout << "Length : " << st.GetCount() << endl;
	while (!st.IsEmpty())
	{
		cout << "Element delete - " << st.Pop() << endl;
	}
	cout << "Count : " << st.GetCount() << endl;
}
