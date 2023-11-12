// Lab 01
// Task 2 - Reading and Displaying Student Records from the File

#include "iostream"
#include "fstream"
#include "cstdio"

using namespace std;

int main()
{
	ifstream inf;
	inf.open("student.txt");

	if (!inf)
	{
		printf("File Loading Failed!!!");
		exit(0);
	}

	int rollNo = 0;
	string fName;
	string lName;
	int marks = 0;

	cout << "Roll Number" << "\t" << "Name" << "\t\t" << "Marks" << endl;
	inf >> rollNo >> fName >> lName >> marks;

	while (!inf.eof())
	{
		cout << rollNo << "\t\t" << fName << " " << lName << "\t" << marks << endl;
		inf >> rollNo >> fName >> lName >> marks;
	}

	inf.close();

	return 0;
}
