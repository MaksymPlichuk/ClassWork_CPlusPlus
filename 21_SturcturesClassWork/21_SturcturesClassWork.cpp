#include <iostream>
using namespace std;
/*Створити структуру, що описує прямокутник.Написати функції для роботи з цією структурою : 
введення  прямокутника(сторін прямокутника), зміна розміру прямокутника(дві функції, одна змінює ширину, 
інша висоту), друк прямокутника(вивести інформацію про сторони прямокутника).Також написати функції, які повертають плошу та периметр прямокутника
** Валідація : сторони прямокутника повинні бути додатними числами

*/

struct rectangle
{
	int height = 4;
	int width = 2;

}; rectangle rec;

void printRec(const rectangle& rec)
{
	cout << "Rectangle heidght " << rec.height << endl;
	cout << "Rectangle width " << rec.width << endl;
}
void inputRec( rectangle& rec)
{
	cout << endl;
	while (true)
	{
		cout << "Enter height : "; cin >> rec.height; cout << endl;
		cout << "Enter width : "; cin >> rec.width;
		if (rec.height <= 0 || rec.width <= 0)
		{
			cout << "All values must be > 0. Try again!" << endl;
			continue;
		}
		else if (rec.height > 0 && rec.width > 0)
		{
			break;
		}
	}
	
}
void recArea(const rectangle& rec)
{
	int area = rec.height * rec.width;
	cout << "Area of rectangle: " << area << endl;
}
void recPer(const rectangle& rec)
{
	int area = (rec.height + rec.width)*2;
	cout << "Area of rectangle: " << area << endl;
}

/*Завдання 2
Створіть структуру, що описує точку в двовимірній системі координат(x, y).За допомогою цієї структури задайте 
дві точки.Напишіть функцію, яка обчислює відстань між цими двома точками.*/
struct Dot
{
	int x = 0;
	int y = 0;
}; Dot dot1,dot2;

void showCor(Dot& dot)
{
	cout << "Coords " <<" x= " << dot.x << " y= " << dot.y << endl;
}

void changeCor(Dot& dot)
{
	cout << "Enter x "; cin >> dot.x;cout << endl;
	cout << "Enter y "; cin >> dot.y;cout << endl;

}

void dotDist(Dot& dot1, Dot& dot2)
{
	int distance = sqrt(pow(dot2.x - dot1.x, 2) + pow(dot2.y - dot1.y, 2));
	cout << "Distance between dots : " << distance;
}

/*Завдання 3
Створіть структуру, що описує простий дріб.Реалізуйте арифметичні операції з дробами : суму, різницю, множення, ділення.
Врахувати можливість скорочення дробів і переведення з неправильного дробу в простий.*/
struct fractions
{
	int numerator = 1;
	int denumerator = 2;

}; fractions n1;

int main()
{
	cout << "Task 1" << endl;
	printRec(rec);
	inputRec(rec);
	recArea(rec);
	recPer(rec);
	cout << "Task 2" << endl;
	changeCor(dot1);
	cout << "Coords for dot 1" << endl;
	showCor(dot1);
	changeCor(dot2);
	cout << "Coords for dot 2" << endl;
	showCor(dot2);
	dotDist(dot1, dot2);
	cout << "Task 3" << endl;
	//to to do






}
