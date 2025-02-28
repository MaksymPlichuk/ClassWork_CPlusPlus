#include <iostream>

using namespace std;
//1.Вивести на екран цілі числа від 1 до 100. - while
//2.Вивести на екран додатні парні числа, які не перевищують 200, та їх кількість. - while
int main()
{	
	/*cout << "Zavdannya1" << endl;
    int counter = 1 ;
	while (counter <= 100)
	{
		cout << counter <<" ";
		counter++;
	}

	cout << "Zavdannya2" << endl;

	counter = 1;
	while (counter <= 200)
	{
		if (counter % 2 == 0) {
			cout << counter << " ";
		}
		
		counter++;
	}*/

	cout << "zavdannya3" << endl;
	//3.дано n(n > 0).вводяться n чисел.знайти суму парних серед цих чисел. - while
	//int countnumber;//10
	//cout << "vvedit skilki chisel vvestu :";  cin >> countnumber;
	//int i = 0;
	//int number;
	//int summa = 0;
	//while (i < countnumber) {
	//	cout << "enter : " << i + 1 << "number : " ;
	//	cin >> number;
	//	if (number%2==0) {
	//		summa += number;
	//	}
	//	i++;
	//}
	//cout << "sum of even number =" << summa << endl;

	cout << "Zavdannya4" << endl;
	//4.Вводяться 10 чисел.Знайти суму та середнє арифметичне цих чисел. - while
	/*int i = 0;
	float number;
	float summa = 0;
	float avg;
	while (i < 10) {
		cout << "Enter " << i + 1 << "number : ";
		cin >> number;
		summa += number;
		avg = summa / 10;
		i++;
	}
	cout << "Sum of 10 number =" << summa << endl;
	cout << "Average of 10 number =" << avg << endl;*/

	cout << "Zavdannya6" << endl;
	//5.Вивести на екран цілі числа : 100 99 98 97...3 2 1. - do..while
	int j = 0;
	do
	{
		cout << j +1<< " ";
		j++;
	} while (j < 100);



	cout << "\nZavdannya6" << endl;
	//6.Написати програму яка обчислює суму семи чисел, які вводяться з клавіатури. - do..while
	int countnumber = 7;
	int i = 0;
	int number;
	int summa = 0;
	do
	{
		cout << "enter : " << i + 1 << "number : ";
		cin >> number;
		summa += number;
		i++;
	} while (i < countnumber);

	cout << "sum of even number =" << summa << endl;


}
