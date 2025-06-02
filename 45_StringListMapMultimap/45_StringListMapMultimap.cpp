#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;

/*Використовуючи контейнер map реалізувати програму - словник.
Програма повинна у вигляді меню надавати наступні можливості:
- додати слово з перекладами;
- знайти переклади слова;
- додати переклад до існуючого слова;
- видалити слово разом зі всіма перекладами;
- показавати всі слова які наявні в словнику;
- *читання і запис словника в файл.
 
Для реалізації даного функціоналу, створити клас Dictionary який містить 
колекцію слів зі списком перекладів та всі необхідні методи.
 */
map<string, int>::iterator FindByValue(map<string, int>& clients, int value)
{

    for (map<string, int>::iterator i = clients.begin(); i != clients.end(); i++)
    {
        if (i->second == value)
        {
            return i;
        }
    }
    return clients.end();
}
struct ID
{
    int id;
    string name;
    ID() {}
    ID(int id, string name) :id(id), name(name) {}
    void Show()const
    {
        cout << "Id : " << id << "  Name : " << name << endl;
    }
    bool operator < (const ID& other)const
    {
        return this->name < other.name;
    }

};
class Dictionary
{
    string name;
    map<string, list<string>> dic;
public:
    void AddNewWord(string key,list<string> value)
    {
       auto res = dic.insert(make_pair(key, value));
       if (res.second)
       {
           cout << "Slovo dodano\n";}
       else
       {
           cout << "Slovo ne dodano\n";
       }
    }
    void AddTranlate(string key,string new_translate)
    {
        if (dic.find(key) == dic.end())
            cout << "Word not found!\n";
        else
        {
                dic[key].push_back(new_translate);
        }
    }//elem.first ключ elem.second всі переклади
    void Print() {
        for (auto elem:dic)
        {
            cout << elem.first << " - ";
            for (string translate:elem.second)
            {
                cout <<"Traslate: "<< translate << endl;
            }
        }
    }

};
int main()
{

    map<string, list<string>> dic;
    string word = "run";
    list<string> meanings = { "bigtu", "pochatu","zapochatkevatu" };

    dic.insert(make_pair(word, meanings));
    dic.insert(make_pair("word", list<string>({ "slovo" })));
    dic.insert(make_pair("mind", list<string>({ "dumka","dusha","spogad" })));
    dic.insert(make_pair("bad", list<string>({ "poganuy","borg" })));
    for (string item : dic["bad"])
    {
        cout << item << " ";
    }

    //////////////////// add translate
    string input = "";
    cout << "Enter word to add translatins: "; getline(cin, input);

    if (dic.find(input) == dic.end())
        cout << "Word not found!\n";
    else
    {
        string translate = "";
        do
        {
            cout << "Enter translate: ";
            getline(cin, translate);
            dic[input].push_back(translate);

        } while (!translate.empty());
    }

    for (string item : dic[input])
    {
        cout << item << " ";
    }

    ////////////////////// check translate
    cout << "Enter word to translate: "; getline(cin, input);

    if (dic.find(input) == dic.end())
        cout << "Translate not found!\n";
    else
    {
        cout << "\tMeans:\n";
        for (string elem : dic[input])
            cout << elem << " ";
    }
