// Lab 01
// Task 1 - Writing Student Records into the File

#include "iostream"
#include "fstream"
#include "cstdio"

using namespace std;

int main()
{
	ofstream outf;
	outf.open("student.txt");

	if (!outf)
	{
		printf("File Creation Failed!!!");
		exit(0);
	}
	int rollNo = 0;
	string fName;
	string lName;
	int marks = 0;

	for (int i = 0; i != -999; i++)
	{
		cout << "Enter Roll Number: ";
		cin >> rollNo;
		if (rollNo == -999)
		{
			printf("Program Exited!!!");
			break;
		}
		cout << "Enter First Name: ";
		cin >> fName;

		cout << "Enter Last Name: ";
		cin >> lName;

		cout << "Enter Marks: ";
		cin >> marks;

		outf << rollNo << "\t" << fName << " " << lName << "\t" << marks << endl;
	}

	outf.close();

	return 0;
}
