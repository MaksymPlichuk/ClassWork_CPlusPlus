
#include <iostream>
#include <vector>
using namespace std;

struct Item
{
    string name;
    int priceInHrn;
    int price;
    int ammount;
    string type;
    string description;
};

class Shop{
    vector<Item> items;
public: 
    Item createItem() {
        Item i;
        cout << "==========Create Item==========" << endl;
        cout << "Enter item name: ";cin >> i.name;
        cout << "\nEnter item price in Hrn: ";cin >> i.priceInHrn;
        cout << "\nEnter item price: ";cin >> i.price;
        cout << "\nEnter item ammount: ";cin >> i.ammount;
        cout << "\nEnter item type: ";cin >> i.type;
        cout << "\nEnter item description: ";cin >> i.description;
        return i;
    }
    void ShowInfo() {
        Item i;
        cout << "==========Item info=========="<< endl;
        cout << "Enter item name: " << i.name << endl;
        cout << "Enter item price in Hrn: " << i.priceInHrn << endl;
        cout << "Enter item price: " << i.price << endl;
        cout << "Enter item ammount: " << i.ammount << endl;
        cout << "Enter item type: " << i.type << endl;
        cout << "Enter item description: " << i.description << endl;;
    }
    void addItemToTheShop() {
        Item i = createItem(); 
        items.push_back(i);    
    }
    void loadtofile() {};
    void savetofile() {};

    void editItem() {};
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
