
#include <iostream>
using namespace std;

/*Завдання N1
Створіть клас Student, який міститиме інформацію
про студента.
За допомогою механізму успадкування, реалізуйте клас
Aspirant (аспірант — студент, який готується до захисту
кандидатської роботи) похідний від Student.
Завдання N2
Створіть клас Passport (паспорт), який буде містити
паспортну інформацію про громадянина України.
За допомогою механізму успадкування, реалізуйте
клас ForeignPassport (закордонний паспорт) похідний
від Passport.
Нагадаємо, що закордонний паспорт містить крім
паспортних даних, також дані про візи, номер закордон-
ного паспорта.*/


class Student
{
protected:
    string name;
    int age;
    string institution;
public:
    Student() :name("no name"), age(0), institution("Harvard") {}
    Student(string name, int age, string inst) :name(name), age(age), institution(inst) {}
    void Print()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout <<"Institution : " << institution << endl;
    }
};

class Aspirant : public Student
{
    string projname;
public:
    Aspirant(): projname("no name"), Student(){}
    Aspirant(string name, int age, string inst, string projn) : projname(projn), Student(name, age, inst) {}
    void Print()
    {
        Student::Print();
        cout << "Final work name: " << projname << endl;
    }

};

class Pasport {
protected:
    string name;
    int age;
    string dateOfBirth;
    string gender;
    string dateOfExpiry;
public:
    Pasport() : name("no name"), age(0), dateOfBirth("0/0/0"), gender("none"), dateOfExpiry("0/0/0") {}
    Pasport(string n, int age, string dob, string gen, string doe) :name(n), age(age), dateOfBirth(dob), gender(gen), dateOfExpiry(doe) {};
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Date of birth: " << dateOfBirth << endl;
        cout << "Gender: " << gender << endl;
        cout << "Date of expire: " << dateOfExpiry << endl;
    }
};

class ForeignPassport : public Pasport
{
    static const int maxSize=10;
    int size;
    string visa[maxSize];
    string passnumber;
public:
    ForeignPassport(): visa{},passnumber("PF2000"),size(0), Pasport(){}
    ForeignPassport(string n, int a, string dob, string gen, string doe, string passnumber) : visa{}, passnumber(passnumber), size(0), Pasport(n, a, dob, gen, doe) {}
    void addVisas(const initializer_list<string>list)
    {
        int i = 0;
        for (string b:list)
        {
            visa[i] = b;
            i++;
        }
        size = list.size();
    }
    void Print()
    {
        Pasport::Print();
        cout << "Passnum: " << passnumber << endl;
        for (int i = 0; i < size; i++)
        {
            cout<< visa[i] << endl;
        }
    }
};

int main()
{
    
    Student s("Bob",23,"Massachutets");
    s.Print();
    Aspirant a("Joe", 24, "Harvard", "Evolution project");
    a.Print();
    cout << "------------------\n" << endl;
    Pasport p;
    ForeignPassport f;

    f.addVisas({ "USA", "Canada", "Germany", "France", "Japan" });
    f.Print();

    //string visa[SIZE] = { "USA", "Canada", "Germany", "France", "Japan" };
}
