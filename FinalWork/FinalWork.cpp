
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <windows.h>
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

ofstream& operator <<(ofstream& out, const Item& item) {
    out << item.id << endl
        << item.name << endl
        << item.priceInHrn << endl
        << item.price << endl
        << item.ammount << endl
        << item.type << endl
        << item.mark << endl
        << item.description << endl;
    return out;
}
ifstream& operator >>(ifstream& in, Item& item) {
    in >> item.id;
    in.ignore();
    getline(in, item.name);
    in >> item.priceInHrn;
    in >> item.price;
    in >> item.ammount;
    in.ignore();
    getline(in, item.type);
    getline(in, item.mark);
    getline(in, item.description);
    return in;
}

class Shop{
    vector<Item> items;
public: 
    Item createItem() {
        Item i;

       cout << "==========Create Item==========" << endl;
       while (true)
       {
           try{ cout << "Enter item id: "; cin >> i.id; if (i.id < 0) { throw invalid_argument("Id must be > 0"); } //if перевірка на <0
           for (size_t j = 0; j < items.size(); j++) { // перевірка на ункікальність
               if (items[j].id == i.id) { throw invalid_argument("Id already exists! Please enter a unique id."); } 
               }
           } // тут закінчується try
           catch (invalid_argument& e){
               cout << "Invalid argument...\n";
               cout << e.what() << endl;
               continue;
           }
           cin.ignore(); // очищає \n після числа
           cout << "Enter item name: "; getline(cin, i.name);
           try { cout << "Enter item price in Hrn: "; cin >> i.priceInHrn; if (i.priceInHrn < 0) { throw invalid_argument("Price in Hrn must be > 0"); } }
           catch (invalid_argument& e) {
               cout << "Invalid argument...\n";
               cout << e.what() << endl;
               continue;
           }
           try { cout << "Enter item price: "; cin >> i.price; if (i.price < 0) { throw invalid_argument("Price must be > 0"); } }
           catch (invalid_argument& e) {
               cout << "Invalid argument...\n";
               cout << e.what() << endl;
               continue;
           }
           try { cout << "Enter item ammount: "; cin >> i.ammount; if (i.ammount < 0) { throw invalid_argument("Ammount must be > 0"); } }
           catch (invalid_argument& e) {
               cout << "Invalid argument...\n";
               cout << e.what() << endl;
               continue;
           }
           cin.ignore();
           cout << "Enter item type: "; getline(cin, i.type);
           cout << "Enter item mark: "; getline(cin, i.mark);
           cout << "Enter item description: "; getline(cin, i.description);
           return i;
       }     
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
    
    void savetofile() {
        ofstream out("Shop.txt");
        if (!out.is_open()) {
            cout << "Error: Cannot open file for writing!" << endl;
            return;
        }
        out << items.size() << endl;
        for (size_t i = 0; i < items.size(); i++) {
            out << items[i];
        }
        out.close();
        cout << "Successfully saved to file!" << endl;
    }

    void loadfromfile() {
        ifstream in("Shop.txt");
        if (!in.is_open()) {
            cout << "Error: Cannot open file for reading!" << endl;
            return;
        }
        items.clear();
        size_t count;
        in >> count;

        for (size_t i = 0; i < count; i++) {
            Item temp;
            in >> temp;
            items.push_back(temp);
        }
        in.close();
        cout << "Successfully loaded from file!" << endl;
    }

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
                    while (true)//перевірки на правильність вводу
                    {
                        /*try { cout << "Enter new item id: "; cin >> items[j].id; if (items[j].id < 0) { throw invalid_argument("Id must be > 0"); }
                        for (size_t i = 0; i < items.size(); i++) { // перевірка на ункікальність
                            if (items[i].id == items[j].id) { throw invalid_argument("Id already exists! Please enter a unique id."); }
                            }
                        }// тут закінчується try
                        catch (invalid_argument& e) {
                            cout << "Invalid argument...\n";
                            cout << e.what() << endl;
                            return;
                        }*/ // неможна ввести те саме айді
                        cin.ignore();
                        cout << "Enter new item name: "; getline(cin, items[j].name);
                        try { cout << "Enter new item price in Hrn: "; cin >> items[j].priceInHrn; if (items[j].priceInHrn < 0) { throw invalid_argument("Price in Hrn must be > 0"); } }
                        catch (invalid_argument& e) {
                            cout << "Invalid argument...\n";
                            cout << e.what() << endl;
                            continue;
                        }
                        try { cout << "Enter new item price: "; cin >> items[j].price;; if (items[j].price < 0) { throw invalid_argument("Price must be > 0"); } }
                        catch (invalid_argument& e) {
                            cout << "Invalid argument...\n";
                            cout << e.what() << endl;
                            continue;
                        }
                        try { cout << "Enter new item ammount: "; cin >> items[j].ammount; if (items[j].ammount < 0) { throw invalid_argument("Ammount must be > 0"); } }
                        catch (invalid_argument& e) {
                            cout << "Invalid argument...\n";
                            cout << e.what() << endl;
                            continue;
                        }
                        cin.ignore();
                        cout << "Enter new item type: "; getline(cin, items[j].type);
                        cout << "Enter new item mark: "; getline(cin, items[j].mark);
                        cout << "Enter new item description: "; getline(cin, items[j].description);
                        return;
                    }  
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
            for (size_t j = 0; j < items.size(); j++) {//цикл по айді

                if (searchID == items[j].id) {
                    cout << "Item with " << searchID << " id found!" << endl;
                    showInfo(items[j]);
                    cout << "==========Edit Item Price==========" << endl;
                    while (true)//перевірки на правильність вводу
                    {
                        try { cout << "Enter new item price in Hrn: "; cin >> items[j].priceInHrn; if (items[j].priceInHrn < 0) { throw invalid_argument("Price in Hrn must be > 0"); } }
                        catch (invalid_argument& e) {
                            cout << "Invalid argument...\n";
                            cout << e.what() << endl;
                            break;
                        }
                        try { cout << "Enter new item price: "; cin >> items[j].price; if (items[j].price < 0) { throw invalid_argument("Price must be > 0"); } }
                        catch (invalid_argument& e) {
                            cout << "Invalid argument...\n";
                            cout << e.what() << endl;
                            break;
                        }
                        return;
                    }   
                }
                else { cout << "Id not found, Try again: "; }
            }
        }
    }

    void showInfoByID() const{
        int searchID;
        cout << "Enter item's id" << endl;
        bool found = false;
        while (true)
        {
            cin >> searchID;
            for (size_t j = 0; j < items.size(); j++) {

                if (searchID == items[j].id) { showInfo(items[j]); found=true; }
            }
            if (found == false) { cout << "Id not found, Try again: "; }
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
        for (size_t j = 0; j < items.size(); j++) {// цикл який шукає айді

            if (searchID == items[j].id) {
                cout << "Item with " << searchID << " id found!" << endl;
                showInfo(items[j]);

                char confirm;
                cout << "\nDo you really want to delete this item?" << endl;//підтвердження
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
        int keyType;
        int n = items.size();
        bool sorted = false;
        cout << "[ 1 ] - Sort types (A-Z) \n[ 2 ] - Sort types (Z-A) \n[ 0 ] - Exit" << endl;
        while (true)
        {
            cin >> keyType;
            if (keyType == 1) {

                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (items[j].type > items[j + 1].type) {
                           swap(items[j], items[j + 1]);
                        }
                    }
                }
                cout << "Items sorted by type (A-Z) using Bubble Sort!" << endl;
                sorted = true;
                break;
            }
            else if (keyType == 2) {

                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (items[j].type < items[j + 1].type) {
                            swap(items[j], items[j + 1]);
                        }
                    }
                }
                cout << "Items sorted by type (Z-A) using Bubble Sort!" << endl;
                sorted = true;
                break;
            }
            else if (keyType == 0) {
                cout << "Exiting....";
                break;
            }
            else {
                cout << "Wrong key! [ 1 ] - Sort types (A-Z) [ 2 ] - Sort types (Z-A) [ 0 ] - Exit" << endl;
            }
        }
        if (sorted = true){
            cout << "\n==========Sorted Items==========" << endl;
            showAllItems();
        }
       
    };

    void sortByPrice() {
        int keyPrice;
        int n = items.size();
        bool sorted = false;
        int priceType;
        cout << "By which Price to sort?\n[ 1 ] - price in Hrn\n[ 2 ] - price in $" << endl;
        while (true)
        {
            cin >> priceType;
            if (priceType == 1) // сорт для гривень
            {
                cout << "[ 1 ] - Sort prices in Hryvnyas (low - high) \n[ 2 ] - Sort prices Hryvnyas (high - low) \n[ 0 ] - Exit" << endl;
                while (true)
                {
                    cin >> keyPrice;
                    if (keyPrice == 1) {

                        for (int i = 0; i < n - 1; i++) {
                            for (int j = 0; j < n - i - 1; j++) {
                                if (items[j].priceInHrn > items[j + 1].priceInHrn) {
                                    swap(items[j], items[j + 1]);
                                }
                            }
                        }
                        cout << "Items sorted by price (low-high) using Bubble Sort!" << endl;
                        sorted = true;
                        break;
                    }
                    else if (keyPrice == 2) {

                        for (int i = 0; i < n - 1; i++) {
                            for (int j = 0; j < n - i - 1; j++) {
                                if (items[j].price < items[j + 1].price) {
                                    swap(items[j], items[j + 1]);
                                }
                            }
                        }
                        cout << "Items sorted by price (high-low) using Bubble Sort!" << endl;
                        sorted = true;
                        break;
                    }
                    else if (keyPrice == 0) {
                        cout << "Exiting....";
                        break;
                    }
                    else {
                        cout << "Wrong key! [ 1 ] - Sort prices (low-high) [ 2 ] - Sort prices (high-low) [ 0 ] - Exit" << endl;
                    }
                }
                break;
            }
            else if (priceType == 2) // сорт для $
            {
                cout << "[ 1 ] - Sort prices (low-high) \n[ 2 ] - Sort types (high-low) \n[ 0 ] - Exit" << endl;
                while (true)
                {
                    cin >> keyPrice;
                    if (keyPrice == 1) {

                        for (int i = 0; i < n - 1; i++) {
                            for (int j = 0; j < n - i - 1; j++) {
                                if (items[j].price > items[j + 1].price) {
                                    swap(items[j], items[j + 1]);
                                }
                            }
                        }
                        cout << "Items sorted by price (low-high) using Bubble Sort!" << endl;
                        sorted = true;
                        break;
                    }
                    else if (keyPrice == 2) {

                        for (int i = 0; i < n - 1; i++) {
                            for (int j = 0; j < n - i - 1; j++) {
                                if (items[j].price < items[j + 1].price) {
                                    swap(items[j], items[j + 1]);
                                }
                            }
                        }
                        cout << "Items sorted by price (high-low) using Bubble Sort!" << endl;
                        sorted = true;
                        break;
                    }
                    else if (keyPrice == 0) {
                        cout << "Exiting....";
                        break;
                    }
                    else {
                        cout << "Wrong key! [ 1 ] - Sort prices (low-high) [ 2 ] - Sort prices (high-low) [ 0 ] - Exit" << endl;
                    }
                }
                break;
            }
            else { cout << "Wrong key! [ 1 ] - price in Hrn [ 2 ] - price in $" << endl; }
        }
       
        if (sorted = true){
            cout << "\n==========Sorted Items==========" << endl;
            showAllItems();
        }
       
    };

    void showByMark() const{
        string m;
        bool found = false;
        cout << "Enter mark of products that you want to see: "; cin >> m;
        
        for (size_t j = 0; j < items.size(); j++)
        {
            if (m==items[j].mark)
            {
                showInfo(items[j]);
                found = true;
            }
        }
        if (found==false) {
            cout << "== No items that fit your mark ==" << endl;
        }
    };

    void showByPriceRange() const{
        cout << "-Enter Price Range-" << endl;
        double lower = 0, higher = INFINITY;
        char keyPrice;
        bool found = false;
        int priceType;
        
        while (true) // вибір межі
        {
            cout << "\n[ h ] - to set price higher than \n[ l ] - to set price lower than \n[ b ] - to set both ranges \n[ e ] - to exit" << endl; cin >> keyPrice;
            if (keyPrice == 'h'){
                cout << "Price must be higher than "; cin >> lower;
                break;
            }
            else if (keyPrice == 'l'){
                cout << "Price must be lower than "; cin >> higher;
                break;
            } 
            else if (keyPrice == 'b'){
                cout << "Price must be higher than "; cin >> lower;
                cout << "Price must be lower than "; cin >> higher;
                break;
            }
            else if (keyPrice == 'e'){
                cout << "Exiting....";
                break;
            }
            else{
                cout << "Wrong key [ h ] - to set price higher than [ l ] - to set price lower than [ e ] - to exit" << endl;
            }
        }

        cout << "By which Price to show?\n[ 1 ] - price in Hrn\n[ 2 ] - price in $" << endl; // вибіп типу price
        while (true)
        {
            cin >> priceType;
            if (priceType == 1) // межі для гривень
            {
                cout << "\nItems that fit your price range: " << lower << " < price in Hrn " << " < " << higher << endl;
                for (size_t j = 0; j < items.size(); j++)
                {
                    if (items[j].priceInHrn > lower && items[j].priceInHrn < higher) {
                        showInfo(items[j]);
                        found = true;
                    }
                }
                if (found == false) {
                    cout << "== No items that fit your price range ==" << endl;
                }
                return;
            }
            else if (priceType == 2) // межі для $
            {
                cout << "\nItems that fit your price range: " << lower << " < price " << " < " << higher << endl;
                for (size_t j = 0; j < items.size(); j++)
                {
                    if (items[j].price > lower && items[j].price < higher) {
                        showInfo(items[j]);
                        found = true;

                    }
                }
                if (found == false) {
                    cout << "== No items that fit your price range ==" << endl;
                }
                return;
            }
            else { cout << "Wrong key [ 1 ] - price in Hrn [ 2 ] - price in $" << endl; }
        }
       
    };
    void showByAmmountRange() const {
        cout << "-Enter Ammount Range-" << endl;
        double lower = 0, higher = INFINITY;
        char keyAmmount;
        bool found = false;
        while (true) //вмбір межі
        {
            cout << "\n[ h ] - to set ammount higher than \n[ l ] - to set ammount lower than \n[ b ] - to set both ranges \n[ e ] - to exit" << endl; cin >> keyAmmount;
            if (keyAmmount == 'h') {
                cout << "Ammount must be higher than "; cin >> lower;
                break;
            }
            else if (keyAmmount == 'l') {
                cout << "Ammount must be lower than "; cin >> higher;
                break;
            }
            else if (keyAmmount == 'b') {
                cout << "Ammount must be higher than "; cin >> lower;
                cout << "Ammount must be lower than "; cin >> higher;
                break;
            }
            else if (keyAmmount == 'e') {
                cout << "Exiting....";
                break;
            }
            else {
                cout << "Wrong key [ h ] - to set ammount higher than [ l ] - to set ammount lower than [ e ] - to exit" << endl;
            }
        }
        cout << "\nItems that fit your ammount range: " << lower << " < ammount " << " < " << higher << endl;
        for (size_t j = 0; j < items.size(); j++)
        {
            if (items[j].ammount > lower && items[j].ammount < higher)
            {
                showInfo(items[j]);
                found = true;
            }
        }
        if (found==false) {
            cout << "== No items that fit your ammount range ==" << endl;
        }
    };

    void tablePrint() {
        sortByType();
        cout << "============================Table Raport================================" << endl;
        cout << "Item id -> " << " Item name -> " << " Item price in Hrn -> " << " Item price -> " << " Item ammount -> " << " Item type -> " << " Item mark -> " << " Item description" << endl;
        for (size_t j = 0; j < items.size(); j++)
        {
            cout << items[j].id << "\t" << items[j].name << "\t" << items[j].priceInHrn << "\t" << items[j].price << "\t" << items[j].priceInHrn << "\t" << items[j].ammount << "\t" << items[j].type << "\t" << items[j].mark << "\t" << items[j].description << endl;
            cout << endl;
        }

    };

    bool isEMPTY() {
        if (items.empty())
        {
            cout << "Shop is empty!" << endl;
            return true;
        }
        else { return false; }
    }
    //кастомна функція ;)
    void showImg()const {
        cout << "\t    ::=-:.                                        " << endl;
        cout << "\t    .**:+#-:                                      " << endl;
        cout << "\t   ::###%-+#-:                  :-:               " << endl;
        cout << "\t   .=%*#%@=-%#::               .-#*.           " << endl;
        cout << "\t   .+***#%@=:#%-.:            :.#%++:             " << endl;
        cout << "\t    :-::*#%@=:*%%#+-::      :-+%@#+#:             " << endl;
        cout << "\t        .*%@=:-+#@@@%*..  ::*%@@%*+#-             " << endl;
        cout << "\t     . :+%@@-:-:-++*%#*+===++***#*+#:             " << endl;
        cout << "\t  ::+##%%@@@@=:-*#++++++++++==-**##.     .:::..  " << endl;
        cout << "\t   :-**##%@@@@#*++++++++**%%##%=%-=+#++*#%=::**::" << endl;
        cout << "\t     ::*+*@@@%%#++++++++*#@%+%*#@@+%%+@%%@%@%-@#+:" << endl;
        cout << "\t    :.+%@@@@@%#+*++*++*%@@@%--+@*%%#%%@@@@@%%%@%+:" << endl;
        cout << "\t   .=++#%@@@@#**#**#*###%%=%@%@%@%%@@@@@@@@@@@%#. " << endl;
        cout << "\t   :+*+##%@######*+**++*#*%####@@@@@@@@@@%####%#- " << endl;
        cout << "\t ::=***+%%#####*++++++#%%##%@%@%%@@@@@@%*+-**%%*: " << endl;
        cout << "\t :+%@**+##*##***++++*#%%#%%%@@@@#=---++=-%%@%+*=: " << endl;
        cout << "\t.:*%@*+++++*#**++*++*%@%%%%@@@%+:#@@@@@@@#*%%%*.  " << endl;
        cout << "\t:=###*%#***#%%########%@@@@@@%@@@@@@@+%*%#=.::.   " << endl;
        cout << "\t .+%#%%*+*#%######*#%@@@@@@%@%@@@@@@@@%#-.        " << endl;
        cout << "\t  .-%@%#*+*%%%%%%%##%@@@@@@*#%@@@@@@%=..          " << endl;
        cout << "\t   .#@%####%%%@%@@@@@@@@@@@@=:+%##@@%-:           " << endl;
        cout << "\t   .+%#**##%%@%@@@@@@@@@@%@@@@++-%%##%*:::::      " << endl;
        cout << "\t    :-#%**%#%%%@@@@@@@@@@@@@%#*##%*:@:%###++:     " << endl;
        cout << "\t     ::#%@@@#%%@@@@@@%%%%%%@%@@@@@@##-==#**+:     " << endl;
        cout << "\t       .=#%%**%@@@@@@@@@@@@@@@@@@@@@%%@@@%*:      " << endl;
        cout << "\t         ::..=#++##%%##%%%%%%####%%%%%%%#:.       " << endl;
        cout << "\t             :.  :::::.::::-:   :::::::..         " << endl;
    }

    friend ofstream& operator <<(ofstream& out, const Item& item);
    friend ifstream& operator >>(ifstream& in, Item& item);
};



int main()
{
    Shop p;
    int choice;
    cout << "-------------------------Welcome to the shop-------------------------" << endl;
    p.showImg();
    while (true)
    {
        cout << "\n==========Shop menu==========" << endl;
        cout << "[ 1 ] - Add new item" << endl;
        cout << "[ 2 ] - Show items with similar mark" << endl;
        cout << "[ 3 ] - Show all/one item info" << endl;
        cout << "[ 4 ] - Edit item/item price" << endl;
        cout << "[ 5 ] - Delete item" << endl;
        cout << "[ 6 ] - Sort items by type/price" << endl;
        cout << "[ 7 ] - Save shop to the file" << endl;
        cout << "[ 8 ] - Load shop from the file" << endl; 
        cout << "[ 9 ] - Show by price/ammount range" << endl; 
        cout << "[ 10 ] - Give tabel raport" << endl;
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
            if (p.isEMPTY()) { break; }
            int key6;
            cout << "[ 1 ] - Sort by type" << endl;
            cout << "[ 2 ] - Sort by price" << endl; cin >> key6;
            if (key6 == 1) { p.sortByType(); }
            if (key6 == 2) { p.sortByPrice(); }
            break;
        case 7:
            p.savetofile();
            break;
        case 8:
            p.loadfromfile();
            break;
        case 9:
            if (p.isEMPTY()) { break; }
            int key9;
            cout << "[ 1 ] - Show by price range" << endl;
            cout << "[ 2 ] - Show by ammount range" << endl; cin >> key9;
            if (key9 == 1) { p.showByPriceRange(); }
            if (key9 == 2) { p.showByAmmountRange(); }
            break;
        case 10:
            if (p.isEMPTY()) { break; }
            p.tablePrint();
            break;
        case 0:
            cout << "Have a nice day!" << endl;
            cout << "Closing Shop..." << endl;
            Sleep(1000);
            p.showImg();
            return 0;
        default:
            cout << "Enter right key!!!" << endl;
            break;
        }
    }
}
