#include <iostream>
using namespace std;
/*Завдання №2
Реалізуйте клас «Точка».Необхідно зберігати координати
x, y, z в змінних - членах класу.Реалізуйте функції - члени
класу для введення даних, виведення даних, реалізуйте
аксесор для доступу до змінних - членів, реалізуйте збе -
реження в файл і завантаження даних з файлу.*/
class Point
{
private:
	int x;
	int y;
	int z;
public:
	void enterCoord()
	{
		cout << "Enter x : ";
		cin >> x;
		cout << "Enter y : ";
		cin >> y;
		cout << "Enter z : ";
		cin >> z;
		
	}
	void setx(int x)
	{
		this->x = x;
	}
	void sety(int y)
	{
		this->y = y;
	}
	void setz(int z)
	{
		this->z = z;
	}
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
	int getz()
	{
		return z;
	}

	void printCoords()
	{
		cout << "x : " << x << endl;
		cout << "y : " << y << endl;
		cout << "z : " << z << endl;
	}

};



int main()
{
	Point p;
	p.enterCoord();
	p.printCoords();
	p.setx(45);
	p.sety(2);
	p.setz(24);
	p.getx();
	p.gety();
	p.getz();
	p.printCoords();
}
