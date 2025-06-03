
#include <iostream>
using namespace std;

/*Завдання 1:

Створіть клас Shape який містить загальні параметри
будь-якої фігури (ім,я, тип і тд). Визначте віртуальні методи:
•Show – вивід на екран інформації про фігуру; 
•Show = 0
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
protected:
	string name;
	string type;
public:
	Shape() : name("no name"), type("no type") {}
	Shape(string n, string t) : name(n), type(t) {}
	virtual void Show()const = 0;
	virtual double GetArea()const = 0;
};

class Rectangle : public Shape {
	double a, b;
public:
	Rectangle(string n, string t, int a, int b) :Shape(n, t), a(a), b(b) {};

	void Show() const override {
		cout << "Shape: " << name << endl;
		cout << "Type: " << type << endl;
		cout << "Side a = " << a << ", Side b = " << b << endl;
	}
	double GetArea() const override {
		return a * b;
	}
};

class Circle : public Shape {
	double radius;
public:
	Circle(string n, string t, int r) :Shape(n, t), radius(r) {};
	void Show() const override {
		cout << "Shape: " << name << endl;
		cout << "Type: " << type << endl;
		cout << "Radius = " <<radius<< endl;
	}
	double GetArea() const override {
		return 3.14 * radius * radius;
	}
};

class RightTriangle : public Shape {
	double a, b;
public:
	RightTriangle(string n, string t, double a, double b) :Shape(n, t), a(a), b(b) {};
	void Show() const override {
		cout << "Shape: " << name << endl;
		cout << "Type: " << type << endl;
		cout << "Side a = " << a << ", Side b = " << b << endl;
	}
	double GetArea() const override {
		return 0.5 * a * b;
	}
};

class Triangle :public Shape {
	double a, b, c;
public:
	Triangle(string n, string t, double a, double b, double c) :Shape(n, t), a(a), b(b), c(c) {};
	void Show() const override {
		cout << "Shape: " << name << endl;
		cout << "Type: " << type << endl;
		cout << "Side a = " << a << ", Side b = " << b << ", Side c = " << c << endl;
	}
	double GetArea() const override {
		double s = (a + b + c) / 2;
		return sqrt(s * (s - a) * (s - b) * (s - c));
	}
};

class Trapezoid :public Shape {
	double a, b, h;
public:
	Trapezoid(string n, string t, double a, double b, double h) :Shape(n, t), a(a), b(b), h(h) {};
	void Show() const override {
		cout << "Shape: " << name << endl;
		cout << "Type: " << type << endl;
		cout << "Side a = " << a << ", Side b = " << b << ", Height = " << h << endl;
	}
	double GetArea() const override {
		return (a + b) * 0.5 * h;
	}
};

void TestShape(const Shape& other) {
	other.Show();
	cout << "Area = " << other.GetArea() << endl;
	cout << "=====================" << endl;
}

int main()
{
	Rectangle r("Rectangle", "Quadrangle", 2, 6);
	Circle c("Circle", "Round", 5);
	RightTriangle rt("Right Triangle", "Triangle", 4, 5);
	Triangle t("Triangle", "Triangle", 3, 4, 5);
	Trapezoid tr("Trapezoid", "Quadrangle", 6, 8, 2);

	TestShape(r);
	TestShape(c);
	TestShape(rt);
	TestShape(t);
	TestShape(tr);
}
