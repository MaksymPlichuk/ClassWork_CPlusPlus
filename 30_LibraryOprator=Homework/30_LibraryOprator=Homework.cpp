
#include <iostream>
using namespace std;

/*Завдання 1:
Створити клас Point – точка на площині (x, y). Реалізувати набір відповідних констуркторів, метод Print() та перевантажити наступні оператори:
•	-- ++ – збільшує/зменшує кожну координату на 1 
•	> < – перевіряє точки на розташування (ближче/далі) відносно початкової координати (0:0)
•	! – змінює значення координат на протилежне
Class Point 
{
int x;
int y;
}
Завдання 2:
Наступним класом є Vector, який описується набором точок на площині. Клас містить динамічний масив точок та їх кількість. 
class Vector
{
Point * points;
int countPoint;
}
Для класу потрібно реалізувати весь необхідний набір конструкторів (копіювання та переміщення обов'язково), оператор =, деструткор, метод Add() 
для додавання нової точки та Print() для виводу інформації на екран. 
*Реалізувати вивів точок у відповідних координатах на консолі. Для цього можна використати функцію gotoxy 
! Результат завантажити у вигляді .cpp файла.
* – додаткове завдання
*/

class Point{
    int x;
    int y;
public:
    Point() : x(0), y(0) {};
    Point(int newx, int newy) : x(newx), y(newy) {};

    void Print() const{
        cout << "X: " << x << " . " << "Y: " << y << endl;
    }
    Point operator++(int a) {
        Point res(x++, y++);
        return res;
    }
    Point operator--(int a) {
        Point res(x--, y--);
            return res;
    }
    Point operator!() {
        Point res(x=-x,y= -y);
        return res;
    }

    bool operator>(const Point& other) {
       return (this->x * this->x + this->y * this->y) > (other.x * other.x + other.y * other.y);
    }
    bool operator<(const Point& other) {
       return (this->x * this->x + this->y * this->y) < (other.x * other.x + other.y * other.y);
    }
};

class Vector {
    Point* points;
    int countPoint;
public:
    Vector() : points(nullptr), countPoint(0) {};
    explicit Vector(int a) : points(nullptr), countPoint(a) {};
    Vector(const Vector& other) {
        this->points = new Point[other.countPoint];
        for (int i = 0; i < other.countPoint; i++)
        {
            this->points[i] = other.points[i];
        }
        this->countPoint = other.countPoint;
    }
    Vector(Vector&& other) {
        this->countPoint = other.countPoint;
        this->points = other.points;
        other.points = nullptr;
    }

    ~Vector(){
        if (points != nullptr) {
            delete[]points;
        }
    }

    Vector operator=(const Vector& other) {
        this->countPoint = other.countPoint;
        if (points != nullptr)
            delete[]points;
        this->points = new Point[countPoint];
        for (int i = 0; i < countPoint; i++)
        {
            this->points[i] = other.points[i];
        }
        return *this;
    }

    void Add(Point point) {
        ++countPoint;
        Point* temp = new Point[countPoint];
        for (int i = 0; i < countPoint - 1; i++)
        {
            temp[i] = points[i];
        }
        temp[countPoint - 1] = point;
        if (points != nullptr)
            delete[]points;
        points = temp;
    };

    void Print()const {
        cout << "Count Points: " << countPoint << endl;
        for (int i = 0; i < countPoint; i++) {
            points[i].Print();
        }
    };
};


int main()
{
    Point p1(4, 3);p1.Print();
    p1++; p1.Print();
    p1--; p1.Print();
    !p1; p1.Print();
    Point p2(1, -3);
    cout << (p1 > p2 ? "p1 is closer" : "p2 is closer") << endl;
    cout << (p1 < p2 ? "p2 is closer" : "p1 is closer") << endl;
    Point p3(5, 9);

    Vector v1;
    v1.Add(p1);
    v1.Add(p2);
    v1.Add(p3);
    cout << "\nVector has this points:" << endl;
    v1.Print();
    cout << "\nBefore =" << endl;
    Vector v2; v2.Print();
    cout << "\nAfter =" << endl;
    v2 = v1; v2.Print();

}
