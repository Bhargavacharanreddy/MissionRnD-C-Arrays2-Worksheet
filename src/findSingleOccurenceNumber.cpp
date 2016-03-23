/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#include<stdlib.h>
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int l, int h)
{
	int x = arr[h];
	int i = (l - 1);

	for (int j = l; j <= h - 1; j++)
	{
		if (arr[j] <= x)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[h]);
	return (i + 1);
}


void quickSort(int A[], int l, int h)
{
	if (l < h)
	{

		int p = partition(A, l, h);
		quickSort(A, l, p - 1);
		quickSort(A, p + 1, h);
	}
}
int findSingleOccurenceNumber(int *A, int len)
{
	if (A == NULL || len < 0)
		return -1;
	quickSort(A, 0, len - 1);/*sorting the array using quick sort algorithm*/
	int x=A[0];                    
	for (int i = 1; i < len; i++)
	{
		if (i ==(len - 1))
		{
			if (A[i - 1] != A[i])
				x = A[i];
			continue;
		}
		if (A[i + 1] != A[i] && A[i - 1] != A[i])/*checking the predessor and successor 
												   the current element*/
			x = A[i];

	}
	return x;
}