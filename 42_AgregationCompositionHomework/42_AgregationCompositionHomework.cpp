
#include <iostream>
using namespace std;

/*Завдання 1:
Розробити клас Car з набором необхідних параметрів та складових (двигун, кузов, колеса, двері, коробка передач, фари і тд.)
Кожна складова описується окремим класом та міститься як композиція в класі Car.
Набір необхідних характеристик та методів описати на ваш розсуд.
Завдання 2:
До попереднього завдання (створення класу Car з використанням композиції) додати агрегацію об'єкта:
Об'єктом буде клас Driver, який матиме наступні характеристики:
-	ім'я
-	прізвище
-	вік
-	стаж керування ТЗ (транспортний засіб)
Конструктор(и)
Методи:
-	Показ інформації про водія
Клас Car повинен мати можливість додавати собі водія методом агрегації, іншими словами, агрегувати водія.
В класі Car буде міститися вказівник на клас Driver та можливість додати його двома способами:
1.	Через параметр конструктора, разом зі всіма іншими даними авто (написати ще один перевантажений конструктор)
2.	Викликавши метод AddDriver та передавши адресу водія
Метод Show для авто повинен також виводити інформацію про водія, якщо він відсутній – відповідне повідомлення.

 */

class Body {
    string bodyType;
public:
    Body() :bodyType("no type") {}//hetchback universal sedan
    Body(string bt) :bodyType(bt) {}

    void showBody() const {
        cout << "Car type: " << bodyType << endl;
    }
};
class Wheel {
    string wheelType;
    int diametr;
public:
    Wheel() : wheelType("no type"), diametr(0) {}
    Wheel(string w, int d) : wheelType(w), diametr(d) {}

    void showWheels() const {
        cout << "Wheel type: " << wheelType << endl;
        cout << "Diameter: " << diametr << endl;
    }
};
class Engine {
    int horsePower;
public:
    Engine() :horsePower(0) {};
    Engine(int h) :horsePower(h) {};

    void showEngine() const {
        cout << "Horsepower: " << horsePower << endl;
    }
};
class Door {
    string color;
    string openType;
public:
    Door() :color("no color"), openType("basic") {};
    Door(string c, string ot) :color(c), openType(ot) {};

    void showDoor() const {
        cout << "Doors color: " << color << endl;
        cout << "Doors open type: " << openType << endl;
    }
};
class Headlight {
    string lightColor;
public:
    Headlight() :lightColor("no color") {};
    Headlight(string l) :lightColor(l) {};
    void showLight() const {
        cout << "Headlight color: " << lightColor << endl;
    }
};
class Driver {
    string name;
    string lastname;
    string surname;
    int age;
    int experience;
public:
    Driver() : name("no name"), lastname("no name"), surname("no name"), age(0), experience(0) {};
    Driver(string n, string ls, string sn, int ag, int exp) : name(n), lastname(ls), surname(sn), age(ag), experience(exp) {};
    void showDriver() const {
        cout << "-- Driver --" << endl;
        cout << "Driver name: " << name << endl;
        cout << "Driver lastname: " << lastname << endl;
        cout << "Driver surname: " << surname << endl;
        cout << "Driver age: " << age << endl;
        cout << "Driver experience: " << experience << endl;
    }
};

class Car {
    Engine engine;
    Body body;
    Wheel* wheels;
    int countWheels;
    Door* doors;
    int countDoors;
    Headlight* headlights;
    int countHeadlights;
    Driver* driver;

    string name;
public:
    Car(Engine e, Body b, Wheel* w, int cw, Door* d, int cd, Headlight* h, int ch, string n) :
        engine(e), body(b), countWheels(cw), countDoors(cd), countHeadlights(ch), driver(nullptr), name(n) {

        wheels = new Wheel[countWheels];
        for (int i = 0; i < countWheels; i++) {
            wheels[i] = w[i];
        }

        doors = new Door[countDoors];
        for (int i = 0; i < countDoors; i++) {
            doors[i] = d[i];
        }

        headlights = new Headlight[countHeadlights];
        for (int i = 0; i < countHeadlights; i++) {
            headlights[i] = h[i];
        }
    };

    Car(Engine e, Body b, Wheel* w, int cw, Door* d, int cd, Headlight* h, int ch, Driver* dr, string n)
        : Car(e, b, w, cw, d, cd, h, ch, n) {
        driver = dr;
    }
    void AddDriver(Driver* dr) {
        driver = dr;
    }
    void showModel()const {
        cout << "Model: " << name << endl;
    }
    void Show() const {
        cout << "===== Car Info =====\n";
        showModel();
        engine.showEngine();
        body.showBody();

        cout << "-- Wheels --\n";
        for (int i = 0; i < countWheels; i++)
            wheels[i].showWheels();

        cout << "-- Doors --\n";
        for (int i = 0; i < countDoors; i++)
            doors[i].showDoor();

        cout << "-- Headlights --\n";
        for (int i = 0; i < countHeadlights; i++)
            headlights[i].showLight();

        if (driver)
            driver->showDriver();
        else
            cout << "-- No driver assigned to this car --\n";
    }

    ~Car() {
        delete[] wheels;
        delete[] doors;
        delete[] headlights;

    }
};

int main()
{
    Driver dr("Rayan", "Gosling", "Constantionovich", 44, 26);
    Engine e(617);
    Body b("Sedan");

    Wheel wheels[4] = { Wheel("Dollar",21), Wheel("Dollar",21), Wheel("Dollar",21), Wheel("Dollar",21) };
    Door doors[4] = { Door("Black", "To the side"), Door("Black", "To the side"), Door("Black", "To the side"), Door("Black", "To the side") };
    Headlight headlights[2] = { Headlight("Blue"), Headlight("Blue") };

    Car c(e, b, wheels, 4, doors, 4, headlights, 2, "BMW M5 competition");
    c.showModel();
    c.Show();
    cout << "------------------------------Adding driver------------------------------" << endl;
    c.AddDriver(&dr);
    c.Show();
}