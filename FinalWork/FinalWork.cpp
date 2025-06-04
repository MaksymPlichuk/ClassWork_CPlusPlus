
#include <iostream>
using namespace std;

class Units {
protected:

public:

};

class Hero :public Units {
    string name;
    int health;
    int strength;
    int endurance;
    int stamina;
public:
    Hero() : name("nn"), health(100), strength(1), endurance(100), stamina(100) {};
    Hero(string n) : name(n), health(100), strength(1), endurance(100), stamina(100) {};
    void Setname(string n) {
        name = n;
    }
    void ShowInfo() {
        cout << "==========Hero=========="<< endl;
        cout << "Name: " << name << endl;
        cout << "Strength: " << strength << endl;
        cout << "Endurance: " << endurance << endl;
        cout << "Staminame: " << stamina << endl;
    }
};

class Enemy :public Units {
protected:

public:
};

class Bigboss :public Enemy {
protected:

public:
};

class Monsters :public Enemy {
protected:

public:
};

class Animal :public Enemy {
protected:

public:
};

class Wood {
protected:

public:
};

class Deck :public Wood {
protected:

public:
};

class Bush :public Wood {
protected:

public:
};

class Tree :public Wood {
protected:

public:
};

class Treasures {

public:

};

class Diamonds {

public:

};

int main()
{
    while (true)
    {
        Hero h;
        string name;
        cout << "-------------------------Welcome to the game-------------------------" << endl;
        cout << "Enter name for the Hero: "; cin >> name; h.Setname(name);

    }
}
