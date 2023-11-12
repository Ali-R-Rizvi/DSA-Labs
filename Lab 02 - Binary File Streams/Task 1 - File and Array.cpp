// Lab 02
// Task 1 - File and Array

#include "iostream"
#include "cstdio"
#include "fstream"

using namespace std;

int arrayToFile(string fileName, int* arr, int size)
{
	fstream outf(fileName, ios::binary | ios::out);

	if (!outf)
	{
		printf("ERROR!!! File Doesn't Exist");
		exit(0);
	}

	outf.write(reinterpret_cast<char*>(arr), (sizeof(int) * size));
	outf.close();
}

int fileToArray(string fileName1, int* arr, int size)
{
	ifstream inf(fileName1, ios::binary | ios::in);

	if (!inf)
	{
		printf("ERROR!!! File Doesn't Exist");
		exit(0);
	}

	inf.read(reinterpret_cast<char*>(arr), (sizeof(int) * size));
	inf.close();
}

int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	string fileName = "std.txt";
	int size = sizeof(arr) / sizeof(arr[0]);

	arrayToFile(fileName, arr, size);

	int newArr[10];
	fileToArray(fileName, newArr, size);

	for (int i = 0; i < 10; i++)
	{
		cout << newArr[i] << " ";
	}

	return 0;
}
