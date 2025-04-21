// Визначити структуру Студент з полями імя студента, ід студента, оцінки (python, html, cplus). Оцінки подати у вигляді окремою структури типу Marks.
//Створити одного-двох студентів,заповнпти дані про них з клавіатури, вивести на екран. Написати для завдання відповідні функції
// 3) printToFile()  4) inputFromFile
#include <iostream>
#include <fstream>
using namespace std;

const int NAME_SIZE = 50;
struct Student
{
	char stname[NAME_SIZE] = "Noname";
	int stid=0;
	struct Marks {
		int mkpython=0;
		int mkhtml=0;
		int mkcplusplus=0;
	};

	Marks marks;
}; 
void printMarks(Student::Marks& marks)
{
	cout << "Python mark: " << marks.mkpython << endl;
	cout << "HTML mark: " << marks.mkhtml << endl;
	cout << "C++ mark: " << marks.mkcplusplus << endl;
}
void inputMarks(Student::Marks& marks)
{
	cout << "Enter Python mark: "; cin >> marks.mkpython; cout << endl;
	cout << "Enter HTML mark: "; cin >> marks.mkhtml; cout << endl;
	cout << "Enter C++ mark: "; cin >> marks.mkcplusplus; cout << endl;
}
void printStName(Student& student)
{
	cout << "Student name: " << student.stname << endl;
	cout << "Student id: " << student.stid << endl;
}
void inputStName(Student& student)
{
	cout << "Enter Student name: "; cin >> student.stname;cout << endl;
	cout << "Enter Student id: "; cin >> student.stid;cout << endl;
}
void writeToFileStudents(const Student& student, string path = "students.txt")
{
	ofstream file;
	file.open(path);
	if (!file)
	{
		cout << "Error file " << path << endl;
		return;
	}
	file << student.stname << endl;
	file << student.stid << endl;

	file << student.marks.mkpython << endl;
	file << student.marks.mkhtml << endl;
	file << student.marks.mkcplusplus << endl;

}
void readFromFileStudents(Student& student, string path = "students.txt")
{
	ifstream file;
	file.open(path);
	if (!file)
	{
		cout << "Error file " << path << endl;
		return;
	}
	file.getline(student.stname, NAME_SIZE);
	file >> student.stid;

	file >> student.marks.mkpython;
	file >> student.marks.mkhtml;
	file >> student.marks.mkcplusplus;
}

int main()
{
	Student student1{}, student2{};
	//Student::Marks student1Marks{}, student2Marks{};
	cout << "\tEnter first student info" << endl;
	inputStName(student1);
	inputMarks(student1.marks);
	//student1.marks = student1Marks;
	printStName(student1);
	printMarks(student1.marks);

	cout << "\n\tEnter second student info" << endl;
	inputStName(student2);
	inputMarks(student2.marks);
	printStName(student2);
	printMarks(student2.marks);
	
	writeToFileStudents(student1, "students.txt");

	readFromFileStudents(student1);
	cout << "\n\nRead student from file\n";
	printStName(student1);
	printMarks(student1.marks);
	

}
