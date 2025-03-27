//Вивести на екран фігури, заповнені зірочками.
//Діалог з користувачем реалізувати за допомогою меню.
#include <iostream>
using namespace std;
int main()
{
 int size = 10;
 int choice;

 while (true)
 {
     cout << "Enter number to build a section form 1-10 & 0 to exit: " << endl;
     cin >> choice;
     if (choice == 1)
     {
         for (int i = 0; i < size; i++)
         {
             for (int j = 0; j < size; j++)
             {
                 if (i <= j)
                     cout << "|###|";
                 else
                     cout << "|===|";
             }
             cout << endl;
         }
         cout << endl;
     }
     else if (choice == 2)
     {
         for (int i = 0; i < size; i++)
         {
             for (int j = 0; j < size; j++)
             {
                 if (i >= j)
                     cout << "|###|";
                 else
                     cout << "|===|";
             }
             cout << endl;
         }
         cout << endl;
     }
     else if (choice == 3)
     {
         for (int i = 0; i < size; i++)
         {
             for (int j = 0; j < size; j++)
             {
                 if (i <= j && i + j <= size - 1)
                     cout << "|###|";
                 else
                     cout << "|===|";
             }
             cout << endl;
         }
         cout << endl;
     }
     else if (choice == 4)
     {
         for (int i = 0; i < size; i++)
         {
             for (int j = 0; j < size; j++)
             {
                 if (i >= j && i + j >= size - 1)
                     cout << "|###|";
                 else
                     cout << "|===|";
             }
             cout << endl;
         }
         cout << endl;
     }
     else if (choice == 5)
     {
 
         for (int i = 0; i < size; i++)
         {
             for (int j = 0; j < size; j++)
             {
                 if ((i <= j && i + j <= size - 1) || (i >= j && i + j >= size - 1))
                     cout << "|###|";
                 else
                     cout << "|===|";
             }
             cout << endl;
         }
         cout << endl;
     }
     else if (choice == 6)
     {
         for (int i = 0; i < size; i++)
         {
             for (int j = 0; j < size; j++)
             {
                 if ((i >= j && i + j <= size - 1) || (i <= j && i + j >= size - 1))
                     cout << "|###|";
                 else
                     cout << "|===|";
             }
             cout << endl;
         }
         cout << endl;
     }
     else if (choice == 7)
     {
         for (int i = 0; i < size; i++)
         {
             for (int j = 0; j < size; j++)
             {
                 if (i >= j && i + j <= size - 1)
                     cout << "|###|";
                 else
                     cout << "|===|";
             }
             cout << endl;
         }
         cout << endl;
     }
     else if (choice == 8)
     {
 
         for (int i = 0; i < size; i++)
         {
             for (int j = 0; j < size; j++)
             {
                 if (i <= j && i + j >= size - 1)
                     cout << "|###|";
                 else
                     cout << "|===|";
             }
             cout << endl;
         }
         cout << endl;
     }
     else if (choice == 9)
     {
         for (int i = 0; i < size; i++)
         {
             for (int j = 0; j < size; j++)
             {
                 if (i + j <= size - 1)
                     cout << "|###|";
                 else
                     cout << "|===|";
             }
             cout << endl;
         }
         cout << endl;
     }
     else if (choice == 10)
     {
         for (int i = 0; i < size; i++)
         {
             for (int j = 0; j < size; j++)
             {
                 if (i + j >= size - 1)
                     cout << "|###|";
                 else
                     cout << "|===|";
             }
             cout << endl;
         }
         cout << endl;
     }
     else if (choice == 0)
     {
         break;
     }
 }
 
}
