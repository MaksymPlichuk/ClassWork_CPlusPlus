#include <iostream>
using namespace std;

//	Реалізувати клас Vector, який містить колекцію точок на площині.
//Точки зберігаються у вигляді списка(змінна типу List).
//Для класу потрібно реалізувати необхідний набір конструкторів,
//методи для видалення, додавання нової точки на початок та в кінець
//та метод Print() для виводу точок на екран.
//
//class List {}
//
//class Point {}
//
//class Vector
//{
//	int size;
//	//Point * points;
//	List<Point> points;
//}

template<typename T>
class List
{
private:
    struct Node
    {
        T value;
        Node* next;

        Node(T value, Node* next) :value(value), next(next) {}
    };
    Node* head;
public:
    List()
    {
        head = nullptr;
    }
    void AddToHead(T value)
    {
        Node* newNode = new Node(value, head);
        head = newNode;
    }
    void Print() const
    {
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
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
        Node* newNode = new Node(value, nullptr);
        if (head == nullptr)
        {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    T GetElement(int pos)
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
    T operator[](int pos)
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
        if (head == nullptr) return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;

        }
        else {
            Node* current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }


    }
    void DeleteFromHead()
    {
        if (head == nullptr) return;
        Node* current = head;
        head = head->next;
        delete current;
    }
};

class Point
{
    int x;
    int y;
public:
    Point() : x(0), y(0) {};
    Point(int x, int y) : x(x), y(y) {};
    Point operator++(int a) {
        Point res(x++, y++);
        return res;
    }
    Point operator--(int a) {
        Point res(x--, y--);
        return res;
    }
    bool operator>(const Point& other) {
        return (this->x * this->x + this->y * this->y) > (other.x * other.x + other.y * other.y);
    }
    bool operator<(const Point& other) {
        return (this->x * this->x + this->y * this->y) < (other.x * other.x + other.y * other.y);
    }
    friend ostream& operator<<(ostream& out, const Point& p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
};

class Vector
{
    List<Point> points;
    int countPoint;

public:
    Vector() : countPoint(0) {}

    void AddToHead(const Point& p){
        points.AddToHead(p);
        countPoint++;
    }

    void AddToTail(const Point& p){
        points.AddToTail(p);
        countPoint++;
    }

    void DeleteFromHead(){
        points.DeleteFromHead();
        if (countPoint > 0) countPoint--;
    }

    void Print() const{
        points.Print();
        cout << "Number of Points: " << countPoint << endl;
    }
};


int main()
{
    Vector v;
    v.AddToHead(Point(5, 6));
    v.AddToHead(Point(8, -4));
    v.AddToTail(Point(2, 3));
    v.Print();
    cout << "\nDelete from head" << endl;
    v.DeleteFromHead();
    v.Print();

    cout << "\nAdd points to tail" << endl;
    v.AddToTail(Point(4, -1));
    v.Print();

    return 0;
}