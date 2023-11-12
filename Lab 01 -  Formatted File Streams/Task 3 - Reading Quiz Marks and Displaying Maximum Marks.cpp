// Lab 01
// Task 3 - Reading Quiz Marks and Displaying Maximum Marks

#include "iostream"
#include "fstream"
#include "cstdio"

using namespace std;

int main()
{
	ifstream inf;
	inf.open("input.txt");

	if (!inf)
	{
		printf("File Loading Failed!!!");
		exit(0);
	}

	int rollNo = 0;
	int marks[10];
	int max[10] = { 0 };
	int j = 0;
	inf >> rollNo >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4] >> marks[5] >> marks[6] >> marks[7] >> marks[8] >> marks[9];

	while (!inf.eof())
	{
		for (int i = 0; i < 10; i++)
		{
			if (max[j] < marks[i])
			{
				max[j] = marks[i];
			}
		}
		
		cout << rollNo << " " << marks[0] << " " << marks[1] << " " << marks[2] << " " << marks[3] << " " << marks[4] << " " << marks[5] << " " << marks[6] << " " << marks[7] << " " << marks[8] << " " << marks[9] << " " << max[j] << endl;
		j++;
		inf >> rollNo >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4] >> marks[5] >> marks[6] >> marks[7] >> marks[8] >> marks[9];
	}

	inf.close();

	return 0;
}
