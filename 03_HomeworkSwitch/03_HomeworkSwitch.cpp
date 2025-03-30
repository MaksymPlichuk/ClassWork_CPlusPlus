// 03_HomeworkSwitch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
/*1.Дано сторони прямокутника. Визначити чи прямокутник є квадратом.
2.Дано вік дитини. Виначити чи дитина по віку може навчатися у школі, чи може відвідувати дитсадок і т.і.*/ 

int main()
{
    cout << "Task 1" << endl;
    int firstside;
    int secondside;
    cout << "Enter first side of rectangle: "; cin >> firstside;
    cout << endl;
    cout << "Enter second side of rectangle: "; cin >> secondside;
    if (firstside == secondside)
    {
        cout << "Rectangle is Square" << endl;
    }
    else {
        cout << "Rectangle is not Square" << endl;
    }

    cout << "Task 2" << endl;
    int age;
    cout << "Enter age: "; cin >> age;
    cout << endl;
    if(age<=1) {
        cout << "Child can't study at kindergarden" << endl;
    }
    else if(age<=6) {
        cout << "Child can study at kindergarden" << endl;
    }
    else if (age<=18)
    {
        cout << "Child can study at school" << endl;
    }
    else {
        cout << "Child is can't study at school nor kindergarden" << endl;
    }

    /*3.Дано 3 числа.Визначити чи рівно два серед них від’ємні.
    4.Дано число.Визначити чи належить воно відрізку[2, 5] або[-1, 1].*/
    cout << "Task 3" << endl;
    int num1;  cout << "Enter first number: "; cin >> num1;
    int num2;  cout << "Enter second number: "; cin >> num2;
    int num3;  cout << "Enter Third number: "; cin >> num3;
    if ((num1 < 0 && num2>0 && num3>0) || (num2 < 0 && num1>0 && num3 > 0) || (num3 < 0 && num2>0 && num1 > 0))
    {
        cout << "Only one number is <0" << endl;
    }
    else if ((num1 < 0 && num2 < 0) || (num2 < 0 && num3 < 0) || (num3 < 0 && num1 < 0))
    {
        cout << "Two number are <0" << endl;
    }
    else
    {
        cout << "All numbers are >0" << endl;
    }
    
    cout << "Task 4" << endl;
    int num;  cout << "Enter number: "; cin >> num;
    if (num >= -1 && num <= 1)
    {
        cout << "Number is at [-1, 1]" << endl;
    }
    else if (num >= 2 && num <= 5)
    {
        cout << "Number is at [2, 5]" << endl;
    }
    else
    {
        cout << "Number is not at [2, 5] or [-1, 1]" << endl;
    }

    /*5.Дано три числа.Визначити чи тільки два з них рівні між собою.*/
    cout << "Task 5" << endl;
    int n1;  cout << "Enter first number: "; cin >> n1;
    int n2;  cout << "Enter first number: "; cin >> n2;
    int n3;  cout << "Enter first number: "; cin >> n3;
    if ((n1 == n2) && (n2 == n3) && (n1 == n3))
    {
        cout << "All numbers equal" << endl;
    }
    else if ((n1 == n2) || (n2 == n3) || (n1 == n3))
    {
        cout << "2 numbers are equal" << endl;
    }
    else
    {
        cout << "Number aren't equal" << endl;
    }
    /*6.Дано 3 числа.Визначити чи всі числа непарні.Числа вводяться з клавіатури*/
    cout << "Task 6" << endl;
    int a1;  cout << "Enter first number: "; cin >> a1;
    int a2;  cout << "Enter first number: "; cin >> a2;
    int a3;  cout << "Enter first number: "; cin >> a3;
    if ((a1 % 2 != 0) && (a2 % 2 != 0) && (a3 % 2 != 0))
    {
        cout << "All numbers are odd" << endl;
    }
    else if ((a1 % 2 != 0 && a2 % 2 != 0) || (a1 % 2 != 0 &&a3 % 2 != 0)|| (a2 % 2 != 0 && a3 % 2 != 0))
    {
        cout << "2 are odd" << endl;
    }
    else if (a1%2==0 && a2%2==0 && a3%2==0)
    {
        cout << "Numbers are equal" << endl;
    }
    else
    {
        cout << "1 number is odd" << endl;
    }
    
cout << "DODATKOVI ZAVDANNYA\n" << endl;
    /*додаткові :
        7.Дано два числа.Якщо вони різні, то поміняти іх місцями. */
    cout << "Task 7" << endl;
    int b1;  cout << "Enter first number: "; cin >> b1;
    int b2;  cout << "Enter first number: "; cin >> b2;
    if (b1 == b2)
    {
        cout << "Numbers are equal" << endl;
    }
    else
    {
        swap(b1, b2);
        cout << "First number :" << b1 <<endl;
        cout << "Second number :" << b2 <<endl;
    }
    /*8.Дано натуральне число а(а > 100 && a < 999).Напишіть програму, що визначає кількість цифр в цьому числі, суму його цифр, 
    і яка виводить на екран першу и останню цифру через два пропуски.
    777 = 3 числа, сума, сума = 21*/
    cout << "Task 8" << endl;
    int number;
    cout << "Enter number(number > 100 && number < 999): "; cin >> number;
    int firstNum = number / 100;
    int secondNum = (number / 10) % 10;
    int lastNum = number % 10;
    int numSum = firstNum + secondNum + lastNum;

    cout << number << " = 3 Numbers;" << " " << "Numbers sum = " << numSum << "; " << "First number : " << firstNum << "  " << "Second number : " << secondNum << endl;

    /*9.Дано час(години, хвилини, секунди).Визначити чи час допустимий(наприклад, 25.61.60 – недопустимий).*/
    cout << "Task 9" << endl;
    int hours; 
    cout << "Enter Hours: "; cin >> hours;
    int minutes; 
    cout << "Enter Minutes: "; cin >> minutes;
    int seconds; 
    cout << "Enter Seconds: "; cin >> seconds;
    
    if ((hours >= 0 && hours <= 23)&&(minutes >= 0 && minutes < 60)&&(seconds >= 0 && seconds < 60))
    {
        cout << "Time is posible: " << hours << "." << minutes << "." << seconds << endl;
    }
    else
    {
        cout << "Wrong Time" << endl;
    }

    /*10.Написати програму яка в залежності від введеної години виводить : good night, good day, good evening, good morning.*/
    cout << "Task 10" << endl;
    int time1;
    cout << "Enter hour of the day: "; cin >> time1;
    if (time1 >= 5 && time1 < 12)
    {
        cout << "Good morning!" << endl;
    }
    else if (time1 >= 12 && time1 < 18)
    {
        cout << "Good day!" << endl;
    }
    else if (time1 >= 18 && time1 < 23)
    {
        cout << "Good evening!" << endl;
    }
    else if (time1 >= 23 || time1 < 5)
    {
        cout << "Good night!" << endl;
    }
    else
    {
        cout << "Wrong time!" << endl;
    }
    
    
    /*11.Написати програму, яка обчислює та виводить мінімум з трьох введених користувачем чисел*/
    cout << "Task 11" << endl;
    int d1;
    cout << "Enter First number: "; cin >> d1;
    int d2;
    cout << "Enter Second number: "; cin >> d2;
    int d3;
    cout << "Enter Third number: "; cin >> d3;
    int min = d1;
    if (d2 < min)
    {
        min = d2;
    }
    if (d3 < min)
    {
        min = d3;
    }
    cout << "Mininimum of 3 numbers: " << min << endl;





}
