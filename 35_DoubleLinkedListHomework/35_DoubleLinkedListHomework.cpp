
#include <iostream>
using namespace std;

/*1. Для масиву вагонів створити окрему структуру

з наступними полями:
struct Vagon
номер вагону
кількість місць
кількість пасажирів

2.class Train
Створити клас Потяг. У класі оголосити поля(змінні члени класу):
модель
кількість вагонів
для збереження масиву вагонів викорисати List<Vagon> vagons;
В класі потяг оголосити дефолтний конструктор
і перезавантажений конструктор.
Реалізувати метод Show()
Додати методи додавання вагона в початок/кінець та видалення з
початку/кінця.
Реалізувати конструктор копіювання

3. Додати метод DeleteFromHead для класу двозв*язного списку.
Завдання 4:
На 12 балів зробити видалення по позиції та додавання по позиції
class Train
{
private:
    string model;
    int countVagons;
    List<Vagon> vagons;
}
 */
template<typename T>
class List
{
    struct Node{
        Node* prev;
        T value;
        Node* next;
        Node(Node* prev, T value, Node* next) :prev(prev), value(value), next(next) {}
    };

private:
    Node* head;
    Node* tail;
public:
    List(){
        head = nullptr;
        tail = nullptr;
    }
    List(const List& other) : head(nullptr), tail(nullptr) {
        Node* current = other.head;
        while (current != nullptr) {
            AddToTail(current->value);
            current = current->next;
        }
    }
    bool IsEmpty(){
        return head == nullptr;
    }
    void AddToHead(T value){
        Node* newNode = new Node(nullptr, value, head);

        if (IsEmpty()){
            head = tail = newNode;
        }
        head->prev = newNode;
        head = newNode;
    }
    void Print()const{

        for (Node* i = head; i != nullptr; i = i->next){
            cout << i->value << " ";
        }
        cout << endl;
    }
    ~List(){
        Node* current = nullptr;
        while (head != nullptr){
            current = head;
            head = head->next;
            delete current;
        }
    }
    void AddToTail(T value){
        Node* newNode = new Node(tail, value, nullptr);
        if (head == nullptr){
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    int GetElement(int pos){
        Node* current = head;
        int i = 1;
        while (current != nullptr){
            if (pos == i) return current->value;
            current = current->next;
            i++;
        }
    }
    int operator[](int pos){
        Node* current = head;
        int i = 1;
        while (current != nullptr){
            if (pos == i) return current->value;
            current = current->next;
            i++;
        }
    }
    void DeleteFromTail(){
        if (IsEmpty()) return;
        if (head->next == nullptr){
            delete head;
            head = tail = nullptr;

        }
        else {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
    }
    void DeleteFromHead() {
        if (IsEmpty()) return;
        Node* current = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete current;
    }
};

struct Vagon {
    int vagonNum;
    int seats;
    int passangers;
};

class Train
{
    List<Vagon> vagons;
    int numberOfVagons;
    string model;
public:
    Train() : numberOfVagons(0), model("no model") {};
    Train(string m) : numberOfVagons(0), model(m) {};
    Train(const Train& other) : numberOfVagons(other.numberOfVagons), vagons(other.vagons), model(other.model) {};
    void Show(){
        cout << "Train model: " << model << endl;
        cout << "Number of Vagons: " << numberOfVagons << endl;
        vagons.Print();
    }
    void addVagonToHead(Vagon value) {
        vagons.AddToHead(value);
        numberOfVagons++;
    }
    void addVagonToTail(Vagon value) {
        vagons.AddToTail(value);
        numberOfVagons++;
    }
    void removeFromTail() {
        vagons.DeleteFromTail();
        if (numberOfVagons > 0) numberOfVagons--;
    }
    void removeFromHead() {
        vagons.DeleteFromHead();
        if (numberOfVagons > 0) numberOfVagons--;
    }
    friend ostream& operator << (ostream& out, const Vagon& v);
    ~Train() {}
};
ostream& operator << (ostream& out, const Vagon& v)
{
    out << v.vagonNum << " " << v.seats << " " << v.passangers << endl;
    return out;
}


int main()
{
    Train t("Ford");
    t.addVagonToHead(Vagon{ 1,30,25 });
    t.Show();
    cout << "\Adding vagons to tail:" << endl;
    t.addVagonToTail(Vagon{ 2,60,24 });
    t.addVagonToTail(Vagon{ 3,25,24 });
    t.addVagonToTail(Vagon{ 4,30,30 });
    t.Show();
  
    cout << "\nRemoving vagons form head:" << endl;
    t.removeFromHead();
    t.Show();
    cout << "\nRemoving vagons form tail:" << endl;
    t.removeFromTail();
    t.Show();

    cout << "\Adding vagons to head:" << endl;
    t.addVagonToHead(Vagon{ 5,10,4 });
    t.addVagonToHead(Vagon{ 6,15,15 });
    t.addVagonToHead(Vagon{ 7,6,5 });
    t.Show();

    cout << "Copy of Train 1" << endl;
    Train t2(t);
    t2.Show();
}
