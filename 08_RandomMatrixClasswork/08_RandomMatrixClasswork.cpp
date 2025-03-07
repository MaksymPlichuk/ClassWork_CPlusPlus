// 08_RandomMatrixClasswork.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;
int main()
{
    /*int start;
    cout << "Enter new start point : ";
    cin >> start;
    srand(start);*/
    //srand(time(NULL)); //dlya randomnuh chisel kozen raz
    //int a;
    //a = rand();
    //cout << "a = " << a << endl;
    //a = rand();
    //cout << "a = " << a << endl;
    //a = rand();
    //cout << "a = " << a << endl;

    ////diapazon 0-X
    //for (int i = 0; i < 10; i++)
    //{
    //    a = rand() % 100;
    //    cout << "a = " << a << endl;
    //}
    /*1.Дано масив розміром 4×3 з елементами цілого типу.
        Визначити кількість елементів відмінних від нуля.*/
    cout << "Task 1" << endl;
    const int row = 4;
    const int col = 3;
    int negatives = 0;
    int arr1[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr1[i][j] = (-20 + rand() % 40);
            if (arr1[i][j] < 0)
            {
                negatives++;
            }
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout <<"Ammount of negatives numbers: " << negatives << endl;

    /*2.Дано масив розміром 3×3 з елементами цілого типу.
        Визначити кількість елементів які б дорівнювали нулю.*/
    cout << "Task 2" << endl;
    const int row1 = 3;
    const int col1 = 3;
    int eq0 = 0;
    int arr2[row1][col1];
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            arr2[i][j] = (-5 + rand() % 10);
            if (arr2[i][j] == 0)
            {
                eq0++;
            }
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Ammount of numbers = 0 : " << eq0 << endl;


    /*3.Дано масив розміром 7×3 з елементами цілого типу.
        Визначити кількість елементів, модуль яких менший 12. (-20 + rand() % 40)*/
    cout << "\nTask 3" << endl;
    const int row2 = 7;
    const int col2 = 3;
    int arr3[row2][col2];
    int mod12 = 0;
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            arr3[i][j] = (-20 + rand() % 40);
            if (arr3[i][j]%12==0)
            {
                mod12++;
            }
            cout << arr3[i][j] << " ";
        }
        cout<< endl;
    }
    cout << endl;
    cout << "Ammount of numbers %12 : " << mod12 << endl;

    /*4.Дано масив розміром 4×5 з елементами цілого типу(позитивні та від’ємні).
        Визначити кількість позитивних елементів.*/

    cout << "\nTask 4" << endl;
    const int row3 = 4;
    const int col3 = 5;
    int arr4[row3][col3];
    int positives = 0;
    for (int i = 0; i < row3; i++)
    {
        for (int j = 0; j < col3; j++)
        {
            arr4[i][j] = (-20 + rand() % 40);
            if (arr4[i][j] > 0)
            {
                positives++;
            }
            cout << arr4[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Ammount of numbers > 0 : " << mod12 << endl;

    /*5.Дано масив розміром 5×4 з елементами дійсного типу(додатні та від’ємні).
        Визначити добуток всіх додатніх елементів.*/
    cout << "\nTask 5" << endl;
    const int row4 = 5;
    const int col4 = 4;
    int arr5[row4][col4];
    int production = 1;
    for (int i = 0; i < row4; i++)
    {
        for (int j = 0; j < col4; j++)
        {
            arr5[i][j] = (-20 + rand() % 40);
            if (arr5[i][j] > 0)
            {
                production*= arr5[i][j];
            }
            cout << arr5[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Production of numbers > 0 : " << production << endl;

    /*6.Дано масив розміром 5×4 з елементами дійсного типу(позитивні та від’ємні).
        Визначити добуток всіх від’ємних елементів.*/
    cout << "\nTask 6" << endl;
    const int row5 = 5;
    const int col5 = 4;
    int arr6[row5][col5];
    int production1 = 1;
    for (int i = 0; i < row5; i++)
    {
        for (int j = 0; j < col5; j++)
        {
            arr6[i][j] = (-20 + rand() % 40);
            if (arr6[i][j] < 0)
            {
                production1 *= arr6[i][j];
            }
            cout << arr6[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Production of numbers < 0 : " << production1 << endl;


    /*7.Дано масив розміром 4×4 з елементами цілого типу.Визначити кількість
        елементів, які б при діленні на 6 давали залишок 1. 13 % 6 = 1*/
    cout << "\nTask 7" << endl;
    const int row6 = 4;
    const int col6 = 4;
    int arr7[row6][col6];
    int div6 = 1;
    for (int i = 0; i < row6; i++)
    {
        for (int j = 0; j < col6; j++)
        {
            arr7[i][j] = (-20 + rand() % 40);
            if (arr7[i][j] %6== 1)
            {
                div6++;
            }
            cout << arr7[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Numbers that %6 = 1 : " << div6 << endl;

    /*8.Дано масив розміром 5хб цілого типу.Знайти мінімальний елемент.*/
    cout << "Task 8" << endl;
    const int row7 = 5;
    const int col7 = 6;
    int arr8[row7][col7];
    
    for (int i = 0; i < row7; i++)
    {
        
        for (int j = 0; j < col7; j++)
        {
            arr8[i][j] = (-20 + rand() % 40);
            cout << arr8[i][j] << " ";
        }
        cout << endl;
    }
    int min = arr8[0][0];
    for (int i = 0; i < row7; i++)
    {

        for (int j = 0; j < col7; j++)
        {
            if (arr8[i][j] < min)
            {
                min = arr8[i][j];
            }
        }
    }
    cout << endl;
    cout << "Minimum : " << min << endl;
    
   /* 9.Дано масив розміром 5×6 цілого типу.Знайти максимальний елемент.*/
    cout << "Task 9" << endl;
    const int row8 = 5;
    const int col8 = 6;
    int arr9[row8][col8];

    for (int i = 0; i < row8; i++)
    {

        for (int j = 0; j < col8; j++)
        {
            arr9[i][j] = (-20 + rand() % 40);
            cout << arr9[i][j] << " ";
        }
        cout << endl;
    }
    int max = arr9[0][0];
    for (int i = 0; i < row8; i++)
    {

        for (int j = 0; j < col8; j++)
        {
            if (arr9[i][j] > max)
            {
                max = arr9[i][j];
            }
        }
    }
    cout << endl;
    cout << "Maximum : " << max << endl;

    /*10.Дано масив розміром 5×4 з елементами дійсного типу(позитивні та від’ємні).
    Визначити суму всіх від’ємних елементів.*/
    cout << "\nTask 10" << endl;
    const int row9 = 5;
    const int col9 = 4;
    int arr10[row9][col9];
    int nsum = 0;
    for (int i = 0; i < row9; i++)
    {
        for (int j = 0; j < col9; j++)
        {
            arr10[i][j] = (-20 + rand() % 40);
            if (arr10[i][j] < 0)
            {
                nsum += arr10[i][j];
            }
            cout << arr10[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Summ of negatives: " << nsum << endl;



}