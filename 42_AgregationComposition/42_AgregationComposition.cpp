
#include <iostream>
using namespace std;

/*Завдання 1:

Розробити клас Car з набором необхідних параметрів та складових (двигун, кузов, колеса, двері, коробка передач, фари і тд.)
Кожна складова описується окремим класом та міститься як композиція в класі Car.
Набір необхідних характеристик та методів описати на ваш розсуд.
 */

class Car {

};
class Body {
    string bodyType;
public:
	Body():bodyType("no type"){}//hetchback universal sedan
    Body(string bt):bodyType(bt){}
    void showBody() {
        cout << "Car type: " << bodyType << endl;
    }
};
class Wheel {
    string wheelType;
    int diametr;
public:
    Wheel(): wheelType("no type"), diametr(0){}
    Wheel(string w, int d) : wheelType(w), diametr(d) {}
    void showWheels() {
        cout << "Wheel type: " << wheelType << endl;
        cout << "Diameter: " << diametr << endl;
    }
};
class Engine {
    int horsePower;
public:
    Engine() :horsePower(0) {};
    Engine(int h) :horsePower(h) {};
    void showEngine()
    {
        cout << "Horsepower: " << horsePower << endl;
    }
};
class Door {
    string color;
    string openType;
public:
    Door() :color("no color"), openType("basic") {};
    Door(string c,string ot) :color(c), openType(ot) {};
    void showDoor()
    {
        cout << "Doors color: " << color << endl;
        cout << "Doors open type: " << openType << endl;
    }
};
class Headlight {
    string lightColor;
public:
    Headlight() :lightColor("no color") {};
    Headlight(string l) :lightColor(l) {};
    void showLight()
    {
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
    void showDriver()
    {
        cout << "Driver name: " << name << endl;
        cout << "Driver lastname: " << lastname << endl;
        cout << "Driver surname: " << surname << endl;
        cout << "Driver age: " << age << endl;
        cout << "Driver experience: " << experience << endl;
    }
};
int main()
{
    std::cout << "Hello World!\n";
}
