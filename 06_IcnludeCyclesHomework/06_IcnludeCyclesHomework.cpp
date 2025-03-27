#include <iostream>
using namespace std;
//На додаткові 12 балів.
//(вкладені цикли)

int main()
{
    //1.Вивести на екран n одиниць, потім 2n двійок,
//потім 3n трійок.Число n вводить користувач.
//(Зробити вкладеним циклом одним)
//н = 5
//11111
//2222222222
//333333333333333
    cout << "Task 1" << endl;
    int num;
    cout << "Enter the how many numbers to print: "; cin >> num; cout << endl;
    for (int n = 1; n <= 3; n++) {
        for (int i = 0; i < n * num; i++) {
            cout << n;
        }
        cout << endl;
    }

//2..Виведіть на екран квадрат з нулів і одиниць,
//причому нулі знаходяться тільки на діагоналі квадрата.
//Всього в квадраті сто цифр.
    cout << "\nTask 2" << endl;
    int size = 10;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j || j == size - i - 1) {
                cout << "0" << " ";
            }
            else {
                cout << "1" << " ";
            }
        }
        cout << endl;
    }

//3.Вивести ряд чисел : десять десяток, дев'ять дев'яток,
//вісім вісімок, ..., одну одиницю.
//Знайти суму всіх цих чисел.
    cout << "\nTask 3" << endl;
    int sum = 0;
    for (int i = 10; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i;
            sum += i;
            
        }
        cout << endl;
    }
    cout << "Sum of all numbers : " << sum << endl;

//4.Вивести на екран 15 рядків.У рядках з парними номерами
//вивести по 8 чисел, рівних номеру рядка.У рядках з
//непарними номерами вивести десять одиниць.
    cout << "\nTask 4" << endl;
    for (int i = 0; i <= 15; i++)
    {
      if (i%2==0)
      {
          for (int j = 0; j < i; j++)
          {
              cout << i << " ";
          }
          cout << endl;
      }
      else
      {
          for (int h = 0; h <= 10; h++)
          {
              cout << 1;
          }
          cout << endl;
      }
    }

//5. Вивести 30 рядків.Непарні рядки містять натуральні числа
//від 1 до номера поточного рядка включно з кроком 1,
//парні рядки складаються з п'яти одиниць.
    cout << "\nTask 5" << endl;
    for (int i = 0; i <= 30; i++)
    {
        if (i%2==0)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << 5;
            }
            cout << endl;
        }

        else
        {
            for (int h = 1; h < i+1; h++)
            {
                cout << h << " ";
            }
            cout <<endl;
        }
    }

    //6.Виведіть на екран таблицю множення для чисел від 1 до 10.
    cout << "\nTask 6" << endl;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            cout << j*i << " ";
        }
        cout << endl;
    }

//7.Знайдіть кількість цілих чисел від a до b включно,
//які діляться на 12.
    cout << "\nTask 7" << endl;
    int a;
    int b;
    int count =0;
    cout << "Enter range: "; cin >> a; cin >> b;
    cout << endl;
    if (a>b)
    {
        swap(a, b);
    }
    cout << "Number range: ";
    for (int i = a; i < b; i++)
    {
        cout << i << " ";
        if (i%12==0)
        {
            count++;
        }
    }
    cout << "\nNumbers that even to 12 in this range: " << count << endl;

//(масиви)
//8. Користувач вводить прибуток фірми за рік(12
//    місяців).Потім користувач вводить діапазон(наприклад,
//        3 і 6 — пошук між третім і шостим місяцем).Необхідно
//    визначити місяць, у якому прибуток був максимальним, і
//    місяць, у якому прибуток був мінімальним, з урахуванням
//    обраного діапазону.
    cout << "\nTask 8" << endl;
    int const sz = 12;
    int arr[sz]; int max;
    cout << "Enter earnings for months: ";
    for (int i = 0; i < sz; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    int c;
    int d;
    cout << "Enter range of months: "; cin >> c; cin >> d; c--; d--;
    cout << endl;
    int max1 = c; 
    int min = c;

    for (int i = c; i <= d; i++) {
        if (arr[i] > arr[max1]) {
            max1 = i;
        }
        if (arr[i] < arr[min]) {
            min = i;
        }
    }

    cout << "Max profit in " << (max1 + 1) << " month with profit " << arr[max1] << endl;
    cout << "Min profit in " << (min + 1) << " month with profit " << arr[min] << endl;

}
