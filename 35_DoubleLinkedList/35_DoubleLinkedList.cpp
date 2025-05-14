
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
    struct Node
    {
        Node* prev;
        T value;
        Node* next;
        //c-tors....show()
        Node(Node* prev, T value, Node* next) :prev(prev), value(value), next(next) {}
    };

private:
    Node* head;
    Node* tail;
public:
    List()
    {
        head = nullptr;
        tail = nullptr;
    }
    bool IsEmpty()
    {
        return head == nullptr;
    }
    void AddToHead(T value)
    {
        Node* newNode = new Node(nullptr, value, head);

        if (IsEmpty())
        {
            head = tail = newNode;
        }
        head->prev = newNode;
        head = newNode;
    }
    void Print()const
    {
      
        for (Node* i = head; i != nullptr; i = i->next)
        {
            cout << i->value << " ";
        }
        cout << endl;
    }
    ~List()
    {
        Node* current = nullptr;
        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }
    void AddToTail(T value)
    {
        Node* newNode = new Node(tail, value, nullptr);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    int GetElement(int pos)
    {
        Node* current = head;
        int i = 1;
        while (current != nullptr)
        {
            if (pos == i) return current->value;
            current = current->next;
            i++;
        }
    }
    int operator[](int pos)
    {
        Node* current = head;
        int i = 1;
        while (current != nullptr)
        {
            if (pos == i) return current->value;
            current = current->next;
            i++;
        }
    }
    void DeleteFromTail()
    {
        if (IsEmpty()) return;
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;

        }
        else {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
    }
};

 struct Vagon {
     int vagonNum;
     int seats;
     int passangers;
 };

 class Train
 {
     int numberOfVagons;
 public:
     Train()
     {
         numberOfVagons = 0;
     }
     void Show()
     {
        cout << "Number of Vagons: " << numberOfVagons << endl;
        vagons.Print();
     }
     void addVagonToHead(Vagon value) {
         vagons.AddToHead(value);
     }
     void addVagonToTail(Vagon value) {
         vagons.AddToTail(value);
     }
     void removeFromTail() {
         vagons.DeleteFromTail();
     }
        friend ostream& operator << (ostream & out, const Vagon & v);
 private:
     List<Vagon> vagons;
 };
 ostream& operator << (ostream& out, const Vagon& v)
 {
         out << v.vagonNum <<" " << v.seats << " " << v.passangers << endl;
         return out;
 }


int main()
{
    Train t;
    t.addVagonToHead(Vagon{ 1,30,25 });
    t.Show();
   /* List<int>l;
    l.AddToHead(100);
    l.AddToHead(200);
    l.AddToHead(300);
    l.Print();
    l.AddToTail(1);
    l.AddToTail(2);
    l.AddToTail(3);
    l.AddToTail(4);
    l.Print();
    l.DeleteFromTail();
    l.DeleteFromTail();
    l.DeleteFromTail();
    l.DeleteFromTail();
    l.Print();*/

}
