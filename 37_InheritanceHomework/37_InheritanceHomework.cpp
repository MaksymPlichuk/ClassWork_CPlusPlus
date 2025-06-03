#include <iostream>
using namespace std;

/*Завдання 1:
Створити базовий клас «Animal», який буде описувати тварину. 
Цей клас буде містити загальні характеристики, які притаманні 
кожній тварині:
•вид
•швидкість
•вага
•середовище мешкання
•і тд…
А також методи:
• Move – метод руху
• Show – вивід інформації на екран
• Say – подача звуку
• і тд…	
Створити похідні класи: Bird, Reptile, Fish.
Ці класи будуть наслідувати базовий клас Animal, додаючи до 
нього певні характкристики та методи, які притаманні кожному об’єкту.
Для кожного з видів створити хоча б по одному класу, який 
буде описувати конкретну тварину-представника. 
Ці класи повинні наслідувати характерний для них базовий клас 
(Bird, Reptile, Fish) та ініціалізувати їхні характеристики 
відповідно до тварини-представника.*/

class Animal {
protected:
    string type;
    int speed;
    int weight;
    string habitat;
public:
    Animal() : type("no type"), speed(0), weight(0), habitat("no habitat") {};
    Animal(string t, int s ,int w, string h) : type(t), speed(s), weight(w), habitat(h) {};

    void Move() {
        cout << type << " moves at speed " << speed << " km/h." << endl;
    };
    void Show() {
        cout << "Type: " << type << endl;
        cout << "Speed: " << speed << " km/h" << endl;
        cout << "Weight: " << weight << " kilograms" << endl;
        cout << "Habitat: " << habitat << endl;
    };
    virtual void Say() {
        cout << type << " makes a sound:" << endl;
    };
};

class Bird : public Animal {
protected:
    int wingspan;
public:
    Bird() : Animal(), wingspan(0) {};
    Bird(string t, int s, int w, string h, int ws) : Animal(t, s, w, h), wingspan(ws) {};

    void Show() {
        Animal::Show();
        cout << "Wingspan: " << wingspan << " meters" << endl;
    }
};

class Crow : public Bird {
public:
    Crow() : Bird("Crow", 50, 2, "Urban", 1) {};
    void Say() override{
        cout << type << " makes a sound: kar-kar-kar" << endl;
    };
};

class Reptile : public Animal {
protected: 
    int taillength;
public:
    Reptile() : taillength(0) {};
    Reptile(string t, int s, int w, string h, int ts) :Animal(t, s, w, h), taillength(ts) {};

    void Show() {
        Animal::Show();
        cout << "Tail lenght: " << taillength << " cm" << endl;
    }
};

class Salamandra : public Reptile {
public:
    Salamandra() : Reptile("Salamandra", 1, 1, "Moist", 1) {};
    void Say() override {
        cout << type << " makes a sound: tsssssssssssss" << endl;
    };
};

class Fish :public Animal {
protected:
    int lenght;
public:
    Fish() : lenght(0) {};
    Fish(string t, int s, int w, string h, int l) : Animal(t, s, w, h), lenght(l) {};
    
    void Show() {
        Animal::Show();
        cout << "Lenght: " << lenght << " meters" << endl;
    }
};

class Catfish :public Fish {
public:
    Catfish() : Fish("Catfish", 1, 2, "Rivers", 2) {};
    void Say() override {
        cout << type << " makes a sound: p-p-p" << endl;
    };
};

int main()
{
    Crow cr;
    Salamandra sa;
    Catfish ct;

    cout << "=== Crow ===" << endl;
    cr.Show();
    cr.Move();
    cr.Say();

    cout << "\n=== Salamandra ===" << endl;
    sa.Show();
    sa.Move();
    sa.Say();

    cout << "\n=== Catfish ===" << endl;
    ct.Show();
    ct.Move();
    ct.Say();
    cout << endl;
}
