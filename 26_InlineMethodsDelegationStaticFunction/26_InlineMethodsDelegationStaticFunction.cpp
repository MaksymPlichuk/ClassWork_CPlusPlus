#include <iostream>
using namespace std;
/*Завдання 1 :(практична робота на уроці)
Створіть додаток «Телефонна книга».Необхідно збері -
гати дані про абонента(ПІБ, домашній телефон, робочий
    телефон, мобільний телефон, додаткова інформація про
    контакт) всередині відповідного класу(Abonent).Наповніть клас
    змінними - членами, функціями - членами, конструкторами.
    Створити статичну змінну для
    кількості абонентів.Використати делегування конструкторів.
    Завдання 2:(домашня робота)
    class PhoneBook
{
    Abonent* abonents
        int countAbonent;
    void Add(Abonent a) {}
    void Delete(string phone) {}
    void SearchByName(string name) {}
    void SearchByPhone(string phone{}
        void ShowAll() {}
}
Надайте користувачеві можливість додавати нових абонентів,
видаляти абонентів,
шукати абонентів за ПІБ, показувати всіх абонентів.
*** зберігати інформацію в файл і завантажувати з файлу(записати у файл треба 1 абонента і
    зчитати з файлу треба 1 абонета).*/
struct Fullname {
    string name;
    string surname;
    string lastname;

};
class Abonent {
    Fullname fullname;
    string homephone;
    string workphone;
    string mobilephone;
    static int AbonentNum;
public:

    Abonent()
    {
        fullname.name = "no name"; 
        fullname.surname = "no surname"; 
        fullname.lastname = "no lastname";
        homephone = "no homephone";
        workphone = "no workphone";
        mobilephone = "no phone";
        AbonentNum++;
    }
    Abonent(string name, string surname, string lastname):Abonent()
    {
        this->fullname.name = name;
        this->fullname.surname = surname;
        this->fullname.lastname = lastname;
    }
    Abonent(string name, string surname, string lastname, string homephone):Abonent(name,surname,lastname)
    {
        this->homephone = homephone;
    }
    Abonent(string name, string surname, string lastname, string homephone, string workphone):Abonent(name,  surname, lastname, homephone)
    {
        this->workphone = workphone;
    }
    Abonent(string name, string surname, string lastname, string homephone, string workphone,string phone):Abonent(name,  surname, lastname, homephone, workphone)
    {
        this->mobilephone = phone;
    }

    void printAbonent()
    {
        cout << "Name :" << fullname.name << endl;
        cout <<"Surname :"<< fullname.surname << endl;
        cout <<"Lastname :"<< fullname.lastname << endl;
        cout <<"Homephone :"<< homephone << endl;
        cout <<"Workphone :"<< workphone << endl;
        cout <<"Phone :"<< mobilephone << endl;
    }
    static int getCountAbonent()
    {
        return AbonentNum;
    }
};
int Abonent::AbonentNum = 0;
int main()
{
    Abonent h1("Ivan", "Lis", "Ahmedovich", "+129856652", "+12454875", "+125656556");
    h1.printAbonent();
    cout << "Number of Abononets: "<< Abonent::getCountAbonent() << endl;
    Abonent h2("Ivan", "Lis", "Ahmedovich", "+129856652", "+125656556");
    h2.printAbonent();
    cout << "Number of Abononets: " << Abonent::getCountAbonent() << endl;
    
}
