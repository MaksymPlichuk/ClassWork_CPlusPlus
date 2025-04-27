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
		width = 3;
		height = 2;
		symb = '#';
		c.x = 0;
		c.y = 0;
	}
	MyRectangle(int size)
	{
		if (size<=0)
		{
			cout << "Enter right size" << endl;
			width = 1;
			height = 1;
		}
		else
		{
		width = size;
		height = size;
		}
		symb = '#';
		c.x = 0;
		c.y = 0;
	}
	MyRectangle(int width, int height)
	{
		if (width<=0)
		{
			cout << "Enter right wdith" << endl;
			this->width = 1;
		}
		else
		{
		this->width = width;
		}
		if (height<=0)
		{
			cout << "Enter right height" << endl;
			this->height = 1;
		}
		else
		{
		this->height = height;
		}
		symb = '#';
		c.x = 0;
		c.y = 0;
	}
	void print()
	{
		SetPos(c.x,c.y);
		for (int i = 0; i < width; i++)
		{
			SetPos(c.x, c.y + i);
			for (int j = 0; j < height; j++)
			{

				cout << symb << " ";

			}
			cout << endl;
		}
	}
	void change(int width, int height)
	{
		if (width <= 0)
		{
			cout << "Enter right wdith" << endl;
			this->width = 1;
		}
		else
		{
			this->width = width;
		}
		if (height <= 0)
		{
			cout << "Enter right height" << endl;
			this->height = 1;
		}
		else
		{
			this->height = height;
		}
	}
	void move(int x, int y)
	{
		if (x <= 0 && y <= 0)
		{
			cout << "Error! X or Y are <=0!";
		}
		else
		{
			c.x = x;
			c.y = y;
		}
	}
};

int main()
{
	int width;
	int height;
	MyRectangle rect1;
	rect1.print();
	Sleep(550);
	MyRectangle rect2(10);
	rect2.print();
	Sleep(550);
	MyRectangle rect3(11, 15);
	rect3.print();
	cout << endl;
	cout << "Enter new width: "; cin >> width;
	cout << "Enter new height: "; cin >> height;
	rect3.change(width,height);
	Sleep(250);
	system("cls");
	rect3.move(2, 2);
	rect3.print();
}
