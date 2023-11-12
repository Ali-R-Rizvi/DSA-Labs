// Lab 05
// Task 1 - Intersection

#include <fstream>
#include <iostream>
#include "string"

using namespace std;

int intersection1(int A[], int B[], int C[], int n)
{
	int total = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i] == B[j])
			{
				C[total] = A[i];
				total++;
				j = n;
			}
		}
	}

	return total;
}

int intersection2(int A[], int B[], int C[], int n)
{
	int common = 0;
	int count = 0;
	int low = 0, high = n - 1, mid = 0;


	for (int i = 0; i < n; i++)
	{
		low = 0;
		high = n - 1;
		while (low <= high)
		{
			mid = low + ((high - low) / 2);
			if (B[mid] == A[i])
			{
				common++;
				C[count] = A[i];
				count++;
				break;
			}

			else if (B[mid] > A[i])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
	}

	return common;
}
int main()
{
	int a[5] = { 1,2,3,4,5 };
	int b[5] = { 2,4,6,8,10 };
	int c[5] = {};

	int n = 5;

	int t = intersection2(a, b, c, n);

	cout << t;

	return 0;
}