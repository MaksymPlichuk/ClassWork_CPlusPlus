
#include <iostream>
using namespace std;

/*
_________________________________________________________________________________________
Завдання 2.
Необхідно створити структуру Fraction, яка описує звичайний дріб у форматі numerator / denominator, де:
numerator — чисельник(ціле число),
denominator — знаменник(ціле число, не рівне нулю).

Структура повинна підтримувати основні арифметичні операції :
Додавання двох дробів
Fraction add(const Fraction& one, const Fraction& two) {
	Fraction result;
	result.numerator = one.numerator * two.denominator + one.denominator * two.numerator;
	result.denominator = one.denominator * two.denominator;
	return result;
}
Віднімання
Множення
Ділення

Програма повинна дозволяти користувачеві вводити два дроби та вибирати операцію, яку слід виконати.
Після виконання операції вивести відповідь у стандартному форматі numerator / denominator.
Приклади роботи програми
Вхід :
Введіть перший дріб : 3 4
Введіть другий дріб : 2 5
Оберіть операцію(+, -, *, / ) : *
Результат : 6 / 20


Додаткове завдання.
Реалізуйте додатковий функціонал для покращення роботи з дробами :
Скорочення дробу(наприклад, 8 / 12 → 2 / 3).
Виведення неправильного дробу у виглді змішаного дробу(наприклад, 7 / 3 → 2(1 / 3)).

_________________________________________________________________________________________

Завдання 3.
Розробіть програму, яка моделює роботу магазину, використовуючи структури.
Створіть структуру Product, що містить наступні дані про товар :
name(назва товару)
category(категорія товару, наприклад: "Молочні продукти", "Хлібобулочні вироби", "Овочі")
price(ціна товару)

Також створіть масив, що зберігатиме товари в магазині.
Програма повинна дозволяти виконувати наступні операції :
Додавання нового товару
Виведення всіх товарів
Виведення товарів за вказаною категорією
Виведення всіх товарів, дешевших за вказану ціну
Видалення товару за номером(або індексом)

https ://github.com/Tetyana-K/PD-411-Step-15-

https ://github.com/Tetyana-K/PD-411-Step-15-/tree/master/structts*/

/*Завдання 1.
Реалізувати структуру «Бойлер»(фірма, колір, потужність, обсяг, температура нагріву).
Створіть екземпляр структури і проілюструйте роботу з ним.
Визначити функції
введення з  клавіатури даних  для бойлера
виведення на екран даних бойлера
збільшення температури бойлера з  перевіркою на  коректність
зменшення температури бойлера з  перевіркою на коректність
порівняння двох бойлерів за  потужністю.
Перевірити роботу функцій.*/
const int SIZE = 255;
int temp;
struct Boiler 
{
	char firm[SIZE] = "Bosh";
	char color[SIZE]="Black";
	int power=50;
	int volume=20;
	int temperature=60;
}; Boiler b1;Boiler b2;

void inputBoiler(Boiler& b)
{
	cout << "\nEnter Boiler firm : "; cin >> b.firm; cout << endl;
	cout << "\nEnter Boiler color : "; cin >> b.color; cout << endl;
	cout << "\nEnter Boiler power : "; cin >> b.power; cout << endl;
	cout << "\nEnter Boiler volume : "; cin >> b.volume; cout << endl;
	cout << "\nEnter Boiler temperature : "; cin >> b.temperature; cout << endl;
}
void printBoiler(const Boiler& b)
{
	cout << "\nEnter Boiler firm : "; cout<< b.firm; cout << endl;
	cout << "\nEnter Boiler color : "; cout << b.color; cout << endl;
	cout << "\nEnter Boiler power : "; cout << b.power; cout << endl;
	cout << "\nEnter Boiler volume : "; cout << b.volume; cout << endl;
	cout << "\nEnter Boiler temperature : "; cout << b.temperature; cout << endl;
}

void tempIncrease(Boiler& b)
{
	cout << "\nEnter how much Boiler temperature to add : "; 
	do
	{
		cin >> temp;
		if (temp>=5 && temp<=80)
		{
			b.temperature += temp;
			break;
		}
		else
		{
			cout << "Enter right temperature";
		}
	} while (true);

}
void tempDecrease(Boiler& b)
{
	cout << "\nEnter how much Boiler temperature to decrease : "; 
	do
	{
		cin >> temp;
		if (temp>=5 && temp<=80)
		{
			b.temperature -= temp;
			break;
		}
		else
		{
			cout << "Enter right temperature";
		}
	} while (true);

}

void compBoilers(const Boiler& b1, const Boiler& b2)
{
	if (b1.power > b2.power)
	{
		cout << "First Boiler power is bigger" << endl;
	}
	else
	{
		cout << "Second Boiler power is bigger" << endl;
	}
}

int main()
{
	inputBoiler(b1);
	printBoiler(b1);
	inputBoiler(b2);
	printBoiler(b2);
	tempIncrease(b1);
	tempDecrease(b2);
	compBoilers(b1, b2);
}
