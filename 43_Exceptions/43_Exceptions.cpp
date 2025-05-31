
#include <iostream>
using namespace std;

/*Завдання 1:

Перепишіть клас Stack(Queue) одного з попередніх домашніх завдань таким чином, 
щоб генерувати виключення для можливих некоректних ситуацій 
які можуть виникнути.
Наприклад, неможливість виділити потрібну кількість пам’яті, 
переповнення стека, витяг з порожнього стека і т.д. Для 
реалізації даного завдання використати або створити власні 
класи-exception або ж взяти з біблеотеки <stdexcept>.
 */

class Stack {
	enum { EMPTY = -1 };
	int* arr;
	int size;
	int topIndex;
public:
	Stack() = delete;

	Stack(int size) :size(size)//100
	{
		if (size<0)
		{
			cout << "Can't divide by zero" << endl;
			throw exception("Wrong Size");
		}
		else
		{
			arr = new int[size];
			topIndex = EMPTY;
		}
	}
	bool IsFull()const
	{
		return topIndex == size - 1;
	}
	bool Push(int elem)
	{
		if (!IsFull())
		{
			arr[++topIndex] = elem;
			return true;
		}
		throw exception("Array is full!");
	}
	bool IsEmpty()const
	{
		return topIndex == EMPTY;
	}
	int Pop()
	{
		if (!IsEmpty())
		{
			return arr[topIndex--];
		}
		else
		{
			throw exception("Array is Empty!");
		}
	}
	int Peek()
	{
		if (!IsEmpty())
		{
			return arr[topIndex];
		}
		else
		{
			throw exception("Array is Empty!");
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

int main()
{
	try
	{
		Stack st(5);

		while (!st.IsFull())
		{
			st.Push(rand() % 100);
		}

		//st.Push(rand() % 100);
		st.Print();
		cout << "Length : " << st.GetCount() << endl;
		while (!st.IsEmpty())
		{
			cout << "Element delete - " << st.Pop() << endl;
		}
		//cout << "Element delete - " << st.Pop() << endl;
		cout << "Count : " << st.GetCount() << endl;

	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
	

}