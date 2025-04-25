
#include <iostream>
using namespace std;
/*Створити функції для роботи з динамічним масивом
- створення  динамічного масиву заданого розміру, розмір приходить як параметр функції
- заповнення масиву випадковими числами + виконано
- виведення масиву + виконано
- доповнення масиву новим елементом(на початок)
- доповнення масиву новим елементом(у хвіст масиву) + виконано
- вилучення із  масиву останнього елементу
- вилучення із  масиву першого елементу
- вилучення елемента за вказаним індексом
- вставки нового елемента за вказаним індексом

Протестувати роботу функцій.

__________________________________________________________
Додаткові завдання(за бажанням)

5. Визначити функцію видалення усіх від'ємних елементів із динамічного масиву. 
Можна скористатися раніше визначеною функцією вилучення елемента(із завдання 3).

6. Створити функцію, яка дозволяє додати блок елементів у кінець  масиву.
int* addBlock(int* arr, int& size, const int* block, int sizeBlock) або
void addBlock(int*& arr, int& size, const int* block, int sizeBlock)


7.  Створити функцію, яка дозволяє вилучити  блок елементів, починаючи із  вказаного індекса вказаної  довжини
int* removeBlock(int* arr, int& size, int index, int length) або
voido removeBlock(int*& arr, int& size, int index, int length)

8. Дано два масиви : А[M] і B[N](M і N вводяться з клавіатури).Необхідно створити третій масив
мінімально можливого розміру, у якому потрібно зібрати спільні елементи двох масивів без повторень.
int* intersect(const int* a, int sizeA, const int* b, int sizeB, int& size)*/
int* createArr(int size)
{
    int* arr = new int [size] {};
    return arr;
}

void fillArrayWithRand(int*& arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 100);
    }
}

void printArray(const int* arr, int size)
{
    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << arr[i];
    }
    cout << endl;
}


void addToFront(int element, int*& arr, int& size)
{
    ++size;
    int* tmp = new int[size];

    for (int i = 0; i < size - 1; i++)
    {
        tmp[i + 1] = arr[i];
    }

    tmp[0] = element;

    delete[] arr;

    arr = tmp;
}


void addToEnd(int element, int*& arr, int& size)
{
    ++size;
    int* tmp = new int[size];


    for (int i = 0; i < size - 1; i++)
    {
        tmp[i] = arr[i];
    }

    tmp[size - 1] = element;


    delete[] arr;


    arr = tmp;
}

void removeLast(int*& arr, int& size)
{
    if (size <= 0) 
    {
        cout << "Error" << endl;
        return;
    }
    --size;
    int* tmp = new int[size];
    for (int i = 0; i < size; i++) {
        tmp[i] = arr[i];
    }
    delete[] arr;
    arr = tmp;
}


void removeFirst(int*& arr, int& size)
{
    if (size <= 0)
    {
        cout << "Error" << endl;
        return;
    }
    --size;
    int* tmp = new int[size];
    for (int i = 0; i < size; i++) {
        tmp[i] = arr[i + 1];
    }
    delete[] arr;
    arr = tmp;
}


void removeAt(int*& arr, int& size, int index)
{
    if (index < 0 || index >= size)
    {
        cout << "Error" << endl;
        return;
    }
    --size;
    int* tmp = new int[size];
    for (int i = 0, j = 0; i < size + 1; i++) {
        if (i != index) 
        {
            tmp[j++] = arr[i];
        }
    }
    delete[] arr;
    arr = tmp;
}


void insertAt(int*& arr, int& size, int index, int element)
{
    if (index < 0 || index > size) 
    {
        cout << "Error" << endl;
        return;
    }
    ++size;
    int* tmp = new int[size];
    for (int i = 0, j = 0; i < size; i++) {
        if (i == index) {
            tmp[i] = element;
        }
        else {
            tmp[i] = arr[j++];
        }
    }
    delete[] arr;
    arr = tmp;
}

int main()
{
    /*-створення  динамічного масиву заданого розміру, розмір приходить як параметр функції
        - заповнення масиву випадковими числами + виконано
        - виведення масиву + виконано
        - доповнення масиву новим елементом(на початок)
        - доповнення масиву новим елементом(у хвіст масиву) + виконано
        - вилучення із  масиву останнього елементу
        - вилучення із  масиву першого елементу
        - вилучення елемента за вказаним індексом
        - вставки нового елемента за вказаним індексом*/
    srand(time(0));
    int SIZE = 5;
    int* myArray = createArr(SIZE);

    fillArrayWithRand(myArray, SIZE);

    cout << "Initialized array : " << endl;
    printArray(myArray, SIZE);

    cout << "\nAdding 100 to the front : " << endl;
    addToFront(100, myArray, SIZE);
    printArray(myArray, SIZE);

    cout << "\nAdding 200 to the end : " << endl;
    addToEnd(200, myArray, SIZE);
    printArray(myArray, SIZE);

    cout << "\nRemoving first element : " << endl;
    removeFirst(myArray, SIZE);
    printArray(myArray, SIZE);

    cout << "\nRemoving last element : " << endl;
    removeLast(myArray, SIZE);
    printArray(myArray, SIZE);

    int insertIndex = 3;
    cout << "\nInserting 300 at index " << insertIndex << " : " << endl;
    insertAt(myArray, SIZE, insertIndex, 300);
    printArray(myArray, SIZE);

    int removeIndex = 2;
    cout << "\nRemoving element at index " << removeIndex << ":" << endl;
    removeAt(myArray, SIZE, removeIndex);
    printArray(myArray, SIZE);

    delete[] myArray;
    myArray = nullptr;
}
