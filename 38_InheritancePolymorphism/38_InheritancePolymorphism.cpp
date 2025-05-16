
#include <iostream>
using namespace std;

/*Завдання 1:

Створіть клас Shape який містить загальні параметри 
будь-якої фігури (ім,я, тип і тд). Визначте віртуальні методи:
•Show – вивід на екран інформації про фігуру; •Show = 0
•GetArea – обчислення площі фігури; (•GetArea = 0)
Визначте похідні класи: прямокутник, коло, прямокутний трикутник,трикутник,

трапеція зі своїми функціями площі. – кожний з яких буде 
містити притаманні даній фігурі характеристики та перевизначати (override) 
алгоритми методів базового класу Shape. 
Також створити функцію TestShape, яка приймає фігуру та відображає її 
інформацію включаючи площу.
В main протестувати роботу, передавши в функцію різні фігури.
 */

class Shape {
	string name;
	string type;
public:
	void Show()
	{
		cout << "Shape name: " << name << endl;
		cout << "Shape: " << type << endl;
	}
	void GetArea()
	{
		cout << "NO area" << endl;
	}
};
class Rectangle: public Shape {
	int a;
	int b;
public:
	void Show()
	{
		
	}
};


int main()
{
   
}
