
#include <iostream>
#include <Windows.h>
using namespace std;

/*Тема: Virtual Destructor
Завдання 1:
Створити абстрактний клас Shape (фігура). Яка містить тип та чисто віртуальний метод Print(), для показу фігури на консоль. 
Реалізувати похідні класи:

Line – містить координати початку та кінця (дві точки)
Rectangle – містить координати верхнього лівого кута, ширину та довжину
Polyline – містить масив точок
 
Всі похідні класи повинні перевизначати метод Print(), друкуючи фігуру на консолі враховуючи її параметри. Додати деструктор  в класи, які його потребують.
Для зручності можна створити структуру struct Point { int x, y };  та скористатися методом gotoxy().
*Додати метод Save() для запису фігури в файл.
 */
void SetPos(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
struct Point
{
    int x;
    int y;
};
class Shape {
 
public:
    virtual void Print() const = 0;

};

class Line: public Shape {
    Point start;
    Point end;
public:
    Line()
    {

    }
    void Print() const override {
        SetPos(start.x, start.y);
        cout << "*";
        SetPos(end.x, end.y);
        cout << "*";
    }

};

class Rectangle: public Shape{
    int width;
    int height;
    Point start;
public:
    void Print() const override {
        SetPos(start.x, start.y);
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
     }
    Rectangle()
    {

    }

};

class Polyline {
    Point start;
    int size;
};

int main()
{
    Line l;
    l
}
