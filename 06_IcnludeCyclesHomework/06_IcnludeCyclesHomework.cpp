#include <iostream>
using namespace std;
//�� �������� 12 ����.
//(������� �����)

int main()
{
    //1.������� �� ����� n �������, ���� 2n �����,
//���� 3n �����.����� n ������� ����������.
//(������� ��������� ������ �����)
//� = 5
//11111
//2222222222
//333333333333333
    cout << "Task 1" << endl;
    int num;
    cout << "Enter the how many numbers to print: "; cin >> num; cout << endl;
    for (int n = 1; n <= 3; n++) {
        for (int i = 0; i < n * num; i++) {
            cout << n;
        }
        cout << endl;
    }

//2..������� �� ����� ������� � ���� � �������,
//������� ��� ����������� ����� �� ������� ��������.
//������ � ������� ��� ����.
    cout << "\nTask 2" << endl;
    int size = 10;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j || j == size - i - 1) {
                cout << "0" << " ";
            }
            else {
                cout << "1" << " ";
            }
        }
        cout << endl;
    }

//3.������� ��� ����� : ������ �������, ���'��� ���'����,
//��� �����, ..., ���� �������.
//������ ���� ��� ��� �����.
    cout << "\nTask 3" << endl;
    int sum = 0;
    for (int i = 10; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i;
            sum += i;
            
        }
        cout << endl;
    }
    cout << "Sum of all numbers : " << sum << endl;

//4.������� �� ����� 15 �����.� ������ � ������� ��������
//������� �� 8 �����, ����� ������ �����.� ������ �
//��������� �������� ������� ������ �������.
    cout << "\nTask 4" << endl;
    for (int i = 0; i <= 15; i++)
    {
      if (i%2==0)
      {
          for (int j = 0; j < i; j++)
          {
              cout << i << " ";
          }
          cout << endl;
      }
      else
      {
          for (int h = 0; h <= 10; h++)
          {
              cout << 1;
          }
          cout << endl;
      }
    }

//5. ������� 30 �����.������ ����� ������ ��������� �����
//�� 1 �� ������ ��������� ����� ������� � ������ 1,
//���� ����� ����������� � �'��� �������.
    cout << "\nTask 5" << endl;
    for (int i = 0; i <= 30; i++)
    {
        if (i%2==0)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << 5;
            }
            cout << endl;
        }

        else
        {
            for (int h = 1; h < i+1; h++)
            {
                cout << h << " ";
            }
            cout <<endl;
        }
    }

    //6.������� �� ����� ������� �������� ��� ����� �� 1 �� 10.
    cout << "\nTask 6" << endl;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            cout << j*i << " ";
        }
        cout << endl;
    }

//7.������� ������� ����� ����� �� a �� b �������,
//�� ������� �� 12.
    cout << "\nTask 7" << endl;
    int a;
    int b;
    int count =0;
    cout << "Enter range: "; cin >> a; cin >> b;
    cout << endl;
    if (a>b)
    {
        swap(a, b);
    }
    cout << "Number range: ";
    for (int i = a; i < b; i++)
    {
        cout << i << " ";
        if (i%12==0)
        {
            count++;
        }
    }
    cout << "\nNumbers that even to 12 in this range: " << count << endl;

//(������)
//8. ���������� ������� �������� ����� �� ��(12
//    ������).���� ���������� ������� �������(���������,
//        3 � 6 � ����� �� ����� � ������ ������).���������
//    ��������� �����, � ����� �������� ��� ������������, �
//    �����, � ����� �������� ��� ���������, � �����������
//    �������� ��������.
    cout << "\nTask 8" << endl;
    int const sz = 12;
    int arr[sz]; int max;
    cout << "Enter earnings for months: ";
    for (int i = 0; i < sz; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    int c;
    int d;
    cout << "Enter range of months: "; cin >> c; cin >> d; c--; d--;
    cout << endl;
    int max1 = c; 
    int min = c;

    for (int i = c; i <= d; i++) {
        if (arr[i] > arr[max1]) {
            max1 = i;
        }
        if (arr[i] < arr[min]) {
            min = i;
        }
    }

    cout << "Max profit in " << (max1 + 1) << " month with profit " << arr[max1] << endl;
    cout << "Min profit in " << (min + 1) << " month with profit " << arr[min] << endl;

}
