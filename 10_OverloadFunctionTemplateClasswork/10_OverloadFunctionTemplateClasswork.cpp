//1.Реалізуйте перевантажені функції для
//■ Знаходження максимального значення двох цілих;
//■ Знаходження максимального значення трьох цілих.
//■ Знаходження мінімального значення двох цілих;
//■ Знаходження мінімального значення трьох цілих.
//
//
//1. Написати шаблон функції для пошуку середнього
//арифметичного значення масиву.
//
//2.Написати шаблонні функції і протестувати їх в ос -
//новній програмі :
//
//■ Знаходження максимального значення в однови -
//мірному масиві;
//■ Знаходження максимального значення у двовимір -
//ному масиві;

#include <iostream>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int max(int a, int b, int c)
{
    int maximum = a;
    if (a >b && a>c)
    {
        maximum = a;
    }
        
    else if(b>a && b>c)
    {
        maximum = b;
    }
    else if (c>a && c>b)
    {
        maximum = c;
    }
    return maximum;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int min(int a, int b, int c)
{
    int minimum = a;
    if (a < b && a < c)
    {
        minimum = a;
    }
        
    else if(b<a && b < c)
    {
        minimum = b;
    }
    else if (c<a && c < b)
    {
        minimum = c;
    }
    return minimum;
}

template <typename T1>
double avg(T1 arr[],int size)
{
    T1 summa = 0;
    
    for (int i = 0; i < size; i++)
    {
        summa +=arr[i]  ;
       
    }
    double avg = (double)summa / size;
        return avg;
}

int main()
{
    cout << "Max element = " << max(5, 3) << endl;
    cout << "Min element = " << min(5, 3) << endl;
    const int size = 10;
    int arr[size] = {5,8,45,21,987,654,1,54,48,566};
    cout << "Average = " << avg(arr,size) << endl;
}
