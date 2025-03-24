#include <iostream>
using namespace std;
//Вивести на екран фігури, заповнені зірочками.
//Діалог з користувачем реалізувати за допомогою меню.
int main()
{
	for (int i = 10; i > 0; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << "*" << " ";
		}
		cout << endl;
	}
}
