﻿
#include <iostream>
using namespace std;
/*До вже існуючого класу, який має колекцію динамічних об*єктів

додати механізм зберігання та зчитування даних класу з файлу

Для даних операцій перевантажити operator <<

operator >> для зчитування  та запису у файл

(Train, Library, Array, Stack)
 */

struct Vagon {
    int num;
    int places;
    int passangers;
};
class Train
{
    Vagon* vagons;
    int countVagon;
    string name;
public:
    Train()
    {
        name = "No name";
        vagons = nullptr;
        countVagon = 0;
    }
    Train(string name)
    {
        this->name = name;
        vagons = nullptr;
        countVagon = 0;
    }
    Train(const Train& other)
    {
        this->name = other.name;
        this->countVagon = other.countVagon;
        if (countVagon > 0)
        {
            this->vagons = new Vagon[countVagon];
            for (int i = 0; i < countVagon; i++)
            {
                this->vagons[i] = other.vagons[i];
            }
        }
        else
        {
            this->vagons = nullptr;
        }
    }
    void Show()
    {
        cout << "Train name: " << name << endl;
        cout << "Number of vagons: " << countVagon << endl;
        for (int i = 0; i < countVagon; i++)
        {
            cout << "Vagon Number: " << vagons[i].num << endl;
            cout << "Number of passangers: " << vagons[i].passangers << endl;
            cout << "Number of places: " << vagons[i].places << endl;
        }

    }
    void addVagon(Vagon vagon)
    {
        ++countVagon;
        Vagon* tmp = new Vagon[countVagon];
        for (int i = 0; i < countVagon - 1; i++)
        {
            tmp[i] = vagons[i];
        }
        tmp[countVagon - 1] = vagon;
        if (vagons != nullptr)
            delete[] vagons;
        vagons = tmp;
    }
    void addPassanger(int vagonNum)
    {
        bool found = false;
        for (int i = 0; i < countVagon; i++)
        {
            if (vagons[i].num == vagonNum)
            {
                vagons[i].passangers++;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "The number of vagon is wrong" << endl;
        }
    }
    ~Train()
    {
        if (vagons != nullptr)
        {
            delete[]vagons;
        }
    }
    friend ofstream& operator <<(ofstream& out, const Train& animal);
    friend ifstream& operator >>(ifstream& in, Train& animal);
};


ofstream& operator <<(ofstream& out, const Train& animal)
{
    out << train.name << " " << animal.type << " " << animal.age << " " << animal.weight;
    return out;
}
ifstream& operator >>(ifstream& in, Train& animal)
{
    in >> animal.name >> animal.type >> animal.age >> animal.weight;
    return in;
}


int main()
{
    Train t1("Ford");
    t1.Show();
    Vagon vagon1{ 5,20,15 };
    cout << "\nAdded vagon" << endl;
    t1.addVagon(vagon1);
    t1.Show();
    cout << "\nAdded passanger" << endl;
    t1.addPassanger(5);
    t1.Show();
    cout << "\nConstructor copy" << endl;
    Train t2(t1);
    t2.Show();
}