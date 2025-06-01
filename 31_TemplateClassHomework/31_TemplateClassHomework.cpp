
#include <iostream>
using namespace std;

/*Шаблони класів. initializer_list
Завдання 1:
Перетворити раніше створений клас Array на шаблон, який дозволить 
зберігати елементи будь-якого типу. Функціональність залишити на 
тому ж рівні.
Додати можливість створювати об'єкт та присвоювати йому 
значення шляхом спискової ініціалізації: { 1, 2, 3...}
Завдання 2:
Реалізуйте шаблонні функції для пошуку максимуму,
мінімуму, сортування масиву (будь-яким алгоритмом
сортування), двійкового пошуку в масиві, заміни елемента
масиву на передане значення. Ці методи винести за межі класу*/
template<typename T_arr>
class Array
{
	T_arr* arr;
	int size;
public:
	Array() : arr(nullptr), size(0) {};

	explicit Array(int size): size(size)
	{
		arr = new T_arr[size] {};
	}
	Array(const initializer_list<T_arr>& list)
	{
		this->size = list.size();
		arr = new T_arr[size];
		int i = 0;
		for (T_arr elem : list)
		{
			arr[i++] = elem;
		}
	}
	void Fill(const initializer_list<T_arr>& list)
	{
		if (arr != nullptr)delete[]arr;
		this->size = list.size();
		arr = new T_arr[size];
		int i = 0;
		for (T_arr elem : list)
		{
			arr[i++] = elem;
		}
	}
	~Array(){
		if (arr != nullptr)
			delete[]arr;
	}
	void Print() const{
		for (int i = 0; i < size; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	int GetSize() const { return size; }

	T_arr GetMax() const;
	T_arr GetMin() const;
	void Sort();
	int BinarySearch(T_arr value) const;
	void Replace(int index, T_arr newValue);
};

template <typename T_arr>
T_arr Array<T_arr>::GetMax() const
{
	T_arr max = arr[0];
	for (int i = 1; i < size; i++){
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

template <typename T_arr>
T_arr Array<T_arr>::GetMin() const
{
	T_arr min = arr[0];
	for (int i = 1; i < size; i++){
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}

template <typename T_arr>
void Array<T_arr>::Sort()
{
	for (int i = 0; i < size - 1; i++){
		for (int j = 0; j < size - i - 1; j++){
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

template<typename T_arr>
int Array<T_arr>::BinarySearch(T_arr value) const
{
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == value)
			return mid;
		else if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return -1;
}

template<typename T_arr>
void Array<T_arr>::Replace(int index, T_arr newValue)
{
	if (index >= 0 && index < size)
	{
		arr[index] = newValue;
	}
}

int main()
{
	Array<int> a1({ 2,5,6,8,9,4 });
	a1.Print();
	cout << "-Sorting int array-" << endl;
	a1.Sort();
	a1.Print();

	cout << "Filling a1 with new numbers" << endl;
	a1.Fill({ 56,23,4,5161,87,56,15,95,263 });
	a1.Print();
	cout << endl;
	Array<long> a2({ 10,11,12,13,14,15,16,17,18,911,19,20,21,22,23 });
	a2.Print();
	cout << "Max element in a2: " << a2.GetMax() << endl;
	cout << "Min element in a2: " << a2.GetMin() << endl;

	cout << "-Sorting long array-" << endl;
	a2.Sort();
	a2.Print();

	long value = 911;
	int index = a2.BinarySearch(value);
	if (index != -1)
		cout << "Value " << value << " found at index: " << index << endl;
	else
		cout << "Value " << value << " not found." << endl;

	cout << "Replacing third element with -5" << endl;
	a2.Replace(2, -5);
	a2.Print();


}