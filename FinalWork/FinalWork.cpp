
#include <iostream>
#include <vector>
using namespace std;

struct Item
{
    int id;
    string name;
    int priceInHrn;
    int price;
    int ammount;
    string type;
    string mark;
    string description;

    Item() : id(0), name(""), priceInHrn(0), price(0), ammount(0), type(""), mark(""), description("") {};
};

class Shop{
    vector<Item> items;
public: 
    Item createItem() {
        Item i;
        cout << "==========Create Item==========" << endl;
        cout << "Enter item id: "; cin >> i.id;
        cout << "Enter item name: ";cin >> i.name;
        cout << "Enter item price in Hrn: ";cin >> i.priceInHrn;
        cout << "Enter item price: ";cin >> i.price;
        cout << "Enter item ammount: ";cin >> i.ammount;
        cout << "Enter item type: ";cin >> i.type;
        cout << "Enter item mark: ";cin >> i.mark;
        cout << "Enter item description: ";cin >> i.description;
        return i;
    }
    void showInfo(const Item& i) const{
        cout << "==========Item info=========="<< endl;
        cout << "Item's id: " << i.id << endl;
        cout << "Item's name: " << i.name << endl;
        cout << "Item's price in Hrn: " << i.priceInHrn << endl;
        cout << "Item's price: " << i.price << endl;
        cout << "Item's ammount: " << i.ammount << endl;
        cout << "Item's type: " << i.type << endl;
        cout << "Item's mark: " << i.mark << endl;
        cout << "Item's description: " << i.description << endl;
    }
    void addItemToTheShop() {
        Item i = createItem(); 
        items.push_back(i);    
    }
    void loadtofile() {};
    void savetofile() {};

    void editItem() {
        int searchID;
        cout << "Enter item's id" << endl;
       
        while (true){
            cin >> searchID;
            for (size_t j = 0; j < items.size(); j++) {

                if (searchID == items[j].id){
                    cout << "Item with " << searchID << " id found!" << endl;
                    showInfo(items[j]);
                    cout << "==========Edit Item==========" << endl;
                    cout << "Enter new item id: "; cin >> items[j].id;
                    cout << "Enter new item name: "; cin >> items[j].name;
                    cout << "Enter new item price in Hrn: "; cin >> items[j].priceInHrn;
                    cout << "Enter new item price: "; cin >> items[j].price;
                    cout << "Enter new item ammount: "; cin >> items[j].ammount;
                    cout << "Enter new item type: "; cin >> items[j].type;
                    cout << "Enter new item mark: "; cin >> items[j].mark;
                    cout << "Enter new item description: "; cin >> items[j].description;
                    return;
                }
                else{cout << "Id not found, Try again: ";}
            }
        }
        
    };

    void editItemPrice() {
        int searchID;
        cout << "Enter item's id" << endl;

        while (true){
            cin >> searchID;
            for (size_t j = 0; j < items.size(); j++) {

                if (searchID == items[j].id) {
                    cout << "Item with " << searchID << " id found!" << endl;
                    showInfo(items[j]);
                    cout << "==========Edit Item Price==========" << endl;
                    cout << "Enter new item price in Hrn: "; cin >> items[j].priceInHrn;
                    cout << "Enter new item price: "; cin >> items[j].price;
                }
                else { cout << "Id not found, Try again: "; }
            }
        }
    }

    void showInfoByID() const{
        int searchID;
        cout << "Enter item's id" << endl;

        while (true)
        {
            cin >> searchID;
            for (size_t j = 0; j < items.size(); j++) {

                if (searchID == items[j].id) { showInfo(items[j]); }
                else { cout << "Id not found, Try again: "; }
            }
        }
    }

    void showAllItems() const{
        cout << "==========All Items==========\n" << endl;
        for (size_t j = 0; j < items.size(); j++)
        {
            showInfo(items[j]);
        }
    };

    void deleteItem() {
    int searchID;
    cout << "Enter item's id" << endl;

    while (true) {
        cin >> searchID;
        for (size_t j = 0; j < items.size(); j++) {

            if (searchID == items[j].id) {
                cout << "Item with " << searchID << " id found!" << endl;
                showInfo(items[j]);

                char confirm;
                cout << "\nDo you really want to delete this item?" << endl;
                cout << "[ y ] - to delete,  [ n ] - to cancel" << endl; 
                while (true)
                {
                    cin >> confirm;
                    if (confirm == 'y') {
                        items.erase(items.begin() + j);
                        cout << "Item with " << searchID << " id was deleted!" << endl;
                        return;
                    }
                    else if (confirm == 'n') {
                        cout << "Deletion was canceled!" << endl;
                        return;
                    }
                    else{
                        cout << "Wrong key! Enter [ y ] - to delete,  [ n ] - to cancel " << endl;
                    }
                }
                
                
            }
            else { cout << "Id not found, Try again: "; }
        }
    }
    };

    void sortByType() {
        items;
    };

    void sortByPrice() {};

    void showByMark() const{
        string m;
        cout << "Enter mark of products that you want to see: "; cin >> m;
        
        for (size_t j = 0; j < items.size(); j++)
        {
            if (m==items[j].mark)
            {
                showInfo(items[j]);
            }
        }
    };

    void showByPriceRange() {
        cout << "-Enter Price Range-" << endl;
        double lower = 0, higher = INFINITY;
        char keyPrice;
        while (true)
        {
            cout << "\n [ h ] - to set higher than [ l ] - to set lower than [ e ] - to exit" << endl; cin >> keyPrice;
            if (keyPrice == 'h'){
                cout << "Price must be higher than "; cin >> lower;
                break;
            }
            if (keyPrice == 'l'){
                cout << "Price must be lower than "; cin >> higher;
                break;
            }
            if (keyPrice == 'e'){
                cout << "Exiting....";
                return;
            }
            else{
                break;
            }
        }
        
        for (size_t j = 0; j < items.size(); j++)
        {
            if (items[j].price>lower && items[j].price < higher)
            {
                cout << "-Items that fit your price range-" << endl;
                showInfo(items[j]);

            }
            cout << "- No items that fit your price range-" << endl;
        }
    };
    void showByAmmountRange() {
        //cout << ;
    };

    void tablePrint() {};

    bool isEMPTY() {
        if (items.empty())
        {
            cout << "Shop is empty!" << endl;
            return true;
        }
    }
};


int main()
{
    Shop p;
    int choice;
    cout << "-------------------------Welcome to the shop-------------------------" << endl;
    while (true)
    {
        cout << "\n==========Shop menu==========" << endl;
        cout << "[ 1 ] - Add new item" << endl;
        cout << "[ 2 ] - Show item with one mark" << endl;
        cout << "[ 3 ] - Show all/one item info" << endl;
        cout << "[ 4 ] - Edit item/item price" << endl;
        cout << "[ 5 ] - Delete item" << endl;
        cout << "[ 6 ] - Sort items" << endl;
        cout << "[ 7 ] - Save shop to the file" << endl;
        cout << "[ 8 ] - Load shop from the file" << endl; 
        cout << "[ 9 ] - Show by price/ammount range" << endl;
        cout << "[ 0 ] - Exit program" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            p.addItemToTheShop();
            break;
        case 2:
            if (p.isEMPTY()) { break; }
            p.showByMark();
            break;
        case 3:
            if (p.isEMPTY()) { break; }
                int key3;
                cout << "[ 1 ] - Show one item info" << endl;
                cout << "[ 2 ] - Show all items info" << endl; cin >> key3;
                if (key3 == 1) { p.showInfoByID(); }
                if (key3 == 2) { p.showAllItems(); }
                break;
           
        case 4:
            if (p.isEMPTY()) { break; }
            int key4;
            cout << "[ 1 ] - Edit everything" << endl;
            cout << "[ 2 ] - Edit only price" << endl; cin >> key4;
            if (key4 == 1) { p.editItem(); }
            if (key4 == 2) { p.editItemPrice(); }
            
            break;
        case 5:
            if (p.isEMPTY()) { break; }
            p.deleteItem();
            break;
            
        case 6:
            p.editItem();
            break;
        case 7:
            p.editItem();
            break;
        case 8:
            p.editItem();
            break;
        case 9:
            if (p.isEMPTY()) { break; }
            int key9;
            cout << "[ 1 ] - Show by price range" << endl;
            cout << "[ 2 ] - Show by ammount range" << endl; cin >> key9;
            if (key9 == 1) { p.showByPriceRange(); }
            if (key9 == 2) { p.showByAmmountRange(); }
            break;

        case 0:
            cout << "Closing Shop..." << endl;
            return 0;
        default:
            break;
        }
    }
}
