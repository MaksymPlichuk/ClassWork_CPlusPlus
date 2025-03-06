
#include <iostream>
using namespace std;
/*1.Оголосити одновимірний масив з 10 елементів типу int.
Заповнити його значеннями з клавіатури, вивести на екран та
підрахувати добуток елементів масиву

2.Оголосити одновимірний масив з 7 елементів типу int.
Заповнити його випадковими значеннями в діапазоні[-12.. + 50]
та вивести на екран.
Підрахувати кількість відємних та додатніх елементів масиву.

*/
int main()
{
    cout << "Task1" << endl;
    int dob = 1;
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter " << i + 1 << " element: ";
        cin >> arr[i];
        dob *= arr[i];
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
        
    }
    cout << endl;
    cout << dob;

    cout << "\nTask2" << endl;
    int negatives = 0;
    int positives = 0;
    int arr1[7] = { -27, 42, 5, -19, 31, -8, 47 };
    for (int i = 0; i < 7; i++)
    {
        cout << arr1[i] << " ";
        if (arr1[i] < 0)
        {
            negatives++;
        }
        if (arr1[i] > 0)
        {
            positives++;
        }
    }
    cout << "\nAmmount of numbers > 0" << positives << ";" << "Ammount of numbers < 0" << negatives << endl;

    /*3.Оголосити, проініціалізувати початковими значеннями та вивести
        одновимірний масив з 7 елементів типу long.Визначити суму парних елементів масиву

        4.Утворити одновимірний масив розміром 30.
        Заповнити його числами, які є степенями 2: (1, 2, 4, 8, 16, ...).
        Вивести елементи масиву на екран у прямому і оберненому порядку.

        5.Дано одновимірний масив.Замінити всі від’ємні елементи їх модулями*/

    cout << "\nTask3" << endl;
    long arr2[7];
    int summa = 0;
    for (int i = 0; i < 7; i++)
    {
        cout << "Enter " << i + 1 << " element: ";
        cin >> arr2[i];
        if (arr2[i] %2==0) {
            summa += arr2[i];
        }
        
    }

    for (int i = 0; i < 7; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << "\nSum of even numbers: " << summa;
    cout << endl;

    cout << "\nTask4" << endl;
    const int size = 30;
    long long arr3[size] = { 1 };
    for (int i = 1; i <= size; i++)
    {
        arr3[i] = arr3[i - 1] * 2;
        cout <<i <<"\t" << arr3[i] << endl;
    }
    for (int i = 29; i >= 1; i--)
    {
        arr3[i] = arr3[i + 1] / 2;
        cout <<i <<"\t" << arr3[i] << endl;
    }
    
    cout << "Task5" << endl;
    const int size1 = 10;
    int arr4[size1] = { -7, -3, 15, -11, 27, -5, 34, -9, 42, 10 };
    cout << "----------Before change----------" << endl;
    for (int i = 0; i < size1; i++)
    {
            cout << arr4[i] << " ";
    }
    cout << endl;
    cout << "----------After change----------" << endl;
    for (int i = 0; i < size1; i++)
    {
        if (arr4[i] < 0) {
            arr4[i] = arr4[i] * (-1);
            cout << arr4[i]<< " ";
        }
        else
        {
            cout << arr4[i] << " ";
        }
    }



}