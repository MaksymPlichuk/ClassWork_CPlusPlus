#include <iostream>
using namespace std;

/*ТЕМА: DYNAMIC DATA STRUCTURES. PRIORITY QUEUE. 

Завдання 1:
Розробити додаток, що імітує чергу друку принтера. 
Програма надає меню з наступними можливостями:

•Додати документ в чергу. 
Користувач повинен ввести ім’я файлу та 
вибрати свою посаду. В залежності від посади, 

документу надається певний пріорітет 
(до прикладу: гість – 1, адміністратор – 2, менеджер – 3,
директор – 4 і тд.)

•Виконати друк. Відображається на екран документ, 
який наразі друкується (з максимальним пріорітетом).

Для збереження колекції документів використати динамічну 
структуру даних – Queue (черга з пріорітетним включенням).
Клас черга має бути шаблонним. 

 */

void Print()
{
    int a;
}
template<typename T>
class QueueWithPriority
{
private:
    struct Element
    {
        T name;
        int priority;
        void Print()
        {
            cout << "Name : " << name << ". Priority : " << priority << endl;
        }
    };
    Element* arr;
    int size;
public:
    QueueWithPriority() :arr(nullptr), size(0) {}
    ~QueueWithPriority()
    {
        if (arr != nullptr)delete[]arr;
    }
    void Enqueue(T value, int priority)
    {
        int index = 0;//size = 2
        while (index < size && arr[index].priority > priority) { index++; }
        size++;//1
        Element* temp = new Element[size];
        for (int i = 0; i < index; i++)
        {
            temp[i] = arr[i];
        }
        temp[index] = Element{ value,priority };
        for (int i = index; i < size - 1; i++)
        {
            temp[i + 1] = arr[i];
        }
        if (arr != nullptr)delete[]arr;
        arr = temp;
    }
    bool IsEmpty()
    {
        return size == 0;
    }
    Element Dequeue()
    {
        if (!IsEmpty())
        {
            Element first = arr[0];
            for (int i = 0; i < size - 1; i++)
            {
                //size = 6
                arr[i] = arr[i + 1];
            }
            size--;
            return first;
        }
        return Element();
    }
    void Print()
    {
        cout << "------------------ Queueu -----------------" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i].value << " : " << arr[i].priority << "  ";
        }
        cout << "\n______________________________________" << endl;
    }

};

int main()
{
    QueueWithPriority<string> q;
        int key;
        string name;
        short position;
    while (true)
    {
        cout << "\n1. Add into the queue\n";
        cout << "2. Print document\n";
        cout << "0. Exit\n";
        cout << "\nEnter number\n";cin >> key;
        switch (key)
        {
        case 0:
            return 0;
            
        case 1:
            
            cout << "Enter file name: ";cin >> name;
            cout << "\nEnter position:\n";cout << "1 - guest\n 2 - admin\n 3 - manager\n 4 - ceo\n"; cin >> position;
            while (position > 4 || position < 1)
            {
                cout << "\nError position must be 1 2 3 or 4: ";cin >> position;
                if (position>0 && position<5)
                {
                    break;
                }
            }

                q.Enqueue(name,position);
                break;
        case 2:
            
            while (!q.IsEmpty())
            {
                q.Dequeue().Print();
            }
            break;
        default:
            break;
        }

    }



    





}
