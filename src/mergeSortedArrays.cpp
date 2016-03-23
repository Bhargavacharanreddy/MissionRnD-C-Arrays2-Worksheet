/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

#include<malloc.h>
#include<stdlib.h>
struct transaction
{
	int amount;
	char date[11];
	char description[20];
};

int toInt(char a[], int i, int j)/*to convert a string to int specified by the postions i to j to numbers*/
{
	int c, n;
	n = 0;
	for (c = i; c <= j; c++)
	{
		n = n * 10 + a[c] - '0';
	}
	return n;
}
int datecmp(char *str1, char *str2, int i, int j)/*comparing the dates of specified fields*/
{

	int n1, n2;
	n1 = toInt(str1, i, j);
	n2 = toInt(str2, i, j);
	if (n1 == n2)
		return 2;
	if (n1<n2)
		return 1;
	else
		return 0;
}
int  cmp(struct transaction *A, struct transaction *B, int i, int j)/* this function will compare the dates of 
																	 particular transactions of A and B*/
{
	int count = 0; int flag = 0, x = 0;
	x = datecmp(A[i].date, B[j].date, 6, 9);
	if (x != 2)
		return x;
	x = datecmp(A[i].date, B[j].date, 3, 4);
	if (x != 2)
		return x;
	x = datecmp(A[i].date, B[j].date, 0, 1);
	if (x == 2)
		return 0;
	else
		return x;
}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	int i = 0, j = 0, k = 0;
	if (A == NULL || B == NULL || ALen<0 || BLen<0)/*checking for null conditions and invalid inputs*/
		return NULL;
	struct transaction *temp = (struct transaction *)malloc((ALen + BLen)*sizeof(struct transaction));
	while (i < ALen && j < BLen)
	{

		if (cmp(A, B, i, j))
		{
			temp[k] = A[i];
			i++;
		}
		else
		{
			temp[k] = B[j];
			j++;
		}
		k++;
	}
	if (i >= ALen)/* i points to first transaction A*/
	{
		while (j < BLen)
		{
			temp[k] = B[j];
			j++;
			k++;
		}
	}
	if (j >= BLen)/*j points to second transaction B*/
	{
		while (i < ALen)
		{
			temp[k] = A[i];
			i++;
			k++;
		}
	}
	return temp;
}

