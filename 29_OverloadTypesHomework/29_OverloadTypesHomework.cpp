
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
    Airplane() : model("no model"), type("no type"), passangernum(0), maxpass(0) {};
    Airplane(string m, string t, int ps, int mp) : model(m), type(t), passangernum(ps), maxpass(mp) {};

    friend bool operator==(const Airplane& a1, const Airplane& a2);
    friend bool operator>(const Airplane& a1, const Airplane& a2);

    Airplane operator++(int a) {
        if (passangernum < maxpass)
            passangernum++;
        return *this;
    }
    Airplane operator--(int a) {
        if (passangernum > 0)
            passangernum--;
        return *this;
    }

    void operator()(int value){
        passangernum += value;
        if (passangernum > maxpass)
            passangernum = maxpass;
        if (passangernum < 0)
            passangernum = 0;
    }

    void ShowAirplane() const
    {
        cout << "\nModel: " << model << endl;
        cout << "Type: " << type << endl;
        cout << "Passengers: " << passangernum << "/" << maxpass << endl;
    }
};
bool operator==(const Airplane& a1, const Airplane& a2){
    return a1.type == a2.type;
}

bool operator>(const Airplane& a1, const Airplane& a2){
    return a1.passangernum > a2.passangernum;
}

int main()
{
    Airplane a1{ "Boeing 737", "Boeing", 170, 230 }; 
    Airplane a2{ "Boeing 777", "Boeing", 476, 550 };
    cout << "Before flight:";
    a1.ShowAirplane();
    a2.ShowAirplane();
    cout << "\nAfter flight:";
    a1++; a1.ShowAirplane();
    a2--; a2.ShowAirplane();
    cout << "\nAdded 29 passangers to a1" << endl;
    a1(29); a1.ShowAirplane();
    cout << "\nDoes a1 & a2 have same types?" << endl;
    cout << (a1 == a2 ? "Same type" : "Different types") << endl;
    cout << "Who has more passangers on board?" << endl;
    cout << (a1 > a2 ? "a1" : "a2") << endl;
}
