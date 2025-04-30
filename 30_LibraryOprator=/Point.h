#pragma once
using namespace std;
/*Тема: Move Constructor. operator =
//Завдання 1:
//Створити клас Point – точка на площині (x, y). Реалізувати набір відповідних констуркторів, метод Print() та перевантажити наступні оператори:
//-- ++ – збільшує/зменшує кожну координату на 1
//> < – перевіряє точки на розташування (ближче/далі) відносно початкової координати (0:0)
//! – змінює значення координат на протилежне
//Class Point
//{
//int x;
//int y;
//}*/
class Point
{
	int x;
	int y;
public:
	Point() :x(0), y(0) {}
	Point(int x, int y) :x(x), y(y) {}
	
	void print()const;
	Point operator--();
	Point operator++();
	Point operator>();
	Point operator<();
	
};

