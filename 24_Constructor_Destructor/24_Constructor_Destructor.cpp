#include <Windows.h>

#include <iostream>
using namespace std;
/*Завдання 1:
Створити клас Rectangle, який буде описувати прямокутник.Клас містить розміри : ширина, висота, символ, який відображатиме прямокутник на екрані та координати розміщення.Для збереження координат створити структуру Coord, яка міститиме X та Y координату.
Клас повинен містити наступні конструктори :
Конструктор по замовчуванню, який встановлюватиме «дефолтні» дані
Параметризований конструктор, який приймає один параметр «розмір» та ініціалізує ним ширину та висоту
Параметризований конструктор, який приймає два параметри «ширину» та «висоту», які являються розмірами об’єкта
Та наступні методи :
Вивід фігури на екран, відповідного розміру, символом та у відповідних координатах
Зміна розміру прямокутника.Метод приймає два парметри : 1 – зміна висоти, 2 – ширини
Переміщення прямокутника.Метод приймає два парметри : 1 – величина переміщення по осі X, 2 – по осі Y
Методи повинні включати перевірку на коректність даних(від’ємна ширина, координати і тд).Створити екземпляр об’єкту та протестувати написаті методи.*/
struct coords {
	int x;
	int y;
};
void SetPos(int x, int y)
{

	COORD c;
	c.X = x;
	c.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

class MyRectangle
{
private:
	int width;
	int height;
	char symb;
	coords c;
public:
	MyRectangle()
	{
		width = 0;
		height = 0;
		symb = '#';
		c.x = 0;
		c.y = 0;
	}
	MyRectangle(int size)
	{
		width = size;
		height = size;
		symb = '#';
		c.x = 0;
		c.y = 0;
	}
	MyRectangle(int width, int height)
	{
		this->width = width;
		this->height = height;
		symb = '#';
		c.x = 0;
		c.y = 0;
	}
	void print()
	{
		SetPos(c.x,c.y);
		for (int i = 0; i < width; i++)
		{

			for (int i = 0; i < height; i++)
			{

				cout << symb << " ";

			}
			cout << endl;
		}
	}
	void change(int width, int height)
	{
		
		this->width = width;
		
		this->height = height;
	}
	
};

int main()
{
	int width;
	int height;
	MyRectangle rect1;
	MyRectangle rect2(10);
	rect2.print();
	cout << endl;
	MyRectangle rect3(11, 15);
	rect3.print();
	cout << endl;
	cout << "Enter new width: "; cin >> width;
	cout << "Enter new height: "; cin >> height;
	rect3.change(width,height);
	Sleep(250);
	system("cls");
	rect3.print();
}
