
#include <iostream>
using namespace std;

/*Завдання 1 :(практична робота на уроці)
Створіть додаток «Телефонна книга». Необхідно збері-
гати дані про абонента (ПІБ, домашній телефон, робочий
телефон, мобільний телефон, додаткова інформація про
контакт) всередині відповідного класу(Abonent). Наповніть клас
змінними-членами, функціями-членами, конструкторами.
Створити статичну змінну для
кількості абонентів. Використати делегування конструкторів.
Завдання 2:(домашня робота)
class PhoneBook
{
Abonent * abonents
int countAbonent ;
void Add(Abonent a){}
void Delete(string phone){}
void SearchByName(string name){}
void SearchByPhone(string phone{}
void ShowAll(){}
}
Надайте користувачеві можливість додавати нових абонентів, 
видаляти абонентів,
шукати абонентів за ПІБ, показувати всіх абонентів. 

***зберігати інформацію в файл і завантажувати з файлу (записати у файл треба 1 абонента і 
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
    Abonent(string name, string surname, string lastname) :Abonent()
    {
        this->fullname.name = name;
        this->fullname.surname = surname;
        this->fullname.lastname = lastname;
    }
    Abonent(string name, string surname, string lastname, string homephone) :Abonent(name, surname, lastname)
    {
        this->homephone = homephone;
    }
    Abonent(string name, string surname, string lastname, string homephone, string workphone) :Abonent(name, surname, lastname, homephone)
    {
        this->workphone = workphone;
    }
    Abonent(string name, string surname, string lastname, string homephone, string workphone, string phone) :Abonent(name, surname, lastname, homephone, workphone)
    {
        this->mobilephone = phone;
    }

    void printAbonent()
    {
        cout << "\nName :" << fullname.name << endl;
        cout << "Surname :" << fullname.surname << endl;
        cout << "Lastname :" << fullname.lastname << endl;
        cout << "Homephone :" << homephone << endl;
        cout << "Workphone :" << workphone << endl;
        cout << "Phone :" << mobilephone << endl;
    }
    static int getCountAbonent()
    {
        return AbonentNum;
    }
    string getName() { return fullname.name; }
    string getSurname() { return fullname.surname; }
    string getLastname() { return fullname.lastname; }
    string getFullname() { return fullname.name + " " + fullname.surname + " " + fullname.lastname; }
    string getHomePhone() { return homephone; }
    string getWorkPhone() { return workphone; }
    string getMobilePhone() { return mobilephone; }
};
int Abonent::AbonentNum = 0;

class PhoneBook {
    Abonent* abonents;
    int countAbonent;
public:
    PhoneBook() :abonents(nullptr), countAbonent(0) {};
    ~PhoneBook() {
        if (abonents != nullptr)
            delete[] abonents;
    }
    void AddAbonent(Abonent ab) {
        countAbonent++;

        Abonent* temp = new Abonent[countAbonent];
        for (int i = 0; i < countAbonent - 1; i++)
        {
            temp[i] = abonents[i];
        }
        temp[countAbonent - 1] = ab;

        if (abonents != nullptr)
            delete[] abonents;
        abonents = temp;
    }

    void ShowAbonent() {
        for (int i = 0; i < countAbonent; i++)
        {
            cout << "Abonent# " << i + 1 << ":" << endl;
            abonents[i].printAbonent();
            cout << "--------------" << endl;
        }
    }
    
    void Delete(string phone) {
        int id = -1;
        for (int i = 0; i < countAbonent; i++) {
            if (abonents[i].getMobilePhone() == phone ||
                abonents[i].getHomePhone() == phone ||
                abonents[i].getWorkPhone() == phone) {
                id = i;
                break;
            }
        }
    }
    void SearchByName(string name) {
        for (int i = 0; i < countAbonent; i++) {
            if (abonents[i].getName() == name) {
                abonents[i].printAbonent();
                return;
            }
        }
        cout << "Abonent not found." << endl;
    }

    void SearchByPhone(string phone) {
        for (int i = 0; i < countAbonent; i++) {
            if (abonents[i].getHomePhone() == phone ||
                abonents[i].getWorkPhone() == phone ||
                abonents[i].getMobilePhone() == phone) {
                abonents[i].printAbonent();
                return;
            }
        }
        cout << "Abonent not found." << endl;
    }
   
};

int main()
{

    Abonent h1("Ivan", "Lis", "Ahmedovich", "+129856652", "+12454875", "+125656556");
    h1.printAbonent();
    cout << "Number of Abononets: " << Abonent::getCountAbonent() << endl;
    Abonent h2("Andriy", "Prohorov", "Konstantinovich", "+380951235461", "+125656556");
    h2.printAbonent();
    cout << "Number of Abononets: " << Abonent::getCountAbonent() << endl;

    PhoneBook book1;
    book1.AddAbonent(h1);
    book1.AddAbonent(h2);
    book1.SearchByName("Andriy");
    book1.SearchByPhone("+125656556");
    book1.ShowAbonent();
    book1.Delete("+380951235461");
    book1.ShowAbonent();
}

