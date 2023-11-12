// Lab 01
// Task 4 - Best of Two Quizzes in Decreasing Order

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

	ofstream outf;
	outf.open("output.txt");

	if (!outf)
	{
		printf("File Creation Failed!!!");
		exit(0);
	}

	int rollNo = 0;
	int marks[10];
	int max[10] = { 0 };
	int max2[10] = { 0 };
	int j = 0;
	int k = 0;
	int maxMarks = 0;
	int dupMarks[10] = { 0 };
	inf >> rollNo >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4] >> marks[5] >> marks[6] >> marks[7] >> marks[8] >> marks[9];
	int temp = 0;

	while (!inf.eof())
	{
		for (int i = 0; i < 10; i++) // Finding Maximum Marks
		{
			if (max[j] < marks[i])
			{
				max[j] = marks[i];
			}
		}

		for (int a = 0; a < 10; a++) // Copying Marks Array
		{
			dupMarks[a] = marks[a];
		}

		for (int i = 0; i < 10; i++) // Sorting Duplicate Array
		{
			for (int j = 0; j < 10; j++)
			{
				if (dupMarks[i] > dupMarks[j])
				{
					temp = dupMarks[i];
					dupMarks[i] = dupMarks[j];
					dupMarks[j] = temp;
				}
			}
		}
		max2[k] = dupMarks[1];
		cout << rollNo << " " << max[j] << " " << max2[k] << endl;
		outf << rollNo << " " << max[j] << " " << max2[k] << endl;
		j++;
		k++;
		inf >> rollNo >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4] >> marks[5] >> marks[6] >> marks[7] >> marks[8] >> marks[9];
	}

	inf.close();
	outf.close();

	return 0;
}
