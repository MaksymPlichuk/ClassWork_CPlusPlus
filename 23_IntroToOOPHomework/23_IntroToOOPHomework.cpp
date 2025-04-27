
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
/*Завдання №1
Реалізуйте клас «Студент».Необхідно зберігати в
змінних - членах класу : ПІБ, дату народження, контактний
телефон, місто, країну, назву навчального закладу, місто
та країну(де знаходиться навчальний заклад), номер
групи.Реалізуйте функції - члени класу для введення даних, виведення даних, реалізуйте аксесор для доступу до
окремих змінних - членів.
Завдання №2
Реалізуйте клас «Точка».Необхідно зберігати координати
x, y, z в змінних - членах класу.Реалізуйте функції - члени
класу для введення даних, виведення даних, реалізуйте
аксесор для доступу до змінних - членів, реалізуйте збереження в файл і завантаження даних з файлу*/

class Student {

    string name;
    string surname;
    string lastname;
    string dateofbirth;
    string phone;
    string country;
    string city;
    string institution;
    string instcity;
    string instcountry;
    int groupnum;
public:
    void input() {
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter student surname: ";
        getline(cin, surname);
        cout << "Enter student lastname: ";
        getline(cin, lastname);
        cout << "Enter student date of birth: ";
        getline(cin, dateofbirth);
        cout << "Enter student phone number: ";
        getline(cin, phone);
        cout << "Enter student country: ";
        getline(cin, country);
        cout << "Enter student city: ";
        getline(cin, city);
        cout << "Enter student institution name: ";
        getline(cin, institution);
        cout << "Enter institution city: ";
        getline(cin, instcity);
        cout << "Enter institution country: ";
        getline(cin, instcountry);
        cout << "Enter student group number: ";
        cin >> groupnum;
    }

    void output() {
        cout << "\nStudent Name: " << name << endl;
        cout << "Student Surname: " << surname << endl;
        cout << "Student Lastname: " << lastname << endl;
        cout << "Date of Birth: " << dateofbirth << endl;
        cout << "Phone Number: " << phone << endl;
        cout << "Country: " << country << endl;
        cout << "City: " << city << endl;
        cout << "Institution: " << institution << endl;
        cout << "Institution City: " << instcity << endl;
        cout << "Institution Country: " << instcountry << endl;
        cout << "Group Number: " << groupnum << endl;
    }


    string getName() { return name; }
    

    string getSurname() { return surname; }
    
    
    string getLastname() { return lastname; }


    string getDateOfBirth() { return dateofbirth; }


    string getPhone() { return phone; }


    string getCountry() { return country; }


    string getCity() { return city; }


    string getInstName() { return institution; }


    string getInstCity() { return instcity; }


    string getInstCountry() { return instcountry; }


    int getGroupNum() { return groupnum; }


    void setName(string name) {
        this->name = name;
    }
    
    void setSurname(string surname) {
        this->surname = surname;
    }
    
    void setLastname(string lastname) {
        this->lastname = lastname;
    }

    void setDateOfBirth(string dateofbirth) {
        this->dateofbirth = dateofbirth;
    }

    void setPhone(string phone) {
        this->phone = phone;
    }

    void setCountry(string country) {
        this->country = country;
    }

    void setCity(string city) {
        this->city = city;
    }

    void setInstName(string institution) {
        this->institution = institution;
    }

    void setInstCity(string instcity) {
        this->instcity = instcity;
    }

    void setInstCountry(string instcountry) {
        this->instcountry = instcountry;
    }

    void setGroupNum(int groupnum) {
        this->groupnum = groupnum;
    }


};

class Point {

    float x, y, z;

public:

    void input() {
        cout << "Enter coords for point (x,y,z): ";
        cin >> x >> y >> z;
    }
    void output() {
        cout << "Coords of point: " << "(" << x << "," << y << "," << z << ")";
    }

    void setX(float x) {
        this->x = x;
    }
    void setY(float y) {
        this->y = y;
    }
    void setZ(float z) {
        this->z = z;
    }

    float getX() { return x; }
    float getY() { return y; }
    float getZ() { return z; }
};
int main()
{
    Point p1;
    Student s1;
    s1.input();
    s1.output();

    s1.setName("Gordon");
    s1.setSurname("Freeman");
    s1.setLastname("Smith");
    s1.setDateOfBirth("02/03/2003");
    s1.setPhone("+123456789");
    s1.setCountry("USA");
    s1.setCity("Sietle");
    s1.setInstName("Harvard University");
    s1.setInstCity("Massachutes");
    s1.setInstCountry("USA");
    s1.setGroupNum(101);

    cout << "\n--- After using set methods ---\n";
    s1.output();

    cout << "\n\n\t-----Points-----" << endl;
    p1.input();
    p1.output();
    p1.setX(3);
    p1.setY(6);
    p1.setZ(0);
    p1.getX();
    p1.getY();
    p1.getZ();
}
