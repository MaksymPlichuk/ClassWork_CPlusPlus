#include <iostream>
using namespace std;
//�������� 4. �������� �������, ��� ������� ��� �����.
//�������� 5. �������� ������� ��� ����������� ���������� � ���� �����.
//�������� 6. �������� �������, ��� ������� ������, ����
//�������� �������� �������, �� ������, ���� �䒺���.

int cubeOfNumber(int a)
{
	int cube = 1;
	for (int i = 0; i < 3; i++)
	{
		cube*= a;
	}
	return cube;
}
int maxFinder(int a, int b)
{
	int max = a;
	if (b>a)
	{
		max = b;
	}
	return max;
}
bool numberPositivity(int a)
{
	if (a > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	int a; 
	cout << "Enter number to find cube for : "; cin >> a;
	cout << "\nCube of "<< 5 <<" is : " << cubeOfNumber(a) << endl;
	int b; int c; 
	cout << "Enter two numbers to find max of: "; cin >> b; cin>> c;
	cout << "\nMaximum of " << b << " & " << c << " is: " << maxFinder(b, c) << endl;

	int d; cout << "\nEnter number to find if it positive or negative : "; cin >> d;
	cout << "the number is positive : " << numberPositivity(d) << endl;



}
