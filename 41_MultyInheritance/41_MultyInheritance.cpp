
#include <iostream>
using namespace std;

/*1.Створити клас Піца з чисто віртуальним методом 

Приготувати піцу
У класу піца є два наслідники: міланська піца та грецька піца
в яких має бути реалізовано віртуальний метод 
батьківського класу

Створити клас Соус з чисто віртуальним методом 
Приготувати соус
Наслідники : міланський соус та грецький соус

Створити клас Фабрика по приготуванню піци з 
чисто віртуальними методами: 
-Приготувати піцу та 
-Приготувати  соус

Для класу Фабрика створити два наслідника :
ФабрикаМілан та ФабрикаГреція з реалізацією віртуальних
методів
class Factory
{
cout
virtual Pizza* CreatePiza()= 0;
virtual Souse* CreateSouse() = 0;
}

class MilanFactory
{
void CreatePiza()
{
return new MilanPizza();
}
void CreateSouse()
{
return new MilanSouse();
}
}
В мейні реалізувати меню для роботи з програмою
2. За бажанням доповнити клас піца та соус інградієнтами
 */

class Pizza{
public:
    virtual void CookPizza() = 0;
};
class PizzaMilano :public Pizza {
public:
    void CookPizza() override {
        cout << "Im cooking milan pizza" << endl;
    }
};
class PizzaGreek : public Pizza {
public:
    void CookPizza()override {
        cout << "Im cooking greek pizza" << endl;
    }
};
class Sauce {
public:
    virtual void CookSauce() = 0;
};
class SauceMilano : public Sauce {
public:
    void CookSauce() override {
        cout << "Im cooking milano Sauce" << endl;
    }
};
class SauceGreek : public Sauce {
public:
    void CookSauce()override {
        cout << "Im cooking greek sauce" << endl;
    }
};
class Factory {
public:
    virtual Pizza* CreatePizza() = 0;
    virtual Sauce* CreateSauce() = 0;
};
class FactoryMilano :public Factory
{
    Pizza* CreatePizza()override {
        return new PizzaMilano();
    }
    Sauce* CreateSauce()override {
        return new SauceMilano();
    }
};
class FactoryGreek :public Factory
{
    Pizza* CreatePizza()override {
        return new PizzaGreek();
    }
    Sauce* CreateSauce()override {
        return new SauceGreek();
    }
};

int main()
{
    Factory* factory = new FactoryMilano();

    Pizza* pizza = factory->CreatePizza();

    pizza->CookPizza();

    Sauce* sauce = factory->CreateSauce();

    sauce->CookSauce();

    delete factory;

    delete pizza;

    delete sauce;

    factory = new FactoryGreek();
    pizza = factory->CreatePizza();
    pizza->CookPizza();
    sauce = factory->CreateSauce();
    sauce->CookSauce();

    delete factory;
    delete pizza;
    delete sauce;

}
