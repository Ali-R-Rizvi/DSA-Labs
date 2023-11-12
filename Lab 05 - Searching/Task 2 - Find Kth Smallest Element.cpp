// Lab 05
// Task 2 - Find Kth Smallest Element

#include <fstream>
#include <iostream>
#include "string"

using namespace std;

void intesertionsSort(int A[], int n)
{
	int j = 0;
	for (int i = 0; i < n - 1; i++)
	{
		j = i + 1;
		while ((j > 0) && A[j] < A[j - 1])
		{
			swap(A[j], A[j - 1]);
			j--;
		}
	}
}

int FindKthSmallest(int A[], int n, int k)
{
	if (k <=0)
	{
		cout << "ERROR!!! Negative Number to Find";
		exit(0);
	}
	intesertionsSort(A, n);
	return A[k - 1];
}

int main()
{
	int arr[5] = { 11,21,31,41,55 };

	int a = FindKthSmallest(arr, 5, 3);
	cout << a;

	return 0;
}
