#include <iostream>
using namespace std;
//1.������� �� ����� ��� ����� �� 14 �� 123. - while
//2.������� �� ����� ������ ������ �����, �� �� ����������� 100. - while



int main()
{	
	cout << "\tTask 1" << endl;
    int a = 14;
	while (a<=123)
	{
		cout << a << " ";
		a++;
	}
	cout << endl;
	cout << "\tTask 2" << endl;
	int b = 0;
	cout << "Positive uneven numbers: ";
	while (b <= 100)
	{	
		
		if (b%2!=0)
		{
			cout << b << " ";
		}
		b++;
	}
	//3.���� N(N > 0).��������� N �����.������ ������� �䒺���� ����� ���. - while
	cout << "\n\tTask 3" << endl;
	int c;
	int count = 0;
	int ncount = 0;
	int n;
	cout << "Enter hom many numbers you want to input: "; cin >> n;
	cout << "\nEnter Numbers";
	while (count<n)
	{
		cin >> c;
		if (c<0)
		{
			ncount++;
		}
		count++;
	}
	cout << "Number of negative numbers: " << ncount << endl;

	cout << "\n\tTask 4" << endl;
	//4.��������� 8 �����.������ ������� �� ������ ����������� ��� �����. - while
	
	count = 0;
	int i = 0;
	int n1;
	int dob = 1;
	float sum = 0;
	cout << "Enter Numbers: ";
	while (i<8)
	{
		cin >> n1;
		dob *= n1;
		sum += n1;
		i++;
	}
	cout << "Product of numbers: " << dob << ";" << " " << "Average of numbers: " << sum / 8 << endl;

	//5.������� �� ����� ��� ������  ����� : 100 98 96 94...4  2 1. - do..while
	//6.�������� �������� ��� �������� ������� ���� �����, �� ��������� � ���������. - do..while
	cout << "\n\tTask 5" << endl;
	int n2 = 100;
	do
	{
		
		if (n2%2!=0)
		{ 
			cout << n2 << " ";
		}
		n2--;
	} while (n2>0);

	cout << "\n\tTask 6" << endl;
	int n3;
	int j=0;
	int dob2 = 1;
	cout << "Enter Numbers: ";
	do
	{
		cin >> n3;
		dob2 *= n3;
		j++;
	} while (j<5);

	cout << "Product of numbers: " << dob2;
}
