#include <iostream>
using namespace std;

/*1.Дано три числа.Оголосити вказівники на ці числа.Отримати добуток трьох
заданих чисел, середє арифметичне, найменше з них, користуючись
непрямим доступом до чисел(через вказівники).
*/
int main()
{
    srand(time(0));
    cout << "\tTask 1" << endl;
    int a, b, c;
    cout << "Enter a : "; cin >> a;
    cout << "Enter b : "; cin >> b;
    cout << "Enter c : "; cin >> c;
    int* pa = &a;
    int* pb = &b;
    int* pc = &c;
    int dob = (*pa) * (*pb) * (*pc);
    int avg = ((*pa) + (*pb) + (*pc)) / 3;
    int min=*pa;
    if (*pb < *pa && *pb < *pc)
    {
         min = *pb;
    }
    else if (*pc<*pa && *pc<*pb)
    {
         min = *pc;
    }
    else if (*pa<*pb && *pa<*pc)
    {
         min = *pc;
    }
    cout << "Product of numbers : " << dob << endl;
    cout << "Average of numbers : " << avg << endl;
    cout << "Minimum of numbers : " << min << endl;

    /*2.Дано цілочисельний одновимірний масив.Заповнити його,
        вивести на екран у прямому та зворотньому порядку та порахувати
        суму елементів з використанням вказівників.*/
    cout << "\tTask 2" << endl;
    const int SIZE = 5;
    int arr[SIZE]{};
    int* parr = arr;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter " << i + 1 << " element ";
        cin >> *parr;
        parr++;
    }
    parr=arr;
    for (int i = 0; i < SIZE; i++)
    {
        cout << *parr << " ";
        parr++;
    }
    cout << endl;
    *(parr--);
    for (int i = 0; i < SIZE; i++)
    {
        cout << *parr << " ";
        parr--;
    }
    
    cout << "\n\tTask 3" << endl;
    /*3.Дано одновимірний масив.Знайти найбільше та найменше значення у
        масиві та поміняти їх у масиві місцями.Вивести перетворений масив на екран.*/
    int arr2[SIZE]{};
    int temp;
    int* parr2 = arr2;
    for (int i = 0; i < SIZE; i++)
    {
        *parr2 = rand() % 100;
        parr2++;
    }
    parr2 = arr2;
    int min2 = *parr2;
    int* min_p = parr2;
    int max2 = *parr2;
    int* max_p = parr2;
    for (int i = 0; i < SIZE; i++)
    {
        cout << *parr2 << " ";
        if (*parr2>max2)
        {
             max2=* parr2;
             max_p = parr2;
        }
        if (*parr2<min2)
        {
             min2= * parr2;
             min_p = parr2;
        }
        parr2++;
    }
    cout << endl;
    cout << "Max Element : " << max2 << endl;
    cout << "Min Element : " << min2 << endl;
    temp = *max_p;
    *max_p = *min_p;
    *min_p = temp;
    parr2 = arr2;
    for (int i = 0; i < SIZE; i++)
    {
        cout << *parr2 << " ";
        parr2++;
    }

    cout << "\n\tTask 4" << endl;
    /*4.Дано масив цілих чисел.Користуючись вказівниками, поміняти місцями елементи
        масиву з парними и непарними індексами(тобто ті елементи масиву, які стоять
            на парних місцях, поміняти з елементами, які стоять на непарних місцях).*/

    int arr3[SIZE]{};
    temp=0;
    int* parr3 = arr3;
    for (int i = 0; i < SIZE; i++)
    {
        *parr3 = rand() % 100;
        parr3++;
    }
    parr3 = arr3;
 
    for (int i = 0; i < SIZE; i++)
    {
        cout << *parr3 << " ";
        parr3++;
    }
    parr3 = arr3;
    for (int i = 0; i < SIZE-1; i++)
    {
        temp = *(parr3 + i + 1);
        *(parr3 + i + 1) = *(parr3 + i);
        *(parr3 + i) = temp;
    }
    cout << endl;

    parr3 = arr3;
    for (int i = 0; i < SIZE; i++)
    {
        cout << *parr3 << " ";
        parr3++;
    }
}

