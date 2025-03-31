
#include <iostream>
using namespace std;
// 1. Визначити функції обчислення суми, різниці, добутку, частки двох дробових 
//чисел. Викликати функції через вказівник функції.
double sum(double a, double b)
{
    return a + b;
}
double subtract(double a, double b)
{
    return a - b;
}
double multiplication(double a, double b)
{
    return a * b;
}
double division(double a, double b)
{
    return a / b;
}


int main()
{
    cout << "Task 1" << endl;
    double (*ptrFun) (double, double);
    double a; double b;
    cout << "\nEnter double 2 values : ";
    cin >> a >> b;
    ptrFun = sum;
    cout << "PtrFun (" << a << "," << b << ") = " << ptrFun(a, b) << endl;
    ptrFun = subtract;
    cout << "PtrFun (" << a << "," << b << ") = " << ptrFun(a, b) << endl;
    ptrFun = multiplication;
    cout << "PtrFun (" << a << "," << b << ") = " << ptrFun(a, b) << endl;
    ptrFun = division;
    cout << "PtrFun (" << a << "," << b << ") = " << ptrFun(a, b) << endl;

    // 2. Організувати меню за допомогою масиву вказівників на функції  обчислення суми, різниці, добутку, частки двох дробових чисел.
    cout << "Task 2" << endl;

    const int SIZE = 4;
    double (*arrFun[SIZE]) (double, double) = { sum,subtract, multiplication, division };// масив вказівників на функції, які отримують double та повертають double
    cout << "Enter  values : ";
    cin >>a >>b;
    for (int i = 0; i < SIZE; i++)
    {
    cout << i+1 <<" func results : " << arrFun[i](a,b) << endl;
    cout << endl;
    }
    cout << "Make a choice\n";
    int choice;
    do {
        cout << "1. Sum(a+b)\n2. Subtract(a-b)\n3.multiplication(a*b)\n4. division(a/b)\n";
        cin >> choice;
        if (choice >= 1 and choice <= SIZE)
        {
            cout << "Result = " << arrFun[choice-1](a,b) << endl;
        }
        else if (choice == 0) {
            cout << "Bye-bye!\n";
            break;
        }
    } 
    while (true);

    cout << "Task 3" << endl;
    /*Визначити функцію, яка отримує одновимірний масив та замінює всі елементи масиву за певним правилом(подвоює, збільшує на 1  чи інше).
        Правило зміни задавати як вказівник на функцію з прототипом int func(int) або void func(int&).
        Визначити допоміжні функції для зміни одного елемента, наприклад void inc(int&) для збільшення числа на 1  та ін.*/
    /*const int size = 8;
    int arr[size] = { 16, 24, 18, 96, 54, 68, 41, 87 };
      cout << "Original : " << endl;
      print_arr(arr, size);

        change_arr(arr, size, increase);
        cout << "After +1:" << endl;
        print_arr(arr, size);

        change_arr(arr, size, double_value);
        cout << "After double: " << endl;
        print_arr(arr, size);

        change_arr(arr, size, square);
        cout << "After square:" << endl;
        print_arr(arr, size);*/

        /*//Визначити допоміжні функції для зміни одного елемента, //наприклад void inc(ints) для збільшення числа на 1 та ін.

        void double_value(int& value) {
        value = 2;
        void increase(int& value) {
        value += 1;
        }
        void square(int value) {
        value value;
        using funType = void (*) (int);
        void change_arr(int arr[], int size, funType func) {
        }
        cout arr[i]<<";
        cout
        for (int 18; 1 size; i++) {
        func(arr[1]);
        void print arr(int arr[], int size) {
        for (int i=0; i < size; i++) [
        endl;*/








    /*4. Визначити  функцію arraysAction(масив1, масив2, масив3, функціяДія), яка приймає як аргументи покажчики на три масиви однакові за розміром, 
    їх розмір та вказівник на функцію.Функція arraysAction() повинна виконати операцію, передану через вказіваник на функцію над відповідними елементами перших двох масивів, 
    та занести результат у відповіний елемент треього масиву.
    творити функції для виконання дій (наприклад додавання, віднімання, множення, середнє, максимальне з двох).*/

}

