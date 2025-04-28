
#include <iostream>
using namespace std;

/*Завдання 1:
Створити клас Airplane (літак), який буде мати наступні характеристики:
• Модель
• Тип
• Кількість пасажирів
• Максимальна кількість пасажирів
За допомогою перевантаження операторів реалізувати:
1. Перевірку на рівність типів літаків (операція ==) friend
2. Збільшення і зменшення пасажирів в салоні літака (операції ++ та -- 
в префіксній формі)
3. Порівняння двох літаків по максимально можливій кількості пасажирів 
на борту (операція >) friend
4. Збільшити кількість пасажирів на певне значення (оператор (15))
Перевантаження логічних операцій виконати за допомогою дружніх функцій.
При виконанні операцій, потрібно перевіряти чи не перебільшено максимальну 
кількість пасажирів.
! Результат завантажити у вигляді .cpp файла.*/

class Airplane
{
    string model;
    string type;
    int passangernum;
    int maxpass;
public:
    Airplane()
    {
        model = "no model";
        type = "no type";
        passangernum = 0;
        maxpass = 0;
    }
    Airplane(string model,string type, int passangernum, int maxpass)
    {
        this->model=model;
        this->type=type;
        this->passangernum=passangernum ;
        this->maxpass=maxpass;
    }

};

Airplane::Airplane()
{
}

Airplane::~Airplane()
{
}

int main()
{
    std::cout << "Hello World!\n";
}
